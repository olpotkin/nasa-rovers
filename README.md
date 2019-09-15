# nasa-rovers
 A squad of robotic rovers are to be landed by NASA on a different planets like Mars, Pluto etc.

The project pipeline is responsible to land and operate the rovers sent for Mars plateau. This plateau, which is curiously flat and rectangular, must be navigated by the rovers so that their on-board cameras can get a complete view of the surrounding terrain to send back to Earth.

A rover's position is represented by a combination of an x and y coordinates and a letter representing one of the four cardinal compass points. The plateau is divided up into a grid of cells to simplify navigation. An example position might be `0, 0, N`, which means the rover is in the bottom left corner and facing North.

In order to control a rover, NASA sends a simple string of letters. The possible letters are `L`,
`R` and `M`.<br>
`L` and `R` makes the rover spin 90 degrees left or right respectively, without moving from its current spot.<br>
`M` means move forward one grid cell, and maintain the same heading.<br>
Assume that the square directly North from `(x, y)` is `(x, y+1)`. Also assume that each cell size is 1 sq-cm and individual rover occupies the entire cell.

## Input:
The first line of input is the upper-right coordinates of the plateau, the lower-left coordinates are assumed to be `0,0`.
The rest of the input is information pertaining to the rovers that have been deployed. Each rover has two lines of input. The first line gives the rover's position, and the second line is a series of instructions telling the rover how to explore the plateau.
The position is made up of two integers and a letter separated by spaces, corresponding to the `x` and `y` coordinates and the rover's orientation. Each rover will be finished sequentially, which means that the second rover won't start to move until the first one has finished moving.
 
## Output:
The trail of rover has to be recorded in an output TXT file including each Rovers final
coordinates and heading.
 
### Part example of Test Input for Rover in TXT i/p file:
`5 5` <br>
`1 2 N` <br>
`LMLMLMLMM` <br>
`3 3 E` <br>
`MMRMMRMRRM`
 
### Part example of Expected Output for addressed Rover in TXT o/p file:
`1 3 N` <br>
`5 1 E`
