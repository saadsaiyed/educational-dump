#include"Header.h"

#include"Monster.h"
#include"Player.h"
#include"Position.h"

//loadLevel function takes input from input file and covert them to numbers and add them to level array 
void loadLevel(Level level, char c[], int size)
{
	int count = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (c[count] == '.')
				level[i][j] = 0;
			else if (c[count] == '^')
				level[i][j] = 1;
			else if (c[count] == ':')
				level[i][j] = 2;
			else if (c[count] == '#')
				level[i][j] = 3;
			else if (c[count] == 'P')
				level[i][j] = 4;
			else if (c[count] == '*')
				level[i][j] = 5;
			else if (c[count] == 'S')
				level[i][j] = 6;
			else if (c[count] == 'A')
				level[i][j] = 7;
			else if (c[count] == 'D')
				level[i][j] = 8;

			count++;
		}
	}
}

//This function finds the starting (current) position of Monster and assign values to M.row and M.column
void findMonsterStart(const Level level, Position& M) // This function finds the starting position of monster
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (level[i][j] == 6)
			{
				M.row = i;
				M.column = j;
			}
		}
	}
}

//This function finds the starting (current) position of Player and assign values to P.row and P.column
void findPlayerStart(const Level level, Position& P)	//This function finds the starting position of Player
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (level[i][j] == 4)
			{
				P.row = i;
				P.column = j;
			}
		}
	}
}

//This function finds the price of each move Monster makes
unsigned int getCost(const Level level, Position& M)
{
	int travelCost[9] = { 1,2,4,1000,1,1,1,1,1 };
	int no = level[M.row][M.column];
	return travelCost[no];
}

//This function Gives the MAIN OUTPUT of map
void printLevel(const Level level, const Position& M, const Position& P, const Monster monster)	//main out put of program
{
	char  Array[9] = {' ', '^', ':', '#', ' ', '*', ' ', ' ', ' '};

	cout << "##";
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << '=';
	}
	cout << "##" << endl;

	for (int i = 0; i < ROWS; i++)
	{
		cout << "||";
		for (int j = 0; j < COLUMNS; j++)
		{
			if (M.row == i && M.column == j)
			{
				cout << 'M';
			}
			else if (P.row == i && P.column == j)
			{
				if (M.row == P.row && M.column == P.column && !monsterIsDead(monster))
					cout << 'M';
				else
					cout << '@';
			}
			else
				cout << Array[level[i][j]];
		}
		cout << "||" << endl;
	}
	cout << "##";
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << '=';
	}
	cout << "##" << endl;
}
