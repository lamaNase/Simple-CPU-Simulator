#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include "instruction.h"

class Print: public Instruction {
public:
    Print (std::vector<int> params);
    void execute(CPU* cpu) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    int print_address;
};

#endif // LIBRARY_H

