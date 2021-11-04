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
        fprintf (stderr, "Process %d failed to access message queue!\n", getpid ());
        return 1;
    }

    if (msgctl (messageID, IPC_RMID, NULL) == -1)
    {
        fprintf (stderr, "Process %d has failed to deallocate message queue %d!\n", getpid (), messageID);
        return 1;
    }

    printf ("Process %d has deallocated message queue %d.\n", getpid (), messageID);

    return 0;
}