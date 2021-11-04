#include <cassert>
#include <iostream>
#include"Player.h"

using namespace std;

Player::Player()
{
	health = 0;
	damage = 0;
	position.row = 1;
	position.column = 1;
	score = 0;
	total_move_cost = 0;
}

Player::Player(const Position& start)
{
	assert(isValid(start));

	health = STARTING_HEALTH_PLAYER;
	score = 0;
	position = start;
	damage = DAMAGE_PLAYER;
	total_move_cost = 0;
}

Player::Player(const Player& original)
{
	this->health = original.health;
	this->damage = original.damage;
	this->score = original.score;
	this->position = original.position;
	this->total_move_cost = original.total_move_cost;
}

Player::~Player()
{

}

Player& Player::operator= (const Player& original)
{
	if (this != &original)
	{
		this->health = original.health;
		this->damage = original.damage;
		this->score = original.score;
		this->position = original.position;
		this->total_move_cost = original.total_move_cost;
	}
	return *this;
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
	assert(isValid(P));
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