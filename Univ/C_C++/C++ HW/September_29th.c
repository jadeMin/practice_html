/*
 * 29th.c
 *
 *  Created on: 2016. 9. 29.
 *      Author: �̼���
 */
#include<stdio.h>

int num;	//input
int digits[100];	//output
int nDigits;	//# of digits

void printDigits()
{
	int i;
	printf("digits[%d]: ", nDigits);
	for(i=0; i<=nDigits-1; i++)	//�־��� ���� �ڸ�����ŭ �ڸ����� �迭�� ���� �� �� �迭�� ���� �ڸ����� ���� �ִ´�
	{
		printf("%d ", digits[i]);
	}
	printf("\n");
}

void getDigits()
{
	int num2 = num;
	int i = 0;

	while(1)
	{
		int d = num2 % 10;	//�־��� ������ ���� ���� �ڸ����� ���� ���Ѵ�
		digits[i] = d;	//�� ���� �ش� �ڸ����� �迭�� �ִ´�
		i++;	//���� �ڸ����� ���ϱ� ���� i���� ������Ų��
		num2 = num2 / 10;	//�־��� ������ ���� ���� �ڸ����κ��� ���� ���� �ڸ����� ���� ������ �� �ְ� �����Ѵ�
		//printf("%d %d\n", d, num2);

		if(num2 == 0)	//��� �ڸ����� ���� ���ϰ� �� �Ŀ��� ���̻� �ݺ����� �ʰ� �Ѵ�
			break;
	}
	nDigits = i;	//i���� �ڸ����� ���� ����
}

int digitsToNum()
{
	int i;
	int numR = 0;
	int k = 1;

	for(i=0; i<nDigits; i++)	//�ڸ��� ��ŭ ����Ǵ� �ݺ����� �����Ͽ� �ʱ� ���� �����Ѵ�
	{
		numR = numR + digits[i] * k;	//�� �ڸ����� �´� 10��  n�°��� �����־� ������ ������ ���� �������� �Ѵ�
		k = k * 10;
	}
	return numR;
}


int getOneDigit()
{
	static int num2 = -1, i=0;
	int d;
	if(num2 == -1)
	{
		num2 = num;
	}
	d = num2 % 10;	//���� ���� �ڸ����� ���� ���Ѵ�
	digits[i] = d;	//�� ���� �ش��ϴ� �ڸ����� �迭�� �ִ´�
	i++;	//�ڸ����� ������Ų��
	num2 = num2 / 10;
		//���� �ڸ����� ����� �� �ֵ��� ���� ���� �ڸ����� ���� ���� �������� ���� �ڸ����� ���� ���� �ڸ����� �ǵ��� �����Ѵ�
	nDigits = i;	//�ڸ����� i-1���� ����

	if(num2 == 0)	//num2�� 0�̸� d���� -1�� ����
		d = -1;
	return d;
}

void getOneDigit2()
{
	while(1)
	{
		int d= getOneDigit();	//���� d�� �����Ͽ� getOneDigit�Լ��� ���� ����Ǵ� �ڸ����� ���� �޴´�

		if(d == -1)	//d�� ���� -1�϶� �ݺ����� �����
			break;
	}

}

void main()
{
	num = 54321;	//�ʱ� ��

	getOneDigit2();
	printDigits();
}
