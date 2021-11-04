//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//
/*
Name: Saad Saiyed
Course: CS 115
Assignment: 2
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19
*/
#ifndef MONSTER_H
#define MONSTER_H

const unsigned int STARTING_HEALTH_MONSTER	= 20;
const unsigned int DAMAGE_MONSTER			= 3;
const unsigned int POINTS_MONSTER			= 50;

struct Monster
{
	int health;
	int damage;
	Position position;
	unsigned int points ;
};

//
//  monsterInit
//
//  Purpose: To initialize a monster at a specific position.
//  Parameter(s):
//    <1> monster: The Monster to initialize
//    <2> start: The starting position for the monster
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster monster is initialized to have
//               default values and to be at position start.
//
void monsterInit(Monster& monster, const Position& start);

//
//  monsterIsDead
//
//  Purpose: To determine if a monster is dead.
//  Parameter(s):
//    <1> monster: The Monster to check
//  Precondition: N/A
//  Returns: Whether the Monster is dead.
//  Side Effect: N/A
//
bool monsterIsDead(const Monster& monster);

//
//  monsterGetDamage
//
//  Purpose: To determine how much damage a Monster deals when
//           attacking.
//  Parameter(s):
//    <1> monster: The Monster to check
//  Precondition: N/A
//  Returns: How much damage Monster monster deals when
//           attacking.
//  Side Effect: N/A
//
int monsterGetDamage(const Monster& monster);

//
//  monsterGetPoints
//
//  Purpose: To determine how many points are awarded for
//           killing a monster.
//  Parameter(s):
//    <1> monster: The Monster to check
//  Precondition: N/A
//  Returns: How many points are awarded for killing Monster
//           monster.
//  Side Effect: N/A
//
unsigned int monsterGetPoints(const Monster& monster);

//
//  monsterGetPosition
//
//  Purpose: To determine a Monster's current position.
//  Parameter(s):
//    <1> monster: The Monster to check
//  Precondition: N/A
//  Returns: Monster monster's current position.
//  Side Effect: N/A
//
const Position& monsterGetPosition(const Monster& monster);

//
//  monsterSetPosition
//
//  Purpose: To change a Monster's current position.
//  Parameter(s):
//    <1> monster: The Monster to move
//    <2> p: The new position
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The current position of Monster monster is set
//               to p.
//
void monsterSetPosition(Monster& monster, const Position& p);

//
//  monsterReceiveDamage
//
//  Purpose: To reduce an Monster's health.
//  Parameter(s):
//    <1> monster: The Monster to damage
//    <2> amount: The amount to reduce the Monster's health by
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: Monster monster's health is reduced by amount.
//
void monsterReceiveDamage(Monster& monster,	int amount);

//
//  monsterCalculateMove
//
//  Purpose: To calculate a monster's next move in the game.
//  Parameter(s):
//    <1> monster: The Monster to calculate the move for
//    <2> player_position: The player's current position
//  Precondition: N/A
//  Returns: The new position for Monster monster.  If this is
//           the same as the player's position, monster is
//           attacking the player instead of moving.
//  Side Effect: N/A
//
Position monsterCalculateMove(const Monster& monster, const Position& player_position);
#endif