#include "HashFunction.h"
#include <iostream>
using namespace std;

HashFunction hashFunc;


int main() {
	int badHashValue = hashFunc.badHash("hello", 3);
	int RSHashValue = hashFunc.RSHash("hello", 3);
	int JSHashValue = hashFunc.JSHash("hello", 3);


	cout << "For the data input of: hello" << endl;
	cout << endl;
	cout << "badHash: " << badHashValue << endl;
	cout << "RSHash: " << RSHashValue << endl;
	cout << "JSHash: " << JSHashValue << endl;
	cout << endl;

	system("pause");
	return 0;
}