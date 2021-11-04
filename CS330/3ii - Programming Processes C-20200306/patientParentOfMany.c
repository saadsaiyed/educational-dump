#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
    pid_t childPid;
    int i;
    int n = 4;
    int status;
    pid_t waitPid;

    for (i = 1; i < n; i ++)
    {
        if ((childPid = fork ()) <= 0)
        {
            break;
        }
    }

    if (childPid == 0)
    {
        printf ("I am process %d", getpid ());
        printf (" and my parent is %d.\n", getppid ());
    }
    else if (childPid > 0)
    {
        printf ("I am parent %d", getpid ());
        printf (" and my most recent child is %d.\n", childPid);
    }
    else
    {
        fprintf (stderr, "Process %d failed to fork!\n", getpid ());
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
        printf (" and I'm waiting for all my children.\n");
        for (i = 1; i < n; i ++)
        {
            do
            {
                waitPid = waitpid (-1, NULL, WNOHANG);
            } while (waitPid <= 0);
            printf ("I am parent %d", getpid ());
            printf (" and child %d", waitPid);
            printf (" has arrived.\n");
        }
        printf ("I am parent %d", getpid ());
        printf (" and all my children have arrived.");
        printf (" I quit too.\n");
    }

    return 0;
}
