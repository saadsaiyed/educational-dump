#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
	long double OH=0, pH, H;
	cout << "Please input the concentration of hydroxide: ";
	cin >> OH;
	cout << fixed << setprecision(10);
	
	while (OH!=0)
	{

			

			H = pow(10, -14) / OH;
			//cout << H;
			pH = (log10(H));
			pH = (pH)*(-1);

			
			cout << endl << "The pH level of solution " << OH << "is " << pH << "\t";

			if (pH < 7)

				cout << "The solution is acidic." << endl << endl;

			if (pH >= 7)

				cout << "The solution is basic." << endl << endl;

			//if (pH == 0)

			//	cout << "The solution is nutral." << endl << endl;

			cout << "Please input the concentration of hydroxide: ";
			cin >> OH;

		
	}
	return 0;
}