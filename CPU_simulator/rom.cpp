#include "rom.h"
#include "instruction.h"

ROM::ROM(int size) : Memory(size) {
	flashed = false;
	empty = true;
}

ROM::~ROM() {
	for (int i = 0; i < getSize(); ++i) {
        	delete this->instructions[i]; // Free the memory allocated for each instruction
    	}
}

Instruction* ROM::read(int address) {
	if (address < 0 || address >= getSize()) {
		std::string msg = "cannot read the data\n";
		msg += "\taddress: ";
		msg += std::to_string(address) + " is out of range\n";
		throw InstructionValidationException(msg);
	}
	return this->instructions[address];
}

void ROM::flash(Instruction* instructions[]) {
	if (!flashed) {
		flashed = true;
		for (int i = 0; i < getSize() ; i++) {
			if (instructions[i] != nullptr) {
				this->instructions[i] = instructions[i];
				this->empty = false;
			}
		}
	} else {
		std::cout << "Flashing can be done only one time...!" << std::endl;
		exit(1);
	}
}
