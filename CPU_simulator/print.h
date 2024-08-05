#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Print: public Instruction {
public:
    Print (CPU* cpu);
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
private:
    int print_address;
};

