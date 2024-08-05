#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Set: public Instruction {
public:
    Set (CPU* cpu) ;
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
private:
    int dest;
    int imm;
};

