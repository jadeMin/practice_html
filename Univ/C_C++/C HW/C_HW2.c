#include<stdio.h>
void computeDivision() //몫과 나머지 출력
{
 int x, y, rest, quota;
 printf("두 정수를 입력하시오: ");
 fflush(stdout);
 scanf("%d %d", &x, &y);

 quota = x / y; //몫을 구하기
 rest = x % y; //나머지 구하기

 printf("%d / %d 의 몫은 %d입니다.\n", x, y, quota);
 printf("%d / %d 의 나머지는 %d입니다.", x, y, rest);	//결과값 출력

}

void computeTemperature() //화씨를 섭씨로, 섭씨를 화씨로 변환
{
 float feh1, feh2, cel1, cel2;
 printf("화씨 온도를 입력하세요: ");
 fflush(stdout);
 scanf("%f", &feh1);

 cel1 = (feh1 - 32) / 1.8;	//화씨를 섭씨로 변환

 printf("화씨온도 %.f는 섭씨 온도 %.2f입니다.\n", feh1, cel1);

 printf("섭씨 온도를 입력하세요: ");
 fflush(stdout);
 scanf("%f", &cel2);

 feh2 = (cel2 * 1.8) + 32;	//섭씨를 화씨로 변환

 printf("섭씨 온도 %.f는 화씨온도 %.2f입니다.", cel2, feh2);


}

 


void computeHoursforMars() //화성까지의 시간 계산
{
 const int distance = 75000000;	//화성까지의 거리
 float rocket, air, f1, ktx;
 
 printf("지구에서 화성까지의 거리 : 약 %d km\n", distance);

 rocket = distance / 11.9 / 60 / 60;	//로켓을 이용했을 때 걸리는 시간
 air = distance / 850.0;	//항공기을 이용했을 때 걸리는 시간
 f1 = distance / 350.0;	//f1을 이용했을 때 걸리는 시간
 ktx = distance / 300.0;	//ktx을 이용했을 때 걸리는 시간

 printf("역추진 로켓을 이용했을때 화성까지 걸리는 시간: %.2f\n", rocket);
 printf("민간 항공기를 이용했을때 화성까지 걸리는 시간: %.2f\n", air);
 printf("경주용 자동차(F1)을 이용했을 때 화성까지 걸리는 시간: %.2f\n", f1);
 printf("KTX 열차를 이용했을 때 화성까지 걸리는 시간: %.2f", ktx);	//결과값 출력

}


void computeDigitSum()
{
 int num, thou, hund, ten, one, temp, temp1, result;
 printf("숫자<0<= number <= 10000>를 입력하시오: ");
 fflush(stdout);
 scanf("%d", &num);

 thou = num / 1000;	//천의 자리수를 구하기
 temp = num % 1000;	
 hund = temp / 100;	//백의 자리수를 구하기
 temp1 = temp % 100;
 ten = temp1 / 10;	//십의 자리수를 구하기
 one = temp1 % 10;	//일의 자리수를 구하기

 result = thou + hund + ten + one; //각 자리수의 합

 printf("%d 의 자리수의 합은 %d 입니다.", num, result);

 (result % 7 == 0)?printf("%d는 7의 배수입니다.", result):printf("%d는 7의 배수가 아닙니다.", result); //자리수의 합이 7의 배수인지 확인

}

void checkQuadrant()
{
 int x, y;
 printf("2차원 공간의 좌표 (x, y)를 입력하세요: ");
 fflush(stdout);
 scanf("%d %d", &x, &y);

 (x>0 && y>0)?printf("(%d, %d)는 1사분면에 속합니다.\n", x, y):printf("(%d, %d)는 1사분면에 속하지 않습니다.\n", x, y);	//조건연산자를 통해 1사분면인지 여부 확인
 (x<0 && y>0)?printf("(%d, %d)는 2사분면에 속합니다.\n", x, y):printf("(%d, %d)는 2사분면에 속하지 않습니다.\n", x, y);	//조건연산자를 통해 2사분면인지 여부 확인
 (x<0 && y<0)?printf("(%d, %d)는 3사분면에 속합니다.\n", x, y):printf("(%d, %d)는 3사분면에 속하지 않습니다.\n", x, y);	//조건연산자를 통해 3사분면인지 여부 확인
 (x>0 && y<0)?printf("(%d, %d)는 4사분면에 속합니다.\n", x, y):printf("(%d, %d)는 4사분면에 속하지 않습니다.\n", x, y);	//조건연산자를 통해 4사분면인지 여부 확인
 
}

 

void checkParallelLine()
{
 int x1, x2, x3, x4, y1, y2, y3, y4;
 int grad1, grad2;
 printf("첫 번째 2차원 공간의 두 점 (x1, y1), (x2, y2)를 입력하세요: ");
 fflush(stdout);
 scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

 printf("두 번째 2차원 공간의 두 점 (x3, y3), (x4, y4)를 입력하세요: ");
 fflush(stdout);
 scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

 printf("(x1, y1), (x2, y2)의 값은 (%d, %d), (%d, %d)\n", x1, y1, x2, y2);	//입력받은 값 확인
 printf("(x3, y3), (x4, y4)의 값은 (%d, %d), (%d, %d)\n", x3, y3, x4, y4);	//입력받은 값 확인

 grad1 = (y2-y1) / (x2-x1);	//(x1, y1)과 (x2, y2) 간의 기울기 확인
 grad2 = (y4-y3) / (x4-x3);	//(x3 ,y3)와 (x4, y4) 간의 기울기 확인

 (grad1 == grad2) ? printf("두 직선은 평행합니다."):printf("두 직선은 평행하지 않습니다.");	//결과값 출력


}



int main()
{
	computeDivision();
	computeTemperature();
	computeHoursforMars();
	computeDigitSum();
	checkQuadrant();
	checkParallelLine();



	return 0;
}