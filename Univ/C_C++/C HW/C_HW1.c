/*
 * March.c
 *
 *  Created on: 2016. 3. 31.
 *      Author: Administrator
 */
#include<stdio.h>

void printReport()  // 3���� �� ������ ���� �Է¹ް� ������ ����, ����� ���
{
 int korean1, korean2, korean3;
 int english1, english2, english3;
 int math1, math2, math3;
 int total1, total2, total3;
 float average1, average2, average3;
 printf("ù ��° �л��� �� ���� ������ �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%d %d %d", &korean1, &english1, &math1);
 printf("�� ��° �л��� �� ���� ������ �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%d %d %d", &korean2, &english2, &math2);
 printf("�� ��° �л��� �� ���� ������ �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%d %d %d", &korean3, &english3, &math3);

 total1 = korean1 + english1 + math1;
 average1 = total1 / 3.0;
 total2 = korean2 + english2 + math2;
 average2 = total2 / 3.0;
 total3 = korean3 + english3 + math3;
 average3 = total3 / 3.0;
 printf("����	����	����	����	���\n");
 printf("%d	%d	%d	%d	%.2f\n", korean1, english1, math1, total1, average1);
 printf("%d	%d	%d	%d	%.2f\n", korean2, english2, math2, total2, average2);
 printf("%d	%d	%d	%d	%.2f\n", korean3, english3, math3, total3, average3);
}

void arithmeticOperations()  // �Է¹��� �� ���� ��Ģ���� ��� ���
{
 long long x, y, add, subs, mult, divi;
 printf("�� ���� ������ �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%lld %lld", &x, &y);
 add = x + y;
 subs = x - y;
 mult = x * y;
 divi = x / y;
 printf("%lld + %lld = %lld\n", x, y, add);
 printf("%lld - %lld = %lld\n", x, y, subs);
 printf("%lld * %lld = %lld\n", x, y, mult);
 printf("%lld / %lld = %lld\n", x, y, divi);
}

void transformSpace()  // ���� �������ͷ�, �������͸� ������ ��ȯ�Ͽ� ���
{
 float square1, square2, pyeong1, pyeong2;
 printf("���� �Է��Ͻÿ�:");
 fflush(stdout);
 scanf("%f", &pyeong1);

 square1 = pyeong1 * 3.3;

 printf("�Է��� ��� %.f�� %.2f ���������Դϴ�.\n", pyeong1, square1 );

 printf("�������͸� �Է��Ͻÿ�:");
 fflush(stdout);
 scanf("%f", &square2);
 pyeong2 =  square2 / 3.3;

 printf("�Է��� �������� %.f�� %.2f ���Դϴ�.", square2, pyeong2);
}

void transformHeight()  // �Է¹��� Ű�� ��Ʈ�� ��ȯ�Ͽ� ���
{
 int height, feet;
 float inch;
 printf("Ű(cm)�� �Է��Ͻÿ�:");
 fflush(stdout);
 scanf("%d", &height);

 feet = height / 2.54 / 12;
 inch = height / 2.54 - feet * 12;
 printf("�Է��� Ű %d�� %d ��Ʈ %.3f ��ġ �Դϴ�.", height, feet, inch);
}

void printDigits()  // 1000 �̸��� �� �Է¹޾� ��, ��, �����ڸ� ���
{
	int thous, hund, ten, one, temp;
	printf("1000�̸��� ������ �Է��Ͻÿ�: ");
	fflush(stdout);
	scanf("%d", &thous);

	hund = thous / 100;
	temp = thous % 100;
	ten = temp / 10;
	one = temp % 10;

	printf("%d�� ���� �ڸ��� %d�Դϴ�.\n", thous, hund);
	printf("%d�� ���� �ڸ��� %d�Դϴ�.\n", thous, ten);
	printf("%d�� ���� �ڸ��� %d�Դϴ�.\n", thous, one);

}

int main()
{
	printReport();
	transformSpace();
	arithmeticOperations();
	printDigits();
	transformHeight();

	return 0;
}

