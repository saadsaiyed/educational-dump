//
//  Level.cpp
//
//  Implementation of the Level type For the 
//  CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//  Updated by Howard Hamilton,  2019-01-28
//

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Level.h"

const unsigned int TERRAIN_COUNT = 9;
	const char INPUT_TERRAIN_TYPE[TERRAIN_COUNT] =
	{
		'.', // EMPTY
		'^', // ROCKY
		':', // ROUGH
		'#', // WALL
		'P', // PLAYER_START
		'*', // PLAYER_GOAL
		'S', // MONSTER_START
		'A', // ATTACKER_START
		'D', // DRONE_START
	};

const char OUTPUT_TERRAIN_TYPE[TERRAIN_COUNT] =
{
	' ', // EMPTY 
	'^', // ROCKY
	':', // ROUGH
	'#', // WALL
	' ', // PLAYER_START
	'*', // PLAYER_GOAL
	' ', // MONSTER_START
	' ', // ATTACKER_START
	' ', // DRONE_START
};

const unsigned int TRAVERSAL_COST[TERRAIN_COUNT] =
{
	1,  // EMPTY
	2,  // ROCKY
	4,  // ROUGH
	1000, // WALL
	1,  // PLAYER_START
	0,  // PLAYER_GOAL
	1,  // MONSTER_START
	1,  // ATTACKER_START
	1,  // DRONE_START
};

void loadLevel(Level level,
               string file_name)
{
	ifstream in(file_name.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	for (int r = 0; in && (r < ROWS); r++)
	{
		for (int c = 0; in && (c < COLUMNS); c++)
		{
			char next_char;
			in >> next_char;

			bool is_input_valid = false;
			for (unsigned int t = 0; t < TERRAIN_COUNT; t++)
			{
				if (next_char == INPUT_TERRAIN_TYPE[t])
				{
					level[r][c] = t;
					is_input_valid = true;
				}
			}
			
			if (!is_input_valid)
			{
				cout	<< "Error: Invalid input at row " << r 
					<< ", column " << c
					<< ", substituted empty terrain" << endl; 
				level[r][c] = EMPTY;
			}
			//cout << setw(2) << right << level[r][c];
		}
		//cout << endl;
	}
}

void findMonsterStart (Level level,
                       int& row, int& column)
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			if (level[r][c] == MONSTER_START)
			{
				row    = r;
				column = c;
				//cout	<< "Found monster start at row " << row 
				//		<< " and column " << column << endl;
				return;
			}
		}
	}

	// default: set to upper left corner if not found
	row    = 0;
	column = 0;
}

void findPlayerStart (Level level,
                      int& row, int& column)
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			if (level[r][c] == PLAYER_START)
			{
				row    = r;
				column = c;
				return;
			}

	// default: set to upper left corner if not found
	row    = 0;
	column = 0;
}

unsigned int getCost (Level level,
                      int row, int column)
{
	unsigned int t = level[row][column];
	return TRAVERSAL_COST[t];
}

void printLevel (Level level, 
                 int current_row, int current_column, 
                 int target_row, int target_column)
{
	// print top outline
	cout << "+";
	for (int c = 0; c < COLUMNS; c++)
		cout << "-";
	cout << "+" << endl;

	for (int r = 0; r < ROWS; r++)
	{
		// print left outline
		cout << '|';

		// print level contents
		for (int c = 0; c < COLUMNS; c++)
		{
			if (r == current_row && c == current_column)
				cout << 'M';
			else if (r == target_row && c == target_column)
				cout << '@';
			else
			{
				unsigned int t = level[r][c];
				cout << OUTPUT_TERRAIN_TYPE[t];
			}
		}

		// print right outline
		cout << '|' << endl;
	}

	// print bottom outline
	cout << "+";
	for (int c = 0; c < COLUMNS; c++)
		cout << "-";
	cout << "+" << endl;
}

