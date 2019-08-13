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
void Binary::decToBin(char* binaryString, int length, int value) {
	int dec = value;
	int a[10];
	int i = 0;

	for (i = 0; dec > 0; i++) {
		a[i] = dec % 2;
		dec = dec / 2;
	}

	for (i = i - 1; i > 0; i--) {
		binaryString[i] = (char)a[i];
	}
	//for (i = 0; *binaryString; ++i, ++binaryString) {
	//	a[i] = dec % 2;
	//	dec = dec / 2;
	//}
}

void Binary::setBit(char& bitfield, char bit, char value) {
	bitfield |= value << bit;
}
char Binary::checkBit(char& bitfield, char bit) {
	bit = (bitfield >> bit) & 1U;
	return bit;
}