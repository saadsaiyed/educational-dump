#include"Game.h"

int maxLevelCount = 0;//maxLevelCount is the total count of maps in current game\

//initializer 
Game::Game(const string& file_name) 
	: level(file_name), 
	player(level.getPlayerStart()),
	monsterCount(level.getMonsterCount())
{
	monsterPtr = new Monster*[monsterCount];
	for (unsigned int i = 0; i < monsterCount; i++)
	{
		monsterPtr[i] = new Monster;
	}

	unsigned int tempCount = 0;
	for (unsigned int i = 0; i < ROWS && tempCount < monsterCount; i++)
	{
		for (unsigned int j = 0; j < COLUMNS && tempCount < monsterCount; j++)
		{
			if (level.getValue(toPosition(i, j)) == MONSTER_START)
			{
				monsterPtr[tempCount] = new Monster(toPosition(i, j));
				tempCount++;
			}
		}
	}
}

//default
Game ::Game() 
	:level(Level()), 
	player(level.getPlayerStart())
{
	for (unsigned int i = 0; i < monsterCount; i++)
	{
		monsterPtr[i] = nullptr;
	}
}

//copy constructor
Game :: Game(const Game& original)
	:level(original.level), 
	player(original.player)
{
	//I have used the reference of a You Tube video - "Rule of Three Implementation in C++" by ReelLearning, Published on Jun 2, 2012.
	//I could have used design suggestion from assignment but choose not to, as this is more easier for me to understand later for my assignment.
	monsterPtr = new Monster* [monsterCount];
	for (unsigned int i = 0; i < monsterCount; i++)
	{
		monsterPtr[i] = original.monsterPtr[i];
	}
}

//distructor
Game :: ~Game()
{
	for (unsigned int i = 0; i < monsterCount; i++)
		delete monsterPtr[i];
	delete[] monsterPtr;
}

//overloading operator
Game& Game :: operator= (const Game& original)
{
	if (this == &original)
		return *this;

	this->player = original.player;
	this->level = original.level;

	for (unsigned int i = 0; i < monsterCount; i++)
		this->monsterPtr[i] = original.monsterPtr[i];

	return *this;
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
			for (unsigned int k = 0; k < level.getMonsterCount(); k++)
			{
				if (monsterPtr[k]->getPosition().row == i && monsterPtr[k]->getPosition().column == j)
				{
					check = true;
				}
			}
			if (check == true)
				cout << 'M';


			else if (check == false && player.getPosition().row == i && player.getPosition().column == j)
				cout << '@';

			else
				level.printAtPosition(toPosition(i, j));
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

	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
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
	if (!level.isWall(tempPlayerPosition) && isValid(tempPlayerPosition) && attacks == false)
	{
		player.increaseTotalMoveCost(level.getCost(tempPlayerPosition));
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
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{ 
		if (!monsterPtr[i]->isDead())
		{
			if (areEqual(monsterPtr[i]->calculateMove(player.getPosition(), *this), player.getPosition()))
				player.receiveDamage(monsterPtr[i]->getDamage());

			else
				monsterPtr[i]->setPosition(monsterPtr[i]->calculateMove(player.getPosition(), *this));
		}
	}
}

bool Game :: isBlockedForMonster(const Position& position) const
{
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{
		return (level.isWall(position) || level.getValue(position) == MONSTER_START);
	}
	return 0;
}