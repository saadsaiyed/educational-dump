#include<iostream>
using namespace std;

int main()
{
	double balance, cost;
	balance = 10;
	while (balance >= .99)
	{
		cout << "Enter the cost of a song: ";
		cin >> cost;
		if (balance >= cost)
		{
			balance -= cost;
			cout << "Your remaining balance is: " << balance << endl << endl;
		}
		else
		{
			cout << "your choice is too expensive!!!  Choose another one please!";
			cout << "Your remaining balance is: " << balance << endl << endl;
		}
	}
	cout << "Sorry, your balance is $0.06. You can not buy more songs.";
	return 0;
}