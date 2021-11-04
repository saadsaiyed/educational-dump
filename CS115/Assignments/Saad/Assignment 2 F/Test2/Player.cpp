#include<iostream>
#include"Header.h"

#include"Monster.h"
#include"Player.h"
#include"Position.h"

using namespace std;

void playerInit(Player& player, const Position& start)
{
	player.health = STARTING_HEALTH_PLAYER;
	player.score = 0;
	player.position = start;
	player.damage = DAMAGE_PLAYER;
	player.total_move_cost = 0;
}

bool playerIsDead(const Player& player)
{
	if (player.health <= 0)
		return true;
	return false;
}

int playerGetHealth(const Player& player)
{
	return player.health;
}

int playerGetDamage(const Player& player)
{
	return player.damage;
}

unsigned int playerGetScore(const Player& player)
{
	return player.score;
}

unsigned int playerGetTotalMoveCost(const Player& player)
{
	return player.total_move_cost;
}

const Position& playerGetPosition(const Player& player)
{
	return player.position;
}

void playerSetPosition(Player& player, const Position& P)
{
	player.position = P;
}

void playerReceiveDamage(Player& player, int amount)
{
	player.health -= amount;
}

void playerIncreaseScore(Player& player, unsigned int amount)
{
	player.score += amount;
}

void playerIncreaseTotalMoveCost(Player& player, unsigned int amount)
{
	player.total_move_cost += amount;
}