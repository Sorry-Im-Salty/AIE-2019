#pragma once
template<class T>
class DynamArray
{
public:
	DynamArray();
	~DynamArray();
	T& operator[] (int nIndex);
	void add(int nVal);
	int size();

private:
	T *pArray;
	int nLength;
	int nNextIndex;
};