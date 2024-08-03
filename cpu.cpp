#include "cpu.h"

CPU::CPU() {
	this->PC = 0;
	this->halted = false;
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

void CPU::execute(ROM *rom,RAM* ram) {
	if (rom->empty == true) {
		std::cout << "No instructions to execute" << std::endl;
		exit(1);
	}
	while (this->halted == false) {
		fetch_instructions(rom,ram);
	//	std::cout << "looping" << std::endl;
	}
	std::cout << "Program ended..." << std::endl;
	exit(1);
}

void CPU::fetch_instructions(ROM *rom,RAM* ram){
	Instruction* instruction = rom->read(this->PC);
	if (instruction != nullptr)
		instruction->execute(this,ram);
}

