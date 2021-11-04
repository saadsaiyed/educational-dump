///*
//Name: Saad Saiyed
//Course: CS 115
//Assignment: 5
//Lab Section: Section 084
//Section: 5:30pm to 6:30pm
//Date: 04/30/19
//
//This program deals with two dimensional arrays and classes to run an ASCII value game of Monster and Player where,
//Monster moves towards Player and user needs to handle Player.
//Specific to assignment 4 we have a Game class which replaces many variables in Main function and also 
//this program will NOT over if monster is dead (not even all are dead).
//*/
//
//#include"Level.h"
//#include"Monster.h"
//#include"Player.h"
//#include"Position.h"
//#include"Game.h"
////
////  playerPositionChange
////
////  Purpose: To change values of Player's Position according to user's desire.
////  Parameter(s):
////    <1> P		: The Position P to modify players positon.
////  Precondition(s): N/A
////  Returns: N/A
////  Side Effect: Values of Player's position changed accordingly.
////
//void playerPositionChange(char input, Game& game);
//
//int main()
//{
//	cout << "Enter the name of the file to load, including the file extension. ";
//	string file_name;
//
//	getline(cin, file_name);
//	while (file_name.empty())
//		getline(cin, file_name);
//
//	Game game(file_name);
//
//	char move = '.';							//to get input from user to move player
//
//	while (!game.isOver() && move != 'q' && move != 'Q') //This is main loop which controls the print function and ends it when monster or player one of them is dead
//	{
//		system("CLS");
//		game.print();							//print the output of map and monster is just to look if he is dead or not
//
//		cin >> move;							//getting input from user
//
//		playerPositionChange(move, game);		//updating Player according to user's desire
//		game.updateMonsters();					//updating Monster according to closest distance from player position
//
//	}
//	system("CLS");
//	game.print();
//
//	return 0;
//}
//
////-----------------------------------------------------------------------------------------------------------------//
//
//void playerPositionChange(char input, Game& game)
//{
//	if (input == 'w' || input == 'W')
//		game.tryMoveWest();
//
//	else if (input == 'n' || input == 'N')
//		game.tryMoveNorth();
//
//	else if (input == 'e' || input == 'E')
//		game.tryMoveEast();
//
//	else if (input == 's' || input == 'S')
//		game.tryMoveSouth();
//
//	else if (input == 'q' || input == 'Q')
//		exit(1);
//
//	else if (input == '.')
//		input = 'p';
//}



//
//  MainC.cpp
//

// standard includes
#include <string>
#include <iostream>
#include <fstream>

// custom includes
#include "Vector2.h"
#include "PathWalked.h"

// using declarations
using namespace std;

static PathWalked loadPath(const string& filename);
static void printPath(const PathWalked& path, const string& name);



int main()
{
	cout << "Testing PathWalked class:" << endl;
	cout << "=========================" << endl;
	cout << endl;

	// test default constructor
	PathWalked path0;

	// test add function and copy constructor
	PathWalked path1 = loadPath("path1.txt");

	// test assignment operator
	PathWalked path2;
	path2 = loadPath("circle.txt");

	cout << "Paths after loading:" << endl;
	cout << "--------------------" << endl;
	printPath(path0, "Path 0");
	printPath(path1, "Path 1");
	printPath(path2, "Path 2");

	// test assignment operator more and clear function
	path0 = path1;
	path1 = path2;
	path2.clear();

	cout << "Paths after assignment and clear:" << endl;
	cout << "---------------------------------" << endl;
	printPath(path0, "Path 0");
	printPath(path1, "Path 1");
	printPath(path2, "Path 2");

	// test copy constructor again and destructor
	PathWalked* p_path3 = new PathWalked(path0);
	cout << "Path 3 before clearing path 0:" << endl;
	cout << "------------------------------" << endl;
	printPath(*p_path3, "Path 3");
	path0.clear();
	cout << "Path 3 after clearing path 0:" << endl;
	cout << "-----------------------------" << endl;
	printPath(*p_path3, "Path 3");
	delete p_path3;

	cout << "Remaining Paths after delete:" << endl;
	cout << "-----------------------------" << endl;
	printPath(path0, "Path 0");
	printPath(path1, "Path 1");
	printPath(path2, "Path 2");

	return 0;
}



PathWalked loadPath(const string& filename)
{
	ifstream in1(filename.c_str());

	// check for missing/unreadable file
	if (!in1)
	{
		cerr << "Warning: Error opening path file \"" << filename
			<< "\" - substituting empty path" << endl;
		return PathWalked();
	}

	// determine the number of positions on the path
	unsigned int count;
	in1 >> count;

	// check for bad path count
	if (!in1)
	{
		cerr << "Warning: Error reading position count in path file \""
			<< filename << "\" - substituting empty path" << endl;
		return PathWalked();
	}

	// read the positions and add them to the path
	PathWalked path;
	for (unsigned int i = 0; i < count; i++)
	{
		float x, y;
		in1 >> x;
		in1 >> y;
		path.add(Vector2(x, y));
	}

	// check for errors reading positions
	if (!in1)
	{
		cerr << "Warning: Error reading positions in path file \""
			<< filename << "\" - path may be incorrect" << endl;
		return path;
	}

	// return the completed path
	return path;
}

void printPath(const PathWalked& path, const string& name)
{
	cout << name << ":" << endl;

	// test empty function
	if (path.empty())
	{
		cout << "(Empty)" << endl;
	}
	else
	{
		// test print function
		path.print();

		// test getPathLength function
		cout << "Total Length " << path.getPathLength() << endl;
	}

	cout << endl;
}
