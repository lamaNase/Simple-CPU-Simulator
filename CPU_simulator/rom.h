#ifndef ROM_H
#define ROM_H

#include <iostream>
#include <string>
#include "memory.h"

class Instruction;

class ROM : public Memory{
public:
    ROM(int size);
    Instruction* read(int address);
    void flash(Instruction* instructions[]);
    bool empty;
private:
    Instruction* instructions[MAX_SIZE];
    bool flashed;
};

#endif // LIBRARY_H

