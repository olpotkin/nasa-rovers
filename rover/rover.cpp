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
int Rover::getPosX() {
  return this->pos_x;
}


// Return y-pos
int Rover::getPosY() {
  return this->pos_y;
}


// Return orientation
char Rover::getOrientation() {
  return this->pos_orientation;
}


// Show position of the rover
void Rover::displayPos() {
  std::cout << this->pos_x << " "
    << this->pos_y << " "
    << this->pos_orientation
    << std::endl;
}


void Rover::setCommands(const std::string &received_commands) {
  this->commands = received_commands;
}


std::string Rover::getCommands() {
  return this->commands;
}


void Rover::rotateRight() {
  switch (pos_orientation) {
    case 'N': pos_orientation = 'E'; break;
    case 'E': pos_orientation = 'S'; break;
    case 'S': pos_orientation = 'W'; break;
    case 'W': pos_orientation = 'N'; break;
  }
}

void Rover::rotateLeft() {
  switch (pos_orientation) {
    case 'N': pos_orientation = 'W'; break;
    case 'E': pos_orientation = 'N'; break;
    case 'S': pos_orientation = 'E'; break;
    case 'W': pos_orientation = 'S'; break;
  }
}


