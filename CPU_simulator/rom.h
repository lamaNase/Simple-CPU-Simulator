#pragma once

#include <iostream>
#include <string>
#include "memory.h"

class Instruction;

class ROM : public Memory <std::shared_ptr<Instruction>> {
public:
    ROM(int size);
    std::shared_ptr<Instruction> read(int address) override;
    void flash(std::shared_ptr<Instruction> instructions[]);
private:
    std::shared_ptr<Instruction> instructions[MAX_SIZE];
    bool flashed;
};
