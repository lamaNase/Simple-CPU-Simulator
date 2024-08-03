#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include "instruction.h"

class Set: public Instruction {
public:
    Set (std::vector<int> params) ;
    void execute(CPU* cpu,RAM* ram) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    int dest;
    int imm;
};

#endif // LIBRARY_H

