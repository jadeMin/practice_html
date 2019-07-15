/*
 * 201602357.c
 *
 *  Created on: 2016. 9. 22.
 *      Author: ¿Ãº±πŒ
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum(int *a, int n)
{
	int i;
	int total = 0;
	for(i=0; i<n; i++)
	{
		total = total + a[i];
	}
	return total;
}

float mean(int *a, int n)
{
	int s = sum(a, n);
	return s / (float)n;
}

float variance(int *a, int n)
{
	float m = mean(a, n);
	float total;
	int i;

	for(i=0; i<n; i++)
	{
		total = total + (a[i] - m)*(a[i] - m);
	}
	return total / n;
}

float std(int *a, int n)
{
	float v = variance(a, n);
	return sqrt(v);
}

int main()
{
	int a[3] = {1, 2, 3};
	float result = std(a, 3);
	printf("%f", result);
}
