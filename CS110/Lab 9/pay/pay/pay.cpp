#include<iostream>

using namespace std;

void GetData(double&, double&);

double CalcPay(double, double);

void PrintPay(double);

int main()
{
	double pay, hours, wage;

	cout << "This program calculates total pay for an employee." << endl;

	GetData(pay, hours);

	wage = CalcPay(pay, hours);

	PrintPay(wage);

	cout << "For an employee who worked " << hours << " hours with a pay rate $ " << pay << " per hour," << endl;
}

void GetData(double & p, double & h)
{
	cout << "please enter pay rate per hour: ";
	cin >> p;
	cout << "Please enter hours worked: ";
	cin >> h;
}

double CalcPay(double p, double h)
{
	return p*h;
}

void PrintPay(double w)
{
	cout << "The total pay is $ " << w << endl;
}