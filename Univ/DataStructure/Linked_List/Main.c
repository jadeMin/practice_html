#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define EMPTY -999999

typedef struct node_elm * node;
struct node_elm {
	int  key;
	node next;
};
node createNode(int key) {
	node v = (node)malloc(sizeof(struct node_elm));
	v->key = key;
	v->next = NULL;
	return v;
}
void print_list(node v) {
	while(v) {
		printf("%d -> ", v->key);
		v = v->next;
	}
	printf("NULL\n");
}
node insertAtHead(node head, int key) {
	node new_node = createNode(key);
	new_node->next = head;
	return new_node;
}
node deleteFromHead(node head, int *val) {
	if(head == NULL)
		*val = EMPTY;
	if(head != NULL){
		node old = head;
		*val = head->key;
		head = head ->next;
		free(old);
	}
	return head;
}
node deleteFromTail(node head, int *val) {
	if(head == NULL){
		*val = EMPTY;
		return NULL;
	}
	node prev, tail;
	prev = NULL;
	tail = head;
	while(tail->next != NULL){
		prev = tail;
		tail = tail->next;
	}
	*val = tail->key;
	if(prev != NULL)
		prev->next = tail->next;
	free(tail);
	if(prev == NULL)
		return NULL;
	else
		return head;
}

node search(node v, int key){
	while(v != NULL){
		if(v->key == key)
			return v;
		v = v->next;
	}
	return NULL;
}

node deleteNode(node head, node x) {
	node prev;
	int v;
	if(head == NULL || x == NULL)
		return head;
	if(x == head)
		return deleteFromHead(head, &v);
	if(x->next == NULL)
		return deleteFromTail(head, &v);
	prev = head;
	while(prev->next != x){
		prev = prev->next;
	}
	prev->next = x->next;
	free(x);
	return head;
}

int sumOfList(node head){
	int sum = 0;
	while(head != NULL){
		sum = sum + head->key;
		head = head->next;
	}
	return sum;
}
int maxOfList(node head){
	int max;
	if(head == NULL)
		return EMPTY;
	max = head->key;
	
	while(head != NULL){
		if(max < head->key)
			max = head->key;	
		head = head->next;
	}
	return max;
}
void addToList(node v, int x){
	while(v != NULL){
		v->key += x;
		v = v->next;
	}
}

void main(void) {
	node head = NULL, v;
	char com[10];
	int value, d, sum, max,x;

	while (1) {
		scanf("%s", com);
		if (strcmp(com, "ins") == 0) { // insertAtHead
			scanf("%d", &value); // insert할 값을 입력받음
			head = insertAtHead(head, value);
			printf("%d is inserted at head \n", value);
			print_list(head); printf("\n");
		}
		else if (strcmp(com, "delh") == 0) { // deleteFromHead
			head = deleteFromHead(head, &value);
			printf("%d is deleted from head: \n", value);
			print_list(head); printf("\n");
		}
		else if (strcmp(com, "delt") == 0) { // deleteFromHead
			head = deleteFromTail(head, &value);
			printf("%d is deleted from tail: \n", value);
			print_list(head); printf("\n");
		}
		else if (strcmp(com, "deln") == 0) { // deleteNode
			scanf("%d", &value); // delete할 value를 입력받음
			v = search(head, value);
			if (v) {
				head = deleteNode(head, v);
				printf("%d is deleted from list: \n", value);
				print_list(head); printf("\n");
			}
			else printf("%d is not found in the list: \n", value);
		}
		else if (strcmp(com, "search") == 0) { // search
			scanf("%d", &value); // search할 value를 입력받음
			if (v = search(head, value))
				printf("%d is found in the list: \n", value);
			else	printf("%d is not found in the list: \n", value);
		}
		else if (strcmp(com, "sum") == 0) { // 노드 값들의 합 계산
			sum = sumOfList(head);
			printf("Sum of list = %d\n", sum);
		}
		else if (strcmp(com, "max") == 0) { // 노드 값들 중 최대값 계산
			max = maxOfList(head);
			printf("Maximum of list = %d\n", max);
		}
		else if (strcmp(com, "add") == 0) { // search
			scanf("%d", &value); // add 시작할 노드의 key 값 입력
			v = search(head, value); printf("\n");
			if (v) {
				scanf("%d", &x); // add할 값 x를 입력받음
				addToList(v, x);
				printf("%d is added to nodes: \n", x);
				print_list(head);
			}
			else printf("%d is not found in the list: \n", value);
		}
		else if (strcmp(com, "exit") == 0) // 프로그램을 종료함
			break;
		else printf(" No legal commands\n");
	}
}