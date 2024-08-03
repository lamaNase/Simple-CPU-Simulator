#include "runner.h"

void Runner::execute(ROM* rom){
	std::ifstream file("instructions.txt");

	if (!file.is_open()) {
	        std::cerr << "Unable to open file" << std::endl;
	        exit(1);
	}
	
	Instruction* instructions[rom->getSize()];
	initalize(instructions,rom->getSize());
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
		
		if (!items.empty() && items.size() <= 4){
			std::string type = items.at(0);
			// convert to lower case
			std::transform(type.begin(), type.end(), type.begin(),
				[](unsigned char c){ return std::tolower(c); });
			
			std::vector<int> params = convertToIntegers(items);
			if (!params.empty() || type == "exit") {
				Instruction* inst = Factory::createInst(type,params);
				instructions[index] = inst;
			} else {
				std::cout << "Invalid instruction, skiped..." << std::endl;
				continue;
			}
		} else {
			std::cout << "Invalid instruction, skiped..." << std::endl;
			continue;
		}
    		index++;
	}
	
	file.close();
	if (empty){
		std::cout << "File is empty...\n";
		exit(1);
	}
	rom->flash(instructions);
	
}

std::vector<int> Runner::convertToIntegers(std::vector<std::string> items){
	std::vector<int> values;
	for (int i = 1; i < items.size(); i++){
		try {
			int num = std::stoi(items.at(i));
			values.push_back(num);
		} catch (const std::invalid_argument &e) {
			std::cout << "Invalid instruction, skiped..." << std::endl;
			return {};
		} catch (const std::out_of_range &e) {
			std::cout << "Invalid instruction, skiped..." << std::endl;
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

