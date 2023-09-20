cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/adc514538678a61b13c240f7b41babbc03b2ac24.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  factory_function_test
  factory_function_test.cc
)
target_link_libraries(
  factory_function_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(factory_function_test)