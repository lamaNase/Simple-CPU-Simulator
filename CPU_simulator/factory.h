#pragma once

#include <iostream>
#include <vector>
#include <string.h>
#include "instruction.h"
#include "jump.h"
#include "exit.h"
#include "add.h"
#include "addi.h"
#include "print.h"
#include "set.h"

class Factory {
public:
    static Instruction* createInst(CPU* cpu,std::string type);
};

