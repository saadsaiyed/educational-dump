#include"Level.h"

const char INPUT_TERRAIN_TYPE[9] ={	'.', '^', ':', '#', 'P', '*', 'S', 'A', 'D'};

//This function is a default constructor which sets the Empty value to whole array except top left corner
Level::Level()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			map[i][j] = EMPTY;
		}
	}
	map[0][0] = PLAYER_START;
}

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

Level::Level(const Level& original)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			this->map[i][j] = original.map[i][j];
		}
	}
}

Level::~Level()
{
}

Level& Level::operator=(const Level& original)
{
	if(this != &original)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				this->map[i][j] = original.map[i][j];
			}
		}
	}
	return *this;
}

//This function finds the starting (current) position of Monster and assign values to M.row and M.column
Position Level::getPlayerStart() const // This function finds the starting position of monster
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (map[i][j] == PLAYER_START)
			{
				return toPosition(i, j);
			}
		}
	}
	return toPosition(0, 0);
}

//This function gives the value of number of monsters inside this map
unsigned int Level::getMonsterCount() const 
{
	unsigned int count = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (map[i][j] == SENTRY_START || map[i][j] == ATTACKER_START || map[i][j] == DRONE_START)
				count++;
		}
	}

	return count;
}

//This functions returns the value in our main 2d array of level at Position p
unsigned int Level::getValue(const Position& p) const
{
	return map[p.row][p.column];
}

//This function prints the default map without any changes to monster or player
void Level::printAtPosition(const Position& p) const
{
	char  Array[9] = { ' ', '^', ':', '#', ' ', '*', ' ', ' ', ' ' };

	cout << Array[map[p.row][p.column]];
}

//This function returns that the current position is the player goal or not
bool Level::isGoalPosition(const Position& p) const
{
	return (map[p.row][p.column] == PLAYER_GOAL);
}

//This function finds the price of each move Monster makes
unsigned int Level::getCost(const Position& P) const
{
	int travelCost[9] = { 1,2,4,1000,1,1,1,1,1 };
	int no = map[P.row][P.column];
	return travelCost[no];
}

//This function Gives the information that is there wall ahead or not
bool Level::isWall(const Position& check)const
{
	return (map[check.row][check.column] == WALL);
}