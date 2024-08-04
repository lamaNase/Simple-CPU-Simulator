#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include "vector"
#include "rom.h"

class CPU;
class RAM;

class Instruction {
public:
    Instruction ();
    void virtual execute(CPU* cpu) = 0;
    bool virtual validate(std::vector<int> params) = 0;
    std::string virtual getType() = 0;
private:
    std::string type;
};

#endif // LIBRARY_H

