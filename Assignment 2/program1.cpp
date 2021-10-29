#include<iostream>
using namespace std;

int main()
{
	int marks; //creating variable marks

	cout << "Enter marks : "; //printing 
	cin >> marks; //gathering value of variable marks


	if (marks < 0 || marks > 100) //starting arguments with 'if statement 
		{
			cout << "Please Enter marks between 0-100" << endl;
		}

		else if (marks > 80) //continuing argument with 'nested if'
			{
				cout << "Exemplary performance." << endl;
			}
			else if (marks > 70)
				{
					cout << "Proficient performance." << endl;
				}
				else if (marks > 60)
					{
						cout << "Adequate performance." << endl;
					}
					else if (marks > 50)
						{
							cout << "Limited performance." << endl;
						}
						else //ending argumnet with 'else'
							{
								cout << "Week performance." << endl;
							}
}