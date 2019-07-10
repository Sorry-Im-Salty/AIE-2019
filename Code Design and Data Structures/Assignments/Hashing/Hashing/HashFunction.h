#pragma once
#include <functional>

class HashFunction {
public:
	unsigned int badHash(const char* data, unsigned int length);
	unsigned int RSHash(const char* data, unsigned int length);
	unsigned int JSHash(const char* data, unsigned int length);

};