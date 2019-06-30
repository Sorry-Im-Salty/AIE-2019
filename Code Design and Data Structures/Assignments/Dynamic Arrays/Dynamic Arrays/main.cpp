#include <iostream>
#include "DynamArray.h"
using namespace std;

template<class T>

int main() {
	DynamArray<T> dArray;
	dArray.add(15);
	dArray.add(12);
	dArray.add(19);
	dArray.add(7);


	cout << dArray << endl;

	system("pause");
	return 0;
}