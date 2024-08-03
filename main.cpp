#include <iostream>
#include "cpu.h"
#include "runner.h"

int main() {
	CPU* cpu = new CPU();
	
	RAM* ram = new RAM(50);
	ROM* rom = new ROM(50);
	
	Runner::execute(rom);
	
	cpu->execute(rom,ram);
	
	return 0;
}
