#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<stdlib.h>

using namespace std;


const int ROWS = 20, COLUMNS = 60;						//This represents the ROWS and COLUMNS of map
typedef int Level[ROWS][COLUMNS];						//Level is data type which will be assigned to main 2d level array


void loadLevel(Level level, char c[], int size);
void findMonsterStart(const Level level, int& m_Row, int& m_Column);
void findPlayerStart(const Level level, int& p_Row, int& p_Column);
unsigned int getCost(const Level level, int m_Row, int m_Column);
double calculateDistance(int m_Row, int m_Column, int p_Row, int p_Column);
void printLevel(const Level level, int m_Row, int m_Column, int p_Row, int p_Column);
void Change(Level level, int& m_Row, int& m_Column, int& p_Row, int& p_Column, int& travel_cost);