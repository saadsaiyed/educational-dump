//
// Program to test "is_even" function.
//

#include <iostream>
using namespace std;



void is_even(int); // Function Prototype

int main()
{
	int num;
	cout << "Enter an integer:\n";
	cin >> num;
	cout << "Is " << num << " even?  ";
	is_even(num);
	cout << endl;
	return 0;
}

// "is_even" function.
// Prints "yes" if a is even, "no" otherwise.

void is_even(int a)
{
	if (a %2==0)
	{
		cout << "Yes it is ";
	}
	else
	{
		cout << "No its not";
	}
}
