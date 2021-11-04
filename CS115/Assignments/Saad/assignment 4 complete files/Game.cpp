#include"Game.h"

int maxLevelCount = 0;//maxLevelCount is the total count of maps in current game

Game::Game(const string& file_name):player(level[0].getPlayerStart())
{
	currentLevel = 0;//will be changed when ever player reaches GOAL_POSITION(make it ++).
	
	ifstream in(file_name.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	in >> maxLevelCount;

	string levelStrings[LEVEL_COUNT_MAX]; //this is to take input of file_name.

	for (int i = 0; i < maxLevelCount; i++)
	{
		in >> levelStrings[i];
		level[i] = Level(levelStrings[i]);
	}
	player = Player(level[currentLevel].getPlayerStart());
	
	//this is normal initializer for monster
	monsterInitialize();
}

void Game::isAtGoalPos()
{
	if (level[currentLevel].isGoalPosition(player.getPosition()))
	{
		if (currentLevel < maxLevelCount - 1)//maxLevelCount is -1 cause we dont need to increase currentLevel when we are on maxLevelCount
		{
			currentLevel++;
			monsterInitialize();
			player.setPosition(level[currentLevel].getPlayerStart());
		}
		else //make the gameover here
			exit(1);
	}
}

bool Game::isOver() const
{
	return (player.isDead());
}

void Game::print() const
{
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
			bool check = false;
			for (unsigned int k = 0; k < level[currentLevel].getMonsterCount(); k++)
			{
				if (monster[k].getPosition().row == i && monster[k].getPosition().column == j)
				{
					check = true;
				}
			}
			if (check == true)
				cout << 'M';


			else if (check == false && player.getPosition().row == i && player.getPosition().column == j)
				cout << '@';

			else
				level[currentLevel].printAtPosition(toPosition(i, j));
		}
		cout << "||" << endl;
	}
	cout << "##";
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << '=';
	}
	cout << "##" << endl;
	cout << "Player's Current Health = " << player.getHealth() << endl << "Player's Current Move cost = " << player.getTotalMoveCost()
		<< endl << "Player's Current Score = " << player.getScore() << endl;
	/*for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{
		cout << "Current Health of Monster " << i << " = " << monster[i].getHealth() << endl;			//This is if you want to see the monster's current health after each print function
	}*/
	cout << "Please enter direction to move your player '@': ";
}

void Game::tryMove(Position& tempPlayerPosition)
{
	bool attacks = false;

	for (unsigned int i = 0; i < level[currentLevel].getMonsterCount(); i++)
	{
		if (areEqual(monster[i].getPosition(), tempPlayerPosition) && !monster[i].isDead())
		{
			monster[i].receiveDamage(player.getDamage());
			attacks = true;
			if (monster[i].isDead())
			{
				player.increaseScore(monster[i].getPoints());
			}
		}
	}
	if (!level[currentLevel].isWall(tempPlayerPosition) && isValid(tempPlayerPosition) && attacks == false)
	{
		player.increaseTotalMoveCost(level[currentLevel].getCost(tempPlayerPosition));
		player.setPosition(tempPlayerPosition);
	}
}

void Game::tryMoveNorth()
{
	Position tempPlayerPosition = player.getPosition();
	
	tempPlayerPosition.row--;
	
	tryMove(tempPlayerPosition);
}

void Game::tryMoveSouth()
{
	Position tempPlayerPosition = player.getPosition();

	tempPlayerPosition.row++;

	tryMove(tempPlayerPosition);
}

void Game::tryMoveEast()
{
	Position tempPlayerPosition = player.getPosition();
	
	tempPlayerPosition.column++;

	tryMove(tempPlayerPosition);
}

void Game::tryMoveWest()
{
	Position tempPlayerPosition = player.getPosition();

	tempPlayerPosition.column--;

	tryMove(tempPlayerPosition);
}

void Game::updateMonsters()
{
	for (unsigned int i = 0; i < level[currentLevel].getMonsterCount(); i++)
	{ 
		if (!monster[i].isDead())
		{
			if (areEqual(monster[i].calculateMove(player.getPosition(), *this), player.getPosition()))
				player.receiveDamage(monster[i].getDamage());

			else
				monster[i].setPosition(monster[i].calculateMove(player.getPosition(), *this));
		}
	}
}

bool Game::isBlockedForMonster(const Position& position) const
{
	for (unsigned int i = 0; i < level[currentLevel].getMonsterCount(); i++)
	{
		return (level[currentLevel].isWall(position) || level[currentLevel].getValue(position) == MONSTER_START);
	}
}

void Game::monsterInitialize()
{
	unsigned int monsterCount = level[currentLevel].getMonsterCount();
	unsigned int tempCount = 0;
	for (unsigned int i = 0; i < ROWS && tempCount < monsterCount; i++)
	{
		for (unsigned int j = 0; j < COLUMNS && tempCount < monsterCount; j++)
		{
			if (level[currentLevel].getValue(toPosition(i, j)) == MONSTER_START)
			{
				monster[tempCount] = Monster(toPosition(i, j));
				tempCount++;
			}
		}
	}
}


//3 point in Part D in Assignment 4