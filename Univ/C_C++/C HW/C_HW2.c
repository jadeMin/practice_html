#include<stdio.h>
void computeDivision() //��� ������ ���
{
 int x, y, rest, quota;
 printf("�� ������ �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%d %d", &x, &y);

 quota = x / y; //���� ���ϱ�
 rest = x % y; //������ ���ϱ�

 printf("%d / %d �� ���� %d�Դϴ�.\n", x, y, quota);
 printf("%d / %d �� �������� %d�Դϴ�.", x, y, rest);	//����� ���

}

void computeTemperature() //ȭ���� ������, ������ ȭ���� ��ȯ
{
 float feh1, feh2, cel1, cel2;
 printf("ȭ�� �µ��� �Է��ϼ���: ");
 fflush(stdout);
 scanf("%f", &feh1);

 cel1 = (feh1 - 32) / 1.8;	//ȭ���� ������ ��ȯ

 printf("ȭ���µ� %.f�� ���� �µ� %.2f�Դϴ�.\n", feh1, cel1);

 printf("���� �µ��� �Է��ϼ���: ");
 fflush(stdout);
 scanf("%f", &cel2);

 feh2 = (cel2 * 1.8) + 32;	//������ ȭ���� ��ȯ

 printf("���� �µ� %.f�� ȭ���µ� %.2f�Դϴ�.", cel2, feh2);


}

 


void computeHoursforMars() //ȭ�������� �ð� ���
{
 const int distance = 75000000;	//ȭ�������� �Ÿ�
 float rocket, air, f1, ktx;
 
 printf("�������� ȭ�������� �Ÿ� : �� %d km\n", distance);

 rocket = distance / 11.9 / 60 / 60;	//������ �̿����� �� �ɸ��� �ð�
 air = distance / 850.0;	//�װ����� �̿����� �� �ɸ��� �ð�
 f1 = distance / 350.0;	//f1�� �̿����� �� �ɸ��� �ð�
 ktx = distance / 300.0;	//ktx�� �̿����� �� �ɸ��� �ð�

 printf("������ ������ �̿������� ȭ������ �ɸ��� �ð�: %.2f\n", rocket);
 printf("�ΰ� �װ��⸦ �̿������� ȭ������ �ɸ��� �ð�: %.2f\n", air);
 printf("���ֿ� �ڵ���(F1)�� �̿����� �� ȭ������ �ɸ��� �ð�: %.2f\n", f1);
 printf("KTX ������ �̿����� �� ȭ������ �ɸ��� �ð�: %.2f", ktx);	//����� ���

}


void computeDigitSum()
{
 int num, thou, hund, ten, one, temp, temp1, result;
 printf("����<0<= number <= 10000>�� �Է��Ͻÿ�: ");
 fflush(stdout);
 scanf("%d", &num);

 thou = num / 1000;	//õ�� �ڸ����� ���ϱ�
 temp = num % 1000;	
 hund = temp / 100;	//���� �ڸ����� ���ϱ�
 temp1 = temp % 100;
 ten = temp1 / 10;	//���� �ڸ����� ���ϱ�
 one = temp1 % 10;	//���� �ڸ����� ���ϱ�

 result = thou + hund + ten + one; //�� �ڸ����� ��

 printf("%d �� �ڸ����� ���� %d �Դϴ�.", num, result);

 (result % 7 == 0)?printf("%d�� 7�� ����Դϴ�.", result):printf("%d�� 7�� ����� �ƴմϴ�.", result); //�ڸ����� ���� 7�� ������� Ȯ��

}

void checkQuadrant()
{
 int x, y;
 printf("2���� ������ ��ǥ (x, y)�� �Է��ϼ���: ");
 fflush(stdout);
 scanf("%d %d", &x, &y);

 (x>0 && y>0)?printf("(%d, %d)�� 1��и鿡 ���մϴ�.\n", x, y):printf("(%d, %d)�� 1��и鿡 ������ �ʽ��ϴ�.\n", x, y);	//���ǿ����ڸ� ���� 1��и����� ���� Ȯ��
 (x<0 && y>0)?printf("(%d, %d)�� 2��и鿡 ���մϴ�.\n", x, y):printf("(%d, %d)�� 2��и鿡 ������ �ʽ��ϴ�.\n", x, y);	//���ǿ����ڸ� ���� 2��и����� ���� Ȯ��
 (x<0 && y<0)?printf("(%d, %d)�� 3��и鿡 ���մϴ�.\n", x, y):printf("(%d, %d)�� 3��и鿡 ������ �ʽ��ϴ�.\n", x, y);	//���ǿ����ڸ� ���� 3��и����� ���� Ȯ��
 (x>0 && y<0)?printf("(%d, %d)�� 4��и鿡 ���մϴ�.\n", x, y):printf("(%d, %d)�� 4��и鿡 ������ �ʽ��ϴ�.\n", x, y);	//���ǿ����ڸ� ���� 4��и����� ���� Ȯ��
 
}

 

void checkParallelLine()
{
 int x1, x2, x3, x4, y1, y2, y3, y4;
 int grad1, grad2;
 printf("ù ��° 2���� ������ �� �� (x1, y1), (x2, y2)�� �Է��ϼ���: ");
 fflush(stdout);
 scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

 printf("�� ��° 2���� ������ �� �� (x3, y3), (x4, y4)�� �Է��ϼ���: ");
 fflush(stdout);
 scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

 printf("(x1, y1), (x2, y2)�� ���� (%d, %d), (%d, %d)\n", x1, y1, x2, y2);	//�Է¹��� �� Ȯ��
 printf("(x3, y3), (x4, y4)�� ���� (%d, %d), (%d, %d)\n", x3, y3, x4, y4);	//�Է¹��� �� Ȯ��

 grad1 = (y2-y1) / (x2-x1);	//(x1, y1)�� (x2, y2) ���� ���� Ȯ��
 grad2 = (y4-y3) / (x4-x3);	//(x3 ,y3)�� (x4, y4) ���� ���� Ȯ��

 (grad1 == grad2) ? printf("�� ������ �����մϴ�."):printf("�� ������ �������� �ʽ��ϴ�.");	//����� ���


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