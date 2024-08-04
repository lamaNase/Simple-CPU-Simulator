#ifndef RUNNER_H
#define RUNNER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cctype>
#include "factory.h"
#include "rom.h"

class Runner {
public:
    // This function reads instructions from a file and flash them into the ROM
    static void execute(ROM* rom, char* argv[]);
    static std::vector<int> convertToIntegers(std::vector<std::string> items);
    static void initalize(Instruction* instructions[], int size);
};

#endif // BOOK_FACTORY_H

