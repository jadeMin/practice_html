/*
 * source.c
 *
 *  Created on: 2016. 4. 8.
 *      Author: Administrator
 */
#include <stdio.h>

void checkCommonDivisor()
{
	int a, b, result;

	printf("두 개의 양의 정수를 입력하시오: ");
	fflush(stdout);
	scanf("%d %d", &a, &b);

	result = (a % b == 0)||(b % a == 0);	//나누었을 때 나머지가 0인지 확인하여 배수조건 만족 여부 확인

	if(result == 1)
		printf("Yes");	//배수일 경우 참이므로 결과는 1이 된다
	else
		printf("No");	//배수가 아닐 경우 거짓이므로 결과가 0이 된다

}

void checkTriangle()
{
	int a, b, c, total;

	printf("삼각형의 세 변의 길이를 입력하시오: ");
	fflush(stdout);
	scanf("%d %d %d", &a, &b, &c);

	total = (a + b > c)&&(b + c > a)&&(a + c > b);	//삼각형 성립 조건: 가장 긴 변의 길이가 다른 변의 길이 합보다 작을때 성립한다

	if(total == 1)
		printf("Yes");	//성립조건을 만족할 경우 최종 값을 참이므로 1이 된다
	else
		printf("No");	//성립조건을 만족하지 않을 경우 최종 값이 거짓이므로 0이 된다
}


void calculateFee()
{
	int hour, min, age, time;
	printf("현재 시간(시, 분)과 나이를 입력하시오: ");
	fflush(stdout);
	scanf("%d %d %d", &hour, &min, &age);

	time = hour * 60 + min;	//시간을 분으로 환산

	if(time >= 540 && time <= 1020){	//시간이 오전 9시 이후 오후 5시 이전일 경우
			if(age <=12 || age >= 65){	//나이가 12세 이하 65세 이상일 경우
		printf("25,000");}

			else{	//시간은 오전 9시이후 오후 5시 이전이나 나이가 12세 초과 65세 미만일 경우
		printf("34,000");}
	}
	else	//시간이 오전 9시이후 오후 5시 이전이 아닐 경우
		printf("10,000");

}

void calculateTax()
{
	float income, result;

	printf("근로소득액을 입력하시오: ");
	fflush(stdout);
	scanf("%f", &income);

	if(income<=12000000){result = income * 0.06;}	//소득이 1200만원 이하일 경우 6%의 세율 적용
	else if(income<=46000000){result = income * 0.15;}	//소득이 1200만원 이상 4600만원 이하일 경우 15%의 세율 적용
	else if(income<=88000000){result = income * 0.24;}	//소득이 4600만원 이상 8800만원 이하일 경우 24%의 세율 적용
	else if(income<=150000000){result = income * 0.35;}	//소득이 8800만원 이상 1억5천만원 이하일 경우 35%의 세율 적용
	else{result = income * 0.38;}	//소득이 1억5천만원 초과일 경우 38%의 세율 적용

	printf("%.f", result);
}

void calculateOverlapRect()
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	int width, height;
	int temp1, temp2;
	int result;

	printf("두개의 사각형의 좌표를 입력하시오: ");
	fflush(stdout);
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

	if(x4 > x2){	//두번째 사각형이 더 오른쪽에 위치할 경우 경우
		if(x1 > x3)	//첫번째 사각형의 가로가 두번째 사각형의 가로 범위 안에 포함될 경우
			temp1 = x4 - x3;	//포함하는 사각형의 가로길이
		else	//척번째 사각형의 가로가 두번째 사각형의 가로 범위 안에 포함되지 않을 경우
			temp1 = x4 - x1;	//사각형의 가로가 위치하는 x의 전체 길이
	}
	else{	//두번째 사각형이 첫번째보다 오른쪽에 위치하지 않을 경우
		if (x3 > x1)	//두번째 사각형의 가로가 첫번째 사각형의 가로 범위 안에 포함될 경우
			temp1 = x2 - x1;	//포함하는 사각형의 가로길이
		else	//두번째 사각형의 가로가 첫번째 사각형의 가로 범위 안에 포함되지 않을 경우
			temp1 = x2 - x3;	//사각형의 가로가 위치하는 x의 전체 길이
	}

	width = (x2 - x1) + (x4 - x3) - temp1;	//사각형이 곂치는 부분의 가로길이

	if(y4 > y2){	//두번째 사각형이 더 위쪽에 위치할 경우 경우
			if(y1 > y3)	//첫번째 사각형의 세로가 두번째 사각형의 세로 범위 안에 포함될 경우
				temp2 = y4 - y3;	//포함하는 사각형의 세로길이
			else	//척번째 사각형의 세로가 두번째 사각형의 세로 범위 안에 포함되지 않을 경우
				temp2 = y4 - y1;	//사각형의 세로가 위치하는 y의 전체 길이
		}
		else{	//두번째 사각형이 첫번째보다 위쪽에 위치하지 않을 경우
			if (y3 > y1)	//두번째 사각형의 세로가 첫번째 사각형의 세로 범위 안에 포함될 경우
				temp2 = y2 - y1;	//포함하는 사각형의 세로길이
			else	//두번째 사각형의 세로가 첫번째 사각형의 세로 범위 안에 포함되지 않을 경우
				temp2 = y2 - y3;	//사각형의 세로가 위치하는 y의 전체 길이
		}

	height = (y2 - y1) + (y4 - y3) - temp2;	//사각형이 곂치는 부분의 세로길이

	if(width > 0 && height > 0)
		result = width * height;	//곂치는 부분의 넓이

	else
		result = 0;	//width나 height가 음수일경우 곂치는 부분이 없으므로 0을 출력

	printf("%d", result);

}

int main()
{
	//checkCommonDivisor();
	//checkTriangle();
	//calculateFee();
	//calculateTax();
	//calculateOverlapRect();

	return 0;
}

