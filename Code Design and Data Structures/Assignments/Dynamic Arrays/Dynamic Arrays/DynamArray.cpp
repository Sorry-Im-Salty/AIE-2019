#include "DynamArray.h"
template<class T>
DynamArray<T>::DynamArray()
{
	pArray = new T[10];
	for (int i = 0; i < 10; i++)
		pArray[i] = 0;
	nLength = 10;
	nNextIndex = 0;
}

template<class T>
DynamArray<T>::~DynamArray()
{
	delete[] pArray;
}

template<class T>
T& DynamArray<T>::operator[](int nIndex)
{
	T *pNewArray;
	if (nIndex >= nLength)
	{
		pNewArray = new T[nIndex + 10];
		for (int i = 0; i < nNextIndex; i++)
			pNewArray[i] = pArray[i];
		for (int j = nNextIndex; j < nIndex + 10; j++)
			pNewArray[j] = 0;
		nLength = nIndex + 10;
		delete[] pArray;
		pArray = pNewArray;
	}
	if (nIndex > nNextIndex)
		nNextIndex = nIndex + 1;
	return *(pArray + nIndex);
}

template<class T>
void DynamArray<T>::add(int nVal)
{
	T *pNewArray;
	if (nNextIndex == nLength)
	{
		nLength = nLength + 10;
		pNewArray = new T[nLength];
		for (int i = 0; i < nNextIndex; i++)
			pNewArray[i] = pArray[i];
		for (int j = nNextIndex; j < nLength; j++)
			pNewArray[j] = 0;
		delete[] pArray;
		pArray = pNewArray;
	}
	pArray[nNextIndex++] = nVal;
}

template<class T>
int DynamArray<T>::size()
{
	return nLength;
}