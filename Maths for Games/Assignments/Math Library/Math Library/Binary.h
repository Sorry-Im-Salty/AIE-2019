#pragma once

class Binary {
public:
	Binary();
	~Binary();

	int binToDec(const char* binaryString);
	void decToBin(char* binaryString, int length, int value);
	void setBit(char& bitfield, char bit, char value);
	char checkBit(char& bitfield, char bit);
};