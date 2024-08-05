#include "addi.h"
#include "cpu.h"
#include "runner.h"

Addi::Addi (CPU* cpu) : Instruction(cpu) {}

void Addi::execute() {
	std::cout << "\nExecuting addi instruction...\n";

	int operand = this->cpu->getRAM()->read(this->src1); 
	std::cout<< "operand 1 = " << operand << " at address: " << this->src1 << "\n";
	std::cout << "operand 2 = " << this->imm << " immediate value" << "\n";
	int result = operand + this->imm;
	std::cout << operand << " + " << this->imm << " = " << result << std::endl;
	this->cpu->getRAM()->write(this->dest,result);	
	std::cout<< "Result stored at address: " << this->dest << "\n" << std::endl;
	update_pc();
	
	std::cout << "=====================================\n" << std::endl;
}

std::string Addi::getType() {
	return "addi";
}

bool Addi::validate(std::vector<std::string> params, int line){
	if (params.size() != 4) {
		std::string msg = "Line ";
		msg += std::to_string(line) + ": ";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nADDi instruction taks three parameters\n";
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
		this->imm  = operands.at(1);
		this->dest = operands.at(2);
	}
	return true;
}
