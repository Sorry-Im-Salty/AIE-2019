#include <iostream>
#include <stdlib.h>
using namespace std;

int nMid; // Middle value.
int nHigh = 100; // Highest value.
int nLow = 0; // Lowest value.
char kChoice[1]; // Player input.
int nTurn = 0; // Number of turns.

int main()
{
	cout << "                           Number Guess" << endl; cout << endl;
	cout << "Think of a number between 1 and 100, once you have thought of it, do not change it." << endl; system("pause");

	while (true)
	{
		nTurn++; // Turns will increase when the loop comes back around.
		nMid = (nLow + nHigh) / 2; // Middle will = low + high then halved.
		system("cls");
		cout << "                           Number Guess" << endl; cout << endl;
		cout << "Is your number : " << nMid << "?" << endl;
		cout << "Type 'y' if yes or type 'n' if no : "; cin >> kChoice[1]; cout << endl;
		
		if (kChoice[1] == 'y') // The program has guesses the number.
		{
			cout << "Your number is " << nMid << endl;
			cout << "It took me " << nTurn << " turns to guess your number." << endl;
			system("pause");
			return 0;
		}
		else if (kChoice[1] == 'n') // The program doesn't guess the number.
		{
			cout << "Is your number higher or lower than " << nMid << "?" << endl;
			cout << "Type 'h' if higher or type 'l' if lower : "; cin >> kChoice[1]; cout << endl;
			if (kChoice[1] == 'h') // Higher.
			{
				nMid++; // Mid will increase by 1.
				nLow = nMid; // Lowest will then be Mid value.
			}
			else if (kChoice[1] == 'l') // Lower.
			{
				nMid--; // Mid will decrease by 1.
				nHigh = nMid; // Highest will then be Mid value.
			}
		}
	}

	system("pause");
	return 0;
}