#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define THREAD_NUM 2

//Task function prototypes. 
static void *disp_time( void * arg ) {
    time_t rawt;
    struct tm *t;
    while(1) {
        time(&rawt);
        t = localtime(&rawt);
        printf("Time: %02d:%02d:%02d\r", t->tm_hour, t->tm_min, t->tm_sec);
        fflush(stdout);
        sleep(1);
    }
}

static void *quitProcess( void * arg ) {
    char c;

    scanf("%c", &c);
    fflush(stdout);
    printf("Bye~\n");    
    exit();
}

//----------------------------------------------------------
int main( void ) {
    
    int status[THREAD_NUM], t;
    pthread_t thread_t[THREAD_NUM];

    char c;
    printf("Sun Min Lee 201602357\n");
    printf("Press any key and Enter to quit the program.... \n");
    fflush(stdout);

    if( pthread_create( &thread_t[0], NULL, disp_time, NULL) < 0){
        printf("Error: was failed to create thread.");
    }
    if( pthread_create( &thread_t[1], NULL, quitProcess, NULL) < 0){
        printf("Error: was failed to create thread.");
    }

    for(t=0; t<THREAD_NUM; t++) {
        pthread_join(thread_t[t], (void**)&status[t]);
    } 

    return 0;
}

