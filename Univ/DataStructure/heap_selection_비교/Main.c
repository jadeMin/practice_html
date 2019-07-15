#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX	10000
clock_t before;

int checkOrder(int A[], int n) {
	int i;
	for (i = 0; i < n-1; i++)
		if (A[i] > A[i+1]) return 0;
	return 1;
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void heapify(int A[], int n, int k){
	int L, R, m;
	while(2*k+1 < n){
		L = 2*k + 1;
		R = 2*k + 2;
		m = k;
		if(A[m] < A[L]) m = L;
		if(R<=n-1 && A[m] < A[R]) m = R;
		if (m != k){
			swap(&A[k], &A[m]);
			k = m;
		}
		else break;
	}
}

void make_heap(int A[], int n){
	int k;
	for(k = n-1; k >= 0; k--){
		heapify(A, n, k);
	}
}

void heap_sort(int A[], int n){
	int k;
	make_heap(A, n);
	for(k = n-1; k>0; k--){
		swap(&A[0], &A[k]);
		heapify(A, k, 0);
	}	
}

int find_max_index(int B[], int n){
	 int i, max_index;
   max_index = 0;
   for(i=1; i<=n; i++){
		 if(B[max_index] < B[i]){
			 max_index = i;
		}
	}
	return max_index;
}

void selection_sort(int B[], int n){
	int i, m;
  for(i=n-1; i>0; i--){
		m = find_max_index(B, i);
		swap(&B[i], &B[m]);
	}
}
void main(void) {
	int A[MAX], B[MAX], k, n, i;
	double sort_time;
	scanf("%d", &n); // 입력 크기 n <= 10000을 scanf 받는다.
	// 배열 A, B에 동일한 랜덤 값 n개를 생성해 저장한다.
	srand(time(NULL));
	for(k = 0; k < n; k++) {
		B[k] = A[k] = rand() % 1000;
	}
	before = clock();
	heap_sort(A, n); // heap_sort 호출
	sort_time = ((double)(clock()-before)/CLOCKS_PER_SEC);
	if(checkOrder(A,n))
		printf("heap sort for %d numbers = %3.6lf seconds\n", n, sort_time);

	before = clock();
	selection_sort(B, n); // selection_sort 호출
	sort_time = ((double)(clock()-before)/CLOCKS_PER_SEC);
	if(checkOrder(B,n))
		printf("selection for %d numbers = %3.6lf seconds\n", n, sort_time);
}

