//
//  Monster.cpp
//

#include <cassert>
#include <iostream>

#include "Position.h"
#include "Game.h"
#include "Monster.h"

using namespace std;

static const          int STARTING_HEALTH = 20;
static const          int DAMAGE          =  3;
static const unsigned int POINTS          = 50;

static const bool DEBUGGING_MONSTER_ALLOCATION = false;
static int allocated = 0;



Monster :: Monster ()
		: health(0),
		  damage(DAMAGE),
		  position(toPosition(0, 0)),
		  points(POINTS)
{
	allocated++;
	if(DEBUGGING_MONSTER_ALLOCATION)
		cout << "Default constructor: now " << allocated << " monsters allocated" << endl;
}

Monster :: Monster (const Position& start)
		: health(STARTING_HEALTH),
		  damage(DAMAGE),
		  position(start),
		  points(POINTS)
{
	assert(isValid(start));

	allocated++;
	if(DEBUGGING_MONSTER_ALLOCATION)
		cout << "Constructor: now " << allocated << " monsters allocated" << endl;
}

// put in Monster copy constructor to test memory allocations
//	allocated++;
//	if(DEBUGGING_MONSTER_ALLOCATION)
//		cout << "Copy Constructor: now " << allocated << " monsters allocated" << endl;

// put in Monster destructor to test memory allocations
//	allocated--;
//	if(DEBUGGING_MONSTER_ALLOCATION)
//		cout << "Destructor: now " << allocated << " monsters allocated" << endl;



bool Monster :: isDead () const
{
	if(health <= 0)
		return true;
	return false;
}

int Monster :: getDamage () const
{
	return damage;
}

unsigned int Monster :: getPoints () const
{
	return points;
}

const Position& Monster :: getPosition () const
{
	return position;
}



void Monster :: setPosition (const Position& p)
{
	assert(isValid(p));

	position = p;
}

void Monster :: receiveDamage (int amount)
{
	health = health - amount;
}

Position Monster :: calculateMove (const Game& game,
                                   const Position& player_position) const
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

	double here_distance  = calculateDistance(position, player_position);
	double north_distance = calculateDistance(north,    player_position);
	double south_distance = calculateDistance(south,    player_position);
	double east_distance  = calculateDistance(east,     player_position);
	double west_distance  = calculateDistance(west,     player_position);

	// forbid invalid moves

	if(!isValid(north) || game.isBlockedForMonster(north))
		north_distance = DONT_GO_THERE;
	if(!isValid(south) || game.isBlockedForMonster(south))
		south_distance = DONT_GO_THERE;
	if(!isValid(east)  || game.isBlockedForMonster(east))
		east_distance = DONT_GO_THERE;
	if(!isValid(west)  || game.isBlockedForMonster(west))
		west_distance = DONT_GO_THERE;

	// choose best move

	if(north_distance <  south_distance &&
	   north_distance <= east_distance  &&
	   north_distance <= west_distance  &&
	   north_distance <  here_distance)
	{
		return north;
	}
	else if(south_distance <= east_distance &&
	        south_distance <= west_distance &&
	        south_distance <  here_distance)
	{
		return south;
	}
	else if(east_distance < west_distance &&
	        east_distance < here_distance)
	{
		return east;
	}
	else if(west_distance < here_distance)
	{
		return west;
	}
	else
	{
		// all moves are bad; stay at current position
		return position;
	}
}

