#include "add.h"
#include "cpu.h"
#include "runner.h"

Add::Add (CPU* cpu) : Instruction(cpu) {}

void Add::execute() {
	std::cout << "\nExecuting add instruction..." << std::endl; 

	int operand1 = this->cpu->getRAM()->read(this->src1);
	std::cout<<"operand 1 = " << operand1 << " at address: " << this->src1 << "\n";
	int operand2 = this->cpu->getRAM()->read(this->src2);
	std::cout<<"operand 2 = " << operand2 << " at address: " << this->src2 << "\n";
	int result = operand1 + operand2;
	std::cout << operand1 << " + " << operand2 << " = " << result << std::endl;
	this->cpu->getRAM()->write(this->dest,result);	
	std::cout<< "Result stored at address: " << this->dest << "\n" << std::endl;
	update_pc();
	
	std::cout << "=====================================\n" << std::endl;
}

std::string Add::getType() {
	return "add";
}

bool Add::validate(std::vector<std::string> params, int line){
	if (params.size() != 4) {
		std::string msg = "Line ";
		msg += std::to_string(line) + ": ";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nADD instruction taks three parameters\n";
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
		this->src1 = operands.at(0);
		this->src2 = operands.at(1);
		this->dest = operands.at(2);
	}
	return true;
}
