#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000  // n은 최대 100000이하여야 함!
int X[MAX], A[MAX];

void prefixSum1(int n) {
	clock_t before, after;
	before = clock();
	for(int i=0;i<n;i++){
		A[i]=0;
		for(int j=0; j<=i; j++){
			A[i] = A[i] + X[j];
		}
	}
	after = clock();
	printf("prefixSum1의 실행시간은 %.6f이다\n", (double)(after-before)/CLOCKS_PER_SEC);
}

void prefixSum2(int n) {
	clock_t before, after;
	before = clock();
	A[0] = X[0];
	for(int i=1; i<n; i++)
		A[i] = A[i-1] + X[i];
	after = clock();
	printf("prefixSum2의 실행시간은 %.6f이다\n", (double)(after-before)/CLOCKS_PER_SEC);
}

void main() {
	int n, i;

	scanf("%d", &n);
	srand((unsigned)time(NULL));  	 
	for(i = 0 ; i < n ; i++)
		X[i] = rand() % 100 + 1;
	
	prefixSum1(n);
	prefixSum2(n);
	// prefixSum1과 prefixSum2를 호출하고, 실행시간 측정하여 각각 출력함
	
}