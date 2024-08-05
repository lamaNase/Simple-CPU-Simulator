#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Exit: public Instruction {
public:
    Exit (CPU* cpu);
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
private:
    
};

