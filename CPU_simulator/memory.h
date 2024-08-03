#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string>

class Memory {
public:
    static const int MAX_SIZE = 200;
    Memory(int size);
    int getSize();
private:
    int size;
};

#endif // LIBRARY_H

