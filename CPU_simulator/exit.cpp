#include "exit.h"
#include "cpu.h"

Exit::Exit(std::vector<int> params) {
	if (!validate(params)){
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Exit instruction taskes no parameters\n";
		exit(1);
	}
}

void Exit::execute(CPU* cpu,RAM* ram) {
	std::cout << "Executing exit instruction..." << std::endl;
	cpu->setHalted_true();
}

std::string Exit::getType() {
	return "exit";
}

bool Exit::validate(std::vector<int> params){
	if (params.empty())
		return true;
	return false;
}
