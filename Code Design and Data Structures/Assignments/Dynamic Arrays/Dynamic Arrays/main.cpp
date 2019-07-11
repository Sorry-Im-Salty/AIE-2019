#include <iostream>
#include "DynamArray.h"
using namespace std;

int main() {
	DynamArray<int> dArray;

	cout << "Before adding anything, the current size of the array is: " << dArray.size() << endl;

	dArray.add(15);
	dArray.add(12);
	dArray.add(17);
	dArray.add(19);
	dArray.add(7);
	dArray.add(3);
	dArray.add(11);
	dArray.add(1);
	dArray.add(4);
	dArray.add(23);
	dArray.add(26);

	cout << "After adding 11 ints to the array, the size has increased to: " << dArray.size() << endl;

	dArray.remove(1);

	cout << "After removing 1 int, the size has decreased to: " << dArray.size() << endl;

	dArray.BubbleSort(dArray.size());

	if (dArray.LinearSearch(dArray.size(), 7) != true)
		cout << "A 7 was found." << endl;

	system("pause");
	return 0;
}