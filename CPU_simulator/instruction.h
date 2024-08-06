#pragma once

#include <iostream>
#include <string>
#include "vector"
#include "cpu.h"
#include "exception.h"


class Instruction {
public:
    Instruction (std::shared_ptr<CPU> cpu);
    virtual ~Instruction() = default;
    void virtual execute() = 0;
    bool virtual validate(std::vector<std::string> params,int line) = 0;
    std::string virtual getType() = 0;
    void virtual update_pc();
    std::shared_ptr<CPU> cpu;
private:
    std::string type;
};

