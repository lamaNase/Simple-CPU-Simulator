#pragma once

#include <iostream>
#include <string>
#include "memory.h"

class RAM : public Memory<int>{
public:
    RAM(int size);
    int read(int address) override;
    void write(int address, int data);
private:
    std::unique_ptr<int> data[MAX_SIZE];
};

