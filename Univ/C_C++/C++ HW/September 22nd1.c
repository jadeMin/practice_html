/*
 * 201620357.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: 이선민
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *unionSet(int *A, int *B)
{
	int nA = A[0];	//A[1]~A[nA]
	int nB = B[0];	//B[1]~B[nB]

	int *C;
	int nC = nA + nB;	//합집합의 최대 갯수

	int k;	//C의 index
	int i, j;
	C = (int*)malloc(sizeof(int)*(nC + 1));
	k = 1;
		//무조건 A 복사
	for(i=1; i<=nA; i++)	//C[k] = A[i]; k증가
	{
		C[k] = A[i];
		k++;
	}
		//process B
	for(i=1; i<=nB; i++)	//B[i] ~ B[nB]
	{
		int exist = 0;
		for(j=1; j<=nA; j++)	//A[1] ~ A[nA]
		{
			if(C[j] == B[i])
				exist++;
		}
		if(exist == 0)	//C[k] = B[i]; k증가
		{
			C[k] = B[i];
			k++;
		}
	}
	C[0] = k;	//C[0] = nC = k
	//C[1]~C[k]
	return C;
}

int main(void)
{
	int A[] = {3, 1, 2, 3};
	int B[] = {4, 2, 3, 4, 5};
	int *C, nC;
	C =unionSet(A, B);	//함수를 호출하여 합집합 C를 구함

	int i;

	nC = C[0];	//합집합 C의 개수

	for(i=1; i<nC; i++)
	{
		printf("%d ", C[i]);	//합집합 출력
	}
}

