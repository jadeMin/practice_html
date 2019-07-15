/*
 * 201620357.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: �̼���
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *unionSet(int *A, int *B)
{
	int nA = A[0];	//A[1]~A[nA]
	int nB = B[0];	//B[1]~B[nB]

	int *C;
	int nC = nA + nB;	//�������� �ִ� ����

	int k;	//C�� index
	int i, j;
	C = (int*)malloc(sizeof(int)*(nC + 1));
	k = 1;
		//������ A ����
	for(i=1; i<=nA; i++)	//C[k] = A[i]; k����
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
		if(exist == 0)	//C[k] = B[i]; k����
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
	C =unionSet(A, B);	//�Լ��� ȣ���Ͽ� ������ C�� ����

	int i;

	nC = C[0];	//������ C�� ����

	for(i=1; i<nC; i++)
	{
		printf("%d ", C[i]);	//������ ���
	}
}

