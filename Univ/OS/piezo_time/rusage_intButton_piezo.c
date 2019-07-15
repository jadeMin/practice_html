#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

extern void *myRunCntTask(void* arg);

int main(void) {
   int buttonDev, piezoDev;
	char buff[100];
	int tone;

	pthread_t thr_id;

	buttonDev = open("/dev/int_button", O_RDWR);
	if (buttonDev < 0) {
		printf("201602357, Sun Min Lee: Button Device Open ERROR!, errNo=%d\n", errno);
		return -1;
	}

	piezoDev = open("/dev/piezo", O_RDWR | O_SYNC);
	if (piezoDev < 0) {
		printf("201602357, Sun Min Lee: Piezo Device Open ERROR!, errNo=%d\n", errno);
		return -1;
	}

	pthread_create(&thr_id, NULL, myRunCntTask, NULL);
   
	printf("201602357 Sun Min Lee: Please push the button !\n");
	while (1) {
		read(buttonDev, buff, 100);
		printf("201602357, Sun Min Lee: %s\r\n", buff);
		if (strcmp(buff, "WheelUp") == 0) {
			tone = 0x05;
			write(piezoDev, &tone, 4);
			usleep(500000);
			tone = 0x06;
			write(piezoDev, &tone, 4);
			usleep(500000);
			tone = 0x11;
			write(piezoDev, &tone, 4);
			usleep(500000);
			tone = 0;
			write(piezoDev, &tone, 4);
		}
    else if (strcmp(buff, "WheelDown") == 0) {
      tone = 0x12;
      write(piezoDev, &tone, 4);
      usleep(500000);
      tone = 0x13;
      write(piezoDev, &tone, 4);
      usleep(500000);
      tone = 0x14;
      write(piezoDev, &tone, 4);
      usleep(500000);
      tone = 0;
      write(piezoDev, &tone, 4);
    }
	} // end of while

	close(piezoDev);
	close(buttonDev);
	return 0;
}

