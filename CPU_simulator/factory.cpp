#include "factory.h"

Instruction* Factory::createInst(CPU* cpu, std::string type){
	if (type == "jump" )
		return new Jump(cpu);
	else if (type == "exit")
		return new Exit(cpu);
	else if (type == "add")
		return new Add(cpu);
	else if (type == "addi")
		return new Addi(cpu);
	else if (type == "print")
		return new Print(cpu);
	else if (type == "set")
		return new Set(cpu);
	else {
		std::cout << "No instruction called " << type << std::endl;
		exit(1);
	}
}
