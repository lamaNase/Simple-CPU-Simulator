#ifndef ADD_H
#define ADD_H

#include <iostream>
#include <string>
#include "instruction.h"

class Add: public Instruction {
public:
    Add (std::vector<int> params);
    void execute(CPU* cpu,RAM* ram) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    int src1;
    int src2;
    int dest;
};

#endif // LIBRARY_H

