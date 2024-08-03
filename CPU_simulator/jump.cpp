#include "jump.h"
#include "cpu.h"

Jump::Jump(std::vector<int> params) {
	if (validate(params))
		this->jump_address = params.at(0);
	else {
		std::cout << "Invalid instruction syntax...\n";
		std::cout << "Jump instruction taskes only one parameter\n";
		exit(1);
	}
}

void Jump::execute(CPU* cpu,RAM* ram) {
	std::cout << "\nExecuting jump instruction..." << std::endl;
	if (this->jump_address >= 0 && this->jump_address < ram->getSize()) {
		cpu->setPC(this->jump_address);
		std::cout << "New PC value is " << cpu->getPC() << "\n" << std::endl;
	} else {
		std::cout << "Address out of range\n";
		exit(1);
	}
	std::cout << "=====================================\n" << std::endl;
} 

std::string Jump::getType() {
	return "jump";
}

bool Jump::validate(std::vector<int> params){
	if (params.size() == 1)
		return true;
	return false;
}
