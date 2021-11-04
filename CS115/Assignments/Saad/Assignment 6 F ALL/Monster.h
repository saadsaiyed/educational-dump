//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//
/*
Name: Saad Saiyed
Course: CS 115
Assignment: 3
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19
*/
#ifndef MONSTER_H
#define MONSTER_H

#include "Position.h"
#include "Level.h"
const unsigned int STARTING_HEALTH_MONSTER	= 20;
const unsigned int DAMAGE_MONSTER			= 3;
const unsigned int POINTS_MONSTER			= 50;

class Game;

class Monster
{
private:
	Position position;

protected:
	int health;
	int damage;
	unsigned int points;
	//
	//  calculateToPosition
	//
	//  Purpose: To calculate a monster's next move in the game.
	//  Parameter(s):
	//    <1> player_position: The player's current position
	//  Precondition: N/A
	//  Returns: The new position for Monster monster.  If this is
	//           the same as the player's position, monster is
	//           attacking the player instead of moving.
	//  Side Effect: N/A
	//
	Position calculateToPosition(const Game& game, const Position& target_position) const;

public:
	Monster();
	//
	//  Monster (constructor)
	//
	//  Purpose: To initialize a monster at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for the monster
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The Monster monster is initialized to have
	//               default values and to be at position start.
	//
	Monster(const Position& start);

	Monster(const Monster& original);
	
	virtual ~Monster();

	Monster& operator= (const Monster& original);

	//
	//  isDead
	//
	//  Purpose: To determine if a monster is dead.
	//  Parameter(s):
	//  Precondition: N/A
	//  Returns: Whether the Monster is dead.
	//  Side Effect: N/A
	//
	bool isDead() const;
	//
	//  getDamage
	//
	//  Purpose: To determine how much damage a Monster deals when
	//           attacking.
	//  Parameter(s):
	//  Precondition: N/A
	//  Returns: How much damage Monster monster deals when
	//           attacking.
	//  Side Effect: N/A
	//
	int getDamage() const;
	//
	//  getHealth
	//
	//  Purpose: To determine how much health is left.
	//  Parameter(s):
	//  Precondition: N/A
	//  Returns: Health of Monster
	//  Side Effect: N/A
	//
	int getHealth() const;
	//
	//  getPoints
	//
	//  Purpose: To determine how many points are awarded for
	//           killing a monster.
	//  Parameter(s):
	//  Precondition: N/A
	//  Returns: How many points are awarded for killing Monster
	//           monster.
	//  Side Effect: N/A
	//
	unsigned int getPoints() const;
	//
	//  getPosition
	//
	//  Purpose: To determine a Monster's current position.
	//  Parameter(s):
	//  Precondition: N/A
	//  Returns: Monster monster's current position.
	//  Side Effect: N/A
	//
	const Position& getPosition() const;

	virtual char getDisplayChar() const = 0;

	virtual Monster* getClone() const = 0;
	//
	//  setPosition
	//
	//  Purpose: To change a Monster's current position.
	//  Parameter(s):
	//    <1> p: The new position
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: The current position of Monster monster is set
	//               to p.
	//
	void setPosition(const Position& p);
	//
	//  receiveDamage
	//
	//  Purpose: To reduce an Monster's health.
	//  Parameter(s):
	//    <1> amount: The amount to reduce the Monster's health by
	//  Precondition: N/A
	//  Returns: N/A
	//  Side Effect: Monster monster's health is reduced by amount.
	//
	void receiveDamage(int amount);

	virtual Position calculateMove(const Game& game, const Position& player_position) = 0;
};

#endif