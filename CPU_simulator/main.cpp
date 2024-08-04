#include <iostream>
#include "cpu.h"
#include "runner.h"

int main() {
	RAM* ram = new RAM(50);
	ROM* rom = new ROM(50);
	
	CPU* cpu = new CPU(rom,ram);
	
	Runner::execute(rom);
	
	cpu->execute();
	
	return 0;
}
