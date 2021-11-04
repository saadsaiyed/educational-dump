/*
Open two terminals. 
In the first one run this program. Nothing will happen, the propgram will halt/
In the second terminal, it is time to signal for your life.
    TO TEST SIGNAL RECEIVING:
        killall -SIGUSR1  <name of the process>
        killall -SIGUSR2  <name of the process>
    TO STOP:
        killall -SIGSTOP <name of the process>
    TO CONTINUE:
        killall -SIGCONT <name of the process>
        >> After the program is running in the background
    TO TERMINATE:
        killall -SIGINT <name of the process> 
    TO TERMINATE WITH SGMENTATION FAULT:
        killall -SIGSEGV <name of the process> 
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t signalDelivered;

static void SignalHandler (int signalNo, siginfo_t *info, void *context);
sigset_t interruptMask;
struct sigaction act;

int main ()
{
    if ((sigemptyset (&interruptMask) == -1) ||
        (sigaddset (&interruptMask, SIGUSR1) == -1) ||
        (sigaddset (&interruptMask, SIGUSR2) == -1))
    {
        fprintf (stderr, "Process %d can’t initialize interrupt mask!\n", getpid ());
        exit (1);
    }

    act.sa_sigaction = &SignalHandler;
    act.sa_mask = interruptMask;
    act.sa_flags = SA_SIGINFO;

    if (sigaction (SIGUSR1, &act, NULL) == -1)
    {
        fprintf (stderr, "Process %d can’t catch SIGUSR1!\n", getpid ());
        exit (1);
    }
    if (sigaction (SIGUSR2, &act, NULL) == -1)
    {
        fprintf (stderr, "Process %d can't catch SIGUSR2!\n", getpid ());
        exit (1);
    }
   
    while (1)
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
    }

    return 0;
}

static void SignalHandler (int signalNo, siginfo_t *info, void *context)
{
    signalDelivered = signalNo;
}