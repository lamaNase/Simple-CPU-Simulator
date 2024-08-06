#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "memory.h"
#include <mutex>

class RAM : public Memory<int>{
public:
    RAM(int size);
    int read(int address) override;
    void write(int address, int data);
private:
    std::unique_ptr<int> data[MAX_SIZE];
    std::unique_ptr<std::mutex> mutexes[MAX_SIZE];
};

