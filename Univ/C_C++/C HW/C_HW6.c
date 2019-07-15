/*
 * source.c
 *
 *  Created on: 2016. 5. 16.
 *      Author: Administrator
 */
#include <stdio.h>
// ���� ����� ���� �Լ�
int get_integer();
long long factorial(int n);
long long combination(int n, int r);
void computeCombination();

// ������ ����� ���� �Լ�
int checkPerfect(int n);
void findPerfectNumber();

// ģȭ�� ����� ���� �Լ�
int checkFrindNumber(int n1, int n2);
void findFrindNumber();

// ���� �߱� ���� �Լ�
void DigitBaseballGame();

// ���̿����� ����� ���� �Լ�
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


int get_integer()	// ���� �Է°� �Լ�
{
	int num;
	scanf("%d", &num);
	return num;
}

long long factorial(int n)	// ���丮�� ����� �ϴ� �Լ�
{
	int i;
	long long result = 1;
	for(i=1; i<=n; i++)
		result = result * i;	//�ݺ����� Ȱ���Ͽ� ���丮�� ��� �� �ϼ�
	return result;
}

long long combination(int n, int r)	// ���丮���� �̿��Ͽ� ���� ����� �ϴ� �Լ�
{
	return factorial(n)/(factorial(n-r)*factorial(r));	//���� ����
}

void computeCombination()	// ���� ���
{
	int n = get_integer();
	int r = get_integer();
	printf("C(%d, %d) = %lld", n, r, combination(n, r));	//��� ���
}


int checkPerfect(int n)	// �־��� ���� ���������� �ƴ����� �Ǵ��ϴ� �Լ�
{
	int j;
	int sum = 0;
	for(j=1; j<n; j++)	//����� ����
	{
		if(n % j == 0)
			sum += j;	//����� ���� ���
	}
	return sum;
}

void findPerfectNumber()	// 2~10000 ������ ������ ã��
{
	int i;
	for (i = 2; i <= 10000; i++)
	{
		if (checkPerfect(i) == i)	//������ ���� Ȯ��
		{
			printf("%d ", i);	//��� ���
		}
	}
}


int checkFrindNumber(int n1, int n2)	// �־��� ���� ģȭ������ �ƴ����� �Ǵ��ϴ� �Լ�
{
	int i, j;
	int sum1=0, sum2 =0;
	for(i=1; i < n1; i++)	//��� ���ϴ� ����
	{
		if(n1 % i == 0)
		{
			sum1 += i;	//n1 �� ������� �� ����
		}
	}
	for(j=1; j < n2; j++)	//��� ���ϴ� ����
	{
		if(n2 % j == 0)
		{
			sum2 += j;	//n2 �� ������� �� ����
		}
	}
	if(n1 == sum2 && n2 == sum1)	//ģȭ���� ���� ���� ���� Ȯ��
		return 1;

	return 0;
}


void findFrindNumber()	// 2~1000 ������ ģȭ�� ã��
{
	int i, j;
	for (i = 2; i <= 1000; i++)	//���� ���� ģȭ�� ã��
	{
		for (j = i + 1; j <= 1000; j++)
		{
			if (checkFrindNumber(i, j))
			{
				printf("(%d, %d) \n", i, j);	//����� ���
			}
		}
	}
}



void DigitBaseballGame()	// ���� �߱� ���� �Լ�
{
	int count=0, num1, num2, num3;
	int one, two, three;
	int strike=0, ball=0;

	printf("Play game ? <y/n> : y\n");

	srand((unsigned)time(NULL));	//������ ���� ����

	num1 = rand()%9+1;
	num2 = rand()%9+1;
	num3 = rand()%9+1;

	if(num1 == num2 || num2 == num3 || num1 == num3)	//�� ���� ���� ��� ���ο� ���� ����
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
		if(count == 10)	//9������� �����ؼ� �������� ��� ��ǻ�� �¸�
		{
			printf("COMPUTER WINNER !!!!\n");
			printf("The numbers are %d %d %d\n", num1, num2, num3);
			printf("play game?");
		}

		printf("*** BASEBALL GAME .... ROUND : %d\n", count);	//����ڰ� ������ ���� �����Ͽ� �Է�
		printf("USER : ");
		fflush(stdout);
		scanf("%d %d %d", &one, &two, &three);

		if(one == num1 && two == num2 && three == num3)	//�� ���� ��� ���� ��� ���
		{
			printf("USER WINNER!!!\n");

			break;
		}

		else	//��Ʈ����ũ�� ��, �ƿ��� ���ǿ� �°� �Լ� ����
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
				printf("COMPUTER : %d STRIKE !!!!\n", strike);	//���ǿ� �´� ��� ���
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
int checkLeapYear(int year)	// �־��� ������ �������� �ƴ��� �Ǻ��ϴ� �Լ�
{
	if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return 1;
	return 0;
}


int checkMonth(int month, int leap_year)	// �־��� ���� ��ĥ���� �ִ��� �Ǻ��ϴ� �Լ�
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

int countDate(int birth_year, int birth_month, int birth_day, int year, int month)	// ������ϰ� ��� ���� �Է��Ͽ��� �� �� ��¥�� ���
{
	int total_day1, total_day2;
	int leap_day;

	total_day1 =
}

void printBiorhythm(int date, int year, int month)	// �� ��¥���� ���� �� �Է½� ���̿����� ���
{

}

void computeBiorhythm()	// ���̿������� ����ϴ� �Լ�
{
	int birth_year, birth_month, birth_day;
	int year, month, date;
	printf("���� ������ �Է��ϼ��� (ex: 1983 5 21)\n");
	scanf("%d %d %d", &birth_year, &birth_month, &birth_day);
	printf("���ð� ���� �⵵�� ���� �Է��ϼ���. (ex: 2004 11)\n");
	scanf("%d %d", &year, &month);
	date = countDate(birth_year, birth_month, birth_day, year, month);
	printf("\n%d�� %d�� %d�ϰ� %d�� %d�� 1�� ������ ��¥ ���� %d �� �Դϴ�.\n\n", birth_year, birth_month, birth_day, year, month, date + 1);
	printBiorhythm(date, year, month);
}

*/
