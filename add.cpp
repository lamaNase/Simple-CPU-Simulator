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

void Add::execute(CPU* cpu,RAM* ram) {
	std::cout << "\nExecuting add instruction..." << std::endl; 
	if (src1 >= 0 && src1 < ram->getSize() && src2 >= 0 && src2 < ram->getSize() &&
		dest >= 0 && dest < ram->getSize()) {
		int operand1 = ram->read(this->src1);
		std::cout<<"operand 1 = " << operand1 << " at address: " << this->src1 << "\n";
		int operand2 = ram->read(this->src2);
		std::cout<<"operand 2 = " << operand2 << " at address: " << this->src2 << "\n";
		int result = operand1 + operand2;
		std::cout << operand1 << " + " << operand2 << " = " << result << std::endl;
		ram->write(this->dest,result);	
		std::cout<< "Result stored at address: " << this->dest << "\n" << std::endl;
		int pc = cpu->getPC() + 1;
		cpu->setPC(pc);
	} else {
		std::cout << "Address out of range\n";
		exit(1);
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
