#include <iostream>
#include <fstream>
using namespace std;

struct Library
{
	char callNumber[64];
	char title[64];
	char author[64];
	int bookStatus;
	char dueDate[64];
	char borrowersName[64];
};

int loadRecords()
{
	Library libArray[] = { {"001.645.2", "Learning C++", "Gregory Harrison", '1'}, {"001.721.3", "C++ for beginners", "Quentin Resnick", 2, "25 9 1999", "Me"} };
	int arraySize = sizeof(libArray) / sizeof(Library);
	Library lib;
	fstream fin("library.dat", ios::in | ios::binary);
	if (fin.good())
	{
		while (!fin.eof() && fin.peek() != EOF)
		{
			fin.read((char*)&lib, sizeof(Library)); // Will read the entire Library before closing.
		}
		fin.close();
	}
	else
	{
		fstream fin("library.txt", ios::in | ios::binary);
		if (fin.bad()) // If Library is unable to open.
		{
			cout << "Error opening Library.txt ... Terminating." << endl;
			system("pause");
			return 0;
		}
		else
		{
			while (!fin.eof() && fin.peek() != EOF)
			{
				fin.read((char*)&lib, sizeof(Library)); // Read while the file doesn't end.
			}
			fin.close();

			fstream fout("library.dat", ios::out | ios::binary);
			if (fout.good())
			{
				for (int i = 0; i < arraySize; i++)
				{
					fout.write((char*)&libArray[i], sizeof(Library)); // Write to the Library if the file can be opened then close.
				}
				fout.close();
			}
			
			fstream fout2("library.dat", ios::out | ios::binary | ios::in);
			if (fout2.good())
			{
				fout2.seekp(10, ios::beg);
				fout2.write("Test", 4); // Write towards the middle.
			}
		}
	}
}


int main()
{
	loadRecords();




	system("pause");
	return 0;
}