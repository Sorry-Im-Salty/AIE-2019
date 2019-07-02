#include "HashFunction.h"
#include <iostream>
using namespace std;

int main() {
	hash<int> badHash;
	badHash('H');
	badHash('E');
	badHash('L');
	badHash('L');
	badHash('O');

	for (int i = -2; i <= 2; ++i) {
		cout << "badHash(" << i << "): " << badHash(i) << endl;
	}
		
	system("pause");
	return 0;
}