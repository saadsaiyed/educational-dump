#include "HALmod.h"

int GetCommand (string tokens [])
{
    string commandLine;
    bool commandEntered;
    int tokenCount;

    do
    {
        printf( "HALshell> ");
        while (1)
        {
            getline (cin, commandLine);
            commandEntered = CheckForCommand ();
            if (commandEntered)
            {
                break;
            }
           
        }
    } while (commandLine.length () == 0);

    tokenCount = TokenizeCommandLine (tokens, commandLine);

    return tokenCount;
}

int TokenizeCommandLine (string tokens [], string commandLine)
{
    char *token [MAX_COMMAND_LINE_ARGUMENTS];
    char *workCommandLine = new char [commandLine.length () + 1];
    int i;
    int tokenCount;

    for (i = 0; i < MAX_COMMAND_LINE_ARGUMENTS; i ++)
    {
        tokens [i] = "";
    }
    strcpy (workCommandLine, commandLine.c_str ());
    i = 0;
    if ((token [i] = strtok (workCommandLine, " ")) != NULL)
    {
        i ++;
        while ((token [i] = strtok (NULL, " ")) != NULL)
        {
            i ++;
        }
    }
    tokenCount = i;

    for (i = 0; i < tokenCount; i ++)
    {
        tokens [i] = token [i];
    }

    delete [] workCommandLine;

    return tokenCount;
}


//Do not touch the below function
bool CheckForCommand ()
{
    if (cullProcess)
    {
        cullProcess = 0;
        cin.clear ();
        printf("\b\b  \b\b");
        return false;
    }

    return true;
}

	
//This is a very paired down version of Dr. Hilderman's function
int ProcessCommand (string tokens [], int tokenCount)
{
    if (tokens [0] == "shutdown" || tokens [0] == "restart" || token[0] == "lo")
    {
    	if (tokenCount > 1)
    	{
       		printf("HALshell: " << tokens [0] << " does not require any arguments\n");
        	return 1;
    	}
    	printf("\nHALshell: terminating ...\n");

        return 0;
    }
    else
	return 1;
}

char ** ConvertToC (string tokens [], int tokenCount){
    char ** newToken;
    

    return;
}

void CleanUpCArray (char ** cTokens, int tokenCount){

}


void PrintReverse (char ** cTokens, int tokenCount){

}