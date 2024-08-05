#include "runner.h"

void Runner::execute(ROM* rom, char* argv[], CPU* cpu){
	std::ifstream file(argv[1]);

	if (!file.is_open()) {
	        std::cerr << "Unable to open file" << std::endl;
	        exit(1);
	}
	
	Instruction* instructions[rom->getSize()];
	//initalize(instructions,rom->getSize());
	std::string line;
	int index = 0;
	bool empty = true;
	std::cout << "start reading the file..." << std::endl;
	while (std::getline(file, line)) {
		empty = false;
		std::istringstream iss(line);
		std::string item;
		std::vector<std::string> items;
		
		while(iss >> item) { // spliting on spaces
			items.push_back(item);
		}
		std::string type = items.at(0);
		// convert to lower case
		std::transform(type.begin(), type.end(), type.begin(),
			[](unsigned char c){ return std::tolower(c); });
		
		Instruction* inst = Factory::createInst(cpu,type);
		inst->validate(items,(index + 1));
		instructions[index] = inst;
    		index++;
	}
	
	file.close();
	if (empty){
		std::string msg =  "File is empty...\n";
		throw InstructionValidationException(msg);
	}
	
	rom->flash(instructions);
	
	for (int i = 0; i < rom->getSize(); ++i) {
        	delete instructions[i]; // Free the memory allocated for each instruction
    	}
	
}

std::vector<int> Runner::convertToIntegers(std::vector<std::string> items){
	std::vector<int> values;
	for (int i = 1; i < items.size(); i++){
		try {
			int num = std::stoi(items.at(i));
			values.push_back(num);
		} catch (const std::invalid_argument &e) {
			return {};
		} catch (const std::out_of_range &e) {
			return {};
		}
	}
	return values;
}

void Runner::initalize(Instruction* instructions[], int size) {
	for (int i = 0; i < size; i++){
		instructions[i] = nullptr;
	}
}

