#pragma once

#include <iostream>
#include <string>
#include "instruction.h"

class Jump: public Instruction {
public:
    Jump(std::shared_ptr<CPU> cpu);
    void execute() override;
    std::string getType() override;
    bool validate(std::vector<std::string> params, int line) override;
    void update_pc() override;
private:
    int jump_address;
};

