#include <iostream>
using namespace std;

void GetArray(int[], int);

void PrintArray(int[], int);

int MaxArray(int[], int);



int main()
{
	const int size = 10;
	int a[size], max = 0;

	GetArray(a, size);
	PrintArray(a, size);
	
	max = MaxArray(a, size);

	cout << "Maximum is:" << max << endl;
}


void GetArray(int a[], int len)
{
	cout << "Enter the 10 values of array a: " << endl;

	for (int i = 0; i < len; i++)
	{
		cin >> a[i];
	}
}



void PrintArray(int a[], int len)
{
	cout << "The elements in Array a are : ";
	
	for (int i = 0; i < len;i++)
	{
		cout << " "<< a[i];
	}
}



int MaxArray(int a[], int len)
{
	int max = a[0];
	cout << endl;
	for (int i=0; i < len ;i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}