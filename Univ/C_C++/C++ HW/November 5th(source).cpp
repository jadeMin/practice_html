/*
 * Rational.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: �̼���
 */
#include<iostream>
#include "Rational.h"	//Rational.h��� ��������� ���
using namespace std;

/*void Rational::setNumerator(int x)
{
	numerator = x;
}

void Rational::setDenominator(int x)
{
	denominator = x;
}
*/
void Rational::setRational(int x, int y)
{
	numerator = x, denominator = y;	//�������� ���� �и� ���� �޴´�
}
int Rational::getNumerator()
{
	return numerator;	//���� numerator���� ��ȯ
}

int Rational::getDenominator()
{
	return denominator;	//���� denominator���� ��ȯ
}

void Rational::printRational()
{	// ����/�и� �������� ���
	cout << numerator << "/" << denominator << endl;
}

int Rational::getGcd()
{
	int gcd = 1;	//�ִ������� ���Ѵ�
	for(int i=1; i<=numerator; i++)	//���ڿ� �и�� ��� �������� �ڿ��� �� ���� ū ���� ã�� ���� �ݺ��� ����
	{
		if(numerator % i == 0 && denominator % i == 0)
			gcd = i;
	}
	return gcd;	//���� �ִ������� ���� ��ȯ
}

void Rational::reduce()
{	//���м��� ����� ���� �Լ�
	int gcd = getGcd();	//�ִ����� ���� �ҷ���
	numerator = numerator / gcd;	//������ ���� �ִ������� ������
	denominator = denominator / gcd;	//�и��� ���� �ִ������� ������
}

void Rational::add(Rational x)
{
	int n1 = numerator;	//�ʱ� ���� �ٲ��� �ʵ��� ������ �����Ѵ�
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2 + n2*d1;	//�������� ���� => n1/d1 + n2/d2 = n1*d2 + n2*d1 / d1*d2
	denominator = d1*d2;

	reduce();	//���� �������� ���� �ٽ� ���� ������ ������ ����Ѵ�
}

void Rational::sub(Rational x)
{
	int n1 = numerator;	//�ʱ� ���� �ٲ��� �ʵ��� ������ �����Ѵ�
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2 - n2*d1;	//�������� ���� => n1/d1 - n2/d2 = n1*d2 - n2*d1 / d1*d2
	denominator = d1*d2;

	reduce();	//������ ����� ������ ���� �ٽ� ���� ������ ���м��� ����� �����
}

void Rational::mult(Rational x)
{
	int n1 = numerator;	//�ʱ� ���� �ٲ��� �ʵ��� ������ �����Ѵ�
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*n2;	//�������� ���� => n1/d1 * n2/d2 = n1*n2 / d1*d2
	denominator = d1*d2;

	reduce();	//������ ����� ������ ���� �ٽ� ���� ������ ���м��� ����� �����
}

void Rational::div(Rational x)
{
	int n1 = numerator;	//�ʱ� ���� �ٲ��� �ʵ��� ������ �����Ѵ�
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2;	//�������� ������ => n1/d1 / n2/d2 = n1*d2 / d1*n2
	denominator = d1*n2;

	reduce();	//������ ����� ������ ���� �ٽ� ���� ������ ���м��� ����� �����
}
