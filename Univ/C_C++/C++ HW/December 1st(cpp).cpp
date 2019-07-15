/*
 * class2.cpp
 *
 *  Created on: 2016. 12. 1.
 *      Author: �̼���
 */
#include<iostream>
using namespace std;

class Point
{	//(x, y)
	int x, y;

public:
	Point():x(0), y(0){}
	Point(int a, int b):x(a), y(b){}
	Point(const Point& p):x(p.x), y(p.y){}	//���� ������
	friend ostream& operator<<(ostream& os, const Point& p)
	{
		os << "(" << p.x << "," << p.y << ")";	//��ǥ�� �ǹ��ϴ� �������� ����ϱ� ���� ���� ����
		return os;
	}
	friend Point operator+(const Point& a, const Point& b)
	{
		return Point(a.x + b.x, a.y + b.y);	//��ǥ�� x, y���� ���ϴ� �Լ�
	}
	friend Point operator+(const int& a, const Point& b)
	{
		return Point(a + b.x, a + b.y);	//������ ��ǥ�� x, y�� ���ϴ� �Լ�
	}
	friend Point operator+(const Point& a, const int& b)
	{
		return Point(a.x + b, a.y + b);	//��ǥ�� x, y�� ������ ���ϴ� �Լ�
	}
	friend int operator*(const Point& a, const Point& b)
	{
		return a.x*b.x + a.y*b.y;	//�� ��ǥ�� x���� y���� ���� ���ϰ� ���� ���� ���ϴ� �Լ�
	}
	friend Point scale(const Point& a, const Point& b)
	{
		return Point(a.x*b.x, a.y*b.y);	//�� ��ǥ�� x���� y���� ���� ���ϴ� �Լ�
	}
	friend Point transpose(const Point& p)
	{
		return Point(p.y, p.x);	//x��ǥ�� y��ǥ�� �ٲٴ� �Լ�
	}
};

class Rect
{
	Point p, q;	//�� PointŬ������ p�� q�� ���
public:
	Rect():p(0, 0), q(0,0){}
	Rect(int x1, int y1, int x2, int y2):p(x1, y1), q(x2, y2){}
	Rect(const Point& a, const Point& b):p(a), q(b){}	//���簢���� �� �� �� ��ǥ

	friend ostream& operator<<(ostream& os, const Rect& r)
	{
		os << r.p << "-" << r.q;
		return os;	//���簢���� �� �� �� ��ǥ�� ����ϴ� �Լ�
	}
	friend Rect operator+(const Rect& r, const Point& x)
	{
		return Rect(r.p + x, r.q + x);	//���簢���� �� �� ��ǥ�� �����̵��� ���� ��ǥ���� ���ϴ� �Լ�
	}
	friend Rect operator+(const Rect& r, int x)
	{
		return Rect(r.p + x, r.q + x);	//���簢���� �� �� ��ǥ�� �̵��� ũ�⸸ŭ�� ���ϴ� �Լ�
	}
	friend Rect operator*(const Rect& r, Point& x)
	{
		Point m(-1,-1);
		Point t(r.q + scale(m, r.p));	//���簢���� �� �� ��ǥ�� ū ������ ���� ���� ���־� ���簢���� ����, ���ΰ��� ����
		Point a = scale(t, x);	//���� ���ΰ��� Ȯ���� ũ�⸦ ��Ÿ���� ���� ��ǥ�� ���Ͽ��ش�

		a = r.p + a;	//���� ���� �� ��ǥ�� Ȯ���� ��ŭ�� ���� ���� ũ�⸦ ���Ͽ� ū ���� ��ǥ�� ���Ͽ��ش�

		return Rect(r.p, a);	//���� ���� �� ��ǥ�� �ٲ� ū�� ��ǥ�� ��ȯ
	}
	friend int area(const Rect& r)
	{
		Point m(-1,-1);
		Point t(r.q + scale(m, r.p));	//���簢���� �� �� ��ǥ�� ū ������ ���� ���� ���־� ���簢���� ����, ���ΰ��� ����
		Point w = transpose(t);	//���簢���� ���� ���θ� ���� ������ ���Ͽ� ��

		return t * w/2;	//���̴� ���� ������ ���̰� point w�� ���� ���� ���� �� 2���� ���Ͽ� �� ���̱� ������ �� ���� 2�� ������ ���̸� ���� ��ȯ���ش�
	}
};

int main()
{
	Point x(1,2);	//���� ���� ��ǥ
	Point p(1,2);
	Point q(2,3);

	Rect r(p, q);	//���簢���� ��ǥ

	cout << r << endl;	//���簢�� ��ǥ ���
	cout << r + x << endl;	//���簢���� ���� �����̵��� ��ǥ ���
	cout << r + 2 << endl;	//���簢���� ��ǥ�� x, y ��� 2��ŭ ��� �����̵��� ��ǥ ���
	cout << r * x << endl;	//���簢���� �Էµ� ��ǥ�� ��ŭ Ȯ���� ���簢���� �� �� ��ǥ ���
	cout << area(r) << endl;	//���簢���� ���� ���

	return 0;
}
