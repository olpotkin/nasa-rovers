#include "rover.h"

#include <utility>


// Default ctor
Rover::Rover() :
  pos_x(0),
  pos_y(0),
  pos_orientation('N'),
  commands(""){ }


// Ctor with parameters
Rover::Rover(int pos_x, int pos_y, char pos_orientation, std::string commands) :
  pos_x(pos_x),
  pos_y(pos_y),
  pos_orientation(pos_orientation),
  commands(std::move(commands)){ }


// Return x-pos
int Rover::getPosX() const {
  return this->pos_x;
}


// Return y-pos
int Rover::getPosY() const {
  return this->pos_y;
}


// Return orientation
char Rover::getOrientation() const {
  return this->pos_orientation;
}


// Show position of the rover
void Rover::displayPos() const {
  std::cout << this->pos_x << " "
    << this->pos_y << " "
    << this->pos_orientation
    << std::endl;
}


// Set movement scenario
void Rover::setCommands(const std::string &received_commands) {
  this->commands = received_commands;
}


// Get current movement scenario
std::string Rover::getCommands() const {
  return this->commands;
}


// Rotate rover to the right
void Rover::rotateRight() {
  switch (pos_orientation) {
    case 'N': pos_orientation = 'E'; break;
    case 'E': pos_orientation = 'S'; break;
    case 'S': pos_orientation = 'W'; break;
    case 'W': pos_orientation = 'N'; break;
  }
}


// Rotate rover to the left
void Rover::rotateLeft() {
  switch (pos_orientation) {
    case 'N': pos_orientation = 'W'; break;
    case 'E': pos_orientation = 'N'; break;
    case 'S': pos_orientation = 'E'; break;
    case 'W': pos_orientation = 'S'; break;
  }
}


// Move rover on the grid considering borders of the grid
void Rover::moveOnGrid(int l_x, int l_y, int r_x, int r_y) {
  switch (pos_orientation) {
    case 'N':
      if (pos_y < r_y) { ++pos_y; }
      else { pos_y = r_y; }
      break;
    case 'E':
      if (pos_x < r_x) { ++pos_x; }
      else { pos_x = r_x; }
      break;
    case 'S':
      if (pos_y > l_y) { --pos_y; }
      else { pos_y = l_y; }
      break;
    case 'W':
      if (pos_x > l_x) { --pos_x; }
      else { pos_x = l_x; }
      break;
  }
}


// Execute moving scenario
void Rover::execute(const std::string& in_commands, int l_x, int l_y, int r_x, int r_y) {
  if (in_commands.empty()) {
    return;
  }
  else {
    for (const auto& command : in_commands) {
      switch (command) {
        case 'L': this->rotateLeft(); break;
        case 'R': this->rotateRight(); break;
        case 'M': moveOnGrid(l_x, l_y, r_x, r_y);
      }
    }
  }
}
