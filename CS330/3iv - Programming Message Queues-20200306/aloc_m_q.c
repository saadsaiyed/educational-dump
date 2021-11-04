#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MESSAGE_KEY ((key_t) 7890)

int main ()
{
    int messageID;
    int messagePermissions;

    messagePermissions = 0666 | IPC_CREAT;

    if ((messageID = msgget (MESSAGE_KEY, messagePermissions)) == -1)
    {
        fprintf (stderr, "Process %d failed to allocate message queue!\n", getpid ());
        return 1;
    }

    printf ("Process %d allocated message queue %d and quit.\n", getpid (), messageID);

    return 0;
}