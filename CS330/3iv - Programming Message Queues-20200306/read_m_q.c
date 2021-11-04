#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MESSAGE_KEY ((key_t) 7890)
#define MAX_MESSAGE_SIZE 32

typedef struct
{
    long myType;
    char myText [MAX_MESSAGE_SIZE];
} myMsg;

int main ()
{
    char c;
    int i;
    int messageBufferLength;
    int messageID;
    int messagePermissions;
    myMsg *messageBuffer;

    messagePermissions = 0666 | IPC_CREAT;

    if ((messageID = msgget (MESSAGE_KEY, messagePermissions)) == -1)
    {
        fprintf (stderr, "Process %d failed to access message queue!\n", getpid ());
        return 1;
    }

    if ((messageBuffer = (myMsg *) malloc (MAX_MESSAGE_SIZE)) == NULL)
    {
        fprintf (stderr, "Process %d failed to allocate message buffer\n", getpid ());
        return 1;
    }

    if ((messageBufferLength = msgrcv (messageID, messageBuffer, MAX_MESSAGE_SIZE, 0, 0)) == -1)
    {
        fprintf (stderr, "Process %d failed to read message!\n", getpid ());
        return 1;
    }

    printf ("Process %d read \"", getpid ());
    for (i = 0; i < 10; i ++)
    {
        printf ("%c", messageBuffer -> myText [i]);
    }
    printf ("\" from message queue.\n");

    free (messageBuffer);

    return 0;
}
