cmake_minimum_required(VERSION 3.10)
project(CustomArrayProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Директории для include (если headers в include/)
include_directories(include)

# Добавляем исходники библиотеки (allocator.cpp в src/)
add_library(allocator STATIC src/allocator.cpp)

# Указываем include для библиотеки
target_include_directories(allocator PUBLIC include .)  # Если headers в include или корне

# Добавляем executable с main (main.cpp в src/)
add_executable(main src/main.cpp)  # Теперь ищет в src/

# Линкуем main с библиотекой
target_link_libraries(main PRIVATE allocator)
target_include_directories(main PRIVATE include .)  # Для array.h, allocator.h и т.д.