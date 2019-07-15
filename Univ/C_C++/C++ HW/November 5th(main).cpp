/*
 * 201602357.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: 이선민
 */
#include<iostream>
#include "Rational.h"	//Rational.h 라는 헤더파일을 사용

using namespace std;

int main()
{
	Rational r;	//Rational class를 사용하는 r을 생성
	Rational x;	//Rational class를 사용하는 x를 생성
	//r.setNumerator(2);
	//r.setDenominator(3);
	r.setRational(4,6);	//함수의 4, 6변수를 입력
	//int a = r.getNumerator();	//Numerator 값 저장
	r.reduce();	//입력된 변수로 만든 유리수를 약분하여 가장 간단하게 표현

	x.setRational(2,4);	//함수의 6, 9변수를 입력
	x.reduce();	//입력된 변수로 만든 유리수를 약분하여 가장 간단하게 표현

	r.add(x);	//두 유리수를 더한다
	r.printRational();	//합한 유리수의 결과값을 출력한다

	r.setRational(4,6);	//앞서 연산에서 numerator와 denominator의 값이 초기값과 달라졌으므로 맨 처음 값을 다시 선언
	x.setRational(2,4);

	r.sub(x);	//두 유리수를 뺀다
	r.printRational();	//뺀 유리수의 결과값을 출력한다

	r.setRational(4,6);	//앞서 연산에서 numerator와 denominator의 값이 초기값과 달라졌으므로 맨 처음 값을 다시 선언
	x.setRational(2,4);

	r.mult(x);	//두 유리수를 곱한다
	r.printRational();	//곱한 유리수의 결과값을 출력한다

	r.setRational(4,6);	//앞서 연산에서 numerator와 denominator의 값이 초기값과 달라졌으므로 맨 처음 값을 다시 선언
	x.setRational(2,4);

	r.div(x);	//두 유리수를 나눈다
	r.printRational();	//나눈 유리수의 결과값을 출력한다

	return 0;
}



