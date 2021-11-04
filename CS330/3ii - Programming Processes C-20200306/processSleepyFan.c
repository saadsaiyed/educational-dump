#include <stdio.h>
#include <unistd.h>

int main ()
{
    pid_t childPid = 0;
    int i;
    int n = 4;
    int x = 0;

    for (i = 1; i < n; i ++)
    {
        if ((childPid = fork ()) <= 0)
        {
            break;
        }
    }

    x = i;
    printf ("I am process %d, ", getpid ());
    printf ("my parent is %d, ", getppid ());
    if (childPid > 0)
    {
        printf ("my most recent child is %d, ", childPid);
    }
    printf ("and my x is %d.\n", x);

    sleep (10);
    printf ("I am process %d and I am quitting.\n", getpid ());

    return 0;
}
