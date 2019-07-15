
#include <stdio.h>


void gugudan()  // 전체 구구단 출력
{
	int i, j, result;	//변수선언
	for(i=1;i<10;i++)	//구구단의 오른쪽 곱값 설정
	{
		for(j=2;j<10;j++)	//구구단의 왼쪽 곱값 설정
		{
			result = i * j;	//구구단 연산
			printf("%d x %d = %d\t", j, i, result);	//구구단의 모양과 값을 출력
		}
		printf("\n");	//예시와 같은 모양이 되도록 설정하여 출력
	}
}


void printTriangle()  // N을 입력받아 N줄의 직각삼각형 모양으로 별찍기
{
	int i, j, line;	//변수 선언
	printf("N(0 < N <= 10)인 N을 입력하시오:");
	fflush(stdout);
	scanf("%d", &line);	//삼각형을 구성할 줄 개수 입력

	if(line<1||line>10)	//주어진 범위 내 값이 입력되었는지 확인
		printf("wrong!");
	else
	{
		for(i=1;i<=line;i++)	//입력받은 줄 개수만큼 출력되도록 설정
		{
			for(j=1;j<=i;j++)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정
			{
				printf("*");
			}
			printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
		}
	}
}


void printReverseTriangle()  // N줄만큼 역직각삼각형 별찍기
{
	int i, j, line;
		printf("N(0 < N <= 10)인 N을 입력하시오:");
		fflush(stdout);
		scanf("%d", &line);	//삼각형을 구성할 줄 개수 입력

		if(line<1||line>10)	//주어진 범위 내 값이 입력되었는지 확인
			printf("wrong!");
		else
		{
			for(i=1;i<=line;i++)	//입력받은 줄 개수만큼 출력되도록 설정
			{
				for(j=line;j>=i;j--)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정
				{
					printf("*");
				}
				printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
			}
		}
}


void printRealTriangle()  // N줄만큼 직각삼각형 모양으로 별찍기
{
	int i, j, k, line;
	printf("N(0 < N <= 10)인 N을 입력하시오:");
	fflush(stdout);
	scanf("%d", &line);	//삼각형을 구성할 줄 개수 입력

	if(line<1||line>10)	//주어진 범위 내 값이 입력되었는지 확인
		printf("wrong!");
	else
	{
		for(i=1;i<=line;i++)	//입력받은 줄 개수만큼 출력되도록 설정
		{
			for(k=line;k>i;k--)	//정삼각형의 모양이 되도록 *이 출력되기 전 빈공간이 출력될 수 있도록 설정
				printf(" ");
			for(j=1;j<=i;j++)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정
			{
				printf("* ");	//정삼각형의 모양이 되도록 * 뒤에 빈 공간 출력
			}
			printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
		}
	}
}


void printRealReverseTriangle()  // N줄만큼 역정삼각형 모양으로 별찍기
{
	int i, j, k, line;
	printf("N(0 < N <= 10)인 N을 입력하시오:");
	fflush(stdout);
	scanf("%d", &line);	//삼각형을 구성할 줄 개수 입력

	if(line<1||line>10)	//주어진 범위 내 값이 입력되었는지 확인
		printf("wrong!");
	else
	{
		for(i=1;i<=line;i++)	//입력받은 줄 개수만큼 출력되도록 설정
		{
			for(k=1;k<=i;k++)	//정삼각형의 모양이 되도록 *이 출력되기 전 빈공간이 출력될 수 있도록 설정
				printf(" ");
			for(j=line;j>=i;j--)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정
			{
				printf("* ");	//정삼각형의 모양이 되도록 * 뒤에 빈 공간 출력
			}
			printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
		}
	}
}


void printDiamond()  // 마름모의 길이 입력받고 N만큼 마름모모양 별찍기
{
	int i, j, k, line;
	printf("N(0 < N <= 10)인 N을 입력하시오:");
	fflush(stdout);
	scanf("%d", &line);	//삼각형을 구성할 줄 개수 입력

		if(line<1||line>10)	//주어진 범위 내 값이 입력되었는지 확인
			printf("wrong!");
	else
	{
		for(i=1;i<=line;i++)	//입력받은 줄 개수만큼 출력되도록 설정
		{
			for(k=line;k>i;k--)	//정삼각형의 모양이 되도록 *이 출력되기 전 빈공간이 출력될 수 있도록 설정
				printf(" ");
			for(j=1;j<=i;j++)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정
			{
				printf("* ");	//정삼각형의 모양이 되도록 * 뒤에 빈 공간 출력
			}
			printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
		}
		for(i=1;i<=line;i++)	//입력받은 줄 개수보다 하나 작은만큼 출력되도록 설정
		{
			for(k=1;k<=i;k++)	//정삼각형의 모양이 되도록 *이 출력되기 전 빈공간이 출력될 수 있도록 설정
				printf(" ");
			for(j=line;j>i;j--)	//삼각형의 모양을 이루도록 출력되는 * 개수를 설정, 이때 위 정삼각형과 *개수가 겹치는 줄이 없도록 한다.
			{
				printf("* ");	//정삼각형의 모양이 되도록 * 뒤에 빈 공간 출력
			}
			printf("\n");	//삼각형 모양이 제대로 출력되도록 \n을 활용
		}
	}
}


int main()
{
	//gugudan();
	//printTriangle();
	//printReverseTriangle();
	//printRealTriangle();
	//printRealReverseTriangle();
	//printDiamond();

	return 0;
}

