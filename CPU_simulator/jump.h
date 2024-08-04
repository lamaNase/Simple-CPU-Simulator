#ifndef JUMP_H
#define JUMP_H

#include <iostream>
#include <string>
#include "instruction.h"

class Jump: public Instruction {
public:
    Jump(std::vector<int> params);
    void execute(CPU* cpu) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    int jump_address;
};

#endif // LIBRARY_H

