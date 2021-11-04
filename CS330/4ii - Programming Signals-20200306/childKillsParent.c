#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main ()
{
    pid_t childPid;
    int status;
    pid_t waitPid;

    childPid = fork ();
    if (childPid == -1)
    {
        fprintf (stderr, "Child %d failed to fork!\n", getpid ());
        return 1;
    }

    if (childPid == 0)
    {
        printf ("I am process %d", getpid ());
        printf (" and I'm going to kill my parent %d!\n", getppid ());
        printf ("But first, I have to sneak up on her. Sssshhh!\n");
        sleep (5);
        printf ("Hosta la vista, baby! I’ll be back!\n");
        printf ("Momma ");       
        if (kill (getppid (), SIGTERM) == -1)
        {
            fprintf (stderr, "Process %d failed to kill %d.\n", getpid (), getppid ());
        }
    }
    else if (childPid > 0)
    {
        printf ("I am parent %d", getpid ());
        printf (" and I'm waiting for my loving child %d.\n", childPid);
        do
        {
            waitPid = wait (&status);
        } while (waitPid != childPid);
        printf ("This should never print!\n");
    }

    return 0;
}
