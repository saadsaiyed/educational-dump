//
//  Player.cpp
//

#include "Position.h"
#include "Level.h"
#include "Player.h"

 static const unsigned int STARTING_HEALTH = 40;
 static const          int DAMAGE          =  2;



void playerInit (Player& player, const Position& start)
{
	player.health = STARTING_HEALTH;
	player.damage = DAMAGE;
	player.position = start;
	player.score = 0;
	player.total_move_cost = 0;
}



bool playerIsDead (const Player& player)
{
	if(player.health <= 0)
		return true;
	return false;
}

int playerGetHealth (const Player& player)
{
	return player.health;
}

int playerGetDamage (const Player& player)
{
	return player.damage;
}

unsigned int playerGetScore (const Player& player)
{
	return player.score;
}

unsigned int playerGetTotalMoveCost (const Player& player)
{
	return player.total_move_cost;
}

const Position& playerGetPosition (const Player& player)
{
	return player.position;
}



void playerSetPosition (Player& player, const Position& p)
{
	player.position = p;
}

void playerReceiveDamage (Player& player,
                          int amount)
{
	player.health = player.health - amount;
}

void playerIncreaseScore (Player& player,
                          unsigned int amount)
{
	player.score = player.score + amount;
}

void playerIncreaseTotalMoveCost (Player& player,
                                  unsigned int amount)
{
	player.total_move_cost = player.total_move_cost + amount;
}
