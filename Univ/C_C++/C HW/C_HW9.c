/*
 * C_HW9_201602357_이선민.c
 *
 *  Created on: 2016. 6. 5.
 *      Author: Administrator
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void arraySum()  // 문제4. 행렬의 합
{
	int m, n;
	int i, j;
	int countA = 1;
	int countB = 1;

	scanf("%d %d", &m, &n);	//행렬의 크기를 입력받음
	int arrA[m][n];	//배열을 이용하여 행렬 생성
	int arrB[m][n];
	int arr[m][n];

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrA[i][j] = countA;	//1부터 순차적으로 값이 들어간 A행렬 설정
			countA++;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrB[i][j] = countB;	//1부터 홀수값이 순차적으로 들어간 B행렬 설정
			countB += 2;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j] = arrA[i][j] + arrB[i][j];	//두 행렬의 합의 행렬을 설정
			printf("%d ", arr[i][j]);	//합의 행렬을 출력
		}
		printf("\n");
	}
}

void arrayMul()  // 문제5. 행렬의 곱
{
	int m, n;
	int i, j, k;
	int countA = 1;
	int countB = 1;

	scanf("%d %d", &m, &n);	//행렬의 크기를 입력받음
	int arrA[m][n];	//배열을 이용하여 행렬 생성
	int arrB[n][m];
	int arr[m][m];

	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
			arr[i][j] = 0;	//곱의 값이 들어갈 행렬을 0으로 초기화
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arrA[i][j] = countA;	//행렬 A를 1부터 순차적인 값이 들어가도록 설정
			countA++;
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			arrB[i][j] = countB;	//행렬 B를 1부터 순차적인 값이 들어가도록 설정
			countB++;
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
		{
			for(k=0; k<n; k++)
			{
					arr[i][j] += arrA[i][k] * arrB[k][j];	//두 행렬의 곱을 계산하여 곱의 행렬을 설정
			}
			printf("%d ", arr[i][j]);	//결과 값 출력
		}
		printf("\n");
	}

}

void spiralArray()  // 문제6. 나선형 모양 행렬
{
	int m;
	int i, j;
	int count = 1;
	int a;

	scanf("%d", &m);	//행렬의 크기를 입력받음
	int arr[m][m];	//배열을 이용하여 행렬 생성

	for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
		{
			arr[i][j] = count;	//행렬의 값이 1부터 순차적으로 들어갈 수 있게 함
			count++;
		}
	}

	if(m % 2 == 0)	//행렬이 짝수일때
	{
		for(i=0; i< m / 2; i++)	//행렬이 나선형으로 출력되도록 4가지 방향을 설정하여 출력
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
	else	//행렬이 홀수인 경우
	{
		for(i=0; i< m / 2; i++)	//행렬이 나선형으로 출력되도록 4가지 방향을 설정하여 출력
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
		printf("%d ", arr[m / 2][m / 2]);	//출력 후 가운데 남는 한 수를 따로 출력
	}
}
void totalPath()  // 문제7. 가능한 Path의 개수
{
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);	//길의 크기를 입력받음
	int set[m][n];	//배열을 이용하여 행렬을 생성

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			set[i][j] = 0;	//행렬의 초기값을 0으로 설정

	for(i=0; i<m; i++)
	{
		set[i][0] = 1;	//각 1행과 1열부분은 경우의 수가 한가지이므로 1을 입력
	}
	for(j=0; j<n; j++)
	{
		set[0][j] = 1;
	}

	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			set[i][j] = set[i-1][j] + set[i][j-1];	//그 길의 위치에 위와 왼쪽의 경우의 수의 합이 그 위치의 경우의 수 값과 같음
		}
	}
	printf("%d", set[m-1][n-1]);	//해당 길의 경우의 수를 출력
}

void LongestPath()  // 문제8. Longest Path의 값
{
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);	//길의 크기를 입력받음
	int arr[m][n];	//배열을 이용하여 행렬을 생성
	int d[m][n];

	srand(1);	//씨드값을 1로 설정

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j] = rand() % 29 + 1;	//1에서 29까지의 임의의 값을 넣음
			d[i][j] = 0;	//path의 합의 행렬을 0의 값으로 초기화
		}
	}

	d[0][0] = arr[0][0];	//합의 1행 1열의 값은 임의의 값으로 설정된 arr행렬의 1행 1열 값과 같다

	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			d[0][j] = d[0][j-1] + arr[0][j];	//1행들과 1열들은 각각 해당하는 위치의 arr행렬값과 그 전 위치에 arr행렬값의 합과 같다.
			d[i][0] = d[i-1][0] + arr[i][0];
		}
	}

	for(i=1; i<m; i++)	//주어진 점화식을 이용하여 가장 긴 길을 계산한다.
	{
		for(j=1; j<n; j++)
		{
			if(d[i-1][j] > d[i][j-1])	//큰 쪽의 값을 찾아 그 값을 더해야 가장 긴 길을 계산할 수 있다.
			{
				d[i][j] = d[i-1][j] + arr[i][j];
			}
			else
			{
				d[i][j] = d[i][j-1] + arr[i][j];
			}
		}
	}
	printf("%d", d[m-1][n-1]);	//결과값 출력
}

int main()
{
	//arraySum();       // 문제4. 행렬의 합
	//arrayMul();       // 문제5. 행렬의 곱
	//spiralArray();    // 문제6. 나선형 모양 행렬
	//totalPath();      // 문제7. 가능한 Path의 개수
	//LongestPath();    // 문제8. Longest Path의 값

	return 0;
}

