#include "Drone.h"
#include "Game.h"

Drone::Drone() : Monster()
{
	this->damage = 5;
	this->health = 50;
	this->points = 10;	
	facingDirection = 'N';
}

Drone::Drone(const Position& start) : Monster(start)
{
	this->damage = 5;
	this->health = 50;
	this->points = 10;
	facingDirection = 'N';
}

Drone::Drone(const Drone& original) : Monster(original)
{
	facingDirection = original.facingDirection;
}

Drone::~Drone()
{

}

Drone& Drone::operator= (const Drone& original)
{
	if (this != &original)
	{
		this->damage = original.damage;
		this->health = original.health;
		this->points = original.points;
		this->facingDirection = original.facingDirection;
		this->setPosition(original.getPosition());
	}
	return *this;
}

char Drone::getDisplayChar() const
{
	return 'D';
}

Monster* Drone::getClone() const
{
	return new Drone(*this);
}

Position Drone::calculateMove(const Game& game, const Position& player_position)
{
	Position tempPosition;

	if (facingDirection == 'N')
	{
		tempPosition = toPosition(getPosition().row - 1, getPosition().column);

		if (!game.isBlockedForMonster(tempPosition) )
			return tempPosition;
		else
			facingDirection = 'E';
	}
	else if(facingDirection == 'E')
	{
		tempPosition = toPosition(getPosition().row, getPosition().column + 1);

		if (!game.isBlockedForMonster(tempPosition) )
			return tempPosition;
		else
			facingDirection = 'S';
	}
	else if(facingDirection == 'S')
	{
		tempPosition = toPosition(getPosition().row + 1, getPosition().column);

		if (!game.isBlockedForMonster(tempPosition) )
			return tempPosition;
		else
			facingDirection = 'W';
	}
	else if(facingDirection == 'W')
	{
		tempPosition = toPosition(getPosition().row, getPosition().column - 1);

		if (!game.isBlockedForMonster(tempPosition) )
			return tempPosition;
		else
			facingDirection = 'N';
	}
	return getPosition();
}