cmake_minimum_required(VERSION 3.14)
project(stdoptionalbool_tests)

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
  tests
  tests.cc
)
target_link_libraries(
  tests
  GTest::gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(tests)