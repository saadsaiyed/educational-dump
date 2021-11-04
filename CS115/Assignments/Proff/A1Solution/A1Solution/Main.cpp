//
//  Main.h
//
//  For the CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//

#include <cassert>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

#include "Level.h"


void pauseForInput (string message);

double calculateDistance (int row1, int column1,
                          int row2, int column2);

int main ()
{
	const double VERY_FAR = 1.0e20;

	const unsigned int MONSTER_OPTION_COUNT = 5;
	const unsigned int MONSTER_OPTION_WAIT  = 0;
	const int MONSTER_OPTION_ROW [MONSTER_OPTION_COUNT]		= {	0,	-1,	1,	0,	0,	};
	const int MONSTER_OPTION_COLUMN [MONSTER_OPTION_COUNT]	= {	0,	0,	0,	-1,	1,	};
	const string MONSTER_OPTION_NAME [MONSTER_OPTION_COUNT] = {	"wait", "north", "south", "west", "east",	};

	// load a level selected by the user

	cout << "Enter the name of the file to load, including the file extension." << endl;
	string file_name;

	getline(cin, file_name);
	while(file_name.empty())
	{
		getline(cin, file_name);
	}
	assert(!file_name.empty());
	
	Level level;
	loadLevel(level, file_name);
	
	// determine the starting row and column

	int current_row, current_column;
	findMonsterStart(level, current_row, current_column);
	assert(current_row < ROWS);
	assert(current_column < COLUMNS);

	// determine the target row and column

	int target_row, target_column;
	findPlayerStart(level, target_row, target_column);
	assert(target_row < ROWS);
	assert(target_column < COLUMNS);
	
	// display the monster moving to reach the target.
	//  -> note: Each move is one of: north (up), east (right), south (down), and west (left)

	unsigned int total_cost = 0;
	double current_distance = calculateDistance(current_row, current_column,
	                                            target_row,  target_column);
	while (current_distance > 0.001)
	{
		// display the level

		printLevel(level,
		           current_row, current_column,
		           target_row,  target_column);

		// choose the direction for the monster to move

		bool is_move = true;
		unsigned int best_option = MONSTER_OPTION_WAIT;
		int    best_row      = current_row;
		int    best_column   = current_column;
		double best_distance = VERY_FAR;

		for(unsigned int i = 0; i < MONSTER_OPTION_COUNT; i++)
		{
			int test_row    = current_row    + MONSTER_OPTION_ROW   [i];
			int test_column = current_column + MONSTER_OPTION_COLUMN[i];

			double test_distance = calculateDistance(test_row,   test_column,
			                                         target_row, target_column);
			if(test_distance < best_distance)
			{
				best_option   = i;
				best_row      = test_row;
				best_column   = test_column;
				best_distance = test_distance;
			}
		}

		// print the monster information

		cout
			<< "Monster r " << current_row
			<< ", c " << current_column
			<< "   distance: " << current_distance
			<< "   cost: " << total_cost
			<< "   next: " << MONSTER_OPTION_NAME[best_option] << endl;

		// move the monster (if needed)

		if(best_option != MONSTER_OPTION_WAIT)
		{
			// the best move will always be onto the valid map
			assert(best_row    >= 0);
			assert(best_row    <  ROWS);
			assert(best_column >= 0);
			assert(best_column <  COLUMNS);

			current_row      = best_row;
			current_column   = best_column;
			current_distance = best_distance;
			total_cost += getCost(level, current_row, current_column);
		}

		// wait for user input

		pauseForInput("Continue? ");
	}

	// display the level, including the monster's final position

	printLevel(level, current_row, current_column, target_row, target_column);
	cout << "Total traversal cost is " << total_cost << endl;

	pauseForInput("Hit ENTER key to terminate program ");
	
	return 0;  // exited successfully
}

void pauseForInput(string message)
{
	string contentToBeIgnored;
	cout << message;
	getline(cin, contentToBeIgnored);
}

double calculateDistance (int row1, int column1,
                          int row2, int column2)
{
	int rdiff = row1    - row2;
	int cdiff = column1 - column2;
	return sqrt(double(rdiff * rdiff + cdiff * cdiff));
}
