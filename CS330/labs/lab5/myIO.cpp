#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[])
{
  if(argc != 2)
    printf("error! not enough arguments\n");

  else
    {
      int status;
      pid_t fork_return;

      fork_return = fork();

      if(fork_return == 0)
	{
	  int inFile;
	  int n_char = 0;
	  char buffer[10];

	  inFile = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	  if(inFile == -1)
	    {
	      perror("Error");
	      exit(1);
	    }

	  while( (n_char = read(0, buffer, 10)) != 0 )
	    {
	      n_char = write(inFile,buffer,n_char);
	    }

	  close (inFile);
	}

      else if(fork_return > 0)
	{
	  wait(&status);

	  printf("\nParent\n");

	  int inFile;
	  int n_char = 0;
	  char buffer[10];

	  inFile = open(argv[1], O_RDONLY);

	  if(inFile == -1)
	    {
	      perror("Error");
	      exit(1);
	    }

	  while( (n_char = read(inFile, buffer, 10)) != 0 )
	    {
	      n_char = write(1,buffer,n_char);
	    }

	  close (inFile);
	}

        else
	        printf("fork failed.");
    }

  return 0;
}