cmake_minimum_required(VERSION 3.2)

project(rover VERSION 0.0.1)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(rover main.cpp rover/rover.h rover/rover.cpp)

add_executable(rover_tests tests.cpp rover/rover.h rover/rover.cpp)

set_target_properties(rover rover_tests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
  )

set_target_properties(rover_tests PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
  )

target_link_libraries(rover_tests
  ${Boost_LIBRARIES}
  )

enable_testing()

add_test(rover_test_set rover_tests)
