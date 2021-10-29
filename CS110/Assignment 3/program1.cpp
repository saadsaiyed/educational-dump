#include<iostream>

using namespace std;

int main()
{
	int n, ans;											//declaring variables
	cout << " enter an integer number: "; 
	cin >> n;											//storing value at the address of variable n
	do													//initiating do...while loop
	{
		ans = n / 3;									//claculation 
		cout << n << " / 3 = " << ans << endl;			//output with variable value
		n = ans;										//changing vlaue of variable n
	} while (n/3!=0);									// ending do...while loop
	return 0;
}
