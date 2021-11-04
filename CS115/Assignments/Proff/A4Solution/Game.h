//
//  Game.h
//

#pragma once

#include <string>

#include "Position.h"
#include "Level.h"
#include "Player.h"
#include "Monster.h"



//
//  MONSTER_COUNT_MAX
//
//  The maximum number of monsters that can be on a single
//    level.
//
const unsigned int MONSTER_COUNT_MAX = 100;



//
//  Game
//
//  A class to represent the current state of the game.
//
//  Class Invariant:
//    <1> monster_count <= MONSTER_COUNT_MAX
//
class Game
{
public:
//
//  Constructor
//
//  Purpose: To create a new Game based on the level file with
//           the specified name.
//  Parameter(s):
//    <1> file_name: The name of the file to load
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A new Game is created and initalized based on
//               file file_name.
//
	Game (const std::string& file_name);

//
//  isOver
//
//  Purpose: To determine whether this Game is over.  The game
//           is over of the player is dead or has reached the
//           goal position.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether this Game is over.
//  Side Effect: N/A
//
	bool isOver () const;

//
//  print
//
//  Purpose: To display the current state of the game.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current level is displayed, including the
//               current postions of the player and any living
//               monsters.  The player's current health, score,
//               and move cost so far is printed below.
//
	void print () const;

//
//  tryMoveNorth
//  tryMoveSouth
//  tryMoveEast
//  tryMoveWest
//
//  Purpose: To attempt to move the player in the indicated
//           direction.  This function does not move the
//           monsters.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: If there is a monster in the indicated
//               direction, the player attacks it.  Otherwise,
//               if the position in that direction is valid and
//               not a wall, the player moves there.  Otherwise,
//               there is no effect.
//
	void tryMoveNorth ();
	void tryMoveSouth ();
	void tryMoveEast ();
	void tryMoveWest ();

//
//  updateMonsters
//
//  Purpose: To updare the monsters for one move.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: Each monster is updated once.  They may move
//               and the player may be attacked.
//
	void updateMonsters ();

//
//  isBlockedForMonster
//
//  Purpose: To determine whether the specified position is
//           impassible to a monster.  A position is impassible
//           if it is a wall or there is a monster there.  The
//           player position does not count as impassible
//           because the monster can attack the player.
//  Parameter(s):
//    <1> position: The position to check
//  Precondition(s):
//    <1> isValid(position)
//  Returns: Whether Position position is blocked.
//  Side Effect: N/A
//
	bool isBlockedForMonster (const Position& position) const;

private:
//
//  tryMove
//
//  Purpose: To attempt to move the player to the indicated
//           position.  This function does not move the
//           monsters.
//  Parameter(s):
//    <1> position: The position to check
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: If there is a monster at position position,
//               the player attacks it.  Otherwise, if position
//               position is valid and not a wall, the player
//               moves there.  Otherwise, there is no effect.
//
	void tryMove (const Position& position);

//
//  invariant
//
//  Purpose: To determine if the class invariant is true.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the class invariant is true.
//  Side Effect: N/A
//
	bool invariant () const;

private:
	Level level;
	Player player;
	Monster monsters[MONSTER_COUNT_MAX];
};
