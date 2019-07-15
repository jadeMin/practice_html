#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 6

typedef struct _node
{
	int size;
}Node;

int Q[MaxSize] = {0};
int startPos = 0, endPos = 0;

int enqueue(int value, Node* node){
	//if((endPos+1) % MaxSize == startPos){
  		if(node->size == MaxSize){
				printf("Q is full\n");
				return 0;
			}
	
  else{
		Q[endPos] = value;
		endPos++;
		node->size++;
		endPos = endPos % MaxSize;
		return value;
   }
}

int dequeue(Node* node){
	if(node->size == 0){
		printf("Q is empty\n");
		return 0;
	}
	else{
		int temp;
		temp = Q[startPos];
		startPos++;
		node->size--;
		startPos = startPos % MaxSize;
		return temp;
	}
}
	
int size(Node* node){
	return node->size;
}

int front(Node* node){
	if(node->size == 0){
  		printf("Q is empty\n");
			return 0;
	}
	else
		return Q[startPos];	
}

void main(void) {
	char com[10];
	int d, q;

	Node* node = (Node*)malloc(sizeof(Node));
	node->size = 0;
	
	while (1) {
		//printf("(en)Enqueue, (de)Dequeue, (size)print size of Queue, (front)front Enqueue, (quit)\n");
		scanf("%s", com);
		if (strcmp(com, "en") == 0) {
			scanf("%d", &d);
			if (d <= 0) {
				printf("양의 정수만 취급\n");
				continue;
			}
			if (q = enqueue(d, node))
				printf(" # value %d is enqueued to Q \n", d);
		}
		else if (strcmp(com, "de") == 0) {
			if (q = dequeue(node))
				printf(" * value %d is dequeued from Q \n", q);
		}
		else if (strcmp(com, "size") == 0) {
			printf(" $ size of Q is %d \n", size(node));
		}
		else if (strcmp(com, "front") == 0) {
			printf(" @ front of Q is %d\n", front(node));
		}
		else if (strcmp(com, "quit") == 0) {
			break;
		}
		else
			printf("Invalid Command.\n");
	}
}
