#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{
    pid_t childPid;
    int parentToChild_fd [2];
    int childToParent_fd [2];
    int n;
    char parentMessageOut [] = "Hello child!";
    char parentMessageIn [20];
    char childMessageOut [] = "Hello parent!";
    char childMessageIn [20];

    if (pipe (parentToChild_fd) == -1 || pipe (childToParent_fd) == -1)
    {
        fprintf (stderr, "Process %d failed to create pipes!\n", getpid ());
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
        close (parentToChild_fd [1]);
        close (childToParent_fd [0]);
        printf ("I am the child.\n");
        printf ("My read fd is %d and my write fd is %d.\n", parentToChild_fd [0], childToParent_fd [1]);
        if (n = write (childToParent_fd [1], childMessageOut, strlen (childMessageOut)) != strlen (childMessageOut))
        {
            fprintf (stderr, "Process %d pipe write error!\n", getpid ());
            return 1;
        }
        if ((n = read (parentToChild_fd [0], childMessageIn, sizeof (childMessageIn))) <= 0)
        {
            fprintf (stderr, "Process %d pipe read error!\n", getpid ());
            return 1;
        }
        printf ("I am the child. My message received was \"%s\".\n", childMessageIn);
    }
    else
    {
        close (childToParent_fd [1]);
        close (parentToChild_fd [0]);
        printf ("I am the parent.\n");
        printf ("My read fd is %d and my write fd is %d.\n", childToParent_fd [0], parentToChild_fd [1]);
        if (n = write (parentToChild_fd [1], parentMessageOut, strlen (parentMessageOut)) != strlen (parentMessageOut))
        {
            fprintf (stderr, "Process %d pipe write error!\n", getpid ());
            return 1;
        }
        if ((n = read (childToParent_fd [0], parentMessageIn, sizeof (parentMessageIn))) <= 0)
        {
            fprintf (stderr, "Process %d pipe read error!\n", getpid ());
            return 1;
        }
        printf ("I am the parent. My message received was \"%s\".\n", parentMessageIn);
    }

    return 0;
}