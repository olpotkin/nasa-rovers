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
  // Test commands pipeline
  BOOST_AUTO_TEST_CASE(test_03_commands) {
    Rover r_1;
    r_1.setCommands("MRLMMMRM");

    BOOST_CHECK(r_1.getCommands() == "MRLMMMRM");
  }

BOOST_AUTO_TEST_SUITE_END()
