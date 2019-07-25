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

	if (dArray.LinearSearch(dArray.size(), 7) != true)
		cout << "A 7 was found." << endl;

	cout << "Here's what the array looks like: " << endl; cout << endl;
	dArray.print();

	cout << "If we remove int 11 from the array: " << endl; cout << endl;
	dArray.remove(6);
	dArray.print();

	cout << "Sorted Array: " << endl; cout << endl;
	dArray.BubbleSort(dArray.size());
	dArray.print();

	system("pause");
	return 0;
}