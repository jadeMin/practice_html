/*
 * source.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: �̼���
 */
#include<stdio.h>

int factorial(int);
int power(int, int);
void printDivisors(int);

void Assignment1()
{
	int number = 3;	//���ϴ� ���丮���� ���� �� ����
	int result;
	result = factorial(number);	//���丮�� �Լ��� �̿��Ͽ� ��� �� ����
	printf("%d", result);	//��� �� ���
}

int factorial(int n)	//���丮�� ���� ����ϴ� �Լ�
{
	int i;
	int j = 1;
	for(i=1; i<=n; i++)	//������ ���丮�� ������ ���ǵ��� �ݺ����� Ȱ��
	{
		j = j * i;	//1���� ������ �� n���� ���� (���丮���� ����)
	}
	return j;	//���� ��� ��
}

void Assignment2()
{
	int a, b;
	a = 2;	//���ϴ� ���� ����
	b = 3;
	int result;
	result = power(a, b);	//�Լ��� ȣ���Ͽ� ��� ���� ����
	printf("%d", result);	//��� �� ���
}

int power(int x, int n)
{
	int i, j;
	j = 1;	//�ݺ����� ���� ������ ���� ����
	for(i=1; i<=n; i++)	//�Է� �� ���� ���� �� �ֵ��� �ݺ��� ����
	{
		j = j * x;	//�Էµ� �� a �� b�� ������ ���� ������̴�
	}
	return j;	//����� ���
}

void Assignment3()
{
	int number;
	number = 6;	//���ϴ� ���� ���� ����
	printDivisors(number); //����� ����ϴ� �Լ� ȣ��
}

void printDivisors(int x)
{
	int i;
	for(i=1; i<=x; i++)	//���ϴ� ��� ���� ��µǵ��� �ݺ����� ����
	{
		if(x % i == 0)	//������ �� n���� ������ �������� ���� ã�´�
			printf("%d ", i);	//�� ���� ���
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
