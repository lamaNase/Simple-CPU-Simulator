#include <iostream>
#include <future>
#include "cpu.h"
#include "runner.h"

void startCPU(std::shared_ptr<CPU> cpu) {
    cpu->execute();
}

int main(int argc, char* argv[]) {
    // Check if a file is passed
    if (argc != 2) {
        std::string msg =  "pass the instructions file only\n";
	throw InstructionValidationException(msg);
    }

    try {
        std::shared_ptr<RAM> ram = std::make_shared<RAM>(50);
        std::shared_ptr<ROM> rom = std::make_shared<ROM>(50);

        // Create CPU instances with different starting PC values
        std::shared_ptr<CPU> cpu1 = std::make_shared<CPU>(rom, ram);
        //cpu1->setPC(0); // Start at PC = 0

        //std::shared_ptr<CPU> cpu2 = std::make_shared<CPU>(rom, ram);
        //cpu2->setPC(5); // Start at PC = 5 (or any other value)
        
        Runner::execute(rom, argv, cpu1);
        //for (int i = 0; i < 5; i++)
        //	rom->instructions[i]->cpu = cpu1;

        // Launch CPUs using std::async
        //auto future1 = std::async(std::launch::async, startCPU, cpu1);
        //auto future2 = std::async(std::launch::async, startCPU, cpu2);

        // Wait for futures to complete
        //future1.get();
        //future2.get();
        cpu1->execute();

    } catch (const InstructionValidationException& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

