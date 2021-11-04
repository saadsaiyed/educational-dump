#include <stdio.h>
#include <unistd.h>

int main ()
{
    int x = 0;

fork ();
x = 1;
printf ("I am process %d, ", getpid ());
printf ("my parent is %d, ", getppid ());
printf ("and my x is %d.\n", x);

return 0;
}
