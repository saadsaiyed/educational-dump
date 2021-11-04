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
const unsigned int LEVEL_COUNT_MAX = 20;

class Game
{
private:
	Level level[LEVEL_COUNT_MAX];
	Player player;
	Monster** monsterPtr = nullptr;
	int currentLevel;
	void tryMove(Position& tempPlayerPosition);
	unsigned int currentLevelMonsterCount = 1;

public:
	Game();
	//The Game constructor invokes the constructors of its Level, Player, and Monster fields.
	Game(const string& file_name);
	Game(const Game& original);
	~Game();
	Game& operator= (const Game& original);
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
	//This function make sure that player reaches next map when at GOAL_POSITION.
	void isAtGoalPos();
	//just to reuse monster initializer code multiple times.
	void monsterInitialize();
};

#endif