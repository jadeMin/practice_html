/*
 * source.c
 *
 *  Created on: 2016. 5. 16.
 *      Author: Administrator
 */
#include <stdio.h>
// 조합 계산을 위한 함수
int get_integer();
long long factorial(int n);
long long combination(int n, int r);
void computeCombination();

// 완전수 계산을 위한 함수
int checkPerfect(int n);
void findPerfectNumber();

// 친화수 계산을 위한 함수
int checkFrindNumber(int n1, int n2);
void findFrindNumber();

// 숫자 야구 게임 함수
void DigitBaseballGame();

// 바이오리듬 계산을 위한 함수
int checkLeapYear(int year);
int checkMonth(int month, int leap_year);
int countDate(int birth_year, int birth_month, int birth_day, int year, int month);
void printBiorhythm(int date, int year, int month);
void computeBiorhythm();

int main()
{
	//computeCombination();
	//findPerfectNumber();
	//findFrindNumber();
	//DigitBaseballGame();
	//computeBiorhythm();
}


int get_integer()	// 조합 입력값 함수
{
	int num;
	scanf("%d", &num);
	return num;
}

long long factorial(int n)	// 팩토리얼 계산을 하는 함수
{
	int i;
	long long result = 1;
	for(i=1; i<=n; i++)
		result = result * i;	//반복문을 활용하여 팩토리얼 계산 식 완성
	return result;
}

long long combination(int n, int r)	// 팩토리얼을 이용하여 조합 계산을 하는 함수
{
	return factorial(n)/(factorial(n-r)*factorial(r));	//조합 공식
}

void computeCombination()	// 조합 계산
{
	int n = get_integer();
	int r = get_integer();
	printf("C(%d, %d) = %lld", n, r, combination(n, r));	//결과 출력
}


int checkPerfect(int n)	// 주어진 수가 완전수인지 아닌지를 판단하는 함수
{
	int j;
	int sum = 0;
	for(j=1; j<n; j++)	//약수를 구함
	{
		if(n % j == 0)
			sum += j;	//약수의 총합 계산
	}
	return sum;
}

void findPerfectNumber()	// 2~10000 사이의 완전수 찾기
{
	int i;
	for (i = 2; i <= 10000; i++)
	{
		if (checkPerfect(i) == i)	//완전수 여부 확인
		{
			printf("%d ", i);	//결과 출력
		}
	}
}


int checkFrindNumber(int n1, int n2)	// 주어진 수가 친화수인지 아닌지를 판단하는 함수
{
	int i, j;
	int sum1=0, sum2 =0;
	for(i=1; i < n1; i++)	//약수 구하는 공식
	{
		if(n1 % i == 0)
		{
			sum1 += i;	//n1 의 진약수의 합 구함
		}
	}
	for(j=1; j < n2; j++)	//약수 구하는 공식
	{
		if(n2 % j == 0)
		{
			sum2 += j;	//n2 의 진약수의 합 구함
		}
	}
	if(n1 == sum2 && n2 == sum1)	//친화수의 조건 만족 여부 확인
		return 1;

	return 0;
}


void findFrindNumber()	// 2~1000 사이의 친화수 찾기
{
	int i, j;
	for (i = 2; i <= 1000; i++)	//범위 내의 친화수 찾기
	{
		for (j = i + 1; j <= 1000; j++)
		{
			if (checkFrindNumber(i, j))
			{
				printf("(%d, %d) \n", i, j);	//결과값 출력
			}
		}
	}
}



void DigitBaseballGame()	// 숫자 야구 게임 함수
{
	int count=0, num1, num2, num3;
	int one, two, three;
	int strike=0, ball=0;

	printf("Play game ? <y/n> : y\n");

	srand((unsigned)time(NULL));	//임의의 변수 설정

	num1 = rand()%9+1;
	num2 = rand()%9+1;
	num3 = rand()%9+1;

	if(num1 == num2 || num2 == num3 || num1 == num3)	//세 수가 같을 경우 새로운 변수 설정
	{
		num1 = rand()%9+1;
		num2 = rand()%9+1;
		num3 = rand()%9+1;
	}

	while(1)
	{
		count++;
		strike = 0;
		ball = 0;
		if(count == 10)	//9라운드까지 실행해서 실패했을 경우 컴퓨터 승리
		{
			printf("COMPUTER WINNER !!!!\n");
			printf("The numbers are %d %d %d\n", num1, num2, num3);
			printf("play game?");
		}

		printf("*** BASEBALL GAME .... ROUND : %d\n", count);	//사용자가 임의의 수를 유추하여 입력
		printf("USER : ");
		fflush(stdout);
		scanf("%d %d %d", &one, &two, &three);

		if(one == num1 && two == num2 && three == num3)	//세 수가 모두 같은 경우 우승
		{
			printf("USER WINNER!!!\n");

			break;
		}

		else	//스트라이크와 볼, 아웃에 조건에 맞게 함수 설정
		{
			if(one == num1)
				strike+=1;
			if(two == num2)
				strike+=1;
			if(three == num3)
				strike+=1;

			if(one == num2)
				ball+=1;
			if(one == num3)
				ball+=1;
			if(two == num1)
				ball+=1;
			if(two == num3)
				ball+=1;
			if(three == num1)
				ball+=1;
			if(three == num2)
				ball+=1;

			if(strike>0 && ball==0)
				printf("COMPUTER : %d STRIKE !!!!\n", strike);	//조건에 맞는 결과 출력
			else if(ball>0 && strike==0)
				printf("COMPUTER : %d BALL !!!!\n", ball);
			else if(strike>0 && ball>0)
				printf("COMPUTER : %d STRIKE, %d BALL !!!!\n", strike, ball);
			else
				printf(" O U T !!!!\n");
		}
		printf("\n");
	}
	printf("Play game ? <y/n>:");
}
/*
int checkLeapYear(int year)	// 주어진 연도가 윤년인지 아닌지 판별하는 함수
{
	if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return 1;
	return 0;
}


int checkMonth(int month, int leap_year)	// 주어진 달이 며칠까지 있는지 판별하는 함수
{
	int total_day;
	if(checkLeapYear() == 1)
	{
		if(month == 2)
			total_day = 29;
		else if(month == 4 || 6 || 9 || 11)
			total_day = 30;
		else
			total_day = 31;
	}
	if(checkLeapYear() == 0)
	{
		if(month == 2)
			total_day = 28;
		else if(month == 4 || 6 || 9 || 11)
			total_day = 30;
		else
			total_day = 31;
	}

}

int countDate(int birth_year, int birth_month, int birth_day, int year, int month)	// 생년월일과 년과 월을 입력하였을 때 총 날짜수 계산
{
	int total_day1, total_day2;
	int leap_day;

	total_day1 =
}

void printBiorhythm(int date, int year, int month)	// 총 날짜수와 연과 월 입력시 바이오리듬 출력
{

}

void computeBiorhythm()	// 바이오리듬을 계산하는 함수
{
	int birth_year, birth_month, birth_day;
	int year, month, date;
	printf("생년 월일을 입력하세요 (ex: 1983 5 21)\n");
	scanf("%d %d %d", &birth_year, &birth_month, &birth_day);
	printf("보시고 싶은 년도와 월을 입력하세요. (ex: 2004 11)\n");
	scanf("%d %d", &year, &month);
	date = countDate(birth_year, birth_month, birth_day, year, month);
	printf("\n%d년 %d월 %d일과 %d년 %d월 1일 사이의 날짜 수는 %d 일 입니다.\n\n", birth_year, birth_month, birth_day, year, month, date + 1);
	printBiorhythm(date, year, month);
}

*/
