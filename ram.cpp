#include "ram.h"

RAM::RAM(int size) : Memory(size) {}
int RAM::read(int address) {
	return this->data[address];
}

void RAM::write(int address, int data) {
	this->data[address] = data;
}
