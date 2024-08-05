#include "print.h"
#include "cpu.h"
#include "runner.h"

Print::Print (CPU* cpu) : Instruction(cpu) {}

void Print::execute() {
	std::cout << "\nExecuting print instruction..." << std::endl;
	
	int data = this->cpu->getRAM()->read(this->print_address);
	std::cout<<"Data will be printed at address = "<<this->print_address<< "\n";
	std::cout << "Data: " << data << std::endl;
	update_pc();
	
	std::cout << "\n=====================================\n" << std::endl;
}

std::string Print::getType() {
	return "print";
}

bool Print::validate(std::vector<std::string> params, int line){
	if (params.size() != 2) {
		std::string msg = "Line ";
		msg += std::to_string(line) + ": ";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nPrint instruction taks one parameter\n";
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
		this->print_address = operands.at(0);
	}
	return true;
}
