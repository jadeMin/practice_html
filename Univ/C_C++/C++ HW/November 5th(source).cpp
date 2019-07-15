/*
 * Rational.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: 이선민
 */
#include<iostream>
#include "Rational.h"	//Rational.h라는 헤더파일을 사용
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
	numerator = x, denominator = y;	//유리수의 분자 분모 값을 받는다
}
int Rational::getNumerator()
{
	return numerator;	//현재 numerator값을 반환
}

int Rational::getDenominator()
{
	return denominator;	//현재 denominator값을 반환
}

void Rational::printRational()
{	// 분자/분모 형식으로 출력
	cout << numerator << "/" << denominator << endl;
}

int Rational::getGcd()
{
	int gcd = 1;	//최대공약수를 구한다
	for(int i=1; i<=numerator; i++)	//분자와 분모로 모두 나눠지는 자연수 중 가장 큰 값을 찾기 위해 반복문 형성
	{
		if(numerator % i == 0 && denominator % i == 0)
			gcd = i;
	}
	return gcd;	//구한 최대공약수의 값을 반환
}

void Rational::reduce()
{	//기약분수로 만들기 위한 함수
	int gcd = getGcd();	//최대공약수 값을 불러옴
	numerator = numerator / gcd;	//분자의 값을 최대공약수로 나눈다
	denominator = denominator / gcd;	//분모의 값을 최대공약수로 나눈다
}

void Rational::add(Rational x)
{
	int n1 = numerator;	//초기 값이 바뀌지 않도록 변수를 생성한다
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2 + n2*d1;	//유리수의 덧셈 => n1/d1 + n2/d2 = n1*d2 + n2*d1 / d1*d2
	denominator = d1*d2;

	reduce();	//합한 유리수의 값을 다시 가장 간단한 값으로 약분한다
}

void Rational::sub(Rational x)
{
	int n1 = numerator;	//초기 값이 바뀌지 않도록 변수를 생성한다
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2 - n2*d1;	//유리수의 뺄셈 => n1/d1 - n2/d2 = n1*d2 - n2*d1 / d1*d2
	denominator = d1*d2;

	reduce();	//연산한 결과의 유리수 값을 다시 가장 간단한 기약분수의 형대로 만든다
}

void Rational::mult(Rational x)
{
	int n1 = numerator;	//초기 값이 바뀌지 않도록 변수를 생성한다
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*n2;	//유리수의 곱셈 => n1/d1 * n2/d2 = n1*n2 / d1*d2
	denominator = d1*d2;

	reduce();	//연산한 결과의 유리수 값을 다시 가장 간단한 기약분수의 형대로 만든다
}

void Rational::div(Rational x)
{
	int n1 = numerator;	//초기 값이 바뀌지 않도록 변수를 생성한다
	int n2 = x.numerator;
	int d1 = denominator;
	int d2 = x.denominator;

	numerator = n1*d2;	//유리수의 나눗셈 => n1/d1 / n2/d2 = n1*d2 / d1*n2
	denominator = d1*n2;

	reduce();	//연산한 결과의 유리수 값을 다시 가장 간단한 기약분수의 형대로 만든다
}
