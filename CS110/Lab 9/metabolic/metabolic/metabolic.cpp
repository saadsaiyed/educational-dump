#include<iostream>

using namespace std;

void GetData(double&, double&, double&, double&, double&, double&);

void CalcVOC(double&, double, double, double);

double CalcSTP(double, double, double);

double CalcMP(double, double);

void PrintMetPower(double, double&, double&, double&, double&, double&, double&);

double const c1 = 273, c2 = 0.179;

int main()
{
	double mass, at, cp, pre, post, vaf, voc, stp, mp;




}

void GetData(double& mass, double& at, double& cp, double& pre, double& post, double& vaf)
{
	cout << "Please input the mass of the animal: ";
	cin >> mass;

	cout << "Please input the ambient temperature: ";
	cin >> at;

	cout << "Please input chamber pressure: ";
	cin >> cp;

	cout << "Please input concentration of oxygen in ambient air (pre-animal): ";
	cin >> pre;

	cout << "Please input concentration of oxygen in ambient air (post-animal): ";
	cin >> post;

	cout << "Please input the rate of oxygen: ";
	cin >> vaf;
}

void CalcVOC(double& voc, double vaf, double pre, double post)
{
	voc = vaf * (pre - post) / (1 - post);
}

double CalcSTP(double voc, double cp, double at)
{
	return voc * (cp / 760) * (c1 / (c1 + at));
}

double CalcMP(double stp, double mass)
{

}