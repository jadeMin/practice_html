/*
 * complex.cpp
 *
 *  Created on: 2016. 11. 24.
 *      Author: 이선민
 */
#include<iostream>
#include<math.h>
using namespace std;

class Complex
{
	int real, imag;

public:
	Complex():real(0), imag(0){}	//0+0i
	Complex(int x):real(x), imag(0){}	//x+0i
	Complex(int x, int y):real(x), imag(y){}	//x+yi

	friend ostream& operator<<(ostream& os, const Complex& c)	//함수 외부에서도 호출이 자유롭도록 friend 사용
	{	//a+bi
		os << c.real << "+" << c.imag << "i";	//복소수 형태를 출력
		return os;
	}

	friend float mod(const Complex& c)
	{
		return sqrt(c.real*c.real + c.imag*c.imag);	//복소수의 크기를 구하기 위해 루트를 활용
	}

	friend Complex operator+(const Complex& c1, const Complex& c2)
	{
		return Complex(c1.real + c2.real, c1.imag + c2.imag);	//복소수의 합을 구함
	}
	// a>b
	friend bool operator>(const Complex& a, const Complex& b)
	{
		return mod(a)>mod(b);	//복소수의 크기를 비교하여 a가 b보다 크면 true, 작으면 false
	}
};

void swap(int &a, int &b)	//a와  b값을 바꾸는 함수
{
		int temp = a;
		a = b;
		b = temp;
}

void sort(Complex &a, Complex &b, Complex &c)	//큰 값이 먼저 출력되도록 하는 함수
{
	if(!(a>b))	//a가 b보다 작으면 a와 b의 값을 바꿔줌
		swap(a,b);
	if(!(b>c))	//b가 c보다 작으면 b와 c의 값을 바꿔줌
		swap(b,c);
	if(!(a>c))	//a가 c보다 작으면 a와 c의 값을 바꿔줌
		swap(a,c);
}

int main()
{
	Complex c0;
	Complex c1(2);
	Complex c2(1,1);

	cout << c0 << endl;	//0+0i
	cout << c1 << endl;	//2+0i
	cout << c2 << endl;	//1+1i

	cout<< mod(c2) << endl;	//1.414
	cout<< 2+c2 << endl; // 3+1i

	cout<<(c1>c2)<<endl;	//1

	//sort 확인
	sort(c0, c1, c2);

	cout << c0 << endl;	//2+0i
	cout << c1 << endl;	//1+1i
	cout << c2 << endl;	//0+0i

	return 0;
}
