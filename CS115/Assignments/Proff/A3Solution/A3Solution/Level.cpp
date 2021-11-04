//
//  Level.cpp
//
//  Implementation of the Level type for the CS 115 roguelike
//    game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//  Updated by Richard Hamilton, 2019-02-04
//  Updated by Richard Hamilton, 2019-02-14
//

#include <cassert>
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
	1,  // PLAYER_GOAL
	1,  // MONSTER_START
	1,  // ATTACKER_START
	1,  // DRONE_START
};



Level :: Level (const string& file_name)
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
					terrain[r][c] = t;
					is_input_valid = true;
				}
			}
			
			if (!is_input_valid)
			{
				cout	<< "Error: Invalid input at row " << r << ", column " << c
						<< ", substituted empty terrain" << endl;
				terrain[r][c] = EMPTY;
			}
		}
	}
}



Position Level :: getMonsterStart () const
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			if (terrain[r][c] == MONSTER_START)
				return toPosition(r, c);

	// default: return upper left corner if not found
	return toPosition(0, 0);
}

Position Level :: getPlayerStart () const
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
			if (terrain[r][c] == PLAYER_START)
				return toPosition(r, c);

	// default: return upper left corner if not found
	return toPosition(0, 0);
}

unsigned int Level :: getCost (const Position& position) const
{
	assert(isValid(position));

	unsigned int t = terrain[position.row][position.column];
	assert(t < TERRAIN_COUNT);
	return TRAVERSAL_COST[t];
}

bool Level :: isWall (const Position& position) const
{
	assert(isValid(position));

	if(terrain[position.row][position.column] == WALL)
		return true;
	else
		return false;
}

void Level :: print (const Position& monster_position, 
                     const Position& player_position) const
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
			Position here = toPosition(r, c);
			if (areEqual(player_position, here))
				cout << '@';
			else if (areEqual(monster_position, here))
				cout << 'M';
			else
			{
				unsigned int t = terrain[r][c];
				assert(t < TERRAIN_COUNT);
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

