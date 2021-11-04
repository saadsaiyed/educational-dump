//
//  Game.cpp
//

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>

#include "Position.h"
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "Game.h"

using namespace std;



Game :: Game (const std::string& file_name)
	: level_count(0),
	  current_level(0),
	  player(levels[current_level].getPlayerStart()),
	  monster_count(0)
{
	fstream in(file_name.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	in >> level_count;  // read the number of levels
	string line;
	getline(in, line);  // clear out anything else on the line
	if (level_count == 0)
	{
		cout << "Error: No levels listed in file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	for (unsigned int i = 0; i < level_count; i++)
	{
		getline(in, line);  // read the level file name
		levels[i] = Level(line);
	}

	// set up the first level
	assert(0 < level_count);
	goToLevel(0);

	assert(invariant());
}



bool Game :: isOver () const
{
	assert(invariant());

	if(player.isDead())
		return true;
	if(levels[current_level].isGoalPosition(player.getPosition()))
		return true;
	return false;
}

void Game :: print () const
{
	assert(invariant());

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
			bool is_printed = false;

			if(!player.isDead() &&
			   areEqual(player.getPosition(), here))
			{
				cout << '@';
				is_printed = true;
			}
			for(unsigned int i = 0; i < monster_count; i++)
			{
				if(!is_printed &&
				   !monsters[i].isDead() &&
				   areEqual(monsters[i].getPosition(), here))
				{
					cout << 'M';
					is_printed = true;
				}
			}
			if(!is_printed)
				levels[current_level].printAtPosition(here);
		}

		// print right outline
		cout << '|' << endl;
	}

	// print bottom outline
	cout << "+";
	for (int c = 0; c < COLUMNS; c++)
		cout << "-";
	cout << "+" << endl;

	cout
		<< "Health: " << player.getHealth()
		<< "    Move cost: " << player.getTotalMoveCost()
		<< "    Score: " << player.getScore() << endl;
}



void Game :: tryMoveNorth ()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.row -= 1;
	tryMove(new_player_position);

	assert(invariant());
}

void Game :: tryMoveSouth ()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.row += 1;
	tryMove(new_player_position);

	assert(invariant());
}

void Game :: tryMoveEast ()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.column += 1;
	tryMove(new_player_position);

	assert(invariant());
}

void Game :: tryMoveWest ()
{
	assert(invariant());

	Position new_player_position = player.getPosition();
	new_player_position.column -= 1;
	tryMove(new_player_position);

	assert(invariant());
}

void Game :: updateMonsters ()
{
	assert(invariant());

	for(unsigned int i = 0; i < monster_count; i++)
		if(!monsters[i].isDead())
		{
			Position player_position = player.getPosition();
			Position new_monster_position = monsters[i].calculateMove(*this, player_position);
			assert(isValid(new_monster_position));

			if(areEqual(new_monster_position, player_position))
			{
				// monster is attacking the player
				player.receiveDamage(monsters[i].getDamage());
			}
			else
			{
				// monster is moving
				monsters[i].setPosition(new_monster_position);
			}
		}

	assert(invariant());
}

bool Game :: isBlockedForMonster (const Position& position) const
{
	assert(invariant());
	assert(isValid(position));

	if(levels[current_level].isWall(position))
		return true;
	for(unsigned int i = 0; i < monster_count; i++)
	{
		if(!monsters[i].isDead() &&
		   areEqual(position, monsters[i].getPosition()))
		{
			return true;
		}
	}
	return false;
}



void Game :: goToLevel (unsigned int level)
{
	assert(level < level_count);

	// set the current level
	current_level = level;

	// move the player
	player.setPosition(levels[current_level].getPlayerStart());

	// init the monsters
	monster_count = 0;
	assert(levels[current_level].getMonsterCount() <= MONSTER_COUNT_MAX);
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLUMNS; c++)
		{
			Position pos = toPosition(r, c);
			if (levels[current_level].getValue(pos) == MONSTER_START)
			{
				monsters[monster_count] = Monster(pos);
				monster_count++;
			}
		}
	assert(monster_count == levels[current_level].getMonsterCount());

	assert(invariant());
}

void Game :: tryMove (const Position& position)
{
	assert(invariant());

	for(unsigned int i = 0; i < monster_count; i++)
	{
		if(!monsters[i].isDead() &&
		   areEqual(position, monsters[i].getPosition()))
		{
			// player is attacking the monster
			monsters[i].receiveDamage(player.getDamage());
			if(monsters[i].isDead())
				player.increaseScore(monsters[i].getPoints());

			assert(invariant());
			return;
		}
	}

	if(isValid(position) && !levels[current_level].isWall(position))
	{
		// player made a valid move
		unsigned int cost = levels[current_level].getCost(position);
		player.increaseTotalMoveCost(cost);
		player.setPosition(position);

		// go to next level if needed
		if(current_level + 1 < level_count &&
		   levels[current_level].isGoalPosition(player.getPosition()))
		{
			goToLevel(current_level + 1);
			assert(current_level < level_count);
		}
	}
	else
	{
		// player made an invalid move
		// do nothing
	}

	assert(invariant());
}

bool Game :: invariant () const
{
	if(level_count > LEVEL_COUNT_MAX)
		return false;
	if(current_level >= level_count)
		return false;
	if(monster_count > MONSTER_COUNT_MAX)
		return false;
	return true;
}
