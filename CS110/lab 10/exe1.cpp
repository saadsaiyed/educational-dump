#include <iostream>
using namespace std;

int main()
{
	const int size = 10;

	int a[size], sum= 0;

	
	for (int  i = 0; i < size; i++)
	{
		cout << "Enter the 10 values of array a: ";
		cin >> a[i];
	}
	
	
	cout << "Index in Ascending: ";
	for (int i = 0; i < size ;i++)
	{
		cout << " "<< a[i];
	}
	
	
	cout << endl << "Index in Descending: ";
	for (int i = size-1; i >= 0 ;i--)
	{
		cout << " " << a[i];
	}
	
		
	for (int i = 0;i < size;i++)
	{
		sum += a[i];
	}
	cout << endl << "The TOTAL IS: " << sum << endl;
}