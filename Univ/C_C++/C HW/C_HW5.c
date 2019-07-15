/*
 * source.c
 *
 *  Created on: 2016. 5. 5.
 *      Author: Administrator
 */
#include<stdio.h>

void AddReverseNumber()
{
	int j, num;
	int number = 0;
	int digit = 1;
	int reverse = 0;
	int result = 0;

	printf("Input the number: ");
	fflush(stdout);
	scanf("%d", &num);	//초기 값을 입력받음

	number = num;	//초기 입력값이 바뀌지 않도록 새로운 변수 활용

	while(1)	//입력받은 수의 자리수 계산
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//바뀐 값을 입력값으로 초기화

	for(j=1; j<=digit; j++)	//입력받은 수의 자리수 만큼 아래 함수를 실행
	{
		reverse = reverse + (number % 10);	//10으로 나눈 나머지 값을 더하여 입력받은 수의 제일 작은 자리수의 값부터 더해지도록 한다

		if(j<digit)
			reverse = reverse * 10;	//더해야 할 값이 남아있을 경우 10을 곱하여 자리수를 하나씩 증가시킨다
		else
			break;

		number = number / 10;	//더한 자리수의 다음 자리수가 10으로 나눈 나머지값으로 도출 될 수 있도록 식을 유도한다
	}

	result = num + reverse;	//초기 입력값과 변환한 값을 더해 결과 값을 계산한다

	printf("The sum of two numbers is: %d", result);	//결과 출력

}
void RevertDecimalNumber()
{
	long long i, j, num, number;
	long long digit = 1;
	long long revert = 1;
	long long result = 0;

	printf("이진수를 입력하시오 : ");
	fflush(stdout);
	scanf("%lld", &num);

	number = num;

	while(1)	//입력받은 수의 자리수 계산
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//초기 입력값이 바뀌지 않도록 새로운 변수 활용

	for(i=1;i<=digit;i++)	//각각의 자리수의 값을 계산하여 결과 값을 도출
	{
		if(i == 1)	//자리수가 1의 자리일 때 값
			revert = 1;
		else
			for(j=1;j<=i-1;j++)	//해당하는 자리수가 가지는 10진수의 수를 구함
			{
				revert = revert * 2;	//각 자리수의 값이 2의 n승 구조인 이진법의 특성을 이용하여 식을 세움
			}

		if(number % 10 != 0)	//해당하는 자리수의 값을 더할 필요가 있는지 확인
		{
			result = result + revert;	//해당하는 자리수의 10진수를 변환한 값을 더함
			number = number / 10;	//더한 자리수의 다음 자리수가 10으로 나눈 나머지값으로 도출 될 수 있도록 식을 유도한다
		}
		else
			number = number / 10;	//더한 자리수의 다음 자리수가 10으로 나눈 나머지값으로 도출 될 수 있도록 식을 유도한다

		revert = 1;	//자리수 값을 도출하기 위해 변수 초기화
	}

	printf("이진수 %lld의 변환된 10진수 : %lld", num, result);	//결과값 출력

}
void CheckPalindrome()
{
	int j, num, number;
	int digit= 1;
	int reverse = 0;

	printf("Input the number: ");
	fflush(stdout);
	scanf("%d", &num);

	number = num;	//초기 입력값이 바뀌지 않도록 새로운 변수 활용

	while(1)	//입력받은 수의 자리수 계산
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//바뀐 값을 입력값으로 초기화

	for(j=1; j<=digit; j++)	//입력받은 수의 자리수 만큼 아래 함수를 실행
	{
		reverse = reverse + (number % 10);	//10으로 나눈 나머지 값을 더하여 입력받은 수의 제일 작은 자리수의 값부터 더해지도록 한다
		number = number / 10;	//더한 자리수의 다음 자리수가 10으로 나눈 나머지값으로 도출 될 수 있도록 식을 유도한다

		if(j<digit)
			reverse = reverse * 10;	//더해야 할 값이 남아있을 경우 10을 곱하여 자리수를 하나씩 증가시킨다
		else
			break;

	}

	if(num != reverse)
		printf("Not Palindrome");

	else
		printf("Palindrome");
}
void CalculatePCFee()
{
	int hour1, min1, hour2, min2, time, result_hour, result_min, result, remain;
	int fee_for_30;
	printf("시작 시간 입력(시간 분): ");	//시작시간 입력
	fflush(stdout);
	scanf("%d %d", &hour1, &min1);

	printf("종료 시간 입력(시간 분): ");	//종료시간 입력
	fflush(stdout);
	scanf("%d %d", &hour2, &min2);

	printf("30분당 이용 금액(원): ");		//30분당 이용 금액 입력
	fflush(stdout);
	scanf("%d", &fee_for_30);

	time = (hour2 * 60 + min2) - (hour1 * 60 + min1);	//시간을 모두 분 단위로 환산

	while(time>0)	//시간이 양수인 경우에만 계산
	{

		if(time >= 60)	//이용시간을 시간과 분으로 표현
		{
			result_hour = time / 60;
			result_min = time % 60;
			printf("전체 이용 시간: %d시간 %d분 <%d분>\n", result_hour, result_min, time);
		}
		else
			printf("전체 이용 시간: 0시간 %d분 <%d분>\n", time, time);

		if(time <=30)	//이용 시간이 30분 이하일 경우 30분 이용요금으로 출력
			printf("사용 금액: %d", fee_for_30);
		else	//이용시간이 30분 이상이 경우
		{
			result = time / 30;
			remain = time % 30;

			if(remain !=0)	//1분이라도 초과 될 경우 30분 요금을 추가
			{
				result++;
			}
			printf("사용 금액: %d", result * fee_for_30);	//최종 사용 금액 출력
		}
		break;
	}
}
void Calender()
{
	int year, month;
		int totalday;
		int lastyear, day, i;

		printf("Input the Input the year and month: ");	//년도와 월을 입력받음
		fflush(stdout);
		scanf("%d %d", &year, &month);

		if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))	//윤년 계산 공식, 윤년일 경우 각 달의 일수
		{
			if(month == 2)	//윤년일 경우 2월은 29일까지
				totalday = 29;
			else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				totalday = 31;
			else if(month == 4 || month == 6 || month == 9 || month == 11)
				totalday = 30;
		}
		else	//윤년이 아닐 경우 각 달의 일수
		{
			if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				totalday = 31;
		    else if(month == 4 || month == 6 || month == 9 || month == 11)
		    	totalday = 30;
		    else if(month == 2)
		        totalday = 28;	//윤년이 아닐 경우 2월은 28일까지

		}
		lastyear = year-1;
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear/400) +1 ) % 7;	//올 해가 시작되는 요일 계산
		for(i=1; i<month; i++)
			day = day + totalday;

		day %= 7;

		printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat");	//달력 형식에 맞게 요일 출력
		for(i=-day; i<totalday; i++)
		{
			if((i+day)%7==0)
				printf("\n");
			if(i<0)
				printf("\t");
		    else
		        printf("%d\t", i+1);
		}
		printf("\n");
}

