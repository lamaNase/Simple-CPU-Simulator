#include "jump.h"
#include "cpu.h"
#include "runner.h"

Jump::Jump(std::shared_ptr<CPU> cpu) : Instruction(cpu) {}

void Jump::execute() {
	std::cout << "\nExecuting Line: " << this->line << 
		" -> jump "<< this->jump_address << std::endl;
	this->update_pc();
	std::cout << "New PC value is " << this->cpu->getPC() << "\n" << std::endl;
	std::cout << "=====================================\n" << std::endl;
} 

std::string Jump::getType() {
	return "jump";
}

bool Jump::validate(std::vector<std::string> params, int line){
	if (params.size() != 2) {
		std::string msg = "Line ";
		msg += std::to_string(line) + ": ";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nJump instruction taks one parameter\n";
		throw InstructionValidationException(msg);
	} else {
		std::vector<int> operands = Runner::convertToIntegers(params);
		if (operands.empty()){
			std::string msg = "Line ";
			msg += std::to_string(line) + ": ";
			for (int i = 0; i < params.size(); i++)
				msg += params.at(i) + " ";
			msg += "\nInvalid operand (it must be integer)\n";
			throw InstructionValidationException(msg);
		}
		this->jump_address = operands.at(0);
	}
	this->line = line;
	return true;
}

void Jump::update_pc() {
	this->cpu->setPC(this->jump_address);
}
