/*
 * rational3.cpp
 *
 *  Created on: 2016. 11. 17.
 *      Author: 이선민
 */
#include<iostream>

using namespace std;

class Rational
{
	int n, d;
public:
	Rational():n(0),d(1){}	//Rational함수에 n값에는 0값, d값에는 1값이 들어간다

	Rational(int x):n(x),d(1){}	//Rational함수에 n값에는 x값, d값에는 1값이 들어간다

	Rational(int x, int y):n(x),d(y){}	//Rational함수에 n값에는 x값, d값에는 y값이 들어간다

	~Rational(){}	//소멸자

	friend ostream& operator<<(ostream& os,const Rational& x)	//출력을 하는 함수
	{
		os << x.n << "/" << x.d;
		return os;
	}

	friend Rational operator+(const Rational& x, const Rational& y)	//유리수와 유리수를 더하는 함수
	{
		Rational z;
		z.n = x.n*y.d + y.n*x.d;	//n1d2 + n2d1;
		z.d = x.d*y.d;	//d1d2
		z.reduce();	//기약분수로 꼴로 변환하는 함수를 호출

		return z;	//결과값을 반환
	}
	friend Rational operator+(const Rational& x, const int& y)	//유리수와 정수를 더하는 함수
	{
		Rational z;
		z.n = x.n + y*x.d;	//n1 + n*d1;
		z.d = x.d;	//d1
		z.reduce();	//기약분수로 꼴로 변환하는 함수를 호출

		return z;	//결과값을 반환
	}
	friend Rational operator+(const int& x, const Rational& y)	//정수와 우리수를 더하는 함수
	{
		Rational z;
		z.n = x*y.d + y.n;	//n*d2 + n2;
		z.d = y.d;	//d2
		z.reduce();	//기약분수로 꼴로 변환하는 함수를 호출

		return z;	//결과값을 반환
	}
	void reduce()
	{
		int gcd;

		gcd=getGCD(n,d);	//분자와 분모의 최대공약수를 구하는 함수 호출

		n = n/gcd;	//분자와 분모를 각각 최대공약수로 나눔
		d = d/gcd;
	}
	int getGCD(int n, int d)
	{
		int gcd = 1;	//최대공약수를 구한다
		for(int i=1; i<=n; i++)	//분자와 분모로 모두 나눠지는 자연수 중 가장 큰 값을 찾기 위해 반복문 형성
		{
			if(n % i == 0 && d % i == 0)
				gcd = i;
		}
		return gcd;	//구한 최대공약수 값 반환
	}
};

int main()
{
	Rational r1;	// 0/1
	Rational r2(2);	// 2/1
	Rational r3(2,3);	//2/3

	//friend를 사용하여 외부에서도 자유롭게 합수를 호출하여 사용 가능
	r1 = r2 + r3;	//유리수 + 유리수의 연산 진행
	cout<<r1<<endl;

	r1 = r3 + 2;	//유리수 + 정수의 연산 진행
	cout<<r1<<endl;

	r1 = 2 + r3;	//정수 + 유리수의 연산 진행
	cout<<r1<<endl;

	return 0;
}
