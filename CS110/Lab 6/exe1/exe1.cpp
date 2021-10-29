// Program Count prompts for the number of integers to sum.
// It then reads the integers in a loop, summing them.
// Finally, it prints the sum.

#include <iostream>
using namespace std;

int main()
{
	int  sum = 0;                 // summing variable
	int  dataValue;               // input value

	int count;							  // add an int declaration statement here for the loop counter

	int total;							  // add an int declaration statement here for the loop total

	count = 0;								// add an assignment statement here to set the loop counter to 0
	
	cout << "Please input the number of integers that you would like to add: ";							  // add a cout statement here to prompt the user how many numbers
								  //     he/she wants to add i.e. the loop total

	cin >> total;						  // add a cin statement here to get the loop total

	while (count < total)						  // add a while statement here to test the loop counter
							
	{
		cout << "Enter an integer value.  Press return." << endl;
		cin >> dataValue;
		sum = sum + dataValue;

		count++;// add a statement here to increment your counter variable


	}  // end of while loop

	cout << endl << "The sum is " << sum << endl;
	return 0;
}
