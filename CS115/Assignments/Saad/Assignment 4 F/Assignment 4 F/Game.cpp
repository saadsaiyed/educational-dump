#include"Game.h"

Game::Game(const string& file_name):level(file_name), player(level.getPlayerStart())
{	
	unsigned int monsterCount = level.getMonsterCount();
	unsigned int count = 0;
	for (unsigned int i = 0; i < ROWS && count < monsterCount; i++)
	{
		for (unsigned int j = 0; j < COLUMNS && count < monsterCount; j++)
		{
			if (level.getValue(toPosition(i, j)) == MONSTER_START)
			{
				monster[count] = Monster(toPosition(i, j));
				count++;
			}
		}
	}
}

bool Game::isOver() const
{
	return (player.isDead() || level.isGoalPosition(player.getPosition()));
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
			for (unsigned int k = 0; k < level.getMonsterCount(); k++)
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

void Game::tryMove(Position& tempPlayerPosition)
{
	bool attacks = false;

	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
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
	if (!level.isWall(tempPlayerPosition) && isValid(tempPlayerPosition) && attacks == false)
	{
		player.increaseTotalMoveCost(level.getCost(tempPlayerPosition));
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
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
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
	for (unsigned int i = 0; i < level.getMonsterCount(); i++)
	{
		return (level.isWall(position) || level.getValue(position) == MONSTER_START);
	}
}