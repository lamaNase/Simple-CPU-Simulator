#include "cpu.h"
#include "instruction.h"

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
	if (PC < 0 || PC >= this->rom->getSize()){
		std::string msg = "PC address ";
		msg += std::to_string(PC) + " goes out of range\n";
		throw InstructionValidationException(msg);
	}
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
	Instruction* instruction = this->rom->read(this->PC);
	instruction->execute();
}

RAM* CPU::getRAM() {
	return this->ram;
}

ROM* CPU::getROM() {
	return this->rom;
}  

