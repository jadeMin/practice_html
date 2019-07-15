/*
 * class2.cpp
 *
 *  Created on: 2016. 12. 1.
 *      Author: 이선민
 */
#include<iostream>
using namespace std;

class Point
{	//(x, y)
	int x, y;

public:
	Point():x(0), y(0){}
	Point(int a, int b):x(a), y(b){}
	Point(const Point& p):x(p.x), y(p.y){}	//복사 생성자
	friend ostream& operator<<(ostream& os, const Point& p)
	{
		os << "(" << p.x << "," << p.y << ")";	//좌표를 의미하는 형식으로 출력하기 위해 형식 설정
		return os;
	}
	friend Point operator+(const Point& a, const Point& b)
	{
		return Point(a.x + b.x, a.y + b.y);	//좌표를 x, y끼리 더하는 함수
	}
	friend Point operator+(const int& a, const Point& b)
	{
		return Point(a + b.x, a + b.y);	//정수와 좌표의 x, y를 더하는 함수
	}
	friend Point operator+(const Point& a, const int& b)
	{
		return Point(a.x + b, a.y + b);	//좌표의 x, y와 정수를 더하는 함수
	}
	friend int operator*(const Point& a, const Point& b)
	{
		return a.x*b.x + a.y*b.y;	//두 좌표의 x값과 y값을 각각 곱하고 곱한 값을 더하는 함수
	}
	friend Point scale(const Point& a, const Point& b)
	{
		return Point(a.x*b.x, a.y*b.y);	//두 좌표의 x값과 y값을 각각 곱하는 함수
	}
	friend Point transpose(const Point& p)
	{
		return Point(p.y, p.x);	//x좌표와 y좌표를 바꾸는 함수
	}
};

class Rect
{
	Point p, q;	//위 Point클래스의 p와 q를 사용
public:
	Rect():p(0, 0), q(0,0){}
	Rect(int x1, int y1, int x2, int y2):p(x1, y1), q(x2, y2){}
	Rect(const Point& a, const Point& b):p(a), q(b){}	//직사각형의 양 끝 두 좌표

	friend ostream& operator<<(ostream& os, const Rect& r)
	{
		os << r.p << "-" << r.q;
		return os;	//직사각형의 양 끝 두 좌표를 출력하는 함수
	}
	friend Rect operator+(const Rect& r, const Point& x)
	{
		return Rect(r.p + x, r.q + x);	//직사각형의 양 끝 좌표에 평행이동할 기준 좌표점을 더하는 함수
	}
	friend Rect operator+(const Rect& r, int x)
	{
		return Rect(r.p + x, r.q + x);	//직사각형의 양 끝 좌표에 이동할 크기만큼을 더하는 함수
	}
	friend Rect operator*(const Rect& r, Point& x)
	{
		Point m(-1,-1);
		Point t(r.q + scale(m, r.p));	//직사각형의 양 끝 좌표중 큰 값에서 작은 값을 빼주어 직사각형의 가로, 세로값을 구함
		Point a = scale(t, x);	//가로 세로값에 확장할 크기를 나타내는 점의 좌표를 곱하여준다

		a = r.p + a;	//기존 작은 쪽 좌표에 확장한 만큼의 가로 세로 크기를 더하여 큰 쪽의 좌표를 구하여준다

		return Rect(r.p, a);	//기존 작은 쪽 좌표와 바뀐 큰쪽 좌표를 반환
	}
	friend int area(const Rect& r)
	{
		Point m(-1,-1);
		Point t(r.q + scale(m, r.p));	//직사각형의 양 끝 좌표중 큰 값에서 작은 값을 빼주어 직사각형의 가로, 세로값을 구함
		Point w = transpose(t);	//직사각형의 가로 세로를 곱한 값끼리 더하여 줌

		return t * w/2;	//넚이는 가로 세로의 곱이고 point w는 가로 세로 곱한 값 2개를 더하여 준 값이기 때문에 그 값을 2로 나누어 넓이를 구해 반환해준다
	}
};

int main()
{
	Point x(1,2);	//기준 점의 좌표
	Point p(1,2);
	Point q(2,3);

	Rect r(p, q);	//직사각형의 좌표

	cout << r << endl;	//직사각형 좌표 출력
	cout << r + x << endl;	//직사각형을 점에 평행이동한 좌표 출력
	cout << r + 2 << endl;	//직사각형의 좌표를 x, y 모두 2만큼 모두 평행이동한 좌표 출력
	cout << r * x << endl;	//직사각형을 입력된 좌표값 만큼 확장한 직사각형의 양 끝 좌표 출력
	cout << area(r) << endl;	//직사각형의 면적 출력

	return 0;
}
