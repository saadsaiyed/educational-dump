#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

#define MESSAGE_KEY ((key_t) 7890)

typedef struct
{
    long myType;
    char myText [1];
} myMsg;

int main ()
{
    int i;
    int messageID;
    int messageLength;
    int messagePermissions;
    myMsg *messageBuffer;
    char messageText [] = "My message";

    messagePermissions = 0666 | IPC_CREAT;

    if ((messageID = msgget (MESSAGE_KEY, messagePermissions)) == -1)
    {
        fprintf (stderr, "Process %d failed to access message queue!\n", getpid ());
        return 1;
    }

    messageLength = strlen (messageText);
    if ((messageBuffer = (myMsg *) malloc (sizeof (myMsg) + messageLength)) == NULL)
    {
        fprintf (stderr, "Process %d failed to allocate message buffer!\n", getpid ());
        return 1;
    }
    messageBuffer -> myType = 1;
    for (i = 0; i < 10; i ++)
    {
        messageBuffer -> myText [i] = messageText [i];
    }
    if (msgsnd (messageID, messageBuffer, messageLength, 0) == -1)
    {
        fprintf (stderr, "Process %d failed to send message!\n", getpid ());
        return 1;
    }

    printf ("Process %d sent message.\n", getpid ());

    free (messageBuffer);

    return 0;
}
