#include "ram.h"

RAM::RAM(int size) : Memory(size) {
	for (int i = 0; i< size; i++)
		data[i] = std::make_unique<int>(0);
}

int RAM::read(int address) {
	if (address < 0 || address >= getSize()) {
		std::string msg = "cannot read the data\n";
		msg += "\taddress: ";
		msg += std::to_string(address) + " is out of range\n";
		throw InstructionValidationException(msg);
	}
	return *data[address];
}

void RAM::write(int address, int data) {
	if (address < 0 || address >= getSize()) {
		std::string msg = "cannot write the data\n";
		msg += "\taddress: ";
		msg += std::to_string(address) + " is out of range\n";
		throw InstructionValidationException(msg);
	}
	this->data[address] = std::make_unique<int>(data);
}
