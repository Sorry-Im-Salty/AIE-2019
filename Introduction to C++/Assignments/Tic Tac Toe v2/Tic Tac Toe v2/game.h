#pragma once

class game
{
private:
	char grid[3][3] = { {'1','2','3'},
						{'4','5','6'},
						{'7','8','9'} }; // Numbered grid.
	int numTurns; // Total turns.
	int x; // Player input for x.
	int y; // Player input for y.
	int player; // Player number.
	char mark; // Marks, X or O.
	bool gameWin = false; // Has the game been won?

public:
	void play();
};