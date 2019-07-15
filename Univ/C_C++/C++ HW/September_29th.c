/*
 * 29th.c
 *
 *  Created on: 2016. 9. 29.
 *      Author: 이선민
 */
#include<stdio.h>

int num;	//input
int digits[100];	//output
int nDigits;	//# of digits

void printDigits()
{
	int i;
	printf("digits[%d]: ", nDigits);
	for(i=0; i<=nDigits-1; i++)	//주어진 수의 자리수만큼 자리수의 배열을 만든 후 그 배열에 각각 자리수의 값을 넣는다
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
		int d = num2 % 10;	//주어진 숫자의 가장 작은 자리수의 값을 구한다
		digits[i] = d;	//그 값을 해당 자리수의 배열에 넣는다
		i++;	//다음 자리수를 구하기 위해 i값을 증가시킨다
		num2 = num2 / 10;	//주어진 숫자의 가장 작은 자리수부분을 없애 다음 자리수의 값을 도출할 수 있게 설정한다
		//printf("%d %d\n", d, num2);

		if(num2 == 0)	//모든 자리수의 값을 구하고 난 후에는 더이상 반복되지 않게 한다
			break;
	}
	nDigits = i;	//i값이 자리수의 값과 같다
}

int digitsToNum()
{
	int i;
	int numR = 0;
	int k = 1;

	for(i=0; i<nDigits; i++)	//자리수 만큼 실행되는 반복문을 설정하여 초기 값을 도출한다
	{
		numR = numR + digits[i] * k;	//각 자리수의 맞는 10의  n승값을 곱해주어 원래의 형태의 수가 나오도록 한다
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
	d = num2 % 10;	//가장 작은 자리수의 값을 구한다
	digits[i] = d;	//그 값을 해당하는 자리수의 배열에 넣는다
	i++;	//자리수를 증가시킨다
	num2 = num2 / 10;
		//다음 자리수가 도출될 수 있도록 가장 작은 자리수의 값을 없애 다음으로 작은 자리수가 가장 작은 자리수가 되도록 설정한다
	nDigits = i;	//자리수는 i-1개와 같다

	if(num2 == 0)	//num2이 0이면 d값에 -1을 저장
		d = -1;
	return d;
}

void getOneDigit2()
{
	while(1)
	{
		int d= getOneDigit();	//변수 d를 설정하여 getOneDigit함수를 통해 도출되는 자리수의 값을 받는다

		if(d == -1)	//d의 값이 -1일때 반복문을 멈춘다
			break;
	}

}

void main()
{
	num = 54321;	//초기 값

	getOneDigit2();
	printDigits();
}
