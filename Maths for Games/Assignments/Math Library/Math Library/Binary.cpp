#include "Binary.h"
#include <cstring>
#include <cmath>

Binary::Binary() {

}

Binary::~Binary() {

}

// Binary to Decimal *Note to self - Reword this in own words.
int Binary::binToDec(const char* binaryString) {
	int dec = 0;
	int size = strlen(binaryString);
	int i = 0;

	for (i = 0; *binaryString; ++i, ++binaryString) {
		int ch = *binaryString - 48;
		dec += ch * pow(2, size - i - 1);
	}
	return dec;
}

// Decimal to Binary *Note to self - Reword this in own words.
void Binary::decToBin(char* binaryString, int len, int value) {
	int dec = value;
	int size = strlen(binaryString);
	int i = len;
	int a[10];

	for (i = 0; *binaryString; ++i, ++binaryString) {
		a[i] = dec % 2;
		dec = dec / 2;
	}
}

void Binary::setBit(char& bitfield, char bit, char value) {
	bitfield |= value << bit;
}
char Binary::checkBit(char& bitfield, char bit) {
	bit = (bitfield >> bit) & 1U;
	return bit;
}