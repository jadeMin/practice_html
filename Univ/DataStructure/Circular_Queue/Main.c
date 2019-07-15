#include <stdio.h>
#include <string.h>
#define MaxSize 6

int enqueue(int value);
int dequeue();
int size();
int front();
int Q[MaxSize] = {0};
int startPos = 0, endPos = 0;
int ensize = 0, desize = 0;

	
void main(void) {
	char com[10];
	int d, q;
	while (1) {
		//printf("(en)Enqueue, (de)Dequeue, (size)print size of Queue, (front)front Enqueue, (quit)\n");
		scanf("%s", com);
		if (strcmp(com, "en") == 0) {
			scanf("%d", &d);
			if (d <= 0) {
				printf("양의 정수만 취급\n");
				continue;
			}
			if (q = enqueue(d))
				printf(" # value %d is enqueued to Q \n", d);
		}
		else if (strcmp(com, "de") == 0) {
			if (q = dequeue( ))
				printf(" * value %d is dequeued from Q \n", q);
		}
		else if (strcmp(com, "size") == 0) {
			printf(" $ size of Q is %d \n", size( ));
		}
		else if (strcmp(com, "front") == 0) {
			printf(" @ front of Q is %d\n", front( ));
		}
		else if (strcmp(com, "quit") == 0) {
			break;
		}
		else
			printf("Invalid Command.\n");
	}
}

int enqueue(int value){
	if((endPos+1) % MaxSize == startPos){
  		printf("Q is full\n");
			return 0;
	}
   else{
		Q[endPos] = value;
		endPos++;
		ensize++;
		endPos = endPos % MaxSize;
		return value;
   }
}

int dequeue(){
	if(endPos == startPos){
		printf("Q is empty\n");
		return 0;
	}
	else{
		int temp;
		temp = Q[startPos];
		startPos++;
		desize++;
		startPos = startPos % MaxSize;
		return temp;
	}
}
	
int size(){
	return ensize - desize;
}

int front(){
	if(endPos == startPos){
  		printf("Q is empty\n");
			return 0;
	}
	else
		return Q[startPos];	
}

	