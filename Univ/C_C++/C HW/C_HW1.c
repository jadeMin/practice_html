/*
 * March.c
 *
 *  Created on: 2016. 3. 31.
 *      Author: Administrator
 */
#include<stdio.h>

void printReport()  // 3명의 세 과목의 점수 입력받고 점수와 총점, 평균을 출력
{
 int korean1, korean2, korean3;
 int english1, english2, english3;
 int math1, math2, math3;
 int total1, total2, total3;
 float average1, average2, average3;
 printf("첫 번째 학생의 세 과목 점수를 입력하시오: ");
 fflush(stdout);
 scanf("%d %d %d", &korean1, &english1, &math1);
 printf("두 번째 학생의 세 과목 점수를 입력하시오: ");
 fflush(stdout);
 scanf("%d %d %d", &korean2, &english2, &math2);
 printf("세 번째 학생의 세 과목 점수를 입력하시오: ");
 fflush(stdout);
 scanf("%d %d %d", &korean3, &english3, &math3);

 total1 = korean1 + english1 + math1;
 average1 = total1 / 3.0;
 total2 = korean2 + english2 + math2;
 average2 = total2 / 3.0;
 total3 = korean3 + english3 + math3;
 average3 = total3 / 3.0;
 printf("국어	영어	수학	총점	평균\n");
 printf("%d	%d	%d	%d	%.2f\n", korean1, english1, math1, total1, average1);
 printf("%d	%d	%d	%d	%.2f\n", korean2, english2, math2, total2, average2);
 printf("%d	%d	%d	%d	%.2f\n", korean3, english3, math3, total3, average3);
}

void arithmeticOperations()  // 입력받은 두 수의 사칙연산 결과 출력
{
 long long x, y, add, subs, mult, divi;
 printf("두 개의 정수를 입력하시오: ");
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

void transformSpace()  // 평을 제곱미터로, 제곱미터를 평으로 변환하여 출력
{
 float square1, square2, pyeong1, pyeong2;
 printf("평을 입력하시오:");
 fflush(stdout);
 scanf("%f", &pyeong1);

 square1 = pyeong1 * 3.3;

 printf("입력한 평수 %.f는 %.2f 제곱미터입니다.\n", pyeong1, square1 );

 printf("제곱미터를 입력하시오:");
 fflush(stdout);
 scanf("%f", &square2);
 pyeong2 =  square2 / 3.3;

 printf("입력한 제곱미터 %.f는 %.2f 평입니다.", square2, pyeong2);
}

void transformHeight()  // 입력받은 키를 피트로 변환하여 출력
{
 int height, feet;
 float inch;
 printf("키(cm)를 입력하시오:");
 fflush(stdout);
 scanf("%d", &height);

 feet = height / 2.54 / 12;
 inch = height / 2.54 - feet * 12;
 printf("입력한 키 %d는 %d 피트 %.3f 인치 입니다.", height, feet, inch);
}

void printDigits()  // 1000 미만의 수 입력받아 일, 십, 백의자리 출력
{
	int thous, hund, ten, one, temp;
	printf("1000미만의 정수를 입력하시오: ");
	fflush(stdout);
	scanf("%d", &thous);

	hund = thous / 100;
	temp = thous % 100;
	ten = temp / 10;
	one = temp % 10;

	printf("%d의 백의 자리는 %d입니다.\n", thous, hund);
	printf("%d의 십의 자리는 %d입니다.\n", thous, ten);
	printf("%d의 일의 자리는 %d입니다.\n", thous, one);

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

