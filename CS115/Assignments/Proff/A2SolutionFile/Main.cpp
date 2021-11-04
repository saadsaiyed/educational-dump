//
//  Main.h
//
//  For the CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//  Updated by Richard Hamilton, 2019-02-03
//  Updated by Richard Hamilton, 2019-02-07
//

#include <string>
#include <iostream>
using namespace std;

#include "Level.h"
#include "Position.h"
#include "Player.h"
#include "Monster.h"

void printAll (const Level& level,
               const Player& player,
               const Monster& monster);
char getValidInput ();
Position calculatePlayerMove (const Player& player,
                              char input);
void pauseForInput (string message);



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
	
	// initialize the player

	int player_row, player_column;
	findPlayerStart(level, player_row, player_column);
	Player player;
	playerInit(player, toPosition(player_row, player_column));

	// initialize the monster

	int monster_row, monster_column;
	findMonsterStart(level, monster_row, monster_column);
	Monster monster;
	monsterInit(monster, toPosition(monster_row, monster_column));

	// main loop

	char input = '\0';
	while (input != 'q' && !playerIsDead(player))
	{
		printAll(level, player, monster);

		input = getValidInput();
		if(input == 'q')
			continue;  // restart (and exit) the loop immediately

		// move the player

		Position new_player_position = calculatePlayerMove(player, input);

		if(!monsterIsDead(monster) &&
		   areEqual(new_player_position, monsterGetPosition(monster)))
		{
			// player is attacking the monster
			monsterReceiveDamage(monster, playerGetDamage(player));
			if(monsterIsDead(monster))
				playerIncreaseScore(player, monsterGetPoints(monster));
		}
		else if(isValid(new_player_position) &&
		        !areEqual(new_player_position, playerGetPosition(player)))
		{
			// player made a valid move
			unsigned int cost = getCost(level, new_player_position.row, new_player_position.column);
			playerIncreaseTotalMoveCost(player, cost);
			playerSetPosition(player, new_player_position);
		}
		else
		{
			// player made an invalid move (or '.')
			// do nothing
		}

		// move the monster

		if(!monsterIsDead(monster))
		{
			Position player_position = playerGetPosition(player);
			Position new_monster_position = monsterCalculateMove(monster, player_position);

			if(areEqual(new_monster_position, player_position))
			{
				// monster is attacking the player
				playerReceiveDamage(player, monsterGetDamage(monster));
			}
			else
			{
				// monster is moving towards the player
				monsterSetPosition(monster, new_monster_position);
			}
		}
	}

	// display the player's final score and total move cost

	cout << endl;
	cout << "Game over" << endl;
	cout << endl;
	printAll(level, player, monster);

	cout << endl;
	pauseForInput("Hit ENTER key to terminate program ");
	
	return 0;  // exited successfully
}

void printAll (const Level& level,
               const Player& player,
               const Monster& monster)
{
	const Position OUTSIDE_LEVEL = toPosition(ROWS, COLUMNS);

	Position player_position = playerGetPosition(player);
	if(playerIsDead(player))
		player_position = OUTSIDE_LEVEL;

	Position monster_position = monsterGetPosition(monster);
	if(monsterIsDead(monster))
		monster_position = OUTSIDE_LEVEL;

	printLevel(level,
	           monster_position.row, monster_position.column,
	           player_position.row,  player_position.column);

	cout
		<< "Health: "        << playerGetHealth(player)
		<< "    Move cost: " << playerGetTotalMoveCost(player)
		<< "    Score: "     << playerGetScore(player)
		<< endl;
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

	return line[0];
}

Position calculatePlayerMove (const Player& player,
                              char input)
{
	Position position = playerGetPosition(player);
	switch(input)
	{
	case 'n':
		position.row -= 1;
		break;
	case 's':
		position.row += 1;
		break;
	case 'e':
		position.column += 1;
		break;
	case 'w':
		position.column -= 1;
		break;
	}
	return position;
}

void pauseForInput(string message)
{
	string contentToBeIgnored;
	cout << message;
	getline(cin, contentToBeIgnored);
}

