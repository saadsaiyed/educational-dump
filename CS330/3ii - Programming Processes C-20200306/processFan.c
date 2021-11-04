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
        x = i;
        if ((childPid = fork ()) <= 0)
        {
            printf ("I am process %d, ", getpid ());
            printf ("my parent is %d, ", getppid ());
            printf ("my child is %d, ", childPid);
            printf ("and my x is %d.\n", x);
            break;
        }
        else
        {
            printf ("I am process %d, ", getpid ());
            printf ("my parent is %d, ", getppid ());
            printf ("my child is %d, ", childPid);
            printf ("and my x is %d.\n", x);
        }
    }

    return 0;
}
