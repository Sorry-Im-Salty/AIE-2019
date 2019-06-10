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

	int LinearSearch(DynamArray* pArray[], int n, int x);
	void BubbleSort(DynamArray* pArray[], int n);

private:
	T *pArray;
	int nLength;
	int nNextIndex;
};