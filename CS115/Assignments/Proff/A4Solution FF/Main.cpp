//
//  Main.cpp
//
//  Main function and helper functions for the CS 115 roguelike
//    game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//  Updated by Richard Hamilton, 2019-02-14
//  Updated by Richard Hamilton, 2019-02-26
//  Updated by Richard Hamilton, 2019-03-07
//

#include <cassert>
#include <string>
#include <iostream>
using namespace std;

#include "Game.h"

char getValidInput ();
void pauseForInput (const string& message);



int main ()
{
	// load a level list selected by the user

	cout << "Enter the name of the level list file, including the file extension." << endl;
	string file_name;

	getline(cin, file_name);
	while(file_name.empty())
	{
		getline(cin, file_name);
	}
	assert(!file_name.empty());
	
	Game game(file_name);
	
	// main loop

	char input = '\0';
	while (input != 'q' && !game.isOver())
	{
		game.print();

		input = getValidInput();
		switch(input)
		{
		case 'q':
			break;  // do nothing, loop will restart (and exit) immediately
		case 'n':
			game.tryMoveNorth();
			game.updateMonsters();
			break;
		case 's':
			game.tryMoveSouth();
			game.updateMonsters();
			break;
		case 'e':
			game.tryMoveEast();
			game.updateMonsters();
			break;
		case 'w':
			game.tryMoveWest();
			game.updateMonsters();
			break;
		case '.':
			game.updateMonsters();
			break;
		}
	}

	// display the player's final score and total move cost

	cout << endl;
	cout << "Game over" << endl;
	cout << endl;
	game.print();

	cout << endl;
	pauseForInput("Hit ENTER key to terminate program");
	
	return 0;  // exited successfully
}

char getValidInput ()
{
	string line;
	while(line.empty())
	{
		cout << "Next? ";
		getline(cin, line);

		if(line.empty())
			continue;

		// convert to lowercase
		if(line[0] >= 'A' && line[0] <= 'Z')
			line[0] = line[0] - 'A' + 'a';

		// detect valid input
		switch(line[0])
		{
		case 'q':
		case 'n':
		case 's':
		case 'e':
		case 'w':
		case '.':
			break;  // input is good, done with loop
		default:
			line = "";  // input is bad, loop runs again
			break;
		}
	}

	assert(!line.empty());
	return line[0];
}

void pauseForInput (const string& message)
{
	string contentToBeIgnored;
	cout << message;
	getline(cin, contentToBeIgnored);
}

