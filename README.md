# Simple CPU Simulator

This repositry have all related codes written in C++ for building
a simple CPU simulator. The simulator first starts reading assembly
instructions froma file called "instructions.txt". Then checks for
any syntax errors. After that, flashes these instructions into the 
ROM. Finally, it executes the instructions that the program counter
(PC) points for.

The simulation ends if it executes an exit instruction or if it faced
with an exception (out of range address).

The following figure shows the class diagram of the design.
