//
//  Main.h
//
//  Main function and helper function for the CS 115 
//  roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//  Updated by Howard Hamilton,  2019-01-28
//

#include <cmath>
#include <string>
#include <iostream>
using namespace std;

#include "Level.h"


void pauseForInput (string message);

double calculateDistance (int row1, int column1,
                          int row2, int column2);

void chooseMove(int old_monster_row, int old_monster_column, 
		int player_row, int player_column, 
		int &new_monster_row, int &new_monster_column, 
		string &move_string);

int main ()
{
	// load a level selected by the user
	cout << "Enter the name of the file to load, including the file extension." << endl;
	string file_name;

	getline(cin, file_name);
	while(file_name.empty())
	{
		getline(cin, file_name);
	}
	
	Level level;
	loadLevel(level, file_name);
	
	// determine the monster's starting row and column
	int monster_row, monster_column;
	findMonsterStart(level, monster_row, monster_column);

	// determine the target row and column
	int player_row, player_column;
	findPlayerStart(level, player_row, player_column);
	
	// display the monster moving to reach the target.
	//  -> note: Each move is one of: 
	//     north (up), east (right), south (down), and west (left)

	unsigned int total_cost = 0;
	double monster_distance = calculateDistance(monster_row, monster_column,
	                                            player_row,  player_column);
	while (monster_distance > 0.001)
	{
		int new_monster_row;
		int new_monster_column;
		string move_string;

		// display the level
		printLevel(level,
		           monster_row, monster_column,
		           player_row,  player_column);

		// choose next move for monster, but do not move monster yet
		chooseMove(monster_row, monster_column, 
			   player_row, player_column, 
			   new_monster_row, new_monster_column,
			   move_string);

		// print the monster information for current location
		cout
			<< "Monster"
			<< " r " << monster_row
			<< ", c " << monster_column
			<< "   distance: " << monster_distance
			<< "   cost: " << total_cost
			<< "   next: " << move_string << endl;

		// move monster to new location
		monster_row      = new_monster_row;
		monster_column   = new_monster_column;

		total_cost       += getCost(level, monster_row, monster_column);
		monster_distance = calculateDistance(monster_row, monster_column,
	                                            player_row,  player_column);

		// wait for user input
		pauseForInput("Continue? ");
	}

	// display the level, including the monster's final position
	printLevel(level, monster_row, monster_column, 
		player_row, player_column);
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


void chooseMove(int old_monster_row, int old_monster_column, 
		int player_row, int player_column, 
		int &new_monster_row, int &new_monster_column, 
		string &move_string)
{
	double north_distance, south_distance, east_distance, west_distance;

	north_distance = calculateDistance(old_monster_row - 1, old_monster_column,
			player_row, player_column);
	south_distance = calculateDistance(old_monster_row + 1, old_monster_column,
			player_row, player_column);

	east_distance = calculateDistance(old_monster_row, old_monster_column + 1,
			player_row, player_column);
	west_distance = calculateDistance(old_monster_row, old_monster_column - 1,
			player_row, player_column);

	new_monster_row    = old_monster_row;
	new_monster_column = old_monster_column;

	if (	north_distance <= south_distance && 
		north_distance <= east_distance && 
		north_distance <= west_distance)
	{
		move_string = "north";
		new_monster_row--;
	}
	else if (south_distance <= east_distance && 
		south_distance <= west_distance)
	{
		move_string = "south";
		new_monster_row++;
	}
	else if (east_distance <= west_distance)
        {
		move_string = "east";
                new_monster_column++;
        }
	else 
        {
		move_string = "west";
                new_monster_column--;
        }
}

