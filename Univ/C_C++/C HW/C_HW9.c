/*
 * C_HW9_201602357_�̼���.c
 *
 *  Created on: 2016. 6. 5.
 *      Author: Administrator
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void arraySum()  // ����4. ����� ��
{
	int m, n;
	int i, j;
	int countA = 1;
	int countB = 1;

	scanf("%d %d", &m, &n);	//����� ũ�⸦ �Է¹���
	int arrA[m][n];	//�迭�� �̿��Ͽ� ��� ����
	int arrB[m][n];
	int arr[m][n];

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrA[i][j] = countA;	//1���� ���������� ���� �� A��� ����
			countA++;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrB[i][j] = countB;	//1���� Ȧ������ ���������� �� B��� ����
			countB += 2;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j] = arrA[i][j] + arrB[i][j];	//�� ����� ���� ����� ����
			printf("%d ", arr[i][j]);	//���� ����� ���
		}
		printf("\n");
	}
}

void arrayMul()  // ����5. ����� ��
{
	int m, n;
	int i, j, k;
	int countA = 1;
	int countB = 1;

	scanf("%d %d", &m, &n);	//����� ũ�⸦ �Է¹���
	int arrA[m][n];	//�迭�� �̿��Ͽ� ��� ����
	int arrB[n][m];
	int arr[m][m];

	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
			arr[i][j] = 0;	//���� ���� �� ����� 0���� �ʱ�ȭ
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrA[i][j] = countA;	//��� A�� 1���� �������� ���� ������ ����
			countA++;
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			arrB[i][j] = countB;	//��� B�� 1���� �������� ���� ������ ����
			countB++;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
		{
			for(k=0; k<n; k++)
			{
					arr[i][j] += arrA[i][k] * arrB[k][j];	//�� ����� ���� ����Ͽ� ���� ����� ����
			}
			printf("%d ", arr[i][j]);	//��� �� ���
		}
		printf("\n");
	}

}

void spiralArray()  // ����6. ������ ��� ���
{
	int m;
	int i, j;
	int count = 1;
	int a;

	scanf("%d", &m);	//����� ũ�⸦ �Է¹���
	int arr[m][m];	//�迭�� �̿��Ͽ� ��� ����

	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
		{
			arr[i][j] = count;	//����� ���� 1���� ���������� �� �� �ְ� ��
			count++;
		}
	}

	if(m % 2 == 0)	//����� ¦���϶�
	{
		for(i=0; i< m / 2; i++)	//����� ���������� ��µǵ��� 4���� ������ �����Ͽ� ���
		{
			for(j=i; j<m-1-i; j++)
			{
				printf("%d ", arr[i][j]);
			}
			for(j=i; j<m-1-i; j++)
			{
				printf("%d ", arr[j][m-1-i]);
			}
			for(j=m-1-i; j>i; j--)
			{
				printf("%d ", arr[m-1-i][j]);
			}
			for(j=m-1-i; j>i; j--)
			{
				printf("%d ", arr[j][i]);
			}
		}
	}
	else	//����� Ȧ���� ���
	{
		for(i=0; i< m / 2; i++)	//����� ���������� ��µǵ��� 4���� ������ �����Ͽ� ���
		{
			for(j=i; j<m-1-i; j++)
			{
				printf("%d ", arr[i][j]);
			}
			for(j=i; j<m-1-i; j++)
			{
				printf("%d ", arr[j][m-1-i]);
			}
			for(j=m-1-i; j>i; j--)
			{
				printf("%d ", arr[m-1-i][j]);
			}
			for(j=m-1-i; j>i; j--)
			{
				printf("%d ", arr[j][i]);
			}
		}
		printf("%d ", arr[m / 2][m / 2]);	//��� �� ��� ���� �� ���� ���� ���
	}
}
void totalPath()  // ����7. ������ Path�� ����
{
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);	//���� ũ�⸦ �Է¹���
	int set[m][n];	//�迭�� �̿��Ͽ� ����� ����

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			set[i][j] = 0;	//����� �ʱⰪ�� 0���� ����

	for(i=0; i<m; i++)
	{
		set[i][0] = 1;	//�� 1��� 1���κ��� ����� ���� �Ѱ����̹Ƿ� 1�� �Է�
	}
	for(j=0; j<n; j++)
	{
		set[0][j] = 1;
	}

	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			set[i][j] = set[i-1][j] + set[i][j-1];	//�� ���� ��ġ�� ���� ������ ����� ���� ���� �� ��ġ�� ����� �� ���� ����
		}
	}
	printf("%d", set[m-1][n-1]);	//�ش� ���� ����� ���� ���
}

void LongestPath()  // ����8. Longest Path�� ��
{
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);	//���� ũ�⸦ �Է¹���
	int arr[m][n];	//�迭�� �̿��Ͽ� ����� ����
	int d[m][n];

	srand(1);	//���尪�� 1�� ����

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j] = rand() % 29 + 1;	//1���� 29������ ������ ���� ����
			d[i][j] = 0;	//path�� ���� ����� 0�� ������ �ʱ�ȭ
		}
	}

	d[0][0] = arr[0][0];	//���� 1�� 1���� ���� ������ ������ ������ arr����� 1�� 1�� ���� ����

	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			d[0][j] = d[0][j-1] + arr[0][j];	//1���� 1������ ���� �ش��ϴ� ��ġ�� arr��İ��� �� �� ��ġ�� arr��İ��� �հ� ����.
			d[i][0] = d[i-1][0] + arr[i][0];
		}
	}

	for(i=1; i<m; i++)	//�־��� ��ȭ���� �̿��Ͽ� ���� �� ���� ����Ѵ�.
	{
		for(j=1; j<n; j++)
		{
			if(d[i-1][j] > d[i][j-1])	//ū ���� ���� ã�� �� ���� ���ؾ� ���� �� ���� ����� �� �ִ�.
			{
				d[i][j] = d[i-1][j] + arr[i][j];
			}
			else
			{
				d[i][j] = d[i][j-1] + arr[i][j];
			}
		}
	}
	printf("%d", d[m-1][n-1]);	//����� ���
}

int main()
{
	//arraySum();       // ����4. ����� ��
	//arrayMul();       // ����5. ����� ��
	//spiralArray();    // ����6. ������ ��� ���
	//totalPath();      // ����7. ������ Path�� ����
	//LongestPath();    // ����8. Longest Path�� ��

	return 0;
}

