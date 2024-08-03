#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "instruction.h"
#include "rom.h"
#include "ram.h"

class CPU {
public:
    CPU();
    int getPC();
    void setPC(int PC);
    void setHalted_true();
    void execute(ROM *rom,RAM* ram);
    void fetch_instructions(ROM *rom,RAM* ram);

private:
    int PC;
    bool halted;
};

#endif // LIBRARY_H

