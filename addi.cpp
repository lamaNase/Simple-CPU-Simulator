#include "addi.h"
#include "cpu.h"

Addi::Addi (std::vector<int> params) {
	if (validate(params)){
		this->src1 = params.at(0);
		this->imm = params.at(1);
		this->dest = params.at(2);
	} else {
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Addi instruction taskes only 3 parameters\n";
		exit(1);
	}
}

void Addi::execute(CPU* cpu,RAM* ram) {
	std::cout << "\nExecuting addi instruction...\n";
	if (src1 >= 0 && src1 < ram->getSize() && dest >= 0 && dest < ram->getSize()){
		int operand = ram->read(this->src1); 
		std::cout<< "operand 1 = " << operand << " at address: " << this->src1 << "\n";
		std::cout << "operand 2 = " << this->imm << " immediate value" << "\n";
		int result = operand + this->imm;
		std::cout << operand << " + " << this->imm << " = " << result << std::endl;
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

std::string Addi::getType() {
	return "addi";
}

bool Addi::validate(std::vector<int> params){
	if (params.size() == 3)
		return true;
	return false;
}
