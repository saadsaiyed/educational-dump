//
//  Player.h
//
//  Encapsulates a module to represent the player in a
//    grid-based game.
//

#pragma once

#include "Position.h"



class Player
{
public:
//
//  Constructor
//
//  Purpose: To create a Player at a specific position.
//  Parameter(s):
//    <1> start: The starting position for player
//  Precondition:
//    <1> isValid(start)
//  Returns: N/A
//  Side Effect: The new Player is initialized to have default
//               values and to be at position start.
//
	Player (const Position& start);

//
//  isDead
//
//  Purpose: To determine if this Player is dead.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether this Player is dead
//  Side Effect: N/A
//
	bool isDead () const;

//
//  getHealth
//
//  Purpose: To determine the current health of this Player.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: This Player's current health.
//  Side Effect: N/A
//
	int getHealth () const;

//
//  getDamage
//
//  Purpose: To determine how much damage this Player deals when
//           attacking.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: How much damage this Player deals when attacking.
//  Side Effect: N/A
//
	int getDamage () const;

//
//  getScore
//
//  Purpose: To determine the current score for this Player.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: This Player's current score.
//  Side Effect: N/A
//
	unsigned int getScore () const;

//
//  getTotalMoveCost
//
//  Purpose: To determine the total movement cost for this
//           Player.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: This Player's total movement cost.
//  Side Effect: N/A
//
	unsigned int getTotalMoveCost () const;

//
//  getPosition
//
//  Purpose: To determine the current position of this Player.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: This Player's current position.
//  Side Effect: N/A
//
	const Position& getPosition () const;

//
//  setPosition
//
//  Purpose: To change the current position of this Player.
//  Parameter(s):
//    <1> p: The new position
//  Precondition:
//    <1> isValid(p)
//  Returns: N/A
//  Side Effect: This Player player is set to have position p.
//
	void setPosition (const Position& p);
	
//
//  receiveDamage
//
//  Purpose: To reduce the current health of this Player.
//  Parameter(s):
//    <1> amount: The amount to reduce player's health by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: This Player takes damage, reducing its health
//               by amount.
//
	void receiveDamage (int amount);

//
//  increaseScore
//
//  Purpose: To increase the current score for this Player.
//  Parameter(s):
//    <1> amount: The amount to increase the current score by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current score of this Player is increased
//               by amount.
//
	void increaseScore (unsigned int amount);

//
//  increaseTotalMoveCost
//
//  Purpose: To increase the total move cost for this Player.
//  Parameter(s):
//    <1> amount: The amount to increase the total move cost by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The total move cost of this Player is increased
//               by amount.
//
	void increaseTotalMoveCost (unsigned int amount);

private:
    int health;
    int damage;
    Position position;
    unsigned int score;
    unsigned int total_cost;
};
