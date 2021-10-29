#include<iostream>
using namespace	std;
int main()
{

	int dollars, quarters, dimes, nickels, pennies;
	double no, cents;

	cout << "\n\tEnter the amount: ";
	cin >> no;

	dollars = no;

	no = no - dollars;

	pennies = no * 100;

	quarters = pennies / 25;
	pennies = pennies % 25;

	dimes = pennies / 10;
	pennies = pennies % 10;

	nickels = pennies / 5;
	pennies = pennies % 5;

	cout << "\n\tMax number of Dollars: " << dollars << "\n\tMax number of Quarters: " << quarters << "\n\tMax number of Dimes: " << dimes << "\n\tMax number of Nickels: " << nickels << "\n\tMax number of Pennies: " << endl;


	return 0;
}