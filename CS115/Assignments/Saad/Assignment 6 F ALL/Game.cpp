#include"Game.h"
#include"Attacker.h"
#include"Sentry.h"
#include"Drone.h"

int maxLevelCount = 0;//maxLevelCount is the total count of maps in current game\

//initializer 
Game::Game(const string& file_name)
{
	currentLevel = 0;//will be changed when ever player reaches GOAL_POSITION(make it ++). int currentLevel initializer

	ifstream in(file_name.c_str());

	if (!in)
	{
		cout << "Error: Cannot read from file named " << file_name << endl;
		exit(1);  // terminate program immediately
	}

	in >> maxLevelCount;													//int maxLevelCount initializer

	string levelStrings[LEVEL_COUNT_MAX];									//this is to take input of file_name.

	for (int i = 0; i < maxLevelCount; i++)
	{
		in >> levelStrings[i];	
		level[i] = Level(levelStrings[i]);									// Level level initializer
	}
	currentLevelMonsterCount = level[currentLevel].getMonsterCount();

	player = Player(level[0].getPlayerStart());								//Player player initializer

	monsterInitialize();													//Monster monster initializer	
}

//default
Game ::Game() :level(), player(level[currentLevel].getPlayerStart())
{
	currentLevelMonsterCount = level[currentLevel].getMonsterCount();

	for (unsigned int i = 0; i < currentLevelMonsterCount; i++)
	{
		monsterPtr = new Monster*[currentLevelMonsterCount];
	}
}

//copy constructor
Game :: Game(const Game& original) :player(original.player)
{
	//I have used the reference of a You Tube video - "Rule of Three Implementation in C++" by ReelLearning, Published on Jun 2, 2012.

	currentLevel = original.currentLevel;

	currentLevelMonsterCount = original.currentLevelMonsterCount;

	for (int i = 0; i < LEVEL_COUNT_MAX; i++)
	{
		level[i] = original.level[i];
	}

	//I could have used design suggestion from assignment but choose not to as this is more easier for me to understand later for my assignment.
	monsterPtr = new Monster* [currentLevelMonsterCount];
	for (unsigned int i = 0; i < currentLevelMonsterCount; i++)
	{		
		monsterPtr[i] = original.monsterPtr[i]->getClone();
	}
}

//distroctor
Game :: ~Game()
{
	for (unsigned int i = 0; i < currentLevelMonsterCount; i++)
	{
		delete monsterPtr[i];
	}
	delete[] monsterPtr;
}

//overloading operator
Game& Game :: operator= (const Game& original)
{
	if (this != &original)
	{
		this->currentLevel = original.currentLevel;

		this->currentLevelMonsterCount = original.currentLevelMonsterCount;

		this->player = original.player;

		for (int i = 0; i < LEVEL_COUNT_MAX; i++)
		{
			this->level[i] = original.level[i];
		}
		
		for (unsigned int i = 0; i < currentLevelMonsterCount; i++)
		{
			this->monsterPtr[i] = original.monsterPtr[i]->getClone();
		}
	}
	return *this;
}

void Game :: isAtGoalPos()
{
	if (level[currentLevel].isGoalPosition(player.getPosition()))
	{
		if (currentLevel < (maxLevelCount - 1))//maxLevelCount is -1 cause we dont need to increase currentLevel when we are on maxLevelCount
		{
			currentLevel++;
			monsterInitialize();
			player.setPosition(level[currentLevel].getPlayerStart());
		}
		else //make the gameover here
			exit(1);
	}
}

bool Game :: isOver() const
{
	return (player.isDead());
}

void Game :: print() const
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
				if (check == false && monsterPtr[k]->getPosition().row == i && monsterPtr[k]->getPosition().column == j)
				{
					cout << monsterPtr[k]->getDisplayChar();
					check = true;
				}
			}

			if (check == false && player.getPosition().row == i && player.getPosition().column == j)
			{
				cout << '@';
				check = true;
			}

			if (check == false)
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

void Game :: tryMove(Position& tempPlayerPosition)
{
	bool attacks = false;

	for (unsigned int i = 0; i < level[currentLevel].getMonsterCount(); i++)
	{
		if (areEqual(monsterPtr[i]->getPosition(), tempPlayerPosition) && !monsterPtr[i]->isDead())
		{
			monsterPtr[i]->receiveDamage(player.getDamage());
			attacks = true;
			if (monsterPtr[i]->isDead())
			{
				player.increaseScore(monsterPtr[i]->getPoints());
			}
		}
	}
	if (!level[currentLevel].isWall(tempPlayerPosition) && isValid(tempPlayerPosition) && attacks == false)
	{
		player.increaseTotalMoveCost(level[currentLevel].getCost(tempPlayerPosition));
		player.setPosition(tempPlayerPosition);
	}
}

void Game :: tryMoveNorth()
{
	Position tempPlayerPosition = player.getPosition();
	
	tempPlayerPosition.row--;
	
	tryMove(tempPlayerPosition);
}

void Game :: tryMoveSouth()
{
	Position tempPlayerPosition = player.getPosition();

	tempPlayerPosition.row++;

	tryMove(tempPlayerPosition);
}

void Game :: tryMoveEast()
{
	Position tempPlayerPosition = player.getPosition();
	
	tempPlayerPosition.column++;

	tryMove(tempPlayerPosition);
}

void Game :: tryMoveWest()
{
	Position tempPlayerPosition = player.getPosition();

	tempPlayerPosition.column--;

	tryMove(tempPlayerPosition);
}

void Game :: updateMonsters()
{
	for (unsigned int i = 0; i < level[currentLevel].getMonsterCount(); i++)
	{ 
		if (!monsterPtr[i]->isDead())
		{
			Position temp = monsterPtr[i]->calculateMove(*this, player.getPosition());
			
			if (areEqual(temp, player.getPosition()))
				player.receiveDamage(monsterPtr[i]->getDamage());

			else
				monsterPtr[i]->setPosition(temp);
		}
	}
}

bool Game :: isBlockedForMonster(const Position& position) const
{
	if (level[currentLevel].isWall(position))
		return true;

	for (unsigned int i = 0; i < currentLevelMonsterCount; i++)
	{
		if (areEqual(position, monsterPtr[i]->getPosition()) && !monsterPtr[i]->isDead())
			return true;
	}
	return 0;
}

void Game :: monsterInitialize()
{
	monsterPtr = new Monster*[currentLevelMonsterCount];
	
	unsigned int tempCount = 0;
	
	for (unsigned int i = 0; i < ROWS && tempCount < currentLevelMonsterCount; i++)
	{
		for (unsigned int j = 0; j < COLUMNS && tempCount < currentLevelMonsterCount; j++)
		{
			if (level[currentLevel].getValue(toPosition(i, j)) == SENTRY_START)
			{
				monsterPtr[tempCount] = new Sentry(toPosition(i, j));
				tempCount++;
			}
			else if (level[currentLevel].getValue(toPosition(i, j)) == ATTACKER_START)
			{
				monsterPtr[tempCount] = new Attacker(toPosition(i, j));
				tempCount++;
			}
			else if (level[currentLevel].getValue(toPosition(i, j)) == DRONE_START)
			{
				monsterPtr[tempCount] = new Drone(toPosition(i, j));
				tempCount++;
			}
		}
	}
}