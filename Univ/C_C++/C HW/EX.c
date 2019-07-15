/*
 * source.c
 *
 *  Created on: 2016. 6. 9.
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sumReverseNumber()  // 문제 1. 거꾸로 읽은 수의 합
{
	int n, num, sum;
	int reverse = 0;
	int count = 0;
	int i;

	printf("Input the number: ");
	fflush(stdout);
	scanf("%d", &n);

	num = n;

	while(1)
	{
		if(num != 0)
		{
			count++;
			num = num / 10;
		}
		else
			break;
	}

	num = n;

	for(i=1; i<=count; i++)
	{
		reverse = (reverse * 10) + (num % 10);
		num = num / 10;
	}

	sum = n + reverse;
	printf("The sum of two numbers is: %d", sum);

}

void smallestMultiple()  // 문제 2. Smalleset Multiple
{
	int n, i, j;

	scanf("%d", &n);

	i = 2;

	while(1)
	{
		for(j=2; j<=n;)
		{
			if(i % j != 0)
			{
				i++;
				j = 2;
			}
			else
				j++;
		}
		break;
	}
	printf("%d\n", i);
}

void countOne()  // 문제 3. 이진수의 1의 개수 출력
{
	int n, count;

	printf("Input the number: ");
	fflush(stdout);
	scanf("%d", &n);

	count = count_One(n);

	printf("%d", count);
}

int count_One(int n)
{
	if(0<=n && n<10)
		return n;
	else
		return (n % 10) + count_One(n / 10);
}
void differenceSet()  // 문제 5. 두 집합의 차집합
{
	int setA[10];
	int setB[10];
	int sumA = 0;
	int sumB = 0;
	int sum = 0;
	int check;
	int i, j;

	srand((unsigned)time(NULL));

	printf("집합A: ");
	for(i=0; i<10;)
	{
		setA[i] = (rand() % 25) + 1;
		check = 1;

		for(j=0; j<i; j++)
		{
			if(setA[i] == setA[j])
				check = 0;
		}
		if(check == 1)
		{
			printf("%d ", setA[i]);
			i++;
		}
	}

	printf("\n");
	printf("집합B: ");

	for(i=0; i<10;)
	{
		setB[i] = (rand() % 25) + 1;
		check = 1;
		for(j=0; j<i; j++)
		{
			if(setB[i] == setB[j])
			{
				check = 0;
			}
		}

		if(check == 1)
		{
			printf("%d ", setB[i]);
			i++;
		}
	}

	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			if(setA[i] == setB[j])
			{
				setA[i] = 0;
				setB[j] = 0;
			}
		}
	}

	printf("\n");
	printf("A - B: ");

	for(i=0; i<10; i++)
	{
		sumA = sumA + setA[i];

		if(setA[i] != 0)
			printf("%d ", setA[i]);
	}

	printf("\n");
	printf("B - A: ");

	for(j=0; j<10; j++)
	{
		sumB = sumB + setB[j];

		if(setB[j] != 0)
			printf("%d ", setB[j]);
	}

	sum = sumA + sumB;

	printf("\n");
	printf("차집합의 합: %d", sum);
}

void possiblePath()  // 문제 6. 가능한 path의 개수
{
	int m, n;
	int i, j;

	scanf("%d %d", &m, &n);
	int set[m][n];

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			set[i][j] = 0;

	for(i=0; i<m; i++)
	{
		set[i][0] = 1;
	}
	for(j=0; j<n; j++)
	{
		set[0][j] = 1;
	}

	for(i=1; i<m; i++)
	{
		for(j=1; j<n; j++)
		{
			set[i][j] = set[i-1][j] + set[i][j-1];
		}
	}
	printf("%d", set[m-1][n-1]);
}


int main()
{
	// sumReverseNumber();  // 문제 1. 거꾸로 읽은 수의 합
	// smallestMultiple();  // 문제 2. Smalleset Multiple
	// countOne();  // 문제 3. 이진수의 1의 개수 출력
	// differenceSet();  // 문제 5. 두 집합의 차집합
	// possiblePath();  // 문제 6. 가능한 path의 개수

	return 0;
}
