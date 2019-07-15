/*
 * rational3.cpp
 *
 *  Created on: 2016. 11. 17.
 *      Author: �̼���
 */
#include<iostream>

using namespace std;

class Rational
{
	int n, d;
public:
	Rational():n(0),d(1){}	//Rational�Լ��� n������ 0��, d������ 1���� ����

	Rational(int x):n(x),d(1){}	//Rational�Լ��� n������ x��, d������ 1���� ����

	Rational(int x, int y):n(x),d(y){}	//Rational�Լ��� n������ x��, d������ y���� ����

	~Rational(){}	//�Ҹ���

	friend ostream& operator<<(ostream& os,const Rational& x)	//����� �ϴ� �Լ�
	{
		os << x.n << "/" << x.d;
		return os;
	}

	friend Rational operator+(const Rational& x, const Rational& y)	//�������� �������� ���ϴ� �Լ�
	{
		Rational z;
		z.n = x.n*y.d + y.n*x.d;	//n1d2 + n2d1;
		z.d = x.d*y.d;	//d1d2
		z.reduce();	//���м��� �÷� ��ȯ�ϴ� �Լ��� ȣ��

		return z;	//������� ��ȯ
	}
	friend Rational operator+(const Rational& x, const int& y)	//�������� ������ ���ϴ� �Լ�
	{
		Rational z;
		z.n = x.n + y*x.d;	//n1 + n*d1;
		z.d = x.d;	//d1
		z.reduce();	//���м��� �÷� ��ȯ�ϴ� �Լ��� ȣ��

		return z;	//������� ��ȯ
	}
	friend Rational operator+(const int& x, const Rational& y)	//������ �츮���� ���ϴ� �Լ�
	{
		Rational z;
		z.n = x*y.d + y.n;	//n*d2 + n2;
		z.d = y.d;	//d2
		z.reduce();	//���м��� �÷� ��ȯ�ϴ� �Լ��� ȣ��

		return z;	//������� ��ȯ
	}
	void reduce()
	{
		int gcd;

		gcd=getGCD(n,d);	//���ڿ� �и��� �ִ������� ���ϴ� �Լ� ȣ��

		n = n/gcd;	//���ڿ� �и� ���� �ִ������� ����
		d = d/gcd;
	}
	int getGCD(int n, int d)
	{
		int gcd = 1;	//�ִ������� ���Ѵ�
		for(int i=1; i<=n; i++)	//���ڿ� �и�� ��� �������� �ڿ��� �� ���� ū ���� ã�� ���� �ݺ��� ����
		{
			if(n % i == 0 && d % i == 0)
				gcd = i;
		}
		return gcd;	//���� �ִ����� �� ��ȯ
	}
};

int main()
{
	Rational r1;	// 0/1
	Rational r2(2);	// 2/1
	Rational r3(2,3);	//2/3

	//friend�� ����Ͽ� �ܺο����� �����Ӱ� �ռ��� ȣ���Ͽ� ��� ����
	r1 = r2 + r3;	//������ + �������� ���� ����
	cout<<r1<<endl;

	r1 = r3 + 2;	//������ + ������ ���� ����
	cout<<r1<<endl;

	r1 = 2 + r3;	//���� + �������� ���� ����
	cout<<r1<<endl;

	return 0;
}
