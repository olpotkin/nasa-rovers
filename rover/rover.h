/// @brief Rover class declaration
/// @author Oleg Potkin <olpotkin@gmail.com>
/// @date 2019-09-14

#ifndef ROVER_ROVER_H
#define ROVER_ROVER_H

#include <iostream>
#include <string>


class Rover {
public:
  /// @brief Constructor with default values
  explicit Rover();
  /// @brief Constructor with parameters
  Rover (int pos_x, int pos_y, char pos_orientation, std::string commands);
  /// @brief Destructor
  ~Rover() = default;

  /// @brief Returns current x-position of the rover
  int getPosX() const;
  /// @brief Returns current y-position of the rover
  int getPosY() const;
  /// @brief Returns current orientation of the rover
  char getOrientation() const;

  /// @brief Set moving scenario for the rover
  /// @param received_commands - string with movement scenario
  void setCommands(const std::string& received_commands);
  /// @brief Return moving scenario of the rover
  std::string getCommands() const;

  /// @brief Show position of the rover on the grid
  void displayPos() const;
  /// @brief Rotate the rover to the right
  void rotateRight();
  /// @brief Rotate the rover to the left
  void rotateLeft();

  /// @brief Move the rover on the grid
  /// @param l_x - left x corner of the grid
  /// @param l_y - left y corner of the grid
  /// @param r_x - right x corner of the grid
  /// @param r_y - right y corner of the grid
  void moveOnGrid(int l_x, int l_y, int r_x, int r_y);

  /// @brief Execute motion scenario of the rover
  /// Basically, this is wrapper for moveOnGrid method
  /// @param in_commands - string with commands
  void execute(const std::string& in_commands, int l_x, int l_y, int r_x, int r_y);

private:
  int         pos_x;              // x-position on the grid
  int         pos_y;              // y-position on the grid
  char        pos_orientation;    // Orientation (possible values are N-north, S-south, E-east, W-west)
  std::string commands;           // String with moving scenario for rover
};

#endif //ROVER_ROVER_H
