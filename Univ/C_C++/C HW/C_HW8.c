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

	srand((unsigned)time(NULL));	//������ ���� ����

	for(i = 0; i < 20;)
	{
		setA[i] = (rand() % 100) + 1;	//������ 1���� 100������ �� �� �ֵ��� ����
		check = 1;
		for(j = 0; j < i; j ++)
		{
			if(setA[i] == setA[j])	//�ߺ��Ǵ� �� Ȯ��
			{
				check = 0;
				break;
			}
		}
		if(check == 1)	//�ߺ� ���� �ʴ� ��츸 ��µǵ��� ����
		{
			printf("%d ", setA[i]);	//������ ���Ҹ� ��� ���
			result1 = result1 + setA[i];	//A������ �� ���� ����
			i++;
		}
	}

	printf("\n");

	for(i = 0; i < 20;)
	{
		setB[i] = (rand() % 100) + 1;	//������ 1���� 100���� �ǵ��� ����
		check = 1;
		for(j = 0; j < i; j ++)
		{
			if(setB[i] == setB[j])	//�ߺ��Ǵ� �� Ȯ��
			{
				check = 0;
				break;
			}
		}
		if(check == 1)	//�ߺ����� �ʴ� ��� ���
		{
			printf("%d ", setB[i]);
			result2 = result2 + setB[i];	//B������ ������ ��
			i++;
		}
	}

	for(x=0; x<20; x++)
		for(y=0; y<20; y++)
			if(setA[x] == setB[y])	//�� ���ջ��̿� ��ġ�� �� Ȯ��
				sum = sum + setA[x];	//��ġ�� ���� ��

	result = result1 + result2 - sum;	//������ = A������ �� + B������ �� - �� ������ ��ġ�� ��

	printf("\n");
	printf("%d", result);

}


void printHistogram()
{
	int set[1000];
	int count[20] = {};
	int i, j;

	srand(1);	//���尪�� 1�� ����

	for(i = 0; i < 1000; i++)	//1000���� ����ϵ��� �ݺ��� ����
	{
		set[i] = rand() % 20 + 1;	//������ 1���� 20�� �ǵ��� ����

		if(set[i] == 1)	//������ 1���� 20���� �� �� ������ ���� ��
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
	for(i = 0; i<20; i++)	//�� ���� ���� Ƚ����ŭ '*'�� ����ϰ� �� �ڿ� Ƚ���� ���
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

	for(i=0; i < 5 ;i++)	//�ټ����� �л��� ID�� ������ ���� �Է¹���
	{
		printf("INPUT ID: ");
		fflush(stdout);
		scanf("%d", &name[i]);

		printf("INPUT SCORES: ");
		fflush(stdout);
		scanf("%d %d %d %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
	}

	printf("\nID\t����\t����\t����\tC++\t����\t���\n");	//����ǥ ����� �°� ���
	for(i=0 ; i<5 ; i++)	//�� �л��� ������� ������ ����� ����Ͽ� ���
	{
		total= score[i][0]+score[i][1]+score[i][2]+score[i][3];
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%5.2f\n",name[i], score[i][0], score[i][1], score[i][2], score[i][3], total, total/4.0);
	}
}


void mabangjin()
{
	int i, j, m;
	int r, c;
	int next_r, next_c;	//������ �� ����
	int n; //��� �� ����

	scanf("%d", &m);

	if(m % 2 == 0)
		m = m+1;

	int print[m][m];

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			print[i][j] = 0;
	}

	r = m - 1; //ù ��ǥ ��ġ ����
	c = m / 2;
	n = 1; //ó�� ��� �� ���ڴ� 1

	while(1)
	{
		print[r][c] = n; //�ش��ϴ� ��ġ�� ��ǥ�� ���ڸ� ä�� ����

		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(print[i][j] == 0)	//��ǥ�� 0�� ���� �ʵ��� �ݺ��� ����
					break;
			}
			if(j != m)
				break;	//�ش��ϴ� ũ�⸦ ����� �ʵ��� ����
		}
		if(i==m && j==m)	//��ǥ�� ��� ä�������� ����
			break;

		next_r = r+1;	//������ ���� �� ��� ���
		next_c = c+1;

		if(next_r > m-1 && next_c > m-1)
		{
			next_r = r-1;
			next_c = c;
		}
		else if(next_r > m-1)
			next_r = 0;
		else if(next_c > m-1)
			next_c = 0;	//�ش��ϴ� ��ǥ�� ä���� ������ �� ��ǥ�� ��ĭ�� ���� ���ڸ� ä���

		if(print[next_r][next_c])
		{
			next_r = r-1;
			next_c = c;	//���� �ְ� ���� ���ڿ� +1�� �� ����
		}
		print[next_r][next_c] = n++;
		r = next_r;
		c = next_c; //��ǥ ������ �� ������ ����
	}	//��� ��� �� ����

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",print[i][j]);	//��� ���� ���
	printf("\n");
	}
}




void SameNumberGame()
{
	int i, j, n;
	int width, height;

	srand((unsigned)time(NULL));	//������ ������ ����

	printf("Input width, height: ");	//��� �� �迭�� ũ�⸦ ����
	fflush(stdout);
	scanf("%d %d", &width, &height);

	int print[width * height];

	n = (width * height) / 2;	// �Էµ� �迭�� ũ�⿡ �� ������ ���� �� ��ŭ�� ���� ��µǾ�� ��
	while(1)
	{
		if(width * height % 2 == 1)	//�迭�� �� ���� ������ Ȧ���� ��� �ٽ� �Է¹���
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
					print[i * j] = rand() % n + 1;	//��µ� ���� �Էµ� �迭�� ũ�⿡ �� ������ ���� �� ��ŭ�� �ǵ��� ���� ����
					printf("%d\t", print[i * j]);	//���Ŀ� �°� ���
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

