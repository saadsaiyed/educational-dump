// Compile:
//      gcc forkExev.c -o parent
// Call:
//      % parent /bin/ls -l 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv [])
{
    pid_t childPid;
    int status;
    pid_t waitPid;

    childPid = fork ();
    if (childPid == 0)
    {
        sleep (2);
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
        execv (argv [1], &argv [1]);
        fprintf (stderr, "If you see this, execv failed.");
        return 1;
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
        printf (" has arrived.\n");
    }

    return 0;
}
