#include "cpu.h"

CPU::CPU(ROM* rom, RAM* ram) {
	this->PC = 0;
	this->halted = false;
	this->rom = rom;
	this->ram = ram;
}

int CPU::getPC() {
	return this->PC;
}

void CPU::setPC(int PC) {
	this->PC = PC;
}

void CPU::setHalted_true() {
	this->halted = true;
}

void CPU::execute() {
	if (rom->empty == true) {
		std::cout << "No instructions to execute" << std::endl;
		exit(1);
	}
	while (this->halted == false)
		fetch_instructions();
	std::cout << "Program ended..." << std::endl;
	exit(1);
}

void CPU::fetch_instructions(){
	Instruction* instruction = readROM(this->PC);
	instruction->execute(this);
}

void CPU::writeRAM(int address, int data) {
	this->ram->write(address,data);
}

int CPU::readRAM(int address) {
	return this->ram->read(address);
}

Instruction* CPU::readROM(int address) {
	return this->rom->read(address);
}

int CPU::getRAM_size() {
	return this->ram->getSize();
}

int CPU::getROM_size() {
	return this->rom->getSize();
}   

