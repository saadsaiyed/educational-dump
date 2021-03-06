#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int pthread_join (pthread_t thread, void **value_ptr);

void *print_message_function( void *ptr );

main()
{
     pthread_t thread1, thread2;
     char *message1 = "I am Thread 1";
     char *message2 = "I am Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Main continues - Thread 1 returns: %d\n",iret1);
     printf("Main continues - Thread 2 returns: %d\n",iret2);
     exit(0);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
       