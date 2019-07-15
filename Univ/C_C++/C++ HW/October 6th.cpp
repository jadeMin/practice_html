/*
 * 201602357.cpp
 *
 *  Created on: 2016. 10. 6.
 *      Author: �̼���
 */
#include<iostream>

using namespace std;

//�����Լ��� �ִ� ������ �ٲٱ� ���� �����ͷ� ����
void shift(int *a, int *b, int *c)	//a�� ���� b�� b�� ���� c�� a�� ������ 0�� �ִ� �Լ�
{
	int temp = 0;
	*c = *b;
	*b = *a;
	*a = temp;
}


int main()
{
	int x = 1, y = 2, z = 3;

	shift(&x, &y, &z);	//shift �Լ� ȣ��
	cout << x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	shift(&x, &y, &z);	//shift �Լ� ȣ��
	cout << x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	return 0;
}

void shift(int &a, int &b, int &c)	//a�� ���� b�� b�� ���� c�� a�� ������ 0�� �ִ� �Լ�
{
	int temp = 0;
	c = b;
	b = a;
	a = temp;
}

int main()
{
	int x = 1, y = 2, z = 3;

	shift(x, y, z);	//�Լ�ȣ��
	cout << x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	shift(x, y, z);	//�Լ�ȣ��
	cout << x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	return 0;
}


void circularShift(int &a, int &b, int &c)	//a �� ���� b�� b�� ���� c�� a�� ������ a���� �ִ� �Լ�
{
	int temp;
	temp = c;
	c = b;
	b = a;
	a = temp;
}

int main()
{
	int x = 1, y = 2, z = 3;

	circularShift(x, y, z);	//�Լ�ȣ��
	cout<< x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	circularShift(x, y, z);	//�Լ�ȣ��
	cout<< x << " " << y << " " << z << endl;	//�ٲ� x, y, z���� ���

	return 0;
}

void addTwoVector(const int *a, const int *b, int *c, int N)
{
	if(c != NULL)
		delete [] c;	//�迭 c�� a,b�迭�� ������ ����� ���� ���� c���� �ʱ�ȭ

	c = new int[N];	//�迭c�� ������ a,b�迭�� ������ ����

	for(int i = 0; i < N; i++)	//a1~aN �迭�� b1~bN �迭�� ���� c1~cN �迭�� �Է�
		c[i] = a[i] + b[i];

}
int main()
{
	int x[] = {1, 2, 3, 4};
	int y[] = {2, 3, 4, 5};
	//int z[2]

	int *z;
	z = new int [2];	//z�� �迭�� 2�� �ʱ�ȭ�Ͽ� ����

	addTwoVector(x, y, z, 4);	//�Լ��� ȣ��

	for(int i = 0; i < 4; i++)
		cout << z[i] << " " << endl;	//z�迭�� ���

	return 0;
}
