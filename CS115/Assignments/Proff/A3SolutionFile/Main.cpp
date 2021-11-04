//
//  Main.h
//
//  For the CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//

#include <cassert>
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
void pauseForInput (const string& message);



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
	assert(!file_name.empty());
	
	Level level(file_name);
	
	// initialize the player and monster

	Player  player (level.getPlayerStart ());
	Monster monster(level.getMonsterStart());

	// main loop

	char input = '\0';
	while (input != 'q' && !player.isDead())
	{
		printAll(level, player, monster);

		input = getValidInput();
		if(input == 'q')
			continue;  // restart (and exit) the loop immediately

		// move the player

		assert(!player.isDead());
		Position new_player_position = calculatePlayerMove(player, input);

		if(!monster.isDead() &&
		   areEqual(new_player_position, monster.getPosition()))
		{
			// player is attacking the monster
			monster.receiveDamage(player.getDamage());
			if(monster.isDead())
				player.increaseScore(monster.getPoints());
		}
		else if(isValid(new_player_position) &&
		        !level.isWall(new_player_position) &&
		        !areEqual(new_player_position, player.getPosition()))
		{
			// player made a valid move
			unsigned int cost = level.getCost(new_player_position);
			player.increaseTotalMoveCost(cost);
			player.setPosition(new_player_position);
		}
		else
		{
			// player made an invalid move (or '.')
			// do nothing
		}

		// move the monster

		if(!monster.isDead())
		{
			Position player_position = player.getPosition();
			Position new_monster_position = monster.calculateMove(level, player_position);

			if(areEqual(new_monster_position, player_position))
			{
				// monster is attacking the player
				player.receiveDamage(monster.getDamage());
			}
			else
			{
				// monster is moving towards the player
				assert(isValid(new_monster_position));
				monster.setPosition(new_monster_position);
			}
		}
	}

	// display the player's final score and total move cost

	cout << endl;
	cout << "Game over" << endl;
	cout << endl;
	printAll(level, player, monster);

	cout << endl;
	pauseForInput("Hit ENTER key to terminate program");
	
	return 0;  // exited successfully
}

void printAll (const Level& level,
               const Player& player,
               const Monster& monster)
{
	const Position OUTSIDE_LEVEL = toPosition(ROWS, COLUMNS);

	Position player_position  = player.getPosition();
	if(player.isDead())
		player_position = OUTSIDE_LEVEL;

	Position monster_position = monster.getPosition();
	if(monster.isDead())
		monster_position = OUTSIDE_LEVEL;

	level.print(monster_position, player_position);

	cout
		<< "Health: "        << player.getHealth()
		<< "    Move cost: " << player.getTotalMoveCost()
		<< "    Score: "     << player.getScore()
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

	assert(!line.empty());
	return line[0];
}

Position calculatePlayerMove (const Player& player,
                              char input)
{
	Position position = player.getPosition();
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

void pauseForInput (const string& message)
{
	string contentToBeIgnored;
	cout << message;
	getline(cin, contentToBeIgnored);
}

