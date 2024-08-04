#include "add.h"
#include "cpu.h"

Add::Add (std::vector<int> params) {
	if (validate(params)){
		this->src1 = params.at(0);
		this->src2 = params.at(1);
		this->dest = params.at(2);
	} else {
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Add instruction taskes only 3 parameters\n";
		exit(1);
	}
}

void Add::execute(CPU* cpu) {
	std::cout << "\nExecuting add instruction..." << std::endl; 
	if (src1 >= 0 && src1 < cpu->getRAM_size() && src2 >= 0 && src2 < cpu->getRAM_size() 
		&& dest >= 0 && dest < cpu->getRAM_size()) {
		
		int operand1 = cpu->readRAM(this->src1);
		std::cout<<"operand 1 = " << operand1 << " at address: " << this->src1 << "\n";
		int operand2 = cpu->readRAM(this->src2);
		std::cout<<"operand 2 = " << operand2 << " at address: " << this->src2 << "\n";
		int result = operand1 + operand2;
		std::cout << operand1 << " + " << operand2 << " = " << result << std::endl;
		cpu->writeRAM(this->dest,result);	
		std::cout<< "Result stored at address: " << this->dest << "\n" << std::endl;
		int pc = cpu->getPC() + 1;
		cpu->setPC(pc);
	} else {
		if (src1 < 0 || src1 > cpu->getRAM_size()) {
			std::cout << "Address 1: " << src1 <<", out of range\n";
			exit(1);
		} else if (src2 < 0 || src2 > cpu->getRAM_size()) {
			std::cout << "Address 2: " << src2 <<", out of range\n";
			exit(1);
		} else if (dest < 0 || dest > cpu->getRAM_size()) {
			std::cout << "Destination address: " << dest <<", out of range\n";
			exit(1);
		}
	}
	std::cout << "=====================================\n" << std::endl;
}

std::string Add::getType() {
	return "add";
}

bool Add::validate(std::vector<int> params){
	if (params.size() == 3)
		return true;
	return false;
}
