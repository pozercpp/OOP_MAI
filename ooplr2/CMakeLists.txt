cmake_minimum_required(VERSION 3.14)
project(OOP_LR2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)

add_executable(ooplr2 
    src/ooplr2.cpp 
    src/decimal.cpp
    src/myvector.cpp
)

add_executable(tests 
    test/main_test.cpp 
    test/test_decimal.cpp 
    src/decimal.cpp
    src/myvector.cpp
)

target_link_libraries(tests GTest::GTest GTest::Main)
target_include_directories(ooplr2 PRIVATE include)
target_include_directories(tests PRIVATE include)