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
    static std::shared_ptr<Instruction> createInst(std::shared_ptr<CPU> cpu,std::string type);
};

