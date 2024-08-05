#include "rom.h"
#include "instruction.h"


ROM::ROM(int size) : Memory(size), flashed(false) {
	for (int i = 0; i < MAX_SIZE; ++i) {
        	instructions[i] = nullptr;
    	}
}

std::shared_ptr<Instruction> ROM::read(int address) {
	if (address < 0 || address >= getSize()) {
		std::string msg = "cannot read the data\n";
		msg += "\taddress: ";
		msg += std::to_string(address) + " is out of range\n";
		throw InstructionValidationException(msg);
	} else if (!instructions[address]) {
        	std::string msg = "No instruction at address ";
        	msg += std::to_string(address) + "\n";
        	throw InstructionValidationException(msg);
    	}
    	
	return instructions[address];
}

void ROM::flash(std::shared_ptr<Instruction> instructions[]) {
	if (!flashed) {
		flashed = true;
		for (int i = 0; i < getSize() ; i++) {
			this->instructions[i] = instructions[i];
		}
	} else {
		std::string msg = "cannot flashing the ROM again\n";
        	throw InstructionValidationException(msg);
	}
}
