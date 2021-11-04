//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Position.h"

class Monster
{
public:
//
//  Default Constructor
//
//  Purpose: To create a dead Monster.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: A new Monster is initialized to have 0 health
//               at position (0, 0).
//
	Monster ();

//
//  Constructor
//
//  Purpose: To create a Monster at a specific position.
//  Parameter(s):
//    <1> start: The starting position for the monster
//  Precondition:
//    <1> isValid(start)
//  Returns: N/A
//  Side Effect: A new Monster is initialized to have default
//               values and be at position start.
//
	Monster (const Position& start);

//
//  isDead
//
//  Purpose: To determine if this Monster is dead.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: Whether this Monster is dead.
//  Side Effect: N/A
//
	bool isDead () const;

//
//  getDamage
//
//  Purpose: To determine how much damage this Monster deals
//           when attacking.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: How much damage this Monster deals when attacking.
//  Side Effect: N/A
//
	int getDamage () const;

//
//  getPoints
//
//  Purpose: To determine how many points the player gets for
//           killing this Monster.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: How many points are awarded for killing this
//           Monster.
//  Side Effect: N/A
//
	unsigned int getPoints () const;

//
//  getPosition
//
//  Purpose: To determine current position of this Monster.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: This Monster's current position.
//  Side Effect: N/A
//
	const Position& getPosition () const;

//
//  setPosition
//
//  Purpose: To change a Monster's current position.
//  Parameter(s):
//    <1> p: The new position
//  Precondition:
//    <1> isValid(start)
//  Returns: N/A
//  Side Effect: This Monster is set to be at position p.
//
	void setPosition (const Position& p);

//
//  receiveDamage
//
//  Purpose: To reduce the current health of this Monster.
//  Parameter(s):
//    <1> amount: The amount to reduce the Monster's health by
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: This Monster's health is reduced by amount.
//
	void receiveDamage (int amount);

//
//  calculateMove
//
//  Purpose: To calculate this Monster's next move.
//  Parameter(s):
//    <1> level: The Level that this Monster is moving around in
//    <2> player_position: The player's current position
//  Precondition: N/A
//  Returns: The new position for this Monster.  If this is the
//           same as player_position, this Monster is attacking
//           the player instead of moving.
//  Side Effect: N/A
//
	Position calculateMove (
	                     const Level& level,
	                     const Position& player_position) const;

private:
    int health;
    int damage;
    Position position;
    unsigned int points;
};



#endif
