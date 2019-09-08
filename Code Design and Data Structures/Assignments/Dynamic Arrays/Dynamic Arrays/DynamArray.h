#pragma once
template<class T>
class DynamArray
{
public:
	DynamArray() {
		pArray = new T[10];
		for (int i = 0; i < 10; i++)
			pArray[i] = 0;
		nLength = 10;
		nNextIndex = 0;
	}
	
	~DynamArray() {
		delete[] pArray;
	}

	T& operator[] (int nIndex);
	
	void add(int nVal) {
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

	void remove(int nPos) {
		if (nPos < nNextIndex && nPos >= 0) {
			for (int i = nPos; i < nNextIndex; i++) {
				pArray[i] = pArray[i + 1];
			}
				
			nNextIndex--;

			//	pArray[i] = pArray[i + 1];
			//nNextIndex--;
			//if (nNextIndex = nLength - 10)
			//	nLength = nLength - 10;
		}

	}
	
	void print() {
		for (int i = 0; i < nNextIndex; i++) {
			std::cout << pArray[i] << std::endl;
		}
	}

	int size() {
		return nNextIndex;
	}

	int LinearSearch(int n, int x) {
		int i;
		for (i = 0; i < n; i++) {
			if (pArray[i] == x) {
				return i;
			}
		}
		return 0;
	}

	void BubbleSort(int n) {
		int i, j;
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (pArray[j] > pArray[j + 1])
				{
					temp = pArray[j];
					pArray[j] = pArray[j + 1];
					pArray[j + 1] = temp;
				}
			}
		}
	}

private:
	T temp;
	T *pArray;
	int nLength;
	int nNextIndex;
};