#include <stdio.h>
#include <stdlib.h>

void heapify(int A[], int n, int k) {
	int L, R, m, swap;
	while(2*k+1 <= n-1){
		L = 2*k+1;
		R = 2*k+2;
		m = k;
		if(A[m] < A[L]){
			m = L;
		}
		if(R <= n-1 && A[m] < A[R]){
			m = R;
		}
		if(m != k){
			swap = A[k];
			A[k] = A[m];
			A[m] = swap;
			k = m;
		}
		else break;
	}	
}
void make_heap(int A[], int n) {
	int k;
	for(k = n-1; k>=0; k--){
		heapify(A, n, k);
	}
}
void heap_sort(int A[], int n) {
	// make_heap 호출은 main 함수에서 했기 때문에 여기선 생략한다.
	int k;
	int swap = 0;
	for(k = n-1; k>0; k--){
		swap = A[0];
		A[0] = A[k];
		A[k] = swap;
		heapify(A, k, 0);
	}
}

void print_array(int A[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main() {
	int n, i, *A;
	
	scanf("%d", &n); // 정수 개수를 읽어들인다
	A = (int *)malloc(sizeof(int)*n); // n개의 정수를 위한 배열 A를 할당받는다
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]); // n개의 정수를 입력받는다

	print_array(A, n); // 입력으로 받은 배열 값 출력

	// 1. A를 힙의 값 조건을 만족하도록 하여 힙으로 만든다
	make_heap(A, n);
	print_array(A, n);  // make_heap 한 후 힙이 된 배열 값 출력
	
	// 2. heap 정렬
	heap_sort(A, n);
	print_array(A, n); // 정렬된 배열 값 출력
	
  return 0;
}
