/*
 * 201602357.cpp
 *
 *  Created on: 2016. 10. 6.
 *      Author: 이선민
 */
#include<iostream>

using namespace std;

//메인함수에 있는 변수도 바꾸기 위해 포인터로 선언
void shift(int *a, int *b, int *c)	//a의 값을 b로 b의 값을 c로 a의 값에는 0을 넣는 함수
{
	int temp = 0;
	*c = *b;
	*b = *a;
	*a = temp;
}


int main()
{
	int x = 1, y = 2, z = 3;

	shift(&x, &y, &z);	//shift 함수 호출
	cout << x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	shift(&x, &y, &z);	//shift 함수 호출
	cout << x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	return 0;
}

void shift(int &a, int &b, int &c)	//a의 값을 b로 b의 값을 c로 a의 값에는 0을 넣는 함수
{
	int temp = 0;
	c = b;
	b = a;
	a = temp;
}

int main()
{
	int x = 1, y = 2, z = 3;

	shift(x, y, z);	//함수호출
	cout << x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	shift(x, y, z);	//함수호출
	cout << x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	return 0;
}


void circularShift(int &a, int &b, int &c)	//a 의 값을 b로 b의 값을 c로 a의 값에는 a값을 넣는 함수
{
	int temp;
	temp = c;
	c = b;
	b = a;
	a = temp;
}

int main()
{
	int x = 1, y = 2, z = 3;

	circularShift(x, y, z);	//함수호출
	cout<< x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	circularShift(x, y, z);	//함수호출
	cout<< x << " " << y << " " << z << endl;	//바뀐 x, y, z값을 출력

	return 0;
}

void addTwoVector(const int *a, const int *b, int *c, int N)
{
	if(c != NULL)
		delete [] c;	//배열 c를 a,b배열의 개수로 만들기 위해 기존 c값을 초기화

	c = new int[N];	//배열c의 개수를 a,b배열의 개수로 설정

	for(int i = 0; i < N; i++)	//a1~aN 배열과 b1~bN 배열의 합을 c1~cN 배열에 입력
		c[i] = a[i] + b[i];

}
int main()
{
	int x[] = {1, 2, 3, 4};
	int y[] = {2, 3, 4, 5};
	//int z[2]

	int *z;
	z = new int [2];	//z의 배열을 2로 초기화하여 설정

	addTwoVector(x, y, z, 4);	//함수를 호출

	for(int i = 0; i < 4; i++)
		cout << z[i] << " " << endl;	//z배열을 출력

	return 0;
}
