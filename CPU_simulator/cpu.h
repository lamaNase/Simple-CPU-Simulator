#pragma once

#include <iostream>
#include <string>
#include "rom.h"
#include "ram.h"

class CPU {
public:
    CPU(std::shared_ptr<ROM> rom, std::shared_ptr<RAM> ram);
    int getPC();
    void setPC(int PC);
    void setHalted_true();
    void execute();
    void fetch_instructions();
    std::shared_ptr<RAM> getRAM();
    std::shared_ptr<ROM> getROM();

private:
    int PC;
    bool halted;
    std::shared_ptr<ROM> rom;
    std::shared_ptr<RAM> ram;
};
