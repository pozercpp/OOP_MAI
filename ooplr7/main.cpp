#include <cstring>
#include <ctime>
#include <fstream>
#include <set>
#include <queue>
#include <thread>
#include <random>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <optional>
#include <cmath>
#include<algorithm>

#include "factory.hpp"
#include "npc.hpp"

const int MAP_SIZE = 100;
const int MOVE_DIST = 10;
const int KILL_DIST = 5;
const double PI = 3.141592653589793;

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
    std::queue<FightEvent> events;
    std::mutex mtx;
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> d6{1, 6};
    std::atomic_bool& running;
public:
    FightManager(std::atomic_bool &flag) : running(flag) {}
    void add_event(FightEvent&& ev) {
        std::lock_guard<std::mutex> l(mtx);
        events.push(std::move(ev));
    }
    void operator()() {
        while (running || !events.empty()) {
            std::optional<FightEvent> ev;
            {
                std::lock_guard<std::mutex> l(mtx);
                if (!events.empty()) {
                    ev = events.front();
                    events.pop();
                }
            }
            if (ev) {
                auto& att = ev->attacker;
                auto& def = ev->defender;
                if (att->is_alive() && def->is_alive()) {
                    bool can_kill = def->accept(att);
                    if (can_kill) {
                        int attack = d6(rng);
                        int defense = d6(rng);
                        if (attack > defense) {
                            def->die();
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
};

class MovementManager {
    std::set<std::shared_ptr<NPC>>& npcs;
    std::shared_mutex& npcs_mutex;
    std::atomic_bool& running;
    FightManager& fight_manager;
    std::mt19937 rng;
public:
    MovementManager(std::set<std::shared_ptr<NPC>>& n, std::shared_mutex& m, std::atomic_bool& r, FightManager& f)
        : npcs(n), npcs_mutex(m), running(r), fight_manager(f), rng(std::random_device{}()) {}
    void operator()() {
        while (running) {
            {
                std::unique_lock<std::shared_mutex> lock(npcs_mutex);
                for (const auto& npc : npcs) {
                    if (!npc->is_alive()) continue;
                    std::uniform_real_distribution<double> dist_angle(0, 2 * PI);
                    double angle = dist_angle(rng);
                    int dx = static_cast<int>(std::round(MOVE_DIST * std::cos(angle)));
                    int dy = static_cast<int>(std::round(MOVE_DIST * std::sin(angle)));
                    int new_x = std::clamp(npc->x + dx, 0, MAP_SIZE - 1);
                    int new_y = std::clamp(npc->y + dy, 0, MAP_SIZE - 1);
                    npc->x = new_x;
                    npc->y = new_y;
                }
                for (const auto& att : npcs) {
                    if (!att->is_alive()) continue;
                    for (const auto& def : npcs) {
                        if (att == def || !def->is_alive()) continue;
                        if (att->is_close(def, KILL_DIST)) {
                            fight_manager.add_event({att, def});
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

class RenderManager {
    std::set<std::shared_ptr<NPC>>& npcs;
    std::shared_mutex& npcs_mutex;
    std::mutex& cout_mutex;
    std::atomic_bool& running;
public:
    RenderManager(std::set<std::shared_ptr<NPC>>& n, std::shared_mutex& m, std::mutex& c, std::atomic_bool& r)
        : npcs(n), npcs_mutex(m), cout_mutex(c), running(r) {}
    void operator()() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::shared_lock<std::shared_mutex> lock(npcs_mutex);
            std::lock_guard<std::mutex> cout_lock(cout_mutex);
            std::cout << "=== NPC BATTLE FIELD === Живых: ";
            int alive = 0;
            for (const auto& n : npcs) {
                if (n->is_alive()) ++alive;
            }
            std::cout << alive << "\n\n";
            for (int y = 0; y <= MAP_SIZE; y += 10) {
                for (int x = 0; x <= MAP_SIZE; x += 10) {
                    char sym = '.';
                    for (const auto& n : npcs) {
                        if (n->is_alive() &&
                            std::abs(n->x - x) < 7 &&
                            std::abs(n->y - y) < 7) {
                            switch (n->type) {
                                case SquirrelType: sym = 'S'; break;
                                case DruidType: sym = 'D'; break;
                                case OrkType: sym = 'O'; break;
                                default: sym = '?';
                            }
                        }
                    }
                    std::cout << sym;
                }
                std::cout << '\n';
            }
            std::cout << std::flush;
        }
    }
};

void save(const std::set<std::shared_ptr<NPC>>& array, const std::string& filename) {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (const auto& n : array) { n->save(fs); }
    fs.flush();
    fs.close();
}

std::set<std::shared_ptr<NPC>> load(const std::string &filename) {
    std::set<std::shared_ptr<NPC>> res;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i) { res.insert(factory(is)); }
        is.close();
    } else {
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    }
    return res;
}

std::ostream& operator<<(std::ostream &os, const std::set<std::shared_ptr<NPC>>& array) {
    for (const auto& n : array) {
        if (n->is_alive()) {
            n->print();
        }
    }
    return os;
}

int main() {
    std::srand(std::time(0));
    std::atomic_bool running(true);
    std::set<std::shared_ptr<NPC>> array;
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        auto type = static_cast<NpcType>(std::rand() % 3 + 1);
        array.insert(factory(type, "NPC_" + std::to_string(i), std::rand() % MAP_SIZE, std::rand() % MAP_SIZE));
    }
    std::cout << "Saving ..." << std::endl;
    save(array, "npc.txt");
    std::cout << "Loading ..." << std::endl;
    array = load("npc.txt");
    std::cout << "Initial state:" << std::endl << array;
    std::cout << "Starting simulation ..." << std::endl;
    std::shared_mutex npcs_mutex;
    std::mutex cout_mutex;
    FightManager fm(running);
    std::thread fight_thread(std::ref(fm));
    MovementManager mm(array, npcs_mutex, running, fm);
    std::thread move_thread(std::ref(mm));
    RenderManager rm(array, npcs_mutex, cout_mutex, running);
    std::thread render_thread(std::ref(rm));
    std::this_thread::sleep_for(std::chrono::seconds(60));
    running = false;
    move_thread.join();
    fight_thread.join();
    render_thread.join();
    std::cout << "Final state:" << std::endl << array;
    return 0;
}