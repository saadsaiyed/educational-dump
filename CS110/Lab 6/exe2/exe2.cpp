// Program IODemo demonstrates how to use EOF

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	cout << fixed << showpoint;

	float val;
	float sum = 0;
	float average = 0;
	int count = 0;
	ifstream inData;			// declares input stream
	ofstream outData;			// declares output stream

								// binds program variable inData to file "inputfile.txt"
	inData.open("inputfile.txt");

	//Testing the state of the stream
	//true means the last I/O operation on that stream succeeded
	//false means the last I/O operation on that stream failed
	if (!inData)
	{
		cout << "Can't open the input file successfuly." << endl;
		return 1;
	}

	// binds program variable outData to file "outputfile.txt"
	outData.open("outputfile.txt");

	//Testing the state of the stream
	if (!outData)
	{
		cout << "Can't open the output file successfuly." << endl;
		return 2;
	}

	//Read value from the input file
	//Loop terminates when EOF is encountered

	cout << "The initial value for count is " << count << ".  " << endl;
	cout << "Starting to process input file ... " << endl;

	inData >> val;  //read in the first value
	while (inData)   //while previous input succeeded ...
	{
		sum = sum + val;
		count++;						
		inData >> val;						

	}

	if (count != 0)
		average = sum / count;
	else
		average = 0;

	// outputs sum, count  and average
	outData << "The sum of the input values is " << sum << "." << endl;
	outData << "The number of valid input values is " << count << "." << endl;
	outData << "The average is " << average << "." << endl;
	cout << "Output has been placed in the file: outputfile.txt" << endl;

	inData.close();
	outData.close();

	return 0;
}