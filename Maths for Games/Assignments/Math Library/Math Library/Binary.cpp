#include "Binary.h"
#include <cstring>
#include <cmath>

Binary::Binary() {

}

Binary::~Binary() {

}

int Binary::binToDec(const char* binaryString) {
	int dec = 0;
	int size = strlen(binaryString);
	int i = 0;

	for (int i = 0; *binaryString; ++i, ++binaryString);
	{
		int ch = *binaryString - 48;
		dec += ch * pow(2, size - i - 1);
	}
	return dec;
}

void Binary::decToBin(char* binaryString, int len, int value) {

}

void Binary::setBit(char& bitfield, char bit, char value) {

}
char Binary::checkBit(char& bitfield, char bit) {

}