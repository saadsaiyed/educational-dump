/*

1)  What is Dr. Hilderman's code tokenizing based on (ie. what delimeter(s) separate(s) his words)?
->  " " - i.e. an empty space or white space

2)  What are two reasons why his tokens are strings instead of c strings
->  a. Because String is easy to compare in C++ then C
    b. Also to allocate string array we can use C++ then C for better understanding
*/
#include "HALmod.h"

int main()
{
    string tokens [MAX_COMMAND_LINE_ARGUMENTS];
    int tokenCount;

    do
    {
        tokenCount = GetCommand (tokens);
    } while (ProcessCommand (tokens, tokenCount));

    return 0;
}