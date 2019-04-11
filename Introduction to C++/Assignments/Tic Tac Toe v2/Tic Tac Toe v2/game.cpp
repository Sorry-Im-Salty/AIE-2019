#include <iostream>
#include "game.h"
using namespace std;

void game::play()
{
	do
	{
		// Initial Grid
		cout << endl;
		cout << "        Tic Tac Toe" << endl;
		cout << "Player 1 = X | Player 2 = O" << endl;
		cout << endl;
		cout << "       0     1     2" << endl; // Reference for the player.
		cout << "     -----------------" << endl; // Top of grid.
		cout << "  0    " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl; // Top row.
		cout << "     -----+-----+-----" << endl;
		cout << "  1    " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl; // Mid row.
		cout << "     -----+-----+-----" << endl;
		cout << "  2    " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl; // Bottom row.
		cout << "     -----------------" << endl; // Bottom of grid.
		
		// Checking Win
		if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X' ||
			grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X' ||
			grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X' ||
			grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X' ||
			grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X' ||
			grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X' ||
			grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X' ||
			grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
		{
			cout << "Player 1 wins!" << endl;
			break;
		}

		else
			if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O' ||
				grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O' ||
				grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O' ||
				grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O' ||
				grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O' ||
				grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O' ||
				grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O' ||
				grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')
			{
				cout << "Player 2 wins!" << endl;
				break;
			}

		// Assigning Player to a Mark
		if (numTurns % 2)
		{
			mark = 'O';
			player = 2;
			cout << endl;
		}

		else
		{
			mark = 'X';
			player = 1;
			cout << endl;
		}

		// Player input
		do
		{
			cout << "Player " << player << " please input a row number: "; cin >> x; cout << endl;
			if (x >= 3 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid row number, please input a valid number" << endl;
			}
		} while (x >= 3 || cin.fail());

		if (x < 3)
		{
			do
			{
				cout << "Player " << player << " please input a column number: "; cin >> y; cout << endl;
				if (y >= 3 || cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid column number, please input a valid number" << endl;
				}
			} while (y >= 3 || cin.fail());
		}

		// Restricting the Player from Picking a Square Which Has Already Been Selected
		if (grid[x][y] == 'X' || grid[x][y] == 'O')
			cout << "That square has already been used. Please choose another." << endl;
		else
			grid[x][y] = mark;
		
		// Increasing Turn Number and Clearing the Screen
		numTurns++;
		system("cls");
	} while (gameWin == false);
}