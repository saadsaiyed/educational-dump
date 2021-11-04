//
//  Level.h
//
//  For the CS 115 roguelike game.
//
//  By Howard Hamilton
//  Updated by Richard Hamilton, 2019-01-01
//

#include <string>
using namespace std;

const unsigned int ROWS    = 20;
const unsigned int COLUMNS = 60;
typedef unsigned int Level[ROWS][COLUMNS];

const unsigned int EMPTY          = 0;
const unsigned int ROCKY          = 1;
const unsigned int ROUGH          = 2;
const unsigned int WALL           = 3;
const unsigned int PLAYER_START   = 4;
const unsigned int PLAYER_GOAL    = 5;
const unsigned int MONSTER_START  = 6;
const unsigned int ATTACKER_START = 7;
const unsigned int DRONE_START    = 8;


void loadLevel (Level level, string file_name);

void findMonsterStart (Level level, int& row, int& column);

void findPlayerStart (Level level, int& row, int& column);

unsigned int getCost (Level level, int row, int column);

void printLevel (Level level, int current_row, int current_column, int target_row, int target_column);

