/*
 * Rational.h
 *
 *  Created on: 2016. 11. 3.
 *      Author: 이선민
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational{	//클래스 선언
private:
	int numerator;	//분자값
	int denominator;	//분모값

public:
	//void setNumerator(int x);
	//void setDenominator(int x);
	void setRational(int x, int y);	//유리수의 값
	int getNumerator();	//분자값 반환
	int getDenominator();	//분모값 반환
	void printRational();	//유리수의 형대로 출력

	int getGcd();	//최대공약수를 구하는 함수
	void reduce();	//기약분수를 만드는 함수

	void add(Rational x);	//유리수를 더하는 함수
	void sub(Rational x);	//유리수를 빼는 함수
	void mult(Rational x);	//유리수를 곱하는 함수
	void div(Rational x);	//유리수를 나누는 함수
};

#endif /* RATIONAL_H_ */
