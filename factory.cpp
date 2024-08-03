#include "factory.h"

Instruction* Factory::createInst(std::string type, std::vector<int> params){
	if (type == "jump" )
		return new Jump(params);
	else if (type == "exit")
		return new Exit(params);
	else if (type == "add")
		return new Add(params);
	else if (type == "addi")
		return new Addi(params);
	else if (type == "print")
		return new Print(params);
	else if (type == "set")
		return new Set(params);
	else {
		std::cout << "No instruction called " << type << std::endl;
		exit(1);
	}
}
