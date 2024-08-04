#include <iostream>
#include "cpu.h"
#include "runner.h"

int main(int argc, char* argv[]) {

	// Check if a file passed
	if (argc != 2) {
		std::cout << "Error: pass the instructions file only\n";
		exit(1);
	}

	RAM* ram = new RAM(50);
	ROM* rom = new ROM(50);
	
	CPU* cpu = new CPU(rom,ram);
	
	Runner::execute(rom,argv);
	
	cpu->execute();
	
	return 0;
}
