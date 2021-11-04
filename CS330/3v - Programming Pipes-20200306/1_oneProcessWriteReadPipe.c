#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{
    pid_t childPid;
    int fd [2];
    int n;
    char messageOut [] = "Im talking to myself!\n";
    char messageIn [30];

    if (pipe (fd) == -1)
    {
        fprintf (stderr, "Process %d failed to create pipe!\n", getpid ());
        return 1;
    }

    printf ("My read fd is %d and my write fd is %d.\n", fd [0], fd [1]);

    printf ("I’m going to send myself this message: %s", messageOut);
    if (n = write (fd [1], messageOut, strlen (messageOut)) != strlen (messageOut))
    {
        fprintf (stderr, "Process %d pipe write error!\n", getpid ());
        return 1;
    }

    if ((n = read (fd [0], messageIn, sizeof (messageIn))) <= 0)
    {
        fprintf (stderr, "Process %d pipe read error!\n", getpid ());
        return 1;
    }

    printf ("I’ve received a message from myself. The message is:\n");
    write (1, messageIn, n); // What does the 1 correspond to in the last write statement?

    return 0;
}
