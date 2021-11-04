#include <stdio.h>
#include <string.h>
#include <unistd.h>

// using namespace std;

int main ()
{
    pid_t childPid;
    int fd [2];
    int n;
    char messageOut [] = "Hello parent!\n";
    char messageIn [20];

    if (pipe (fd) == -1)
    {
        fprintf (stderr, "Process %d failed to create pipe!\n", getpid ());
        return 1;
    }

    childPid = fork ();
    if (childPid == -1)
    {
        fprintf (stderr, "Process %d failed to fork!\n", getpid ());
        return 1;
    }

    if (childPid == 0)
    {
        printf ("I am the child.\n");
        printf ("My read fd is %d and my write fd is %d.\n", fd [0], fd [1]);
        close (fd [0]);
        printf ("I am the child and have closed the read end of the pipe.\n");
        if (n = write (fd [1], messageOut, strlen (messageOut)) != strlen (messageOut))
        {
            fprintf (stderr, "Process %d pipe write error!\n", getpid ());
            return 1;
        }
    }
    else
    {
        printf ("I am the parent.\n");
        printf ("My read fd is %d and my write fd is %d.\n", fd [0], fd [1]);
        close (fd [1]);
        printf ("I am the parent and have closed the write end of the pipe.\n");
        if ((n = read (fd [0], messageIn, sizeof (messageIn))) <= 0)
        {
            fprintf (stderr, "Process %d pipe read error!\n", getpid ());
            return 1;
        }
        printf ("I am the parent and have received a message. The message is:\n");
        write (1, messageIn, n);
    }

    return 0;
}