/*
Name: Saad Saiyed
Course: CS 115
Assignment: 4
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 04/10/19

This program deals with two dimensional arrays and classes to run an ASCII value game of Monster and Player where,
Monster moves towards Player and user needs to handle Player.
Specific to assignment 4 we have a Game class which replaces many variables in Main function and also 
this program will NOT over if monster is dead (not even all are dead).
*/

#include"Level.h"
#include"Monster.h"
#include"Player.h"
#include"Position.h"
#include"Game.h"

//
//  playerPositionChange
//
//  Purpose: To change values of Player's Position according to user's desire.
//  Parameter(s):
//    <1> P		: The Position P to modify players positon.
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: Values of Player's position changed accordingly.
//
void playerPositionChange(char input, Game& game);

int main()
{

	cout << "Enter the name of the file to load, including the file extension. ";
	string file_name;

	getline(cin, file_name);
	while (file_name.empty())
	{
		getline(cin, file_name);
	}

	Game game(file_name);

	char move = '.';							//to get input from user to move player
	while (!game.isOver() && move != 'q' && move != 'Q') //This is main loop which controls the print function and ends it when monster or player one of them is dead
	{
		system("CLS");
		game.print();							//print the output of map and monster is just to look if he is dead or not

		cin >> move;							//getting input from user
		playerPositionChange(move, game);		//updating Player according to user's desire
		game.updateMonsters();					//updating Monster according to closest distance from player position
		game.isAtGoalPos();
	}
	system("CLS");
	game.print();
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------//

void playerPositionChange(char input, Game& game)
{
	if (input == 'w' || input == 'W')
		game.tryMoveWest();

	else if (input == 'n' || input == 'N')
		game.tryMoveNorth();

	else if (input == 'e' || input == 'E')
		game.tryMoveEast();

	else if (input == 's' || input == 'S')
		game.tryMoveSouth();

	else if (input == '.')
		input = 'p';
}