#include <pthread.h>
#include <sys/resource.h>
#include <sys/time.h>
#define PERIOD 1000
#define MAXRUNCNT 10000

#include <stdio.h>
#include <stdlib.h>

extern void *myRunCntTask(void* arg) {
   pthread_t thr_id;
   int runCnt = 0;
   double elapsedT;
   struct timespec startT, endT;
   struct rusage usage;
   struct timeval sT, eT;
   getrusage(RUSAGE_SELF, &usage);
   sT = usage.ru_utime;
   clock_gettime(CLOCK_REALTIME, &startT);
   pthread_create(&thr_id, NULL, myTunCntTask, NULL);
   while(1) {
      runCnt++;
      printf("runCnt=%d\r", runCnt);
      if (runCnt > MAXRUNCNT) {
         clock_gettime(CLOCK_REALTIME, &endT);
         elapsedT = endT.tv_sec - startT.tv_sec + (endT.tv_nsec - startT.tv_nsec)/1e9L;
         printf("now exits. Elapsed time=%0.9lf\n", elapsedT);
         getrusage(RUSAGE_SELF, &usage);
         eT = usage.ru_utime;
         elapsedT = eT.tv_sec - sT.tv_sec + (eT.tv_usec - sT.tv_usec)/1e6L;
         printf("now exits. Net resource usage time=%0.6lf\n", elapsedT);
         exit(0);
      }
      usleep(PERIOD);
   }
}
