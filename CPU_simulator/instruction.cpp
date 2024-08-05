#include "instruction.h"
#include "cpu.h"

Instruction::Instruction(std::shared_ptr<CPU> cpu) {
	this->cpu = cpu;
}

void Instruction::update_pc() {
	this->cpu->setPC(this->cpu->getPC() + 1);
}
