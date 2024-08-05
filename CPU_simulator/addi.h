#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Addi: public Instruction {
public:
    Addi (CPU* cpu);
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
private:
    int src1;
    int imm;
    int dest;
};

