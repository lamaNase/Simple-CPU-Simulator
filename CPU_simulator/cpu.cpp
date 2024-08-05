#include "cpu.h"
#include "instruction.h"

CPU::CPU(std::shared_ptr<ROM> rom, std::shared_ptr<RAM> ram) {
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
	while (this->halted == false)
		fetch_instructions();
	std::cout << "Program ended..." << std::endl;
}

void CPU::fetch_instructions(){
	std::shared_ptr<Instruction> instruction = this->rom->read(this->PC);
	instruction->execute();
}

std::shared_ptr<RAM> CPU::getRAM() {
	return this->ram;
}

std::shared_ptr<ROM> CPU::getROM() {
	return this->rom;
}  

