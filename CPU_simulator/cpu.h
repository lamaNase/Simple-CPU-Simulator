#pragma once

#include <iostream>
#include <string>
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
    RAM* getRAM();
    ROM* getROM();

private:
    int PC;
    bool halted;
    ROM* rom;
    RAM* ram;
};
