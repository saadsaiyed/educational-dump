//
//  Monster.cpp
//

#include "Position.h"
#include "Monster.h"

 static const          int STARTING_HEALTH = 20;
 static const          int DAMAGE          =  3;
 static const unsigned int POINTS          = 50;



void monsterInit (Monster& monster,
                  const Position& start)
{
	monster.health   = STARTING_HEALTH;
	monster.damage   = DAMAGE;
	monster.position = start;
	monster.points   = POINTS;
}



bool monsterIsDead (const Monster& monster)
{
	if(monster.health <= 0)
		return true;
	return false;
}

int monsterGetDamage (const Monster& monster)
{
	return monster.damage;
}

unsigned int monsterGetPoints (const Monster& monster)
{
	return monster.points;
}

const Position& monsterGetPosition (const Monster& monster)
{
	return monster.position;
}



void monsterSetPosition (Monster& monster,
                         const Position& p)
{
	monster.position = p;
}

void monsterReceiveDamage (Monster& monster,
                           int amount)
{
	monster.health = monster.health - amount;
}

Position monsterCalculateMove (const Monster& monster,
                               const Position& player_position)
{
	const double VERY_FAR = 1.0e40;

	// calculate possible moves

	Position north = monster.position;
	north.row--;
	Position south = monster.position;
	south.row++;
	Position east = monster.position;
	east.column++;
	Position west = monster.position;
	west.column--;

	// calculate distances

	double current_distance  = calculateDistance(monster.position, player_position);
	double north_distance    = calculateDistance(north,            player_position);
	double south_distance    = calculateDistance(south,            player_position);
	double east_distance     = calculateDistance(east,             player_position);
	double west_distance     = calculateDistance(west,             player_position);

	// forbid invalid moves

	if(!isValid(north))
		north_distance = VERY_FAR;
	if(!isValid(south))
		south_distance = VERY_FAR;
	if(!isValid(east))
		east_distance = VERY_FAR;
	if(!isValid(west))
		west_distance = VERY_FAR;

	// choose best move

	if(north_distance <  south_distance &&
	   north_distance <= east_distance  &&
	   north_distance <= west_distance  &&
	   north_distance <  current_distance)
	{
		return north;
	}
	else if(south_distance <= east_distance &&
	        south_distance <= west_distance &&
	        south_distance <  current_distance)
	{
		return south;
	}
	else if(east_distance < west_distance &&
	        east_distance < current_distance)
	{
		return east;
	}
	else if(west_distance < current_distance)
	{
		return west;
	}
	else  // current_distance is smaller than all others
	{
		// stay at current position
		return monster.position;
	}
}

