/*
Name: Saad Saiyed
Course: CS 115
Assignment: 4
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19

This program deals with two dimensional arrays and class to run an ASCII value game of Monster and Player where,
Monster moves towards Player and user needs to handle Player.
*/
#ifndef GAME_H
#define GAME_H
 
#include"Level.h"
#include"Monster.h"
#include"Player.h"
#include"Position.h"


const char INPUT_TERRAIN_TYPE[9] = { '.', '^', ':', '#', 'P', '*', 'S', 'A', 'D' };
const unsigned int MONSTER_COUNT_MAX = 100;

class Game
{
private:
	Level level;
	Player player;
	Monster monster[MONSTER_COUNT_MAX];
	void tryMove(Position& tempPlayerPosition);

public:
	//The Game constructor invokes the constructors of its Level, Player, and Monster fields.
	Game(const string& file_name);
	//The game is over if the player is dead.
	bool isOver() const;
	//The print function prints the whole map and also the player's current health, score, and total move cost.
	void print() const;
	//The tryMoveNorth function should attempt to move the player to the north.
	void tryMoveNorth();
	void tryMoveSouth();
	void tryMoveEast();
	void tryMoveWest();
	//The updateMonsters function makes the monster attack the player if appropriate and otherwise move it.
	void updateMonsters();
	//an isBlockedForMonster function returns a bool indicating whether a Monster would be blocked from moving to that position.
	bool isBlockedForMonster(const Position& position) const;	
};


#endif