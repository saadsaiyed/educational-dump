#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main ()
{
    pid_t childPid;
    int status;
    int fd [2];

    if (pipe (fd) == -1)
    {
        fprintf (stderr, "Process %d failed to create pipe.\n", getpid ());
        return 1;
    }

    childPid = fork ();
    if (childPid == -1)
    {
        fprintf (stderr, "Process %d failed to fork.\n", getpid ());
        return 1;
    }

    if (childPid == 0)
    {
        printf ("I am the ls command. My stdin is %d and my stdout is %d.\n", STDIN_FILENO, STDOUT_FILENO);
        if (dup2 (fd [1], STDOUT_FILENO) == -1)
        {
            fprintf (stderr, "Process %d failed to redirect stdout of ls.\n", getpid ());
            return 1;
        }
        printf ("I am the ls command. My stdin is %d and my stdout is now the same as %d.\n", STDIN_FILENO, fd [1]);
        if ((close (fd [0]) == -1) || (close (fd [1]) == -1))
        {
            fprintf (stderr, "Process %d failed to close extra pipe descriptors of ls.\n", getpid ());
            return 1;
        }
        execl ("/bin/ls", "ls", "-l", NULL);
        fprintf (stderr, "If you see this, execl of ls failed.");
        return 1;
    }
    else
    {
        printf ("I am the sort command. My stdin is %d and my stdout is %d.\n", STDIN_FILENO, STDOUT_FILENO);
        if (dup2 (fd [0], STDIN_FILENO) == -1)
        {
            fprintf (stderr, "Process %d failed to redirect stdin of sort.\n", getpid ());
            return 1;
        }
        printf ("I am the sort command. My stdin is now the same as %d and my stdout is %d.\n", fd [0], STDOUT_FILENO);
        if ((close (fd [0]) == -1) || (close (fd [1]) == -1))
        {
            fprintf (stderr, "Process %d failed to close extra pipe descriptors of sort.\n", getpid ());
            return 1;
        }
        execl ("/bin/sort", "sort", "-k 9", NULL); // sort the 9th column
        fprintf (stderr, "If you see this, execl of sort failed.");
        return 1;
    }

    return 0;
}