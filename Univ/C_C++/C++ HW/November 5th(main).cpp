/*
 * 201602357.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: �̼���
 */
#include<iostream>
#include "Rational.h"	//Rational.h ��� ��������� ���

using namespace std;

int main()
{
	Rational r;	//Rational class�� ����ϴ� r�� ����
	Rational x;	//Rational class�� ����ϴ� x�� ����
	//r.setNumerator(2);
	//r.setDenominator(3);
	r.setRational(4,6);	//�Լ��� 4, 6������ �Է�
	//int a = r.getNumerator();	//Numerator �� ����
	r.reduce();	//�Էµ� ������ ���� �������� ����Ͽ� ���� �����ϰ� ǥ��

	x.setRational(2,4);	//�Լ��� 6, 9������ �Է�
	x.reduce();	//�Էµ� ������ ���� �������� ����Ͽ� ���� �����ϰ� ǥ��

	r.add(x);	//�� �������� ���Ѵ�
	r.printRational();	//���� �������� ������� ����Ѵ�

	r.setRational(4,6);	//�ռ� ���꿡�� numerator�� denominator�� ���� �ʱⰪ�� �޶������Ƿ� �� ó�� ���� �ٽ� ����
	x.setRational(2,4);

	r.sub(x);	//�� �������� ����
	r.printRational();	//�� �������� ������� ����Ѵ�

	r.setRational(4,6);	//�ռ� ���꿡�� numerator�� denominator�� ���� �ʱⰪ�� �޶������Ƿ� �� ó�� ���� �ٽ� ����
	x.setRational(2,4);

	r.mult(x);	//�� �������� ���Ѵ�
	r.printRational();	//���� �������� ������� ����Ѵ�

	r.setRational(4,6);	//�ռ� ���꿡�� numerator�� denominator�� ���� �ʱⰪ�� �޶������Ƿ� �� ó�� ���� �ٽ� ����
	x.setRational(2,4);

	r.div(x);	//�� �������� ������
	r.printRational();	//���� �������� ������� ����Ѵ�

	return 0;
}



