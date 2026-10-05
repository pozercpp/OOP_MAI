cmake_minimum_required(VERSION 3.14)
project(EliminateBits)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
add_executable(eliminate_bits 
    src/oop_lr1.cpp 
    src/eliminate_unset_bits.cpp
)
add_executable(eliminate_unsetbits_test 
    test/test_main.cpp 
    test/test_eliminate_bits.cpp 
    src/eliminate_unset_bits.cpp
)
target_link_libraries(eliminate_unsetbits_test GTest::GTest GTest::Main)
target_include_directories(eliminate_bits PRIVATE include)
target_include_directories(eliminate_unsetbits_test PRIVATE include)