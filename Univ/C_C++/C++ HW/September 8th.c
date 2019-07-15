/*
 * source.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: 이선민
 */
#include<stdio.h>

int factorial(int);
int power(int, int);
void printDivisors(int);

void Assignment1()
{
	int number = 3;	//원하는 팩토리얼의 연산 값 설정
	int result;
	result = factorial(number);	//팩토리얼 함수를 이용하여 결과 값 도출
	printf("%d", result);	//결과 값 출력
}

int factorial(int n)	//팩토리얼 값을 계산하는 함수
{
	int i;
	int j = 1;
	for(i=1; i<=n; i++)	//지정된 팩토리얼 값까지 계산되도록 반복문을 활용
	{
		j = j * i;	//1부터 지정된 수 n까지 곱함 (팩토리얼의 정의)
	}
	return j;	//계산된 결과 값
}

void Assignment2()
{
	int a, b;
	a = 2;	//원하는 값을 설정
	b = 3;
	int result;
	result = power(a, b);	//함수를 호출하여 결과 값을 도출
	printf("%d", result);	//결과 값 출력
}

int power(int x, int n)
{
	int i, j;
	j = 1;	//반복문을 위한 임의의 정수 설정
	for(i=1; i<=n; i++)	//입력 된 값이 계산될 수 있도록 반복문 설정
	{
		j = j * x;	//입력된 값 a 가 b번 곱해진 값이 결과값이다
	}
	return j;	//도출된 결과
}

void Assignment3()
{
	int number;
	number = 6;	//원하는 연산 값을 설정
	printDivisors(number); //결과를 계산하는 함수 호출
}

void printDivisors(int x)
{
	int i;
	for(i=1; i<=x; i++)	//원하는 결과 값이 출력되도록 반복문을 설정
	{
		if(x % i == 0)	//설정된 값 n으로 나누어 떨어지는 수를 찾는다
			printf("%d ", i);	//그 값을 출력
		else
			continue;
	}
}

int main()
{
	//Assignment1();
	//Assignment2();
	Assignment3();
}
