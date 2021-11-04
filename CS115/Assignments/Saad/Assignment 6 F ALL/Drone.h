#pragma once
#ifndef DRONE_H
#define DRONE_H

#include "Monster.h"

class Drone : public Monster
{
private:

	char facingDirection = 'N';

public:

	Drone();

	Drone(const Position& start);

	Drone(const Drone& original);

	virtual ~Drone();

	Drone& operator= (const Drone& original);

	virtual char getDisplayChar() const;

	virtual Monster* getClone() const;

	virtual Position calculateMove(const Game& game, const Position& player_position);
};

#endif // !Drone_H
