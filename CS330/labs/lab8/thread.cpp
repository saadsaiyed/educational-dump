#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

const int NUM_THREADS = 3;

pthread_mutex_t output_lock;
int buffer = 0;

void * say_it(void *);

int main()
{
	pthread_t *thread_ids;

	setvbuf(stdout, (char *)NULL, _IONBF, 0);

	if (pthread_mutex_init(&output_lock, NULL) != 0)
	{
		perror("Could not create mutex for output: ");
		return 1;
	}

	thread_ids = new pthread_t[NUM_THREADS];
	int *num[3];
	for(int i=0; i< 3; i++)
	{
		num[i] = new int;
		*num[i] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		if (pthread_create(&thread_ids[i], NULL, say_it, num[i]) > 0)
		{
			perror("creating thread:");
			return 2;
		}
	}
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (pthread_join(thread_ids[i], NULL) != 0)
		{
			perror("trouble joining thread: ");
			return 3;
		}

		cout <<"TID "<< thread_ids[i] << " worked on the buffer " << *num[i] << " times\n" ;
		sum += *num[i];
	}
	cout << "Total buffer accesses: " << sum << endl;
	
	return 0;
}


void * say_it(void *num)
{
	int i;
	while (buffer <= 23)
	{
		nanosleep((const struct timespec[]) { {0, 5000L} }, NULL);
		if (pthread_mutex_lock(&output_lock) != 0)
		{
			perror("Could not lock output: ");
			exit(4); 
		}
		if (buffer <= 23)
		{
			cout << "TID: " << pthread_self() << " PID: " << getpid() << " Buffer: " << (char)(buffer + 'A') << endl;
			i++;
			buffer++;
		}
		if (pthread_mutex_unlock(&output_lock) != 0)
		{
			perror("Could not unlock output: ");
			exit(5); 
		}
		
	}
	*(int *)num = i;
	return NULL;
}
