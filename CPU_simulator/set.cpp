#include "set.h"
#include "cpu.h"

Set::Set (std::vector<int> params) {
	if (validate(params)) {
		this->dest = params.at(0);
		this->imm = params.at(1);
	} else {
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Set instruction taskes only 2 parameters\n";
		exit(1);
	}
}

void Set::execute(CPU* cpu) {
	std::cout << "\nExecuting set instruction..." << std::endl;
	if (dest >= 0 && dest < cpu->getRAM_size()) {
		cpu->writeRAM(this->dest,this->imm);
		std::cout<<"Data = "<<this->imm<<" wrriteen at address: "<<this->dest<<"\n";
		int pc = cpu->getPC() + 1;
		cpu->setPC(pc);
	} else {
		std::cout << "Address out of range\n";
		exit(1);
	}
	std::cout << "\n=====================================\n" << std::endl;
}

std::string Set::getType() {
	return "set";
}

bool Set::validate(std::vector<int> params){
	if (params.size() == 2)
		return true;
	return false;
}
