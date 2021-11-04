//
//  Player.h
//
//  Encapsulates a module to represent the player in a
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

#ifndef PLAYER_H
#define PLAYER_H

const unsigned int STARTING_HEALTH_PLAYER = 40;
const unsigned int DAMAGE_PLAYER = 2;

struct Player
{
	int health;
	int damage;
	Position position;
	unsigned int score;
	unsigned int total_move_cost;
};

//
//  playerInit
//
//  Purpose: To initialize a Player at a specific position.
//  Parameter(s):
//    <1> player: The Player to initialize
//    <2> start: The starting position for player
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: Player player is initialized to have default
//               values and to be at the position start.
//
void playerInit(Player& player, const Position& start);

//
//  playerIsDead
//
//  Purpose: To determine if a Player is dead.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: Whether Player player is dead
//  Side Effect: N/A
//
bool playerIsDead(const Player& player);//done

//
//  playerGetHealth
//
//  Purpose: To determine a Player's current health.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: Player player's current health.
//  Side Effect: N/A
//
int playerGetHealth(const Player& player);

//
//  playerGetDamage
//
//  Purpose: To determine how much damage a Player deals when
//           attacking.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: How much damage Player player deals when attacking.
//  Side Effect: N/A
//
int playerGetDamage(const Player& player);

//
//  playerGetScore
//
//  Purpose: To determine a Player's current score.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: Player player's current score.
//  Side Effect: N/A
//
unsigned int playerGetScore(const Player& player);

//
//  playerGetTotalMoveCost
//
//  Purpose: To determine a Player's total movement cost.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: Player player's total movement cost.
//  Side Effect: N/A
//
unsigned int playerGetTotalMoveCost(const Player& player);

//
//  playerGetPosition
//
//  Purpose: To determine a Player's current position.
//  Parameter(s):
//    <1> player: The Player to check
//  Precondition(s): N/A
//  Returns: Player player's current position.
//  Side Effect: N/A
//
const Position& playerGetPosition(const Player& player);

//
//  playerSetPosition
//
//  Purpose: To change a Player's current position.
//  Parameter(s):
//    <1> player: The Player to move
//    <2> p: The new position
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current position of Player player is set to
//               p.
//
void playerSetPosition(Player& player, const Position& p);

//
//  playerReceiveDamage
//
//  Purpose: To reduce a Player's health.
//  Parameter(s):
//    <1> player: The Player to damage
//    <2> amount: The amount to reduce player's health by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The health of Player player is reduced by
//               amount.
//
void playerReceiveDamage(Player& player, int amount);

//
//  playerIncreaseScore
//
//  Purpose: To increase a Player's current score.
//  Parameter(s):
//    <1> player: The Player to be modified.
//    <2> amount: The amount to increase player's current score
//                by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current score of Player player is increased
//               by amount.
//
void playerIncreaseScore(Player& player, unsigned int amount);

//
//  playerIncreaseTotalMoveCost
//
//  Purpose: To increase a Player's total move cost.
//  Parameter(s):
//    <1> player: The Player to be modified.
//    <2> amount: The amount to increase player's total move
//                cost by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The total move cost of Player player is
//               increased by amount.
//
void playerIncreaseTotalMoveCost(Player& player, unsigned int amount);

#endif