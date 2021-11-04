#include <stdio.h>
#include <unistd.h>

int main ()
{
    pid_t childPid = 0;
    int x = 0;

    childPid = fork ();
    if (childPid == -1)
    {
        fprintf (stderr, "Process %d failed to fork!\n", getpid ());
        return 1;
    }

    if (childPid == 0)
    {
        x = 2;
        printf ("I am the child ");
    }
    else
    {
        x = 1;
        printf ("I am the parent ");
    }
    printf ("%d, ", getpid ());
    printf ("my parent is %d, ", getppid ());
    printf ("and my x is %d.\n", x);

    return 0;
}
