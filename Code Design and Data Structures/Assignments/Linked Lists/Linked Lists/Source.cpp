#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

int main()
{
	DoubleLinkedList List;
	cout << "Before anything is added: " << endl; List.display(); cout << endl;
	List.pushFront(10);
	cout << "After adding the value of 10, the list looks like: " << endl; List.display(); cout << endl;
	List.pushFront(7);
	cout << "If we add the value of 7 to the front of the list, it looks like: " << endl; List.display(); cout << endl;
	List.pushBack(3);
	cout << "If we add the value of 3 to the back of the list, it looks like: " << endl; List.display(); cout << endl;
	List.pushFront(10);
	cout << "If we had two 10's in the list like this: " << endl; List.display(); cout << endl;
	List.erase(3);
	cout << "We can remove the second 10 to make the list look like this: " << endl; List.display(); cout << endl;

	system("pause");
	return 0;
}