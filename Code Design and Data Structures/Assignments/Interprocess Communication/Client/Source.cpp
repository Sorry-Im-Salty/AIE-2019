#include <Windows.h>
#include <iostream>
using namespace std;


struct MyData
{
	int i;
	float f;
	char c;
	bool b;
	double d;
};

int main()
{
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "MySharedMemory");
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

	cout << "MyData = { ";
	cout << data->i << ", ";
	cout << data->f << ", ";
	cout << data->c << ", ";
	cout << data->b << ", ";
	cout << data->d << ", ";
	cout << " };" << endl;

	UnmapViewOfFile(data);
	system("pause");
	CloseHandle(fileHandle);
	return 0;
}