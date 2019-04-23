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
	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		nullptr,
		PAGE_READWRITE,
		0, sizeof(MyData),
		"MySharedMemory");

	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));

	MyData temp;
	temp.i = 5;
	temp.f = 5.2f;
	temp.c = 'K';
	temp.b = true;
	temp.d = 100;

	*data = temp;

	UnmapViewOfFile(data);
	system("pause");
	CloseHandle(fileHandle);
	return 0;
}