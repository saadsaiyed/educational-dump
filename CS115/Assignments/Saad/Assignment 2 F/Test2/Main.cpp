/*
Name: Saad Saiyed
Course: CS 115
Assignment: 2
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19

This program deals with two dimensional arrays and structs to run an ASCII value game of Monster and Player where,
Monster moves towards Player and user needs to handle Player.
*/
#include"Header.h"

#include"Monster.h"
#include"Player.h"
#include"Position.h"

Position monsterDealsDamage(Monster& monster, Player& player);
void playerPositionChange(Position& P, char input);

int main()
{
	const int size = ROWS * COLUMNS;

	ifstream inData;										//
	string name_of_file;									//
	cout << "Enter MAP name and press enter TWICE: ";		//This part deals with the file input
	getline(cin, name_of_file);								//
	inData.open(name_of_file);								//

	Level level;											//This is our main 2d array

	char c[size];											//This variable is for getting input from input file

	for (int i = 0; i < size; i++)							//This loop works as a data collector from input file
	{
		inData >> c[i];
	}
	loadLevel(level, c, size);

	Monster monster;
	Player player;
															//Declaring struct variables
	Position M;
	Position P;

	findMonsterStart(level, M);								//function calls to get values in struct Position M
	monsterInit(monster, M);

	findPlayerStart(level, P);								//function calls to get values in struct Position P
	playerInit(player, P);

	Position X;	//this variable is for storing the desired future position of the monster
	Position Y;
	Position temp;

	//player.total_move_cost = 0;
	char move = '.';	//to get input from user to move player

	while (!playerIsDead(player) && !monsterIsDead(monster)) //This is main loop which controls the print function and ends it when monster or player one of them is dead
	{
		system("CLS");//for clearing screen after each loop with a fresh screen

		printLevel(level, M, P, monster);//print the output of map and monster is just to look if he is dead or not

		if (!playerIsDead(player) || !monsterIsDead(monster))	//I've added this to get a clear output when loop runs for last time,
		{														//so that everytime loop runs it will enter this loop until the last loop
			// determine Y
			cout << "Player's Current Health = " << player.health << endl << "Player's Current Move cost = " << player.total_move_cost
				<< endl << "Player's Current Score = " << player.score << endl << "Monster's Current Health = " << monster.health << endl;
			cout << "Please enter the keys from intruction to move your player '@': ";//these are bunch of couts
			cin >> move;//getting input from user

			Y = player.position;

			playerPositionChange(Y, move);//updating values of Y according to user's desire

			// is it legal for the player to go to Y
			if (isValid(Y))
			{
				// is the monster currently at Y
				if (monster.position.row == Y.row && monster.position.column == Y.column)
				{
					// fight monster
					monsterReceiveDamage(monster, playerGetDamage(player));
					if (monsterIsDead(monster))
					{
						temp = Y;//If monster is dead update player's position
					}
				}
				// otherwise
				else
				{
					player.position = Y;
					P = Y;
					player.total_move_cost += getCost(level, P);//get the player's cost
					// move player and adjust cost
				}
			}
			// we have successfully updated player's location in player.position

			X = monsterCalculateMove(monster, P);//Here we give values of M to X
			if (X.row == P.row && X.column == P.column)//This conditions is for dealing damage to one another(Monster and/or Player) when they are side by side
			{
				M = monsterDealsDamage(monster, player);//This is not in else because no matter if Player deals damage or not, 
			}											//if they are side by side monster will damage and eat him when health is zero or less then zero 
			else
			{
				M = monsterCalculateMove(monster, P);//So this is in else because we don't want any one of them to move to other's position is side by side
			}
		}

		monsterSetPosition(monster, M);//updating the value position pf monster as in position M

		playerSetPosition(player, P);//updating the value position pf player as in position P

		if (playerIsDead(player))//This condition will be true only when the loop runs for last time
		{
			system("CLS");
			printLevel(level, M, temp, monster);
			cout << "Player's Current Health = " << player.health << endl << "Player's Current Move cost = " << player.total_move_cost
				<< endl << "Player's Current Score = " << player.score << endl << "Monster's Current Health = " << monster.health << endl;
		}

	}
	if (playerIsDead(player))
		cout << "Monster ate Player" << endl;
	else
	{
		cout << "Monster's Current Health = " << monster.health << endl;
		cout << "Monster is Dead" << endl;
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------//

Position monsterDealsDamage(Monster& monster, Player& player)//This function runs only when monster and player both are side by side
{
	Position x;//we are creating this Position variable to eat player when it is dead and return the future position

	x = monsterCalculateMove(monster, player.position);
	playerReceiveDamage(player, monsterGetDamage(monster));

	if (playerIsDead(player) == true)											//This condition checks if player is dead than let monster move to player's position.
		return x;

	return monster.position;//if not then stay and deals damage
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
void playerPositionChange(Position& P, char input)//This loop works according to users input;
{
	if (input == 'w' || input == 'W')
		P.column--;
	else if (input == 'n' || input == 'N')
		P.row--;
	else if (input == 'e' || input == 'E')
		P.column++;
	else if (input == 's' || input == 'S')
		P.row++;
	else if (input == 'q' || input == 'Q')
		exit(1);
	else if (input == '.')
		input = 'p';
}