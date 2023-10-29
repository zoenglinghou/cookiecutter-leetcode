cmake_minimum_required(VERSION 3.5)
project(lc-{{ cookiecutter.project_name }} CXX)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Debug build
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -Wextra -Wpedantic -fsanitize=address -fsanitize=undefined)
add_link_options(-fsanitize=address -fsanitize=undefined)

find_package(lib-leetcode REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

include_directories(include)

set(TEST_SRC
  main.cpp
)

ament_add_gtest(${PROJECT_NAME}_test ${TEST_SRC})
ament_target_dependencies(${PROJECT_NAME}_test lib-leetcode)
set_tests_properties(${PROJECT_NAME}_test PROPERTIES TIMEOUT 2)

ament_package()
