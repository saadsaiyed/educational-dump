#include<iostream>
using namespace std;
int main()
{
	double foot, meter;

	cout << "Enter the value of foot: " << endl;
	cin >> foot;
	
	meter = (0.3048) * foot;

	cout << "The value of meter is : " << meter << endl;
}
