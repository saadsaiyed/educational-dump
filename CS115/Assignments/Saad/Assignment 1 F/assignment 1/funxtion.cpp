#include"header.h"

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

//This function finds the starting (current) position of Monster and assign values to m_Row and m_Column
void findMonsterStart(const Level level, int& m_Row, int& m_Column) // This function finds the starting position of monster
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (level[i][j] == 6)
			{
				m_Row = i;
				m_Column = j;
			}
		}
	}
}

//This function finds the starting (current) position of Player and assign values to p_Row and p_Column
void findPlayerStart(const Level level, int& p_Row, int& p_Column)	//This function finds the starting position of Player
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (level[i][j] == 4)
			{
				p_Row = i;
				p_Column = j;
			}
		}
	}
}

//This function finds the price of each move Monster makes
unsigned int getCost(const Level level, int m_Row, int m_column)
{

	int travelCost[9] = { 1,2,4,1000,1,1,1,1,1 };
	int no = level[m_Row][m_column];
	return travelCost[no];

}

//This function calculates distance between Monster and Player
double calculateDistance(int m_Row, int m_Column, int p_Row, int p_Column) //Calculation of Distance between current position of monster and current position of payer
{
	double result, term1, term2;
	term1 = pow(p_Row - m_Row, 2);
	term2 = pow(p_Column - m_Column, 2);

	result = pow((term1 + term2), 0.5);

	return result;
}

//This function Gives the MAIN OUTPUT of map
void printLevel(const Level level, int m_Row, int m_Column, int p_Row, int p_Column)	//main out put of program
{
	char  Array[9] = { ' ','^',':','#',' ','*',' ',' ',' ' };

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
			if (m_Row == i && m_Column == j)
			{
				cout << 'M';
			}
			else if (p_Row == i && p_Column == j)
			{
				if (m_Row == p_Row && m_Column == p_Column)
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

//This function deals with the movement of Monster towards Player
void Change(Level level, int& m_Row, int& m_Column, int& p_Row, int& p_Column, int& travel_cost) // This function finds the starting position of monster
{
	double Direction[4];

	Direction[0] = calculateDistance(m_Row + 1, m_Column, p_Row, p_Column);
	Direction[1] = calculateDistance(m_Row - 1, m_Column, p_Row, p_Column);
	Direction[2] = calculateDistance(m_Row, m_Column + 1, p_Row, p_Column);
	Direction[3] = calculateDistance(m_Row, m_Column - 1, p_Row, p_Column);

	double min = Direction[0];		//just to move monster and get new row and column

	for (int i = 0; i < 4; i++)
	{
		if (min > Direction[i])
			min = Direction[i];
	}

	if (min == Direction[0])
		m_Row++;
	else if (min == Direction[1])
		m_Row--;
	else if (min == Direction[2])
		m_Column++;
	else if (min == Direction[3])
		m_Column--;

	//level[m_Row][m_Column] = 6;

	printLevel(level, m_Row, m_Column, p_Row, p_Column);

	travel_cost += getCost(level, m_Row, m_Column);

	cout << "The Monster Row Is: " << m_Row << " And The monsters column is: " << m_Column << endl;
	cout << "The Monster's Travel Cost So Far Is: " << travel_cost << endl;
	cout << "The Distance Left To Travel Is: " << calculateDistance(m_Row, m_Column, p_Row, p_Column);
	if (min == Direction[0])
		cout << " SOUTH" << endl;
	else if (min == Direction[1])
		cout << " NORTH" << endl;
	else if (min == Direction[2])
		cout << " EAST" << endl;
	else if (min == Direction[3])
		cout << " WEST" << endl;

}
void changePlayerRollAndColumn( Level level, Position& M, Position& P)
{
	if ()
	}