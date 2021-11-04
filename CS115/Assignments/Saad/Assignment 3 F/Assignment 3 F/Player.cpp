#include<iostream>
#include"Level.h"

#include"Monster.h"
#include"Player.h"
#include"Position.h"

using namespace std;

Player::Player(const Position& start)
{
	health = STARTING_HEALTH_PLAYER;
	score = 0;
	position = start;
	damage = DAMAGE_PLAYER;
	total_move_cost = 0;
}

bool Player::isDead() const
{
	if (health <= 0)
		return true;
	return false;
}

int Player::getHealth( )const
{
	return health;
}

int Player::getDamage()const
{
	return damage;
}

unsigned int Player::getScore()const
{
	return score;
}

unsigned int Player::getTotalMoveCost()const
{
	return total_move_cost;
}

const Position& Player::getPosition()const
{
	return position;
}

void Player::setPosition(const Position& P)
{
	position = P;
}

void Player::receiveDamage(int amount)
{
	health -= amount;
}

void Player::increaseScore(unsigned int amount)
{
	score += amount;
}

void Player::increaseTotalMoveCost(unsigned int amount)
{
	total_move_cost += amount;
}