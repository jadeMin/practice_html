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
	scanf("%d", &num);	//�ʱ� ���� �Է¹���

	number = num;	//�ʱ� �Է°��� �ٲ��� �ʵ��� ���ο� ���� Ȱ��

	while(1)	//�Է¹��� ���� �ڸ��� ���
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//�ٲ� ���� �Է°����� �ʱ�ȭ

	for(j=1; j<=digit; j++)	//�Է¹��� ���� �ڸ��� ��ŭ �Ʒ� �Լ��� ����
	{
		reverse = reverse + (number % 10);	//10���� ���� ������ ���� ���Ͽ� �Է¹��� ���� ���� ���� �ڸ����� ������ ���������� �Ѵ�

		if(j<digit)
			reverse = reverse * 10;	//���ؾ� �� ���� �������� ��� 10�� ���Ͽ� �ڸ����� �ϳ��� ������Ų��
		else
			break;

		number = number / 10;	//���� �ڸ����� ���� �ڸ����� 10���� ���� ������������ ���� �� �� �ֵ��� ���� �����Ѵ�
	}

	result = num + reverse;	//�ʱ� �Է°��� ��ȯ�� ���� ���� ��� ���� ����Ѵ�

	printf("The sum of two numbers is: %d", result);	//��� ���

}
void RevertDecimalNumber()
{
	long long i, j, num, number;
	long long digit = 1;
	long long revert = 1;
	long long result = 0;

	printf("�������� �Է��Ͻÿ� : ");
	fflush(stdout);
	scanf("%lld", &num);

	number = num;

	while(1)	//�Է¹��� ���� �ڸ��� ���
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//�ʱ� �Է°��� �ٲ��� �ʵ��� ���ο� ���� Ȱ��

	for(i=1;i<=digit;i++)	//������ �ڸ����� ���� ����Ͽ� ��� ���� ����
	{
		if(i == 1)	//�ڸ����� 1�� �ڸ��� �� ��
			revert = 1;
		else
			for(j=1;j<=i-1;j++)	//�ش��ϴ� �ڸ����� ������ 10������ ���� ����
			{
				revert = revert * 2;	//�� �ڸ����� ���� 2�� n�� ������ �������� Ư���� �̿��Ͽ� ���� ����
			}

		if(number % 10 != 0)	//�ش��ϴ� �ڸ����� ���� ���� �ʿ䰡 �ִ��� Ȯ��
		{
			result = result + revert;	//�ش��ϴ� �ڸ����� 10������ ��ȯ�� ���� ����
			number = number / 10;	//���� �ڸ����� ���� �ڸ����� 10���� ���� ������������ ���� �� �� �ֵ��� ���� �����Ѵ�
		}
		else
			number = number / 10;	//���� �ڸ����� ���� �ڸ����� 10���� ���� ������������ ���� �� �� �ֵ��� ���� �����Ѵ�

		revert = 1;	//�ڸ��� ���� �����ϱ� ���� ���� �ʱ�ȭ
	}

	printf("������ %lld�� ��ȯ�� 10���� : %lld", num, result);	//����� ���

}
void CheckPalindrome()
{
	int j, num, number;
	int digit= 1;
	int reverse = 0;

	printf("Input the number: ");
	fflush(stdout);
	scanf("%d", &num);

	number = num;	//�ʱ� �Է°��� �ٲ��� �ʵ��� ���ο� ���� Ȱ��

	while(1)	//�Է¹��� ���� �ڸ��� ���
	{
		number = number / 10;

		if(number>0)
			digit++;
		else
			break;
	}

	number = num;	//�ٲ� ���� �Է°����� �ʱ�ȭ

	for(j=1; j<=digit; j++)	//�Է¹��� ���� �ڸ��� ��ŭ �Ʒ� �Լ��� ����
	{
		reverse = reverse + (number % 10);	//10���� ���� ������ ���� ���Ͽ� �Է¹��� ���� ���� ���� �ڸ����� ������ ���������� �Ѵ�
		number = number / 10;	//���� �ڸ����� ���� �ڸ����� 10���� ���� ������������ ���� �� �� �ֵ��� ���� �����Ѵ�

		if(j<digit)
			reverse = reverse * 10;	//���ؾ� �� ���� �������� ��� 10�� ���Ͽ� �ڸ����� �ϳ��� ������Ų��
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
	printf("���� �ð� �Է�(�ð� ��): ");	//���۽ð� �Է�
	fflush(stdout);
	scanf("%d %d", &hour1, &min1);

	printf("���� �ð� �Է�(�ð� ��): ");	//����ð� �Է�
	fflush(stdout);
	scanf("%d %d", &hour2, &min2);

	printf("30�д� �̿� �ݾ�(��): ");		//30�д� �̿� �ݾ� �Է�
	fflush(stdout);
	scanf("%d", &fee_for_30);

	time = (hour2 * 60 + min2) - (hour1 * 60 + min1);	//�ð��� ��� �� ������ ȯ��

	while(time>0)	//�ð��� ����� ��쿡�� ���
	{

		if(time >= 60)	//�̿�ð��� �ð��� ������ ǥ��
		{
			result_hour = time / 60;
			result_min = time % 60;
			printf("��ü �̿� �ð�: %d�ð� %d�� <%d��>\n", result_hour, result_min, time);
		}
		else
			printf("��ü �̿� �ð�: 0�ð� %d�� <%d��>\n", time, time);

		if(time <=30)	//�̿� �ð��� 30�� ������ ��� 30�� �̿������� ���
			printf("��� �ݾ�: %d", fee_for_30);
		else	//�̿�ð��� 30�� �̻��� ���
		{
			result = time / 30;
			remain = time % 30;

			if(remain !=0)	//1���̶� �ʰ� �� ��� 30�� ����� �߰�
			{
				result++;
			}
			printf("��� �ݾ�: %d", result * fee_for_30);	//���� ��� �ݾ� ���
		}
		break;
	}
}
void Calender()
{
	int year, month;
		int totalday;
		int lastyear, day, i;

		printf("Input the Input the year and month: ");	//�⵵�� ���� �Է¹���
		fflush(stdout);
		scanf("%d %d", &year, &month);

		if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))	//���� ��� ����, ������ ��� �� ���� �ϼ�
		{
			if(month == 2)	//������ ��� 2���� 29�ϱ���
				totalday = 29;
			else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				totalday = 31;
			else if(month == 4 || month == 6 || month == 9 || month == 11)
				totalday = 30;
		}
		else	//������ �ƴ� ��� �� ���� �ϼ�
		{
			if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				totalday = 31;
		    else if(month == 4 || month == 6 || month == 9 || month == 11)
		    	totalday = 30;
		    else if(month == 2)
		        totalday = 28;	//������ �ƴ� ��� 2���� 28�ϱ���

		}
		lastyear = year-1;
		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear/400) +1 ) % 7;	//�� �ذ� ���۵Ǵ� ���� ���
		for(i=1; i<month; i++)
			day = day + totalday;

		day %= 7;

		printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat");	//�޷� ���Ŀ� �°� ���� ���
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
		add = add + i;	//1���� 100������ ��
		square = i * i;	//1���� 100���� ���ڵ��� ����
		result2 = result2 + square;	//1���� 100������ ������ �������� ��
	}
	result1 = add * add;	//1���� 100������ ���� ����

	if(result1 >= result2)	//���� ������ ������ �� �� �� ū �� �Ǻ�
	{
		gap = result1 - result2;
	}
	else
	{
		gap = result2 - result1;
	}

	printf("%d", gap);	//���� ������ ������ ���� ���� ���
}
void EulerProject7()
{
	int i=1;
	int j;
	int count = 1;

	while(1)
	{
		i+=2;

		for(j=3;(j*j<i)&&(i%j!=0);j+=2);	//�Ҽ� ���ϴ� ����
	    if(j*j>i)
	    {
	    	count+=1;
	    }
	    if(count==10001)	//10001��° �Ҽ��� ����
	    {
	    	break;
	    }

	}
   printf("%d", i );
}
void EulerProject9()
{
	int a, b, c;

	for(c=1;c<1000;c++)	//a+b+c = 1000�� �����ؾ� �ϹǷ� �� ���� 1000�� ���� ���� �� ����
	{
		for(b=1;b<c;b++)
		{
			for(a=1;a<b;a++)
			{
	            if(a*a+b*b == c*c)	//��Ÿ����� ������ �����ϴ��� Ȯ��
	            {
	               if(a+b+c==1000)	//���� ���� �����ϴ��� ���� Ȯ��
	                  printf("%d", a*b*c);	//�� ���� �䱸�ϴ� ���� ���� ����
	            }
	        }
		}
	}	//a,b,c�� ������ �ٲ� ����� ����. ������ �����Ͽ� �ߺ��Ǵ� ���� ������ �ʵ��� �Ѵ�
}
void EulerProject10()
{
	long long i, j;
	long long sum = 0;

	for(i = 2; i <= 2000000; i++)	//�̹鸸 ������ �Ҽ� ���� ���ϴ� ��
	{
		for(j = 2; j <= i-1; j++)
		{
			if(i % j == 0)
			{
				break;
			}
		}
		if(i == j)	//������ �Ҽ������� ��
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
	const int number = 500;	//500�� ������ ����� ���� �ﰢ���� ���Ͽ��� �ϹǷ� ����� ������  500���� ����
    while (1)
    {
        for (i = 1; i <= num; i++)	//�ﰢ���� ���ϴ� ��
        {
            total = total + i;
        }
        for (j = 1; j <= total; j++)	//�ﰢ���� ��� ������ ���ϴ� ����
        {
            if (total % j == 0)
            {
                t++;
            }
        }
        if (t >= number - 1)	//1�� ���� ��� ���� ����̹Ƿ� 1�� �����Ͽ� 500���� ����� ������ �Ѵ�
            break;
        t = 0;
        total = 0;
        num++;	//������ �������� ���� ���(500��) ���� �ʱ�ȭ
    }

	printf("%d", total);	//����� ���
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

