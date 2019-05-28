#pragma once
template<class T>
class DynamArray
{
public:
	DynamArray();
	~DynamArray();
	T& operator[] (int nIndex);
	void add(int nVal);
	void remove(int nVal);
	int size();

	int LinearSearch(int arr[], int n, int x);

private:
	T *pArray;
	int nLength;
	int nNextIndex;
};