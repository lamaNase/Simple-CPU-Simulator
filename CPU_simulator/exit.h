#ifndef EXIT_H
#define EXIT_H

#include <iostream>
#include <string>
#include "instruction.h"

class Exit: public Instruction {
public:
    Exit (std::vector<int> params);
    void execute(CPU* cpu) override;
    std::string getType() override;
    bool validate(std::vector<int> params) override;
private:
    
};

#endif // LIBRARY_H

