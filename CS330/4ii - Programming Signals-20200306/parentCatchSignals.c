#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

static volatile sig_atomic_t signalDelivered;

static void SignalHandler (int signalNo, siginfo_t *info, void *context);
sigset_t interruptMask;
struct sigaction act;

int main ()
{
    pid_t childPid;

    if ((sigemptyset (&interruptMask) == -1) ||
        (sigaddset (&interruptMask, SIGUSR1) == -1) ||
        (sigaddset (&interruptMask, SIGUSR2) == -1) ||
        (sigaddset (&interruptMask, SIGTERM) == -1))
    {
        fprintf (stderr, "Process %d can't initialize interrupt mask\n", getpid ());
        exit (1);
    }

    act.sa_sigaction = &SignalHandler;
    act.sa_mask = interruptMask;
    act.sa_flags = SA_SIGINFO;

    
    if (sigaction (SIGUSR1, &act, NULL) == -1)
    {
        fprintf (stderr, "Process %d can't catch SIGUSR1!\n", getpid ());
        exit (1);
    }
    if (sigaction (SIGUSR2, &act, NULL) == -1)
    {
        fprintf (stderr, "Process %d can't catch SIGUSR2!\n", getpid ());
        exit (1);
    }
    if (sigaction (SIGTERM, &act, NULL) == -1)
    {
        fprintf (stderr, "Process %d can't catch SIGTERM!\n", getpid ());
        exit (1);
    }
    
    childPid = fork ();
    if (childPid == -1)
    {
        fprintf (stderr, "Child %d failed to fork!\n", getpid ());
        return 1;
    }
    if (childPid == 0)
    {
        sleep (2);
        printf ("I am process %d", getpid ());
        printf (" and I'm going to signal parent %d.\n", getppid ());
        if (kill (getppid (), SIGUSR1) == -1)
        {
            fprintf (stderr, "Process %d failed to signal %d.\n", getpid (), getppid ());
        }
        sleep (2);
        printf ("I am process %d", getpid ());
        printf (" and I'm going to signal parent %d.\n", getppid ());
        if (kill (getppid (), SIGUSR2) == -1)
        {
            fprintf (stderr, "Process %d failed to signal %d.\n", getpid (), getppid ());
        }
        sleep (2);
        printf ("I am process %d", getpid ());
        printf (" and I'm going to kill parent %d.\n", getppid ());
        if (kill (getppid (), SIGTERM) == -1)
        {
            fprintf (stderr, "Process %d failed to kill %d.\n", getpid (), getppid ());
        }
    }
    else if (childPid > 0)
    {
        printf ("I am parent %d", getpid ());
        printf (" and I'm pausing for child %d.\n", childPid);
        do
        {
            pause ();
            if (signalDelivered == SIGUSR1)
            {
                printf ("Process %d received SIGUSR1.\n", getpid ());
            }
            else if (signalDelivered == SIGUSR2)
            {
                printf ("Process %d received SIGUSR2.\n", getpid ());
            }
            else if (signalDelivered == SIGTERM)
            {
                printf ("I am parent %d", getpid ());
                printf (" and I'm very disappointed my child %d killed me.\n", childPid);
                printf ("I am parent %d.", getpid ());
                printf (" Hosta la vista, baby! Yeah, that's right, I'll be back!\n");
                return 0;
            }
        } while (1);
        printf ("This should never print!\n");
    }

    return 0;
}

static void SignalHandler (int signalNo, siginfo_t *info, void *context)
{
    signalDelivered = signalNo;
}
