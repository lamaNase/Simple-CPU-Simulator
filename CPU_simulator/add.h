#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Add: public Instruction {
public:
    Add (std::shared_ptr<CPU> cpu);
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
private:
    int src1;
    int src2;
    int dest;
};

