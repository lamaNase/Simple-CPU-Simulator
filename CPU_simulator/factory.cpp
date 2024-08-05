#include "factory.h"

std::shared_ptr<Instruction> Factory::createInst(std::shared_ptr<CPU> cpu, std::string type){
	if (type == "jump" )
		return std::make_shared<Jump>(cpu);
	else if (type == "exit")
		return std::make_shared<Exit>(cpu);
	else if (type == "add")
		return std::make_shared<Add>(cpu);
	else if (type == "addi")
		return std::make_shared<Addi>(cpu);
	else if (type == "print")
		return std::make_shared<Print>(cpu);
	else if (type == "set")
		return std::make_shared<Set>(cpu);
	else {
		std::cout << "No instruction called " << type << std::endl;
		exit(1);
	}
}
