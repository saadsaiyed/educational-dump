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
//  LEVEL_COUNT_MAX
//
//  The maximum number of monsters that can be on a single
//    level.
//
const unsigned int LEVEL_COUNT_MAX = 20;

//
//  Game
//
//  A class to represent the current state of the game.
//
//  Class Invariant:
//    <1> level_count <= LEVEL_COUNT_MAX
//    <2> current_level < level_count
//    <3> monsters != NULL
//
class Game
{
public:
//
//  Default Constructor
//
//  Purpose: To create a new Game containing an empty level.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A new Game is created and initalized with
//               default values.
//
	Game ();

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
//  Copy Constructor
//
//  Purpose: To create a new Game as a copy of another.
//  Parameter(s):
//    <1> original: The Game to copy
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A new Game is created and set to contain deep
//               copies of the level, player, and monsters in
//               original.
//
	Game (const Game& original);

//
//  Destructor
//
//  Purpose: To safely destroy a Game.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: All dynamically allocated memory associated
//               with this Game is freed.
//
	~Game ();

//
//  Assignment Operator
//
//  Purpose: To modify this Game to be a copy of another.
//  Parameter(s):
//    <1> original: The Game to copy
//  Precondition(s): N/A
//  Returns: A reference to this Game.
//  Side Effect: All dynamically allocated memory associated
//               with this Game is freed.  Then this Game is set
//               to contain deep copies of the level, player,
//               and monsters in original.
//
	Game& operator= (const Game& original);

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
//  loadLevels
//
//  Purpose: To iniialize the monsters from the current Level.
//  Parameter(s):
//    <1> file_name: The name of the file to load
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The levels for this Game are loaded.
//
	void loadLevels (const std::string& file_name);

//
//  goToLevel
//
//  Purpose: To handle the setup for when the player begins a
//           level.
//  Parameter(s):
//    <1> level: Which level to begin
//  Precondition(s):
//    <1> level < level_count
//  Returns: N/A
//  Side Effect: The current level is set to level.  The player
//               is moved to the starting position.  All
//               monsters are initialized.
//
	void goToLevel (unsigned int current_level);

//
//  initMonsters
//
//  Purpose: To iniialize the monsters from the current Level.
//  Parameter(s): N/a
//  Precondition(s):
//    <1> monsters == NULL
//  Returns: N/A
//  Side Effect: The monsters are set to be at the starting
//               positions for the current level.
//
	void initMonsters ();

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
//  copyLevels
//
//  Purpose: To copy the levels from another Game to this one.
//  Parameter(s):
//    <1> original: The Game to copy the levels from
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The levels are set to be copies of the levels
//               in original.
//
	void copyLevels (const Game& original);

//
//  copyMonsters
//
//  Purpose: To copy the monsters from another Game to this one.
//  Parameter(s):
//    <1> original: The Game to copy the monsters from
//  Precondition(s):
//    <1> monsters == NULL
//  Returns: N/A
//  Side Effect: The monsters are set to be deep copies of the
//               monsters in original.
//
	void copyMonsters (const Game& original);

//
//  deleteMonsters
//
//  Purpose: To deallocate the monsters in this Game.
//  Parameter(s): N/A
//  Precondition(s):
//    <1> monsters != NULL
//  Returns: N/A
//  Side Effect: The dynamically allocated memory associated
//               with the monsters in this Game is freed.
//               monsters is set to NULL.
//
	void deleteMonsters ();

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
	Level levels[LEVEL_COUNT_MAX];
	unsigned int level_count;
	unsigned int current_level;
	Player player;
	Monster** monsters;
};
