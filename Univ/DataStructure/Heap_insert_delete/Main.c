#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY  -999999
#define MAX    1000  // 힙 배열 크기

int size = 0;

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void heapify(int A[], int n, int k) {
	int L, R, m;
	while(2*k+1 < n){
		L = 2*k + 1;
		R = 2*k + 2;
		m = k;
		if(A[m] < A[L])
			m = L;
		if(A[m] < A[R])
			m = R;
		if(m != k){
			swap(&A[m], &A[k]);
			k = m;
		}
		else
			break;
	}
}
void heap_insert(int A[], int *n, int x) {
	if(size <= MAX){
	int k = *n;
	A[k] = x;
	while(k>0 && A[k] > A[(k-1)/2]){
		swap(&A[k], &A[(k-1)/2]);
		k = (k-1)/2;
	}
	*n = *n + 1;
	size++;
	}
}
int delete_max(int A[], int *n) {
	if(size > 0){
	int value = A[0];
	A[0] = A[*n-1];
	heapify(A, *n-1, 0);
	*n = *n - 1;
	size--;
	return value;
	}
	return EMPTY;

}

void print_array(int A[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main() {
	int n, x, A[MAX];
	char cmd[20];

	n = 0;
	while(1) {
		scanf("%s", cmd);
		if(strcmp(cmd, "in") == 0 ) {
			scanf("%d", &x);
			heap_insert(A, &n, x);
			printf("+ %d is inserted.\n", x);
		}
		else if(strcmp(cmd, "de") == 0) {
			x = delete_max(A, &n);
			if(x != EMPTY)
				printf("- %d is a maximum and deleted.\n", x);
		}
		else if (strcmp(cmd, "print") == 0)
			print_array(A, n);
		else if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "exit") == 0) {
			printf("bye!\n");
			break;
		}
		else
			printf("in, de, print, exit, quit are only allowed\n");
	}
  return 0;
}
