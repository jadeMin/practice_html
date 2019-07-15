/*
 * Rational.h
 *
 *  Created on: 2016. 11. 3.
 *      Author: �̼���
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational{	//Ŭ���� ����
private:
	int numerator;	//���ڰ�
	int denominator;	//�и�

public:
	//void setNumerator(int x);
	//void setDenominator(int x);
	void setRational(int x, int y);	//�������� ��
	int getNumerator();	//���ڰ� ��ȯ
	int getDenominator();	//�и� ��ȯ
	void printRational();	//�������� ����� ���

	int getGcd();	//�ִ������� ���ϴ� �Լ�
	void reduce();	//���м��� ����� �Լ�

	void add(Rational x);	//�������� ���ϴ� �Լ�
	void sub(Rational x);	//�������� ���� �Լ�
	void mult(Rational x);	//�������� ���ϴ� �Լ�
	void div(Rational x);	//�������� ������ �Լ�
};

#endif /* RATIONAL_H_ */