void EulerProject6()
{
	int result1, square, i, gap;
	int add = 0, result2 = 0;

	for(i=1; i<=100; i++)
	{
		add = add + i;	//1부터 100까지의 합
		square = i * i;	//1부터 100까지 숫자들의 제곱
		result2 = result2 + square;	//1부터 100까지의 숫자의 제곱들의 합
	}
	result1 = add * add;	//1부터 100까지의 합의 제곱

	if(result1 >= result2)	//합의 제곱과 제곱의 합 값 중 큰 값 판별
	{
		gap = result1 - result2;
	}
	else
	{
		gap = result2 - result1;
	}

	printf("%d", gap);	//합의 제곱과 제곱의 합의 차이 출력
}
void EulerProject7()
{
	int i=1;
	int j;
	int count = 1;

	while(1)
	{
		i+=2;

		for(j=3;(j*j<i)&&(i%j!=0);j+=2);	//소수 구하는 공식
	    if(j*j>i)
	    {
	    	count+=1;
	    }
	    if(count==10001)	//10001번째 소수를 구함
	    {
	    	break;
	    }

	}
   printf("%d", i );
}
void EulerProject9()
{
	int a, b, c;

	for(c=1;c<1000;c++)	//a+b+c = 1000을 만족해야 하므로 한 수가 1000을 절대 넘을 수 없다
	{
		for(b=1;b<c;b++)
		{
			for(a=1;a<b;a++)
			{
	            if(a*a+b*b == c*c)	//피타고라스의 정리에 만족하는지 확인
	            {
	               if(a+b+c==1000)	//조건 식을 만족하는지 여부 확인
	                  printf("%d", a*b*c);	//그 때에 요구하는 식의 값을 도출
	            }
	        }
		}
	}	//a,b,c의 순서가 바뀌어도 상관이 없다. 범위를 설정하여 중복되는 값이 나오지 않도록 한다
}
void EulerProject10()
{
	long long i, j;
	long long sum = 0;

	for(i = 2; i <= 2000000; i++)	//이백만 이하의 소수 값을 구하는 식
	{
		for(j = 2; j <= i-1; j++)
		{
			if(i % j == 0)
			{
				break;
			}
		}
		if(i == j)	//구해진 소수값들의 합
		{
			sum = sum + i;
		}

	}
	printf("%lld", sum);
}
void EulerProject12()
{
	int i, j;
	int num = 1;
	int total = 0;
	int t = 0;
	const int number = 500;	//500개 이하의 약수를 갖는 삼각수를 구하여야 하므로 약수의 개수를  500으로 고정
    while (1)
    {
        for (i = 1; i <= num; i++)	//삼각수를 구하는 식
        {
            total = total + i;
        }
        for (j = 1; j <= total; j++)	//삼각수의 약수 값들을 구하는 공식
        {
            if (total % j == 0)
            {
                t++;
            }
        }
        if (t >= number - 1)	//1의 값은 모든 수의 약수이므로 1을 포함하여 500개의 약수를 가져야 한다
            break;
        t = 0;
        total = 0;
        num++;	//조건을 만족하지 못한 경우(500개) 변수 초기화
    }

	printf("%d", total);	//결과값 출력
}
int main()
{
	//AddReverseNumber();
	//RevertDecimalNumber();
	//CheckPalindrome();
	//CalculatePCFee();
	//Calender();
	//EulerProject6();
	//EulerProject7();
	//EulerProject9();
	//EulerProject10();
	//EulerProject12();
	return 0;
}

