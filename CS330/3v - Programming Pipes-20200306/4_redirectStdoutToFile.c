// O_WRONLY : open for writing only
// O_CREAT : create if nonexistant
// O_APPEND : set append mode

// S_IRUSR : READ for owner
// S_IWUSR : WRITE for owner

// STDIN_FILENO == 0 : standard input
// STDOUT_FILENO == 1 : standart output

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define CREATE_FLAGS (O_WRONLY | O_CREAT | O_APPEND)
#define CREATE_MODE (S_IRUSR | S_IWUSR)

int main ()
{
    int fd;
    int fdNew;

    
    fprintf (stderr, "My stdin is %d and my stdout is %d.\n", STDIN_FILENO, STDOUT_FILENO);
    write (1, "\nThis in going to...?\n\n", 23);
    fd = open ("junk.txt", CREATE_FLAGS, CREATE_MODE);
    if (fd == -1)
    {
        fprintf (stderr, "Process %d failed to open junk.txt.\n", getpid ());
        return 1;
    }
    if ((fdNew = dup2 (fd, STDOUT_FILENO)) == -1)
    {
        fprintf (stderr, "Process %d failed to redirect stdout to junk.txt.\n", getpid ());
        return 1;
    }
    fprintf (stderr, "My stdin is %d and my stdout is now the same as %d.\n", STDIN_FILENO, fd);
    if (close (fd) == -1)
    {
        fprintf (stderr, "Process %d failed to close junk.txt.\n", getpid ());
        return 1;
    }
    if (write (fdNew, "OK", 2) == -1)
    {
        fprintf (stderr, "Process %d failed to write to junk.txt.\n", getpid ());
        return 1;
    }
    write (1, "\nThis in going to...?\n\n", 23);

    return 0;
}
