#include <iostream>
using namespace std;
int main()
{
	int firstline;

	cout << "enter no. of lines you want: ";
	cin >> firstline;

	for (int total = firstline; total > 0; total--)
	{
		for (int print = 0;print < total;print++)
		{
			cout << "* ";
		}

		cout << "\n";
	}
	return 0;
}