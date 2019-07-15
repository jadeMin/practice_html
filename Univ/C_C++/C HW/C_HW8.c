#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void findUnionSet()
{
	int setA[20];
	int setB[20];
	int sum = 0;
	int result;
	int result1 = 0;
	int result2 = 0;
	int i, j, check;
	int x, y;

	srand((unsigned)time(NULL));	//임의의 수를 설정

	for(i = 0; i < 20;)
	{
		setA[i] = (rand() % 100) + 1;	//범위가 1부터 100까지가 될 수 있도록 설정
		check = 1;
		for(j = 0; j < i; j ++)
		{
			if(setA[i] == setA[j])	//중복되는 수 확인
			{
				check = 0;
				break;
			}
		}
		if(check == 1)	//중복 되지 않는 경우만 출력되도록 설정
		{
			printf("%d ", setA[i]);	//집합의 원소를 모두 출력
			result1 = result1 + setA[i];	//A집합의 총 합을 구함
			i++;
		}
	}

	printf("\n");

	for(i = 0; i < 20;)
	{
		setB[i] = (rand() % 100) + 1;	//범위가 1부터 100까지 되도록 설정
		check = 1;
		for(j = 0; j < i; j ++)
		{
			if(setB[i] == setB[j])	//중복되는 수 확인
			{
				check = 0;
				break;
			}
		}
		if(check == 1)	//중복되지 않는 경우 출력
		{
			printf("%d ", setB[i]);
			result2 = result2 + setB[i];	//B집합의 원소의 합
			i++;
		}
	}

	for(x=0; x<20; x++)
		for(y=0; y<20; y++)
			if(setA[x] == setB[y])	//두 집합사이에 겹치는 값 확인
				sum = sum + setA[x];	//겹치는 값의 합

	result = result1 + result2 - sum;	//합집합 = A집합의 합 + B집합의 합 - 두 집합의 겹치는 값

	printf("\n");
	printf("%d", result);

}


void printHistogram()
{
	int set[1000];
	int count[20] = {};
	int i, j;

	srand(1);	//씨드값을 1로 고정

	for(i = 0; i < 1000; i++)	//1000개를 계산하도록 반복문 생성
	{
		set[i] = rand() % 20 + 1;	//범위가 1부터 20이 되도록 설정

		if(set[i] == 1)	//각각이 1부터 20가지 몇 번 나오는 지를 셈
			count[0]++;
		else if(set[i] == 2)
			count[1]++;
		else if(set[i] == 3)
			count[2]++;
		else if(set[i] == 4)
			count[3]++;
		else if(set[i] == 5)
			count[4]++;
		else if(set[i] == 6)
			count[5]++;
		else if(set[i] == 7)
			count[6]++;
		else if(set[i] == 8)
			count[7]++;
		else if(set[i] == 9)
			count[8]++;
		else if(set[i] == 10)
			count[9]++;
		else if(set[i] == 11)
			count[10]++;
		else if(set[i] == 12)
			count[11]++;
		else if(set[i] == 13)
			count[12]++;
		else if(set[i] == 14)
			count[13]++;
		else if(set[i] == 15)
			count[14]++;
		else if(set[i] == 16)
			count[15]++;
		else if(set[i] == 17)
			count[16]++;
		else if(set[i] == 18)
			count[17]++;
		else if(set[i] == 19)
			count[18]++;
		else if(set[i] == 20)
			count[19]++;
	}
	for(i = 0; i<20; i++)	//각 값이 나온 횟수만큼 '*'을 출력하고 그 뒤에 횟수를 출력
	{
		printf("%d ", i + 1);
		for(j = 0; j<=count[i]; j++)
		{
			printf("*");
		}
		printf(" %d", count[i]);
		printf("\n");
	}

}


void printScoreReport()
{
	int name[5];
	int score[5][4];
	int i;
	int total = 0;

	for(i=0; i < 5 ;i++)	//다섯명의 학생의 ID와 점수를 각각 입력받음
	{
		printf("INPUT ID: ");
		fflush(stdout);
		scanf("%d", &name[i]);

		printf("INPUT SCORES: ");
		fflush(stdout);
		scanf("%d %d %d %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
	}

	printf("\nID\t국어\t영어\t수학\tC++\t총점\t평균\n");	//성적표 양식의 맞게 출력
	for(i=0 ; i<5 ; i++)	//각 학생의 과목들의 총점과 평균을 계산하여 출력
	{
		total= score[i][0]+score[i][1]+score[i][2]+score[i][3];
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%5.2f\n",name[i], score[i][0], score[i][1], score[i][2], score[i][3], total, total/4.0);
	}
}


void mabangjin()
{
	int i, j, m;
	int r, c;
	int next_r, next_c;	//다음에 올 숫자
	int n; //출력 될 숫자

	scanf("%d", &m);

	if(m % 2 == 0)
		m = m+1;

	int print[m][m];

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			print[i][j] = 0;
	}

	r = m - 1; //첫 좌표 위치 설정
	c = m / 2;
	n = 1; //처음 출력 될 숫자는 1

	while(1)
	{
		print[r][c] = n; //해당하는 위치의 좌표에 숫자를 채워 넣음

		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(print[i][j] == 0)	//좌표에 0이 들어가지 않도록 반복문 생성
					break;
			}
			if(j != m)
				break;	//해당하는 크기를 벗어나지 않도록 설정
		}
		if(i==m && j==m)	//좌표가 모두 채워지도록 설정
			break;

		next_r = r+1;	//영역을 벗어 날 경우 방법
		next_c = c+1;

		if(next_r > m-1 && next_c > m-1)
		{
			next_r = r-1;
			next_c = c;
		}
		else if(next_r > m-1)
			next_r = 0;
		else if(next_c > m-1)
			next_c = 0;	//해당하는 좌표가 채워져 있으면 그 좌표의 위칸에 다음 숫자를 채운다

		if(print[next_r][next_c])
		{
			next_r = r-1;
			next_c = c;	//숫자 넣고 다음 숫자에 +1을 한 다음
		}
		print[next_r][next_c] = n++;
		r = next_r;
		c = next_c; //좌표 갱신한 후 다음을 수행
	}	//결과 출력 후 종료

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",print[i][j]);	//결과 값을 출력
	printf("\n");
	}
}




void SameNumberGame()
{
	int i, j, n;
	int width, height;

	srand((unsigned)time(NULL));	//임의의 변수를 설정

	printf("Input width, height: ");	//출력 될 배열의 크기를 정함
	fflush(stdout);
	scanf("%d %d", &width, &height);

	int print[width * height];

	n = (width * height) / 2;	// 입력된 배열의 크기에 들어갈 숫자의 수의 반 만큼의 값이 출력되어야 함
	while(1)
	{
		if(width * height % 2 == 1)	//배열의 들어갈 수의 개수가 홀수인 경우 다시 입력받음
		{
			printf("Input width, height: ");
			fflush(stdout);
			scanf("%d %d", &width, &height);
			continue;
		}
		else
		{
			for(i=0; i<height; i++)
			{
				for(j=0; j<width; j++)
				{
					print[i * j] = rand() % n + 1;	//출력될 값이 입력된 배열의 크기에 들어갈 숫자의 수의 반 만큼이 되도록 범위 설정
					printf("%d\t", print[i * j]);	//형식에 맞게 출력
				}
				printf("\n");
			}
		}
		break;
	}
}



int main()
{
	//findUnionSet();
	//printHistogram();
	//printScoreReport();
	//mabangjin();
	//SameNumberGame();

	return 0;
}

