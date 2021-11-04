//
//  Player.h
//
//  Encapsulates a module to represent the player in a
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

#ifndef PLAYER_H
#define PLAYER_H
#include "Position.h"
const unsigned int STARTING_HEALTH_PLAYER = 40;
const unsigned int DAMAGE_PLAYER = 2;

class Player
{
private:
	int health;
	int damage;
	Position position;
	unsigned int score;
	unsigned int total_move_cost;
public:
	Player();
	//
	//  Player (constructor)
	//
	//  Purpose: To initialize a Player at a specific position.
	//  Parameter(s):
	//    <1> start: The starting position for player
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: Player player is initialized to have default
	//               values and to be at the position start.
	//
	Player(const Position& start);
	Player(const Player& original);
	~Player();
	Player& operator= (const Player& original);


	//
	//  playerIsDead
	//
	//  Purpose: To determine if a Player is dead.
	//  Parameter(s):
	//  Precondition(s): N/A
	//  Returns: Whether Player player is dead
	//  Side Effect: N/A
	//
	bool isDead() const;

	//
	//  playerGetHealth
	//
	//  Purpose: To determine a Player's current health.
	//  Parameter(s):
	//  Precondition(s): N/A
	//  Returns: Player player's current health.
	//  Side Effect: N/A
	//
	int getHealth() const;
	
	//
	//  playerGetDamage
	//
	//  Purpose: To determine how much damage a Player deals when
	//           attacking.
	//  Parameter(s):
	//  Precondition(s): N/A
	//  Returns: How much damage Player player deals when attacking.
	//  Side Effect: N/A
	//
	int getDamage() const;
	
	//
	//  playerGetScore
	//	
	//	Purpose: To determine a Player's current score.
	//	Parameter(s):
	//  Precondition(s): N/A
	//  Returns: Player player's current score.
	//	Side Effect: N/A
	//
	unsigned int getScore() const;
	
	//
	//  playerGetTotalMoveCost
	//
	//  Purpose: To determine a Player's total movement cost.
	//  Parameter(s):
	//  Precondition(s): N/A
	//  Returns: Player player's total movement cost.
	//  Side Effect: N/A
	//
	unsigned int getTotalMoveCost() const;
	
	//
	//  playerGetPosition
	//
	//  Purpose: To determine a Player's current position.
	//  Parameter(s):
	//  Precondition(s): N/A
	//  Returns: Player player's current position.
	//  Side Effect: N/A
	//
	const Position& getPosition() const;
	
	//
	//  playerSetPosition
	//
	//  Purpose: To change a Player's current position.
	//  Parameter(s):
	//    <1> p: The new position
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The current position of Player player is set to p.
	//
	void setPosition(const Position& );
	
	//
	//  playerReceiveDamage
	//
	//  Purpose: To reduce a Player's health.
	//  Parameter(s):
	//	  <1> amount: The amount to reduce player's health by
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The health of Player player is reduced by
	//               amount.
	//
	void receiveDamage(int amount);
		
	//
	//  playerIncreaseScore
	//
	//  Purpose: To increase a Player's current score.
	//  Parameter(s):
	//    <1> amount: The amount to increase player's current score
	//                by
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The current score of Player player is increased
	//               by amount.
	//
	void increaseScore(unsigned int amount);
		
	//
	//  playerIncreaseTotalMoveCost
	//
	//  Purpose: To increase a Player's total move cost.
	//  Parameter(s):
	//    <1> amount: The amount to increase player's total move
	//                cost by
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The total move cost of Player player is
	//               increased by amount.
	//
	void increaseTotalMoveCost(unsigned int amount);
};

#endif