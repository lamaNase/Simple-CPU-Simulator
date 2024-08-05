#include "exit.h"
#include "cpu.h"

Exit::Exit(std::shared_ptr<CPU> cpu) : Instruction(cpu) {}

void Exit::execute() {
	std::cout << "Executing exit instruction..." << std::endl;
	this->cpu->setHalted_true();
}

std::string Exit::getType() {
	return "exit";
}

bool Exit::validate(std::vector<std::string> params, int line){
	if (params.size() > 1) {
		std::string msg = "Line " + std::to_string(line) + "\n";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nExit instruction taks zero parameters\n";
		throw InstructionValidationException(msg);
	}
	return true;
}
