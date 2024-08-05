#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cctype>
#include "factory.h"
#include "rom.h"

#define max_parameters 3

class Runner {
public:
    // This function reads instructions from a file and flash them into the ROM
    static void execute(std::shared_ptr<ROM> rom, char* argv[], std::shared_ptr<CPU> cpu);
    static std::vector<int> convertToIntegers(std::vector<std::string> items);
};

