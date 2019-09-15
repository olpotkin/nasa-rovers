/// @brief Unit tests
/// @author Oleg Potkin <olpotkin@gmail.com>
/// @date 2019-09-14

#define BOOST_TEST_MODULE rover_test_module

#include <boost/test/unit_test.hpp>
#include "rover/rover.h"


BOOST_AUTO_TEST_SUITE(rover_test_suite)

  // Test 01:
  // Test default constructor works as expected
  BOOST_AUTO_TEST_CASE(test_01_default_ctor) {
    Rover r_1;

    BOOST_CHECK(r_1.getPosX() == 0);
    BOOST_CHECK(r_1.getPosY() == 0);
    BOOST_CHECK(r_1.getOrientation() == 'N');
    BOOST_CHECK(r_1.getCommands() == "");
  }

  // Test 02:
  // Test custom constructor works as expected
  BOOST_AUTO_TEST_CASE(test_02_custom_ctor) {
    Rover r_1(1, 2, 'S', "RLM");

    BOOST_CHECK(r_1.getPosX() == 1);
    BOOST_CHECK(r_1.getPosY() == 2);
    BOOST_CHECK(r_1.getOrientation() == 'S');
    BOOST_CHECK(r_1.getCommands() == "RLM");
  }

  // Test 03:
  // Test commands pipeline works as expected
  BOOST_AUTO_TEST_CASE(test_03_commands) {
    Rover r_1;
    r_1.setCommands("MRLMMMRM");

    BOOST_CHECK(r_1.getCommands() == "MRLMMMRM");
  }

  // Test 04:
  // Test movement on the grid works as expected
  BOOST_AUTO_TEST_CASE(test_04_move) {
    // Bottom border - Down
    Rover r_1(0, 0, 'S', "");
    // Left border - Left
    Rover r_2(0, 0, 'W', "");
    // Top border - Up
    Rover r_3(5, 5, 'N', "");
    // Right border - Right
    Rover r_4(5, 5, 'E', "");

    r_1.moveOnGrid(0, 0, 5, 5);
    r_2.moveOnGrid(0, 0, 5, 5);
    r_3.moveOnGrid(0, 0, 5, 5);
    r_4.moveOnGrid(0, 0, 5, 5);
    BOOST_CHECK(r_1.getPosY() == 0);
    BOOST_CHECK(r_2.getPosX() == 0);
    BOOST_CHECK(r_3.getPosY() == 5);
    BOOST_CHECK(r_4.getPosX() == 5);

    // Change the grid size to see movements not on the borders
    r_1.moveOnGrid(-10, -10, 10, 10);
    r_2.moveOnGrid(-10, -10, 10, 10);
    r_3.moveOnGrid(-10, -10, 10, 10);
    r_4.moveOnGrid(-10, -10, 10, 10);
    BOOST_CHECK(r_1.getPosY() == -1);
    BOOST_CHECK(r_2.getPosX() == -1);
    BOOST_CHECK(r_3.getPosY() == 6);
    BOOST_CHECK(r_4.getPosX() == 6);
  }

BOOST_AUTO_TEST_SUITE_END()
