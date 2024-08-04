# Simple CPU Simulator 🖥️

This repositry have all related codes written in C++ for building
a simple CPU simulator. The simulator first starts reading assembly
instructions froma file called "instructions.txt". Then checks for
any syntax errors. After that, flashes these instructions into the 
ROM. Finally, it executes the instructions that the program counter
(PC) points for.

The simulation ends if it executes an exit instruction or if it faced
with an exception (out of range address).

## Class Diagram 📊

![CPU_simulator](https://github.com/user-attachments/assets/45039993-179b-41f4-8ed0-0278040d1e4f)

## CPU Class 🖥️
  This class represents the main CPU of our simulator that has
  PC(integer), halted(boolean) and two reference pointers the first
  one for ram and the other for the rom attributes. The CPU module will
  go through instructions that the PC points for as long as it is not halted
  by an exit instruction (sets the value of halted to true) then it executes each 
  instruction by calling the execute() method inside each instruction
  that represents each type of instruction how will it be executed.

  The CPU can access a slot in the memory (RAM/ROM) through
  some methods that allows to read/write on the ram and just
  reads from the rom.

## Memory Class 💾

  This is an abstract class that contains the memory size. This class
  will be inherited to two subclasses RAM & ROM.

  ### RAM Class
    This class represents the data memory that will be used in the 
    execution stage. It contains an array of integers represents
    the data. Also it has two methods read and write on theat array.

  ### ROM Class
    This class represents the instruction memory that contains all 
    instructions of the program. the instructions will be stored in the 
    ROM using Flashing for just one time.

## Instruction Class 📜

  This represents the base class for all instructions’ types. It has
  type attribute and the abstract method execute.

  ### ADD Class ➕
    This class inherited from the Instruction class. It has three attributes: 
    address of the first operand (src1), address of the second operand 
    (src2) and address of the destination (dest). It overrides the method 
    execute() to perform addition between data[src1] and data[src2] and 
    store result in the destination address in the RAM.
  
  ### ADDI Class ➕
    This class inherited from the Instruction class. It has three attributes: 
    address of the first operand (src1), immediate value (imm) and address 
    of the destination (dest). It overrides the method execute() to perform 
    addition between data[src1] and imm and store result in the destination 
    address in the RAM.

  ### Exit Class 🚪
    This class inherited from the Instruction class. It has no attributes. It 
    overrides the method execute() to stop the CPU work (sets the halted = 
    true) to exit from the program.

  ### Jump Class 🏃
    This class inherited from the Instruction class. It has one attribute that
    represents the address of the new program counter (PC).

  ### Print Class 🖨️
    This class inherited from the Instruction class. It has one attribute that
    represents the address of the data that will be printed to the screen.

  ### Set Class 🔢
    This class inherited from the Instruction class. It has two attributes: immediate
    value and the address that this immediate value will be stored in.


## Factory Class 🏭

  This class is will be used for the process of creating an instruction based
  on a specific type. the purpose is to perform the principle of factory design 
  pattern. Such that when we want to add more instructions’ types to be 
  executed, then it will be easy and forward.

## Runner Class ⚙️

  This class made to perform the proceess of reading instructions from the input
  file passed to the main. it reads the file line by line such that each line wil 
  represent a single instruction. Then it splits the line based on the space (as the 
  delimeter). The first word represents the type of the instructionn after it converted
  to lower case (to make it case insensitive). After that, it ensures that the rest 
  parts of the line are all integers and there count is maximum 3. Finally, after checking
  all these cases instructions are then created through the factoryand then flashed to the
  ROM using the flash method inside the rom class.


# Prepared by ✍️

<p>
  <img src="https://img.shields.io/badge/Lama%20Naser-blue?style=for-the-badge" alt="Lama Naser">
</p>

# Supervisers 👥

<p>
  <img src="https://img.shields.io/badge/Saeed%20Abdularaheem-yellow?style=for-the-badge">
</p>  

<p>
  <img src="https://img.shields.io/badge/Salsabeel%20Baraghithi-yellow?style=for-the-badge">
</p> 
