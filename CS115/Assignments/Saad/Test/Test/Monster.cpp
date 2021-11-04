#include <cassert>

#include"Monster.h"
#include"Game.h"

using namespace std;

Monster::Monster()
{
	health = 0;
	damage = 0;
	points = 0;
	position = toPosition(0, 0);
}

Monster::Monster(const Position& start)
{
	assert(isValid(start));

	health = STARTING_HEALTH_MONSTER;
	damage = DAMAGE_MONSTER;
	points = POINTS_MONSTER;
	position = start;
}	

Monster::Monster(const Monster& original)
{
	this->health = original.health;
	this->damage = original.health;
	this->points = original.points;
	this->position = original.position;
}

Monster::~Monster()
{

}

Monster& Monster::operator= (const Monster& original)
{
	if (this != &original)
	{
		this->health = original.health;
		this->damage = original.health;
		this->points = original.points;
		this->position = original.position;
	}
	return *this;
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

Position Monster::calculateToPosition(const Game& game, const Position& target_position) const
{
	const double DONT_GO_THERE = 1.0e40;

	// calculate possible moves

	Position north = position;
	north.row--;
	Position south = position;
	south.row++;
	Position east = position;
	east.column++;
	Position west = position;
	west.column--;

	// calculate distances

	double here_distance = calculateDistance(position, target_position);
	double north_distance = calculateDistance(north, target_position);
	double south_distance = calculateDistance(south, target_position);
	double east_distance = calculateDistance(east, target_position);
	double west_distance = calculateDistance(west, target_position);

	// forbid invalid moves

	if (!isValid(north) || game.isBlockedForMonster(north))
		north_distance = DONT_GO_THERE;
	if (!isValid(south) || game.isBlockedForMonster(south))
		south_distance = DONT_GO_THERE;
	if (!isValid(east) || game.isBlockedForMonster(east))
		east_distance = DONT_GO_THERE;
	if (!isValid(west) || game.isBlockedForMonster(west))
		west_distance = DONT_GO_THERE;

	// choose best move

	if (north_distance < south_distance &&
		north_distance <= east_distance &&
		north_distance <= west_distance &&
		north_distance < here_distance)
	{
		return north;
	}
	else if (south_distance <= east_distance &&
		south_distance <= west_distance &&
		south_distance < here_distance)
	{
		return south;
	}
	else if (east_distance < west_distance &&
		east_distance < here_distance)
	{
		return east;
	}
	else if (west_distance < here_distance)
	{
		return west;
	}
	else
	{
		return position;
	}
}