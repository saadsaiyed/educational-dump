//
//  Level.h
//
//  For the CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//

#pragma once

#include <string>
using namespace std;

#include "Position.h"

const unsigned int ROWS    = 20;
const unsigned int COLUMNS = 60;

const unsigned int EMPTY          = 0;
const unsigned int ROCKY          = 1;
const unsigned int ROUGH          = 2;
const unsigned int WALL           = 3;
const unsigned int PLAYER_START   = 4;
const unsigned int PLAYER_GOAL    = 5;
const unsigned int MONSTER_START  = 6;
const unsigned int ATTACKER_START = 7;
const unsigned int DRONE_START    = 8;



class Level
{
public:
//
//  Constructor
//
//  Purpose: To load a Level from the file with the specified
//           file name.
//  Parameter(s):
//    <1> file_name: The name of the file to load
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The contents of file file_name are loaded and
//               stored in the new Level.
//
	Level (const string& file_name);

//
//  getMonsterStart
//
//  Purpose: To determine the starting position of the monster.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The monster's starting position.  If there is more
//           than one monster, the same one is always returned.
//           If there are no monsters, (0, 0) is returned.
//  Side Effect: N/A
//
	Position getMonsterStart () const;

//
//  getPlayerStart
//
//  Purpose: To determine the starting position of the player.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The player's starting position.  If there is no
//           starting position, (0, 0) is returned.
//  Side Effect: N/A
//
	Position getPlayerStart () const;

//
//  getCost
//
//  Purpose: To determine the move cost for this Level at the
//           specified position.
//  Parameter(s):
//    <1> position: The position to check
//  Precondition(s):
//    <1> isValid(position)
//  Returns: The move cost to enter Position position.
//  Side Effect: N/A
//
	unsigned int getCost (const Position& position) const;

//
//  isWall
//
//  Purpose: To determine whether there is a wall in this Level
//           at the specified position.
//  Parameter(s):
//    <1> position: The position to check
//  Precondition(s):
//    <1> isValid(position)
//  Returns: Whether Position position in this Level is a wall.
//  Side Effect: N/A
//
	bool isWall (const Position& position) const;

//
//  print
//
//  Purpose: To display this Level, including the player and
//           monster positions.
//  Parameter(s):
//    <1> monster_position: The position to check
//    <2> player_position: The position to check
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: This level is displayed.  If monster_position
//               is valid, an 'M' is displayed instead of the
//               terrain there.  Otherwise, if player_position
//               is valid, an '@' is displayed instead of the
//               terrain there.
//
	void print (const Position& monster_position, 
	            const Position& player_position) const;

private:
	unsigned int terrain[ROWS][COLUMNS];
};
