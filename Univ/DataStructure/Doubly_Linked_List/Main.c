#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>  // for INT_MAX, INT_MIN
#define EMPTY INT_MIN

typedef struct dnode_elm * dnode;
struct dnode_elm {
	int key;
	dnode next, prev;
};

dnode createDnode(int key) {
  dnode D = (dnode)malloc(sizeof(struct dnode_elm));
  D->key = key;
  D->prev = D->next = D; // prev, next 모두 자신을 가르킴!
  return D;  
}
dnode createDlist(void) {
  // 비어있는 양방향 원형 리스트 생성하여 리턴 (즉, dummy node 리턴)
  return createDnode(INT_MAX);
}

void print_list(dnode head, dnode from) {
    printf("h");
	while(from != head){
	printf(" -> %d", from->key);
	from = from->next;
    }
	printf("\n");
}
int isEmpty(dnode h){
	if(h == NULL || h->next == h)
		return 1;
	else
		return 0;
}
dnode first(dnode h){
	if(h == NULL || h->next == h)
		return h;
	return h->next;
}
dnode last(dnode h){
	if(h == NULL || h->next == h)
		return h;
	return h->prev;
}
void splice(dnode a, dnode b, dnode x) {
	dnode ap = a->prev;
	dnode bn = b->next;
	ap->next = bn;
	bn->prev = ap;
	a->prev = x;
	b->next = x->next;
	x->next->prev = b;
	x->next = a;
}
void moveAfter(dnode b, dnode a){
	splice(b,b,a);
}
void moveBefore(dnode b, dnode a){
	splice(b, b, a->prev);
}
dnode insertAfter(dnode a, int key){
	dnode b = createDnode(key);
	moveAfter(b,a);
	return b;
}
dnode insertBefore(dnode a, int key){
	return insertAfter(a->prev, key);
}
dnode pushFront(dnode head, int key){
	return insertAfter(head, key);
}
dnode pushBack(dnode head, int key){
	return insertBefore(head, key);
}
void deleteNode(dnode x) {
	if(x == NULL || x->next == x)
		return;
	dnode ap = x->prev;
	dnode an = x->next;
	ap->next = an;
	an->prev = ap;
	free(x);
}

int popFront(dnode head) {
	int value = EMPTY;
	if(head->next != head){
		value = head->next->key;
		deleteNode(head->next);
	}
	return value;
}

int popBack(dnode head) {
	int value = EMPTY;
	if(head->prev != head){
		value = head->prev->key;
		deleteNode(head->prev);
	}
	return value;
}
dnode search(dnode head, dnode from, int key){
	while(from != head){
		if(from->key == key)
			return from;
		from = from->next;
	}
	return from;
}
int main(void)
{   int key_a, key_b,key;
    char cmd[20];
    dnode h, a, b;
    h = createDlist();
    while(1) {
	scanf("%s", cmd);
	if(strcmp(cmd, "search")==0) {
		scanf("%d", &key);
		a = search(h, h->next, key);
		if(a != h) printf("@ %d is found\n", a->key);
		else printf("@ %d is NOT found\n", key);
	}
	else if(strcmp(cmd, "first")==0) {
		a = first(h);
		if(a != h) printf("* %d is the first node\n", a->key);
		else  printf("* empty list\n");
	}
	else if(strcmp(cmd, "last")==0) {
		a = last(h);
		if(a != h) printf("* %d is the last node\n", a->key);
		else  printf("* empty list\n");
	}
	else if(strcmp(cmd, "pushF")==0 || strcmp(cmd, "pushf")==0) {
		scanf("%d", &key);
		pushFront(h, key);
		printf("+ %d is pushed at front\n", key);
	}
	else if(strcmp(cmd, "pushB")==0 || strcmp(cmd, "pushb")==0) {
		scanf("%d", &key);
		pushBack(h, key);
		printf("+ %d is pushed at back\n", key);
	}
	else if(strcmp(cmd, "popF")==0 || strcmp(cmd, "popf")==0) {
		if ((key = popFront(h)) != EMPTY)
			printf("- %d is popped from front\n", key);
		else 	printf("- list is empty\n");
	}
	else if(strcmp(cmd, "popB")==0 || strcmp(cmd, "popb")==0) {
		if((key = popBack(h)) != EMPTY)
			printf("- %d is popped from back\n", key);
		else 	printf("- list is empty\n");
	}
	else if(strcmp(cmd, "del")==0) { // search
		scanf("%d", &key);
		a = search(h, h->next, key);
		if(a != h) deleteNode(a);
	}
	else if(strcmp(cmd, "print")==0) { // print
		print_list(h, h->next);
	}
	else if(strcmp(cmd, "exit")==0 || strcmp(cmd, "quit")==0)
		break;
	else {
		printf("# not allowed command!\n");
		break;
	}
    }
    return 0;
}