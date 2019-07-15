/*
 * source.c
 *
 *  Created on: 2016. 6. 2.
 *      Author: Administrator
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_fibbonacci();
long long fib_recursion(long long n);

void print_reverseNumber();
long long delete_zero(long long n);
long long reverse_recursion(long long n);

void print_digitSum();
long long digit_recursion(long long n);

void print_numOfOne();
long long numOfOne_recursion(long long n);

void print_stair();
long long stair_recursion(long long n);


int main()
{

	print_fibbonacci();
	//print_reverseNumber();
	//print_digitSum();
	//print_numOfOne();
	//print_stair();

	return 0;
}


void print_fibbonacci()
{
	long long i, n;

	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//수열의 개수를 입력받음

	for (i = 1; i <= n; i++)	//입력받은 수 만큼 수열이 출력
	{
		printf("%lld\n", fib_recursion(i));	//함수를 호출하여 결과 값 출력
	}
}

long long fib_recursion(long long n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 1;
	else
		return fib_recursion(n-2) + fib_recursion(n-1);	//피보나치 수열은 그 수열의 전과 전전값의 합과 같다

}

void print_reverseNumber()
{
	long long n;

	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//거꾸로 출력 할 수를 입력받음

	n = delete_zero(n);	//거꾸로 뒤집었을 때 앞에 출력되는 0을 지우기 위한 함수 호출

	printf("%lld\n", reverse_recursion(n));	//결과값 출력
}
long long delete_zero(long long n)
{
	while(1)	//1의 자리수가 0일 경우 0을 없애는 반복문을 생성
	{
		if(n % 10 == 0)
			n = n / 10;
		else
			break;
	}
	return n;	//뒤집었을때 앞에 출력되게 되는 0을 제거한 n값 형성
}
long long reverse_recursion(long long n)
{
	if(0<=n && n < 10)	//n이 한자리 수 일때 n값으로 출력
		return n;
	else if(n>=10)	//n이 한자리 수 이상일 때 재귀함수를 이용하여 일에 자리에서 부터 차례대로 출력하여 거꾸로 된 값이 출력하게 함
	{
		printf("%lld", n % 10);
		return reverse_recursion(n / 10);
	}
}




void print_digitSum()
{
	long long n;
	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//수를 입력받음
	printf("%lld\n", digit_recursion(n));	//함수를 호출하여 결과 값을 출력
}
long long digit_recursion(long long n)
{
	if(n>=0 && n<10)	//한자리 수일 경우 그 값을 출력
		return n;
	else
		return (n % 10) + digit_recursion(n / 10);	//두자리 이상 값일 경우 각 자리의 값을 더하여 출력하도록 재귀함수를 생성
}

void print_numOfOne()
{
	long long n;
	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//이진수를 입력받음
	printf("%lld\n", numOfOne_recursion(n)); //함수를 호출하여 결과 값을 출력
}
long long numOfOne_recursion(long long n)	//이진수의 경우 1과 0으로만 이루어져 있어 1의 개수를 세는 것은 각 자리수의 값을 모두 더하는 것과 같은 방식으로 가능하다.
{
	if(n>=0 && n<10)	//한자리수일 경우 그 값이 0인지 1인지 판별하여 그 값을 출력
			return n;
		else
			return (n % 10) + digit_recursion(n / 10);	//두 자리 이상일 경우 각 자리 값을 구하여 더함 (이때 0값을 더해도 무관하므로 더해지는 값은 모두 1값이며 곧 1의 개수를 세는 것과 같다)
}

void print_stair()
{
	long long n;
	scanf("%lld", &n);	//오를 계단의 수를 입력받음
	printf("%lld\n", stair_recursion(n));	//함수를 호출하여 결과 값을 출력
}

long long stair_recursion(long long n)	//계단을 오르는 방법의 수는 피보나치 수열과 같은 맥락으로 계산이 가능하다
{
	if(n == 1)
		return 1;	//계단이 한개일 경우 하나만 오르는 경우	1가지
	else if(n == 2)
		return 2;	//계단이 두개일 경우 한개씩, 두개를 한번에 오르는 2가지 경우
	else
		return stair_recursion(n-1) + stair_recursion(n-2);	//재귀함수를 이용하여 입력받은 값의 계단 수를 오르는 경우의 수를 구하는 함수 생성
}

