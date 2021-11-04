#include"Level.h"

#include"Monster.h"
#include"Player.h"					
#include"Position.h"

const char INPUT_TERRAIN_TYPE[9] ={	'.', '^', ':', '#', 'P', '*', 'S', 'A', 'D'};

//loadLevel function takes input from input file and covert them to numbers and add them to level array 
Level::Level(const string& filename)
{
	ifstream in(filename.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << filename << endl;
		exit(1);  // terminate program immediately
	}

	for (int r = 0; in && (r < ROWS); r++)
	{
		for (int c = 0; in && (c < COLUMNS); c++)
		{
			char next_char;
			in >> next_char;

			for (unsigned int t = 0; t < 9; t++)
			{
				if (next_char == INPUT_TERRAIN_TYPE[t])
				{
					map[r][c] = t;
				}
			}
		}
	}
}
//This function finds the starting (current) position of Monster and assign values to M.row and M.column
Position Level::getPlayerStart() const // This function finds the starting position of monster
{
	Position P = toPosition(0,0);
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (map[i][j] == 4)
			{
				P.row = i;
				P.column = j;
				return P;
			}
		}
	}
	return P;
}

//This function finds the starting (current) position of Player and assign values to P.row and P.column
Position Level::getMonsterStart()const			//This function finds the starting position of Player
{
	Position M = toPosition(0, 0);

	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (map[i][j] == 6)
			{
				M.row = i;
				M.column = j;
				return M;
			}
		}
	}
	return M;
}

//This function finds the price of each move Monster makes
unsigned int Level::getCost(const Position& P) const
{
	int travelCost[9] = { 1,2,4,1000,1,1,1,1,1 };
	int no = map[P.row][P.column];
	return travelCost[no];
}

//This function Gives the MAIN OUTPUT of map
//main out put of program
void Level::print(const Position& monster_position, const Position& player_position) const
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
			if (monster_position.row == i && monster_position.column == j)
			{
				cout << 'M';
			}
			else if (player_position.row == i && player_position.column == j)
			{
				cout << '@';
			}
			else
				cout << Array[map[i][j]];
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

bool Level::isWall(const Position check)const
{
	if (map[check.row][check.column] == WALL)
		return true;
	return false;
}