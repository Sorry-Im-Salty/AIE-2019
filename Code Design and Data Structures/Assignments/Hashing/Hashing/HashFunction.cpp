#include "HashFunction.h"

namespace HashFunction {
	
	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length) {
		unsigned int hash = 0;
		
		for (unsigned int i = 0; i < length; ++i)
			hash += data[i];

		return hash;
	}

	unsigned int RSHash(const char* data, unsigned int length) {
		unsigned int b = 378551;
		unsigned int a = 63689;
		unsigned int hash = 0;
		unsigned int i = 0;

		for (i = 0; i < length; ++data, ++i) {
			hash = hash * a + (*data);
			a = a * b;
		}
		return hash;
	}

	unsigned int JSHash(const char* data, unsigned int length) {
		unsigned int hash = 1315423911;
		unsigned int i = 0;

		for (i = 0; i < length; ++data, ++i) {
			hash ^= ((hash << 5) + (*data) + (hash >> 2));
		}
		return hash;
	}
}