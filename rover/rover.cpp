#include "rover.h"


// Default ctor
Rover::Rover() :
  pos_x(0),
  pos_y(0),
  pos_orientation('N') { }


// Ctor with parameters
Rover::Rover(int pos_x, int pos_y, char pos_orientation) :
  pos_x(pos_x),
  pos_y(pos_y),
  pos_orientation(pos_orientation) { }


// Return x-pos
int Rover::getPosX() {
  return pos_x;
}


// Return y-pos
int Rover::getPosY() {
  return pos_y;
}


// Return orientation
char Rover::getOrientation() {
  return pos_orientation;
}


// Show position of the rover
void Rover::displayPos() {
  std::cout << pos_x << " " << pos_y << " " << pos_orientation << std::endl;
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
