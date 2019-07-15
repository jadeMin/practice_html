#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY  -999999

typedef struct node_elm* node;
struct node_elm {
	int key;
	node next;
};

typedef struct linkedqueue * Lqueue;

struct linkedqueue{
	node top;
	int size;
};
node createNode(int key) {
	node v = malloc(sizeof(struct node_elm));
	
	v->key = key;
	v->next = NULL;
	return v;
}
node insertAtHead(node head, int key){
	node new_node = createNode(key);
	new_node->next = head;
	return new_node;
}
node deleteFromTail(node head){
	node tail, prev;
	if(head == NULL)
		return NULL;
	prev = NULL;
	tail = head;
	while(tail->next != NULL){
		prev = tail;
		tail = tail->next;
	}
	if(prev != NULL)
		prev->next = tail->next;
	free(tail);
	if(prev != NULL)
		return head;
	else
		return NULL;
}

Lqueue createQueue(void) {
	Lqueue Q = (Lqueue)malloc(sizeof(struct linkedqueue));
	Q->top = NULL;
	Q->size = 0;
	return Q;
}
void enqueue(Lqueue Q, int value) {
	Q->top = insertAtHead(Q->top, value);
	Q->size++;
}
int dequeue(Lqueue Q) {
	int value = (Q->size > 0)? Q->top->key:EMPTY;
	Q->top = deleteFromTail(Q->top);
	if(Q->size > 0)
		Q->size--;
	return value;
}
void print_list(node v) {
	while(v != NULL){
		printf("%d -> ", v->key);
		v = v->next;
	}
	if(v == NULL)
		printf("NULL");
	printf("\n");
}
int main() {
	int key;
	char cmd[20];
	Lqueue Q = createQueue();
	while(1) {
		scanf("%s", cmd);
		if(strcmp(cmd, "en") == 0) {
			scanf("%d", &key);
			enqueue(Q, key);
			printf("+ %d is enqueued to Q.\n", key);
		}
		else if(strcmp(cmd, "de") == 0) {
			key = dequeue(Q);
			if(key != EMPTY)
				printf("- %d is dequeued from Q.\n", key);
		}
		else if (strcmp(cmd, "print") == 0)
			print_list(Q->top);
		else if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "exit") == 0) {
			printf("bye!\n");
			break;
		}
		else
			printf("en, de, print, exit, quit are only allowed\n");
	}
  return 0;

}