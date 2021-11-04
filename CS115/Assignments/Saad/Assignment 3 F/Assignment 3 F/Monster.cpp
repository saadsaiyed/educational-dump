#include <iostream>
#include"Level.h"
 
#include"Monster.h"
#include"Position.h"

using namespace std;

Monster::Monster()
{
	health = 0;
}

Monster::Monster(const Position& start)
{
	health = STARTING_HEALTH_MONSTER;
	damage = DAMAGE_MONSTER;
	points = POINTS_MONSTER;
	position = start;
}	

bool Monster::isDead()const
{
	if (health <= 0)
		return true;
	return false;
}

int Monster::getDamage()const
{
	return damage;
}

int Monster::getHealth()const
{
	return health;
}

unsigned int Monster::getPoints()const
{
	return points;
}

const Position& Monster::getPosition()const
{
	return position;
}

void Monster::setPosition(const Position& p)
{
	position = p;
}

void Monster::receiveDamage(int amount)
{
	health -= amount;
}

Position Monster::calculateMove(const Position& player_position, const Level& map)const 
{
	//direction for this was done in class 
	//coverting to class for monster and player
	//also add comments inside aclass as prototypes
	//also for level modual we had to change all function perameters and function calling
	
	//a star search
	//bradth search

	double direction[4];
	Position x;								//this is a struct just to change values of rows and columns

	x = position;
	x.row++;
	direction[0] = calculateDistance(x, player_position);
	
	
	x = position;
	x.row--;
	direction[1] = calculateDistance(x, player_position);
	
	
	x = position;
	x.column++;
	direction[2] = calculateDistance(x, player_position);
	
	
	x = position;
	x.column--;
	direction[3] = calculateDistance(x, player_position);
	
	
	
	double min = direction[0];
	double min2 = direction[0];

	for (int i = 0; i < 4; i++)
	{
		if (min > direction[i])
		{
			min2 = min;
			min = direction[i];
		}
		else if (direction[i] < min2)// && direction[i] != min)
			min2 = direction[i];
		cout << direction[i] << endl;
	}

	cout << "first min is : " << min << endl;//all the couts are just for logical error checks I dont want to remove it because you can also watch my progress, to do so
	cout << "second min is : " << min2 << endl;//just remove the 'system("CLS")' from main.cpp line no.54 make it comment and all set. also you cant see the couts now.

	x = position;
	
	if (min == direction[0])//Condition 1.0.0
	{
		x.row++;
		
		cout << "condition 1.0.0 Yes" << endl;

		if (map.isWall(x))	//Condition 1.1.0
		{
			x.row--;

			cout << "condition 1.1.0 Yes" << endl;

			if (min2 == direction[1])//condition 1.1.1
			{
				x.row--;

				cout << "condition 1.1.1 Yes" << endl;

				if (map.isWall(x))//condition 1.1.1 (1)
				{
					x.row++;

					cout << "condition 1.1.1 (1) Yes" << endl;
				}
			}
			else if (min2 == direction[2])//condition 1.1.2
			{
				x.column++;

				cout << "condition 1.1.2 Yes" << endl;

				if (map.isWall(x))//condition 1.1.2 (2)
				{
					x.column--;

					cout << "condition 1.1.2 (2)Yes" << endl;
				}
			}
			else if (min2 == direction[3])//condition 1.1.3
			{
				x.column--;

				cout << "condition 1.1.3 Yes" << endl;

				if (map.isWall(x))//condition 1.1.3 (3)
				{
					x.column++;

					cout << "condition 1.1.3 Yes" << endl;
				}
			}
		}
	}
	else if (min == direction[1])//Condition 2.0.0
	{
		x.row--;

		cout << "condition 2.0.0 Yes" << endl;
		
		if (map.isWall(x))//Condition 2.1.0
		{
			x.row++;

			cout << "condition 2.1.0 Yes" << endl;

			if (min2 == direction[0])//Condition 2.1.1
			{
				x.row++;

				cout << "condition 2.1.1 Yes" << endl;

				if (map.isWall(x))//Condition 2.1.1 (1)
				{
					x.row--;
					cout << "condition 2.1.1 (1) Yes" << endl;
				}
			}
			else if (min2 == direction[2])//Condition 2.1.2
			{
				x.column++;

				cout << "condition 2.1.2 Yes" << endl;

				if (map.isWall(x))//Condition 2.1.2 (2)
				{
					x.column--;

					cout << "condition 2.1.2 (2) Yes" << endl;
				}
			}
			else if (min2 == direction[3])//Condition 2.1.3
			{
				x.column--;

				cout << "condition 2.1.3 Yes" << endl;

				if (map.isWall(x))//Condition 2.1.3 (3)
				{
					x.column++;

					cout << "condition 2.1.3 (3) Yes" << endl;
				}
			}
		}
	}
	else if (min == direction[2])//Condition 3.0.0
	{
		x.column++;

		cout << "condition 3.0.0 Yes" << endl;

		if (map.isWall(x))//Condition 3.1.0
		{
			x.column--;

			cout << "condition 3.1.0 Yes" << endl;

			if (min2 == direction[0])//Condition 3.1.1
			{
				x.row++;

				cout << "condition 3.1.1 Yes" << endl;

				if (map.isWall(x))//Condition 3.1.1 (1)
				{
					x.row--;

					cout << "condition 3.1.1 (1) Yes" << endl;
				}
			}
			else if (min2 == direction[1])//Condition 3.1.2
			{
				x.row--;

				cout << "condition 3.1.2 Yes" << endl;

				if (map.isWall(x))//Condition 3.1.2 (2)
				{
					x.row++;

					cout << "condition 3.1.2 (2) Yes" << endl;
				}
			}
			else if (min2 == direction[3])//Condition 3.1.3
			{
				x.column--;

				cout << "condition 3.1.3 Yes" << endl;

				if (map.isWall(x))//Condition 3.1.3 (3)
				{
					x.column++;

					cout << "condition 3.1.3 (3) Yes" << endl;
				}
			}
		}
	}
	else if (min == direction[3])//Condition 4.0.0
	{
		x.column--;
		
		cout << "condition 4.0.0 Yes" << endl;

		if (map.isWall(x))//Condition 4.1.0
		{
			x.column++;

			cout << "condition 4.1.0 Yes" << endl;

			if (min2 == direction[0])//Condition 4.1.1
			{
				x.row++;

				cout << "condition 4.1.1 Yes" << endl;

				if (map.isWall(x))//Condition 4.1.1 (1)
				{
					x.row--;

					cout << "condition 4.1.1 (1) Yes" << endl;
				}
			}
			else if (min2 == direction[1])//Condition 4.1.2
			{
				x.row--;

				cout << "condition 4.1.2 Yes" << endl;

				if (map.isWall(x))//Condition 4.1.2 (2)
				{
					x.row++;

					cout << "condition 4.1.2 (2) Yes" << endl;
				}
			}
			else if (min2 == direction[2])//Condition 4.1.3
			{
				x.column++;

				cout << "condition 4.1.3 Yes" << endl;

				if (map.isWall(x))//Condition 4.1.3 (3)
				{
					x.column--;

					cout << "condition 4.1.3 (3) Yes" << endl;
				}
			}
		}
	}

	return x;
}