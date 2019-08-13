#pragma once

class Binary {
public:
	Binary();
	~Binary();

	int binToDec(const char* binaryString);
	int decToBin(int value);
	void setBit(char& bitfield, char bit, char value);
	char checkBit(char& bitfield, char bit);
};