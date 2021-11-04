#include "Sentry.h"


Sentry::Sentry():Monster()
{
	this->damage = 3;
	this->health = 20;
	this->points = 50;
	this->startingPosition = this->getPosition();
}

Sentry::Sentry(const Position& start) : Monster(start)
{
	this->damage = 3;
	this->health = 20;
	this->points = 50;
	this->startingPosition = this->getPosition();
}

Sentry::Sentry(const Sentry& original) : Monster(original)
{
	this->startingPosition = this->getPosition();
}

Sentry::~Sentry()
{

}

Sentry& Sentry::operator= (const Sentry& original)
{
	if(this != &original)
	{
		this->damage = original.damage;
		this->health = original.health;
		this->points = original.points;
		this->setPosition(original.getPosition());
		this->startingPosition = this->getPosition();
	}
	return *this;
}

char Sentry::getDisplayChar() const
{
	return 'S';
}

Monster* Sentry::getClone() const
{
	return new Sentry(*this);
}

Position Sentry::calculateMove(const Game& game, const Position& player_position)
{
	if ((calculateDistance(player_position, this->getPosition()) + calculateDistance(startingPosition, this->getPosition()) > 6))
		return calculateToPosition(game, startingPosition);
	
	return calculateToPosition(game, player_position);
}