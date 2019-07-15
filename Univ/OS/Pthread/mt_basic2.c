//Standard includes. 
#include <stdio.h>
#include <unistd.h>
//Kernel includes. 
#include <pthread.h>
#include <time.h>
#define MAX_RUN_COUNT 3

//Task function prototypes. 
static void *hufsTaskX( void * arg )
{
    int runCount = 0;
    int taskIndex = *(int*) arg ;
    printf("hufsTask%d started.\n", taskIndex);
    fflush(stdout);
    while(1) {
                printf("hufsTask%d [%d] is running.\n", taskIndex, ++runCount);
                fflush(stdout);
                sleep(taskIndex *1);
                if(runCount >= MAX_RUN_COUNT) break;
    }
}
//----------------------------------------------------------

int main( void )
{
        int arg = 5;
        int status[5];
        int k;
        int name[5] = {1, 2, 3, 4, 5};
        int i;
        pthread_t thread_t[5];

        printf("Start: Sun Min Lee, 201602357\n");

        for(k=0; k<arg; k++) {
                printf("Before creating hufsTask%d.\n", k+1);
                fflush(stdout);
                if( pthread_create( &thread_t[k] , NULL, hufsTaskX , &name[k]) < 0){
                        printf("Error: was failed to create thread.");
                }
        }
        printf("After creating all tasks: now joining...\n");
        fflush(stdout);

        for(i=0 ; i<3 ; i++)
                pthread_join(thread_t[i], (void**)&status[i]);

    printf("The End: Sun Min Lee, 201602357\n");
	return 0;
}
