/*
* CS 340 Assignment 3 Q3
* 
* Compiled with Visual Studio
*/

// A)
#include <iostream>

using namespace std;

void maxHeapify(int* array, int i, int n);
void buildHeap(int* array);
void print_array(int* a);
void whatDoIDo(int* array);

const int arrSize = 10;

int main()
{
    int a[arrSize];
    int b[arrSize];
    int c[arrSize];

    cout << "Give 10 numbers with space in between a):";
    int i = 0;
    while (i < 10)
    {
        cin >> a[i++];
    }

    cout << "Give 10 numbers with space in between b):";
    i = 0;
    while (i < 10)
    {
        cin >> b[i++];
    }

    cout << "Give 10 numbers with space in between c):";
    i = 0;
    while (i < 10)
    {
        cin >> c[i++];
    }

    whatDoIDo(a);
    whatDoIDo(b);
    whatDoIDo(c);

    return 0;
}

void maxHeapify(int* array, int i, int n)
{
    int value = array[i];
    int j = 2 * i;

    while (j <= n)
    {
        if (array[j + 1] > array[j] && j < n) j = j + 1;
        if (value > array[j]) break;
        else if (value <= array[j])
        {
            array[j / 2] = array[j];
            j = 2 * j;
        }
    }
    array[j / 2] = value;
}
void buildHeap(int* array)
{
    for (int i = arrSize / 2; i >= 1; i--)
    {
        maxHeapify(array, i, arrSize - 1);
    }
}
void print_array(int* array)
{
    cout << "------START------\n  {";

    int i = 0;
    while (i < arrSize)
    {
        cout << *(array + i++);
        if (i < arrSize) cout << ", ";
    }
    
    cout << "}\n-------END-------\n" << endl;
}
/*
Input/Output for duplicate-free arrays of size about 10.

    Give 10 numbers with space in between a):96 22 12 36 8 93 17 13 11 68
    Give 10 numbers with space in between b):99 96 100 5 85 49 46 15 29 74
    Give 10 numbers with space in between c):80 71 61 51 78 86 19 10 33 41
    ------START------
      {93, 68, 36, 22, 12, 17, 13, 11, 8, 96}
    -------END-------

    ------START------
      {100, 96, 46, 85, 49, 5, 15, 29, 74, 99}
    -------END-------

    ------START------
      {86, 78, 51, 71, 61, 19, 10, 33, 41, 80}
    -------END-------
*/


/*
* B)
* Firstly we call 'buildHeap()' function to create an array in heap space.
* And then we start a loop from j = size of array - 1 as long as j > 0.
* Inside loop we do following things
*   i.      Swap the entries array[0] and array[j].
*   ii.     Percolate down array[0].
*   iii.    Decrement j by 1.
* 
* Explanation: 
*   Basically we go in the process of buildHeap we perform maxHeapify 
*   which is a method that converts a binary tree where every node has
*   child less than or equal to itself. After that we perform swapping
*   which is pretty basic. And at last we print the resulting array.
*/

void whatDoIDo(int* array)
{
    buildHeap(array);

    int j = arrSize - 1;
    int tempArrSwapper;
    while (j > 0)
    {
        tempArrSwapper = array[0];
        array[0] = array[j];
        array[j--] = tempArrSwapper;
    }

    print_array(array);
}


/*
* C)
* Worst case run time is O(n^2 log(n))
*/