// Program LineCt counts the number of characters per line
// and the number of lines in a file.
// Assumption:  There is a '\n' before the EOF.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int lineNo;
	char character;
	int number;
	ifstream inData;

	inData.open("LineData.txt");
	lineNo = 0;
	inData.get(character);

	while (inData)	//while not EOF, go into the loop
							// place the "while" statement here
	{
		lineNo++;
		number = 0;


									//while not "end of line", go into the loop
		while (character!='\n'&& !inData.eof())		// place another "while" statement here
		{
			inData.get(character);	// use get() function here to get a character and 
			number++;				// add to the "number" variable which counts characters
		}

		cout << "Line " << lineNo << " contains "
			<< number << " characters." << endl;
		inData.get(character); // clear out the \n
	}

	inData.close();
	return 0;
}
