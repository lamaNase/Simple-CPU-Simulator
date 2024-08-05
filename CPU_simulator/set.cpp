#include "set.h"
#include "cpu.h"
#include "runner.h"

Set::Set (std::shared_ptr<CPU> cpu) : Instruction(cpu) {}

void Set::execute() {
	std::cout << "\nExecuting set instruction..." << std::endl;
		
	cpu->getRAM()->write(this->dest,this->imm);
	std::cout<<"Data = "<<this->imm<<" wrriteen at address: "<<this->dest<<"\n";
	update_pc();
	
	std::cout << "\n=====================================\n" << std::endl;
}

std::string Set::getType() {
	return "set";
}

bool Set::validate(std::vector<std::string> params, int line){
	if (params.size() != 3) {
		std::string msg = "Line ";
		msg += std::to_string(line) + ": ";
		for (int i = 0; i < params.size(); i++)
			msg += params.at(i) + " ";
		msg += "\nSet instruction taks two parameters\n";
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
		this->dest = operands.at(0);
		this->imm = operands.at(1);
	}
	return true;
}
