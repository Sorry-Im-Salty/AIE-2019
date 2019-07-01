#include "DynamArray.h"
//template<class T>
//DynamArray<T>::DynamArray()
//{
//	pArray = new T[10];
//	for (int i = 0; i < 10; i++)
//		pArray[i] = 0;
//	nLength = 10;
//	nNextIndex = 0;
//}

//template<class T>
//DynamArray<T>::~DynamArray()
//{
//	delete[] pArray;
//}

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

//template<class T>
//void DynamArray<T>::add(int nVal)
//{
//	T *pNewArray;
//	if (nNextIndex == nLength)
//	{
//		nLength = nLength + 10;
//		pNewArray = new T[nLength];
//		for (int i = 0; i < nNextIndex; i++)
//			pNewArray[i] = pArray[i];
//		for (int j = nNextIndex; j < nLength; j++)
//			pNewArray[j] = 0;
//		delete[] pArray;
//		pArray = pNewArray;
//	}
//	pArray[nNextIndex++] = nVal;
//}

//template<class T>
//void DynamArray<T>::remove(int nVal) {
//	pArray[nNextIndex--] = nVal;
//}

//template<class T>
//int DynamArray<T>::size()
//{
//	return nLength;
//}

template<class T>
int DynamArray<T>::LinearSearch(DynamArray* pArray[], int n, int x) {
	int i;
	for (i = 0; i < n; ++i) {
		if (pArray[i] == x) {
			return i;
		}
		return -1;
	}
}

template<class T>
void DynamArray<T>::BubbleSort(DynamArray* pArray[], int n) // Sorts enemies by their health.
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (pArray[j] > pArray[j + 1])
			{
				DynamArray* temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
		}
	}
}