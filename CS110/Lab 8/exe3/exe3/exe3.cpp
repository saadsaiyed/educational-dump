#include <iostream>
#include <iomanip>
using namespace std;

double AVG(int, int, int, int, int);

int main()
{
	int one, two, three, four, five;

	cout << "Enter five integers" << endl;
	cin >> one >> two >> three >> four >> five;

	cout << "The average of " << one <<",\" hi\" " << two << ", " << three << ", " << four << " and " << five << " is " << AVG(one, two, three, four, five)<< endl;

	return 0;
}

double AVG(int a, int b, int c, int d, int e)
{
	return (a + b + c + d + e) / 5.0;
}