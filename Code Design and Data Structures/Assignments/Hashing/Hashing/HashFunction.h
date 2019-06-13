#pragma once
#include <functional>

namespace HashFunction {

	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;

	unsigned int badHash(const char* data, unsigned int length);
	unsigned int RSHash(const char* data, unsigned int length);
	unsigned int JSHash(const char* data, unsigned int length);

}