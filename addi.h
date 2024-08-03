#ifndef ADDI_H
#define ADDI_H

#include <iostream>
#include <string>
#include "instruction.h"

class Addi: public Instruction {
public:
    Addi (std::vector<int> params);
    void execute(CPU* cpu,RAM* ram) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    int src1;
    int imm;
    int dest;
};

#endif // LIBRARY_H

