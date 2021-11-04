#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    pid_t childPid;
    int status;
    pid_t waitPid;

    childPid = fork ();
    if (childPid == 0)
    {
        printf ("I am process %d", getpid ());
        printf (" and my parent is %d.\n", getppid ());
    }
    else if (childPid > 0)
    {
        printf ("I am parent %d", getpid ());
        printf (" and my child is %d.\n", childPid);
    }
    else
    {
        fprintf (stderr, "Process %d failed to fork!\n");
        return 1;
    }

    printf ("I am process %d.\n", getpid ());

    if (childPid == 0)
    {
        sleep (5);
        printf ("I am process %d", getpid ());
        printf (" and I quit.\n");
    }
    else
    {
        printf ("I am parent %d", getpid ());
        printf (" and I'm waiting for child %d.\n", childPid);
        do
        {
            waitPid = wait (&status);
        } while (waitPid != childPid);
        printf ("I am parent %d", getpid ());
        printf (" and my child %d", childPid);
        printf (" has arrived. I quit too.\n");
    }

    return 0;
}
