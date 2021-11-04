		/*
Name: Saad Saiyed
Course: CS 115
Assignment: 2
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
typedef int Level[ROWS][COLUMNS];						//Level is data type which will be assigned to main 2d level array
const unsigned int EMPTY = 0, ROCKY = 1, ROUGH = 2, WALL = 3, PLAYER_START = 4, PLAYER_GOAL = 5, MONSTER_START = 6, ATTACKER_START = 7, DRONE_START = 8;


void loadLevel(Level level, char c[], int size);
void findMonsterStart(const Level level, Position& M);
void findPlayerStart(const Level level, Position& P);
unsigned int getCost(const Level level, Position& M);
void printLevel(const Level level, const Position& M, const Position& P, const Monster monster);
#endif