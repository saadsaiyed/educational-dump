#include <cassert>

#include"Monster.h"
#include"Game.h"

using namespace std;

Monster::Monster()
{
	health = 0;
}

Monster::Monster(const Position& start)
{
	assert(isValid(start));

	health = STARTING_HEALTH_MONSTER;
	damage = DAMAGE_MONSTER;
	points = POINTS_MONSTER;
	position = start;
}	

bool Monster::isDead()const
{
	if (health <= 0)
		return true;
	return false;
}

int Monster::getDamage()const
{
	return damage;
}

int Monster::getHealth()const
{
	return health;
}

unsigned int Monster::getPoints()const
{
	return points;
}

const Position& Monster::getPosition()const
{
	return position;
}

void Monster::setPosition(const Position& p)
{
	assert(isValid(p));

	position = p;
}

void Monster::receiveDamage(int amount)
{
	health -= amount;
}

Position Monster::calculateMove(const Position& player_position, const Game& map)const
{
	Position direction[4];
	double DONT_GO_THERE = 1.0e40;

	direction[0] = position;
	direction[0].row--;//north

	direction[1] = position;
	direction[1].row++;//south

	direction[2] = position;
	direction[2].column++;//east

	direction[3] = position;
	direction[3].column--;//west

	double north, south, east, west, current;

	current = calculateDistance(position, player_position);
	north = calculateDistance(direction[0], player_position);
	south = calculateDistance(direction[1], player_position);
	east = calculateDistance(direction[2], player_position);
	west = calculateDistance(direction[3], player_position);

	if (!isValid(direction[0]) || map.isBlockedForMonster(direction[0]))
		north = DONT_GO_THERE;
	if (!isValid(direction[1]) || map.isBlockedForMonster(direction[1]))
		south = DONT_GO_THERE;
	if (!isValid(direction[2]) || map.isBlockedForMonster(direction[2]))
		east = DONT_GO_THERE;
	if (!isValid(direction[3]) || map.isBlockedForMonster(direction[3]))
		west = DONT_GO_THERE;

	if (north < south &&
		north <= east &&
		north <= west &&
		north < current)
	{
		return direction[0];
	}
	else if (south <= east &&
		south <= west &&
		south < current)
	{
		return direction[1];
	}
	else if (east < west &&
		east < current)
	{
		return direction[2];
	}
	else if (west < current)
	{
		return direction[3];
	}
	else
		return player_position;
}