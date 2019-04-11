#include <iostream>
using namespace std;

void nValues(int &i, int &j)
{
	int temp = i; // Reference i.
	i = j;
	j = temp; // Reference j.
}

int main()
{
	int a = 10;
	int b = 20;

	nValues(a, b); // A and B will be switched.

	cout << "A is " << a << " B is " << b << endl; // A = 20, B = 10.



	system("pause");
	return 0;
}