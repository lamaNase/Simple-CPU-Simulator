#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "instruction.h"
#include "rom.h"
#include "ram.h"

class CPU {
public:
    CPU(ROM* rom, RAM* ram);
    int getPC();
    void setPC(int PC);
    void setHalted_true();
    void execute();
    void fetch_instructions();
    void writeRAM(int address, int data);
    int readRAM(int address);
    Instruction* readROM(int address);
    int getRAM_size();
    int getROM_size();

private:
    int PC;
    bool halted;
    ROM* rom;
    RAM* ram;
};

#endif // LIBRARY_H

