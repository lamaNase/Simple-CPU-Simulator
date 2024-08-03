#ifndef FACTORY_H
#define FACTORY_H

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
    static Instruction* createInst(std::string type, std::vector<int> params);
};

#endif // BOOK_FACTORY_H

