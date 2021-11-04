#include "Attacker.h"
#include "Game.h"


Attacker::Attacker() : Monster()
{
	this->damage = 2;
	this->health = 10;
	this->points = 20;
}

Attacker::Attacker(const Position& start) : Monster(start)
{
	this->damage = 2;
	this->health = 10;
	this->points = 20;
}

Attacker::Attacker(const Attacker& original) : Monster(original)
{
}

Attacker::~Attacker()
{

}

Attacker& Attacker::operator= (const Attacker& original)
{
	if(this != &original)
	{
		this->damage = original.damage;
		this->health = original.health;
		this->points = original.points;
		this->setPosition(original.getPosition());
	}
	return *this;
}

char Attacker::getDisplayChar() const
{
	return 'A';
}

Monster* Attacker::getClone() const
{
	return new Attacker(*this);
}

Position Attacker::calculateMove(const Game& game, const Position& player_position)
{
	return calculateToPosition(game, player_position);
}