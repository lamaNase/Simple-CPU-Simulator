#include "rom.h"
#include "instruction.h"

ROM::ROM(int size) : Memory(size) {
	flashed = false;
	empty = true;
}

Instruction* ROM::read(int address) {
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
