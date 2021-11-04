#pragma once
#ifndef SENTRY_H
#define SENTRY_H

#include "Monster.h"

class Sentry : public Monster
{
private:

	Position startingPosition;

public:
	Sentry();

	Sentry(const Position& start);

	Sentry(const Sentry& original);

	virtual ~Sentry();

	Sentry& operator= (const Sentry& original);

	virtual char getDisplayChar() const;

	virtual Monster* getClone() const;

	virtual Position calculateMove(const Game& game, const Position& player_position);
};

#endif // !Sentry_H
