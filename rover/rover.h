/// @brief Rover class declaration
/// @author Oleg Potkin <olpotkin@gmail.com>
/// @date 2019-09-14

#ifndef ROVER_ROVER_H
#define ROVER_ROVER_H

#include <iostream>


class Rover {
public:
  /// @brief Constructor with default values
  explicit Rover();
  /// @brief Constructor with parameters
  Rover (int pos_x, int pos_y, char pos_orientation);
  /// @brief Destructor
  ~Rover() = default;

  /// @brief Returns current x-position of the rover
  int getPosX();
  /// @brief Returns current y-position of the rover
  int getPosY();
  /// @brief Returns current orientation of the rover
  char getOrientation();

  /// @brief Show position of the rover on the grid
  void displayPos();
  /// @brief Rotate the rover to the right
  void rotateRight();
  /// @brief Rotate the rover to the left
  void rotateLeft();

private:
  int pos_x;                 // x-position on the grid
  int pos_y;                 // y-position on the grid
  char pos_orientation;      // Orientation (possible values are N-north, S-south, E-east, W-west)
};


#endif //ROVER_ROVER_H
