#include <iostream>
#include"Header.h"

#include"Monster.h"
#include"Position.h"

using namespace std;

void monsterInit(Monster& monster, const Position& start)
{
	monster.health = STARTING_HEALTH_MONSTER;
	monster.damage = DAMAGE_MONSTER;
	monster.points = POINTS_MONSTER;
	monster.position = start;
}

bool monsterIsDead(const Monster& monster)
{
	if (monster.health <= 0)
		return true;
	return false;
}

int monsterGetDamage(const Monster& monster)
{
	return monster.damage;
}

unsigned int monsterGetPoints(const Monster& monster)
{
	return monster.points;
}

const Position& monsterGetPosition(const Monster& monster)
{
	return monster.position;
}

void monsterSetPosition(Monster& monster, const Position& p)
{
	monster.position = p;
}

void monsterReceiveDamage(Monster& monster, int amount)
{
	monster.health -= amount;
}

Position monsterCalculateMove(const Monster& monster, const Position& player_position)
{
	double direction[4];
	Position x;								//this is a struct just to change values of rows and columns

	x = monster.position;
	x.row++;
	direction[0] = calculateDistance(x, player_position);
	
	
	x = monster.position;
	x.row--;
	direction[1] = calculateDistance(x, player_position);
	
	
	x = monster.position;
	x.column++;
	direction[2] = calculateDistance(x, player_position);
	
	
	x = monster.position;
	x.column--;
	direction[3] = calculateDistance(x, player_position);
	
	
	
	double min = direction[0];

	for (int i = 0; i < 4; i++)
	{
		if (min > direction[i])
			min = direction[i];
	}

	x = monster.position;
	
	if (min == direction[0])
		x.row++;
	else if (min == direction[1])
		x.row--;
	else if (min == direction[2])
		x.column++;
	else if (min == direction[3])
		x.column--;

	return x;
}