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

static PathWalked loadPath (const string& filename);
static void printPath (const PathWalked& path, const string& name);



int main ()
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



PathWalked loadPath (const string& filename)
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
	for(unsigned int i = 0; i < count; i++)
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

void printPath (const PathWalked& path, const string& name)
{
	cout << name << ":" << endl;

	// test empty function
	if(path.empty())
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

