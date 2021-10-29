// Program functionP prints a triangle of the stars.
// For example:  
//		 *****
//		 ****
//		 ***
//		 **
//		 *

#include <iostream>
#include <iomanip>
using namespace std;

void PrintStars(int);

int main()
{
	int  numofstars;

	cout << "Enter the number of stars in the first line: " << endl;
	cin >> numofstars;

	while (numofstars > 0)
	{

		PrintStars(numofstars);
		numofstars--;
	}

	return 0;
}

//****************************************************************************

void PrintStars(int NUM)
{
	/* FILL IN Code to print the number of NUM stars in a line by using a loop*/
	
	for (int i = 0; i < NUM; i++)
		cout << "*";

	cout << endl;

}
