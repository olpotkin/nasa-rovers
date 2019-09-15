#include <fstream>
#include <vector>
#include <sstream>
#include "rover/rover.h"


int main () {

  int l_x = 0;                    // Left x corner of the grid
  int l_y = 0;                    // Left y corner of the grid
  int r_x = 0;                    // Right x corner of the grid
  int r_y = 0;                    // Right y corner of the grid
  std::vector<Rover> rovers;      // All the rovers on the grid

  // Input data
  std::ifstream in_file ("in.txt");
  std::string line = "";

  //=============
  // PART 1
  // Input
  //=============
  /// @todo This part of code potentially dangerous. Could be improved using exceptions.
  if (in_file.is_open())
  {
    // Read first line with grid size
    getline(in_file, line);
    std::istringstream ss_line_1(line);
    ss_line_1 >> r_x >> r_y;

    // Read rest of the file - each 2 lines describe rover's initial pos and movement scenario
    while (getline(in_file, line))
    {
      // Read position of the rover
      int         pos_x = 0;
      int         pos_y = 0;
      char        orientation = ' ';
      std::istringstream ss_1(line);
      ss_1 >> pos_x >> pos_y >> orientation;

      // Read the motion scenario
      std::string scenario = "";
      getline(in_file, line);
      std::istringstream ss_2(line);
      ss_2 >> scenario;

      // Add rover on the grid
      rovers.emplace_back(
        Rover{pos_x, pos_y, orientation, scenario}
        );
    }
    // Close file
    in_file.close();
  }
  else {
    // IMPORTANT:
    // Keep in mind if you are using CLion, you need to copy 'in.txt' into the 'cmake-build-debug' folder
    std::cout << "Unable to open the file";
  }

  //=============
  // PART 2
  // Action
  //=============
  for (auto& r : rovers) {
    r.execute(r.getCommands(), l_x, l_y, r_x, r_y);
  }

  //=============
  // PART 3
  // Output
  //=============
  // IMPORTANT:
  // Keep in mind if you are using CLion, the output file 'out.txt' will be created the 'cmake-build-debug' folder
  std::ofstream out_file("out.txt");
  for (const auto& r : rovers) {
    out_file << r.getPosX() << " "
      << r.getPosY() << " "
      << r.getOrientation() << std::endl;
  }
  out_file.close();

  return 0;
}
