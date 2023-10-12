cmake_minimum_required(VERSION 3.5)
project({{ cookiecutter.project_name }})

find_package(GTest REQUIRED)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
