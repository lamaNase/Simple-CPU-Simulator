#pragma once

#include <iostream>
#include <string>
#include "memory.h"

class Instruction;

class ROM : public Memory<Instruction*> {
public:
    ROM(int size);
    virtual ~ROM();
    Instruction* read(int address) override;
    void flash(Instruction* instructions[]);
    bool empty;
private:
    Instruction* instructions[MAX_SIZE];
    bool flashed;
};

