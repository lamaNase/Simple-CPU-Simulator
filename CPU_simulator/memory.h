#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "exception.h"

template <typename T>
class Memory {
public:
    static const int MAX_SIZE = 200;
    Memory(int size) {
    	if (size <= MAX_SIZE)
    		this->size = size;
    }
    int getSize() {return this->size;}
    virtual T read(int address) = 0;
private:
    int size;
};


