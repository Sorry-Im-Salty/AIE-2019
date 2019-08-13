#include "Binary.h"
#include <cstring>
#include <cmath>

Binary::Binary() {

}

Binary::~Binary() {

}

// Binary to Decimal
int Binary::binToDec(const char* binaryString) {
	int dec = 0;
	const char* num = binaryString;
	int base = 1;
	int length = strlen(binaryString);

	for (int i = length - 1; i >= 0; i--) {
		if (num[i] == '1')
			dec += base;
		base = base * 2;
	}
	return dec;
}

// Decimal to Binary
int Binary::decToBin(int value) {
	int dec = value;
	int result = 0;
	int remain;
	int i = 1;

	while (dec != 0) {
		remain = dec % 2;
		dec /= 2;
		result += remain * i;
		i *= 10;
	}
	return result;
}

void Binary::setBit(char& bitfield, char bit, char value) {
	bitfield |= value << bit;
}
char Binary::checkBit(char& bitfield, char bit) {
	bit = (bitfield >> bit) & 1U;
	return bit;
}