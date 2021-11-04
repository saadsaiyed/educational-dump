#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
    int fd;
    int fdNew;
    char fileName [100];
    char buffer [100];
    ssize_t bytesRead;

    fprintf (stderr, "My stdin is %d and my stdout is %d.\n", STDIN_FILENO, STDOUT_FILENO);
    if (write (STDOUT_FILENO, "Enter file name: ", 17) == -1)
    {
        fprintf (stderr, "Process %d failed to write prompt.\n", getpid ());
        return 1;
    }
    if ((bytesRead = read (STDIN_FILENO, fileName, 100)) == -1)
    {
        fprintf (stderr, "Process %d failed to read file name.\n", getpid ());
        return 1;
    }
    fileName [bytesRead - 1] = '\0';
    fd = open (fileName, O_RDONLY);
    if (fd == -1)
    {
        fprintf (stderr, "Process %d failed to open file.\n", getpid ());
        return 1;
    }
    if ((fdNew = dup2 (fd, STDIN_FILENO)) == -1)
    {
        fprintf (stderr, "Process %d failed to redirect stdin from file.\n", getpid ());
        return 1;
    }
    fprintf (stderr, "My stdin is now the same as %d and my stdout is as %d.\n", fd, STDOUT_FILENO);
    if (close (fd) == -1)
    {
        fprintf (stderr, "Process %d failed to close file.\n", getpid ());
        return 1;
    }
    if ((bytesRead = read (fdNew, buffer, 100)) == -1)
    {
        fprintf (stderr, "Process %d failed to read file.\n", getpid ());
        return 1;
    }
    buffer [bytesRead] = '\0';
    printf ("buffer = %s\n", buffer);

    return 0;
}
