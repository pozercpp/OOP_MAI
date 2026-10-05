# Создайте README.md с описанием проекта
cat > README.md << 'EOL'
# Eliminate Unset Bits Project

Проект для удаления нулевых битов из строки и вычисления результирующего числа.

## Структура проекта

- `src/` - исходный код основной программы
- `test/` - unit-тесты с использованием Google Test
- `include/` - заголовочные файлы
- `CMakeLists.txt` - конфигурация CMake

## Сборка и запуск

```bash
# Создание директории для сборки
mkdir build
cd build

# Конфигурация CMake
cmake ..

# Сборка проекта
make

# Запуск основной программы
./eliminate_bits

# Запуск тестов
./eliminate_unsetbits_test