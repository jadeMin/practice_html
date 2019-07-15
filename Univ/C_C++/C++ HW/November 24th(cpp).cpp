/*
 * complex.cpp
 *
 *  Created on: 2016. 11. 24.
 *      Author: �̼���
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

	friend ostream& operator<<(ostream& os, const Complex& c)	//�Լ� �ܺο����� ȣ���� �����ӵ��� friend ���
	{	//a+bi
		os << c.real << "+" << c.imag << "i";	//���Ҽ� ���¸� ���
		return os;
	}

	friend float mod(const Complex& c)
	{
		return sqrt(c.real*c.real + c.imag*c.imag);	//���Ҽ��� ũ�⸦ ���ϱ� ���� ��Ʈ�� Ȱ��
	}

	friend Complex operator+(const Complex& c1, const Complex& c2)
	{
		return Complex(c1.real + c2.real, c1.imag + c2.imag);	//���Ҽ��� ���� ����
	}
	// a>b
	friend bool operator>(const Complex& a, const Complex& b)
	{
		return mod(a)>mod(b);	//���Ҽ��� ũ�⸦ ���Ͽ� a�� b���� ũ�� true, ������ false
	}
};

void swap(int &a, int &b)	//a��  b���� �ٲٴ� �Լ�
{
		int temp = a;
		a = b;
		b = temp;
}

void sort(Complex &a, Complex &b, Complex &c)	//ū ���� ���� ��µǵ��� �ϴ� �Լ�
{
	if(!(a>b))	//a�� b���� ������ a�� b�� ���� �ٲ���
		swap(a,b);
	if(!(b>c))	//b�� c���� ������ b�� c�� ���� �ٲ���
		swap(b,c);
	if(!(a>c))	//a�� c���� ������ a�� c�� ���� �ٲ���
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

	//sort Ȯ��
	sort(c0, c1, c2);

	cout << c0 << endl;	//2+0i
	cout << c1 << endl;	//1+1i
	cout << c2 << endl;	//0+0i

	return 0;
}
