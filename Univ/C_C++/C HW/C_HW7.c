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
	scanf("%lld", &n);	//������ ������ �Է¹���

	for (i = 1; i <= n; i++)	//�Է¹��� �� ��ŭ ������ ���
	{
		printf("%lld\n", fib_recursion(i));	//�Լ��� ȣ���Ͽ� ��� �� ���
	}
}

long long fib_recursion(long long n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 1;
	else
		return fib_recursion(n-2) + fib_recursion(n-1);	//�Ǻ���ġ ������ �� ������ ���� �������� �հ� ����

}

void print_reverseNumber()
{
	long long n;

	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//�Ųٷ� ��� �� ���� �Է¹���

	n = delete_zero(n);	//�Ųٷ� �������� �� �տ� ��µǴ� 0�� ����� ���� �Լ� ȣ��

	printf("%lld\n", reverse_recursion(n));	//����� ���
}
long long delete_zero(long long n)
{
	while(1)	//1�� �ڸ����� 0�� ��� 0�� ���ִ� �ݺ����� ����
	{
		if(n % 10 == 0)
			n = n / 10;
		else
			break;
	}
	return n;	//���������� �տ� ��µǰ� �Ǵ� 0�� ������ n�� ����
}
long long reverse_recursion(long long n)
{
	if(0<=n && n < 10)	//n�� ���ڸ� �� �϶� n������ ���
		return n;
	else if(n>=10)	//n�� ���ڸ� �� �̻��� �� ����Լ��� �̿��Ͽ� �Ͽ� �ڸ����� ���� ���ʴ�� ����Ͽ� �Ųٷ� �� ���� ����ϰ� ��
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
	scanf("%lld", &n);	//���� �Է¹���
	printf("%lld\n", digit_recursion(n));	//�Լ��� ȣ���Ͽ� ��� ���� ���
}
long long digit_recursion(long long n)
{
	if(n>=0 && n<10)	//���ڸ� ���� ��� �� ���� ���
		return n;
	else
		return (n % 10) + digit_recursion(n / 10);	//���ڸ� �̻� ���� ��� �� �ڸ��� ���� ���Ͽ� ����ϵ��� ����Լ��� ����
}

void print_numOfOne()
{
	long long n;
	printf("Input the number : ");
	fflush(stdout);
	scanf("%lld", &n);	//�������� �Է¹���
	printf("%lld\n", numOfOne_recursion(n)); //�Լ��� ȣ���Ͽ� ��� ���� ���
}
long long numOfOne_recursion(long long n)	//�������� ��� 1�� 0���θ� �̷���� �־� 1�� ������ ���� ���� �� �ڸ����� ���� ��� ���ϴ� �Ͱ� ���� ������� �����ϴ�.
{
	if(n>=0 && n<10)	//���ڸ����� ��� �� ���� 0���� 1���� �Ǻ��Ͽ� �� ���� ���
			return n;
		else
			return (n % 10) + digit_recursion(n / 10);	//�� �ڸ� �̻��� ��� �� �ڸ� ���� ���Ͽ� ���� (�̶� 0���� ���ص� �����ϹǷ� �������� ���� ��� 1���̸� �� 1�� ������ ���� �Ͱ� ����)
}

void print_stair()
{
	long long n;
	scanf("%lld", &n);	//���� ����� ���� �Է¹���
	printf("%lld\n", stair_recursion(n));	//�Լ��� ȣ���Ͽ� ��� ���� ���
}

long long stair_recursion(long long n)	//����� ������ ����� ���� �Ǻ���ġ ������ ���� �ƶ����� ����� �����ϴ�
{
	if(n == 1)
		return 1;	//����� �Ѱ��� ��� �ϳ��� ������ ���	1����
	else if(n == 2)
		return 2;	//����� �ΰ��� ��� �Ѱ���, �ΰ��� �ѹ��� ������ 2���� ���
	else
		return stair_recursion(n-1) + stair_recursion(n-2);	//����Լ��� �̿��Ͽ� �Է¹��� ���� ��� ���� ������ ����� ���� ���ϴ� �Լ� ����
}

