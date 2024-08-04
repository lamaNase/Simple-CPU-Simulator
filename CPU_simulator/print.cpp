#include "print.h"
#include "cpu.h"

Print::Print (std::vector<int> params) {
	if (validate(params))
		this->print_address = params.at(0);
	else {
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Print instruction taskes one parameter\n";
		exit(1);
	}
}

void Print::execute(CPU* cpu) {
	std::cout << "\nExecuting print instruction..." << std::endl;
	if (print_address >= 0 && print_address < cpu->getRAM_size()) {
		int data = cpu->readRAM(this->print_address);
		std::cout<<"Data will be printed at address = "<<this->print_address<< "\n";
		std::cout << "Data: " << data << std::endl;
		int pc = cpu->getPC() + 1;
		cpu->setPC(pc);
	} else {
		std::cout << "Address out of range\n";
		exit(1);
	}
	std::cout << "\n=====================================\n" << std::endl;
}

std::string Print::getType() {
	return "print";
}

bool Print::validate(std::vector<int> params){
	if (params.size() == 1)
		return true;
	return false;
}
