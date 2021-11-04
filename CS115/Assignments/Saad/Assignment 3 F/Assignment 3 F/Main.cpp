/*
Name: Saad Saiyed
Course: CS 115
Assignment: 3
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19

This program deals with two dimensional arrays and class to run an ASCII value game of Monster and Player where,
Monster moves towards Player and user needs to handle Player.
*/
#include"Level.h"
#include"Monster.h"
#include"Player.h"
#include"Position.h"

void playerPositionChange(Level map, Position& P, char input);

int main()
{
	cout << "Enter the name of the file to load, including the file extension. ";
	string file_name;

	getline(cin, file_name);
	while (file_name.empty())
	{
		getline(cin, file_name);
	}

	Level map(file_name);
	
	Position M;
	Position P;

	M = map.getMonsterStart();
	Monster monster(M);											//function calls to get values in struct Position M

	P = map.getPlayerStart();
	Player player(P);
	
	Position X;	//this variable is for storing the desired future position of the monster
	Position Y;
	Position temp;

	char move = '.';	//to get input from user to move player

	//-----------------Main Loop-------------------//

	while (!player.isDead() && !monster.isDead()) //This is main loop which controls the print function and ends it when monster or player one of them is dead
	{
		system("CLS");//for clearing screen after each loop with a fresh screen

		map.print(M, P);	//print the output of map and monster is just to look if he is dead or not

		if (!player.isDead() || !monster.isDead())	//I've added this to get a clear output when loop runs for last time,
		{														//so that everytime loop runs it will enter this loop until the last loop
			// determine Y
			cout << "Player's Current Health = " << player.getHealth() << endl << "Player's Current Move cost = " << player.getTotalMoveCost()
				<< endl << "Player's Current Score = " << player.getScore() << endl << "Monster's Current Health = " << monster.getHealth() << endl;
			cout << "Please enter direction to move your player '@': ";//these are bunch of couts
			cin >> move;//getting input from user

			Y = player.getPosition();

			playerPositionChange(map, Y, move);		//updating values of Y according to user's desire

			// is it legal for the player to go to Y
			if (isValid(Y))
			{
				// is the monster currently at Y
				if (monster.getPosition().row == Y.row && monster.getPosition().column == Y.column)
				{
					// fight monster
					monster.receiveDamage(player.getDamage());
					temp = P;//If monster is dead update player's position
				}
				// otherwise
				else
				{
					player.setPosition(Y);	// move player and adjust cost
					P = Y;
					if(move != '.')
					player.increaseTotalMoveCost(map.getCost(P));	//get the player's cost
				}
			}
			// we have successfully updated player's location in player.position

			X = monster.calculateMove(P, map);//Here we give values of M to X
			if (X.row == P.row && X.column == P.column)//This conditions is for dealing damage to one another(Monster and/or Player) when they are side by side
			{
				player.receiveDamage(monster.getDamage());

				if (player.isDead() == true)											//This condition checks if player is dead than let monster move to player's position.
					M = monster.calculateMove(P, map);
			}	
			else
			{
				M = monster.calculateMove(P, map);//So this is in else because we don't want any one of them to move to other's position is side by side
			}
		}

		monster.setPosition(M);//updating the value position pf monster as in position M

		player.setPosition(P);//updating the value position pf player as in position P

		if (player.isDead())//This condition will be true only when the loop runs for last time
		{
			system("CLS");
			map.print(M, temp);
			cout << "Player's Current Health = " << player.getHealth() << endl << "Player's Current Move cost = " << player.getTotalMoveCost()
				<< endl << "Player's Current Score = " << player.getScore() << endl << "Monster's Current Health = " << monster.getHealth() << endl;
		}
		else if (monster.isDead())
		{
			system("CLS");
			map.print(M, temp);
			cout << "Player's Current Health = " << player.getHealth() << endl << "Player's Current Move cost = " << player.getTotalMoveCost()
				<< endl << "Player's Current Score = " << player.getScore() << endl << "Monster's Current Health = " << monster.getHealth() << endl;
		}

	}
	if (player.isDead())
		cout << "Monster ate Player" << endl;
	else
	{
		cout << "Monster is Dead" << endl;
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------//

//
//  playerPositionChange
//
//  Purpose: To change values of Player's Position according to user's desire.
//  Parameter(s):
//    <1> P		: The Position P to modify players positon.
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: Values of Player's position changed accordingly.
//
void playerPositionChange(Level map, Position& P, char input)
{
	if (input == 'w' || input == 'W')
	{
		P.column--;
		if (map.isWall(P))
			P.column++;
	}
	else if (input == 'n' || input == 'N')
	{
		P.row--;
		if (map.isWall(P))
			P.row++;
	}
	else if (input == 'e' || input == 'E')
	{
		P.column++;
		if (map.isWall(P))
			P.column--;
	}
	else if (input == 's' || input == 'S')
	{
		P.row++;
		if (map.isWall(P))
			P.row--;
	}
	else if (input == 'q' || input == 'Q')
		exit(1);
	else if (input == '.')
		input = 'p';
}