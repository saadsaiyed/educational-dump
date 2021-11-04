/*
Name: Saad Saiyed
Course: CS 115
Assignment: 3
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19
*/
#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<stdlib.h>


using namespace std;


#include"Position.h"
#include"Monster.h"

const int ROWS = 20, COLUMNS = 60;						//This represents the ROWS and COLUMNS of map
typedef int level[ROWS][COLUMNS];						//Level is data type which will be assigned to main 2d array named level in main.cpp
const unsigned int EMPTY = 0, ROCKY = 1, ROUGH = 2, WALL = 3, PLAYER_START = 4, PLAYER_GOAL = 5, MONSTER_START = 6, ATTACKER_START = 7, DRONE_START = 8;

class Level
{
private:
	level map;
public:
	Level(const string& filename);
	Position getPlayerStart() const;
	Position getMonsterStart() const;
	unsigned int getCost(const Position& p) const;
	void print(const Position& monster_position,
	const Position& player_position) const;
	bool isWall(const Position check)const;
};

#endif