#include <iostream>
#include "cpu.h"
#include "runner.h"

int main(int argc, char* argv[]) {

	// Check if a file passed
	if (argc != 2) {
		std::cout << "Error: pass the instructions file only\n";
		exit(1);
	}

	try {
		RAM* ram = new RAM(50);
		ROM* rom = new ROM(50);
		
		CPU* cpu = new CPU(rom,ram);
		
		Runner::execute(rom,argv,cpu);
		
		cpu->execute();
		
	} catch (const InstructionValidationException& ex) {
        	std::cerr << "Error: " << ex.what() << std::endl;
        	return 1;
    	} catch (const std::exception& ex) {
        	std::cerr << "Unexpected error: " << ex.what() << std::endl;
        	return 1;
    	}
	
	return 0;
}
