#ifndef RAM_H
#define ROM_H

#include <iostream>
#include <string>
#include "memory.h"

class RAM : public Memory{
public:
    RAM(int size);
    int read(int address);
    void write(int address, int data);
private:
    int data[MAX_SIZE];
};

#endif // LIBRARY_H

