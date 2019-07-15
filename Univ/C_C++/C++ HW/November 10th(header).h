/*
 * mySet.h
 *
 *  Created on: 2016. 11. 10.
 *      Author: 이선민
 */

#ifndef MYSET_H_
#define MYSET_H_
#include<iostream>
using namespace std;

class mySet
{
private:
	int *data;
	int sizeMax, currentSize;
	string name;

public:
	mySet()
	{
		cout << "default constructor" << endl;	//mySet함수가 실행되는지 확인할 수 있도록 출력
		name = "default";	//default라는 이름을 설정
		sizeMax = 3;	//최대 원소의 개수가 3개로 설정
		data = new int[sizeMax];	//동적 메모리 할당
		currentSize = 0;	//현재 원소의 개수를 0으로 초기화
	}

	mySet(int n, string str)
	{
		cout << "constructor-2" << endl;	//함수가 실행되는지 확인할 수 있도록 출력
		name = str;	//str이라는 이름 설정
		sizeMax = n;	//원소의 개수를 n으로 설정
		data = new int[sizeMax];	//동적 메모리 할당
		currentSize = 0;	//현재 원소의 개수를 0으로 초기화
	}

	~mySet()	//소멸자 함수를 설정
	{
		cout << "소멸자-" << name << endl;	//소멸자를 호출하여 위 두 함수를 소멸
		delete [] data;	//동적 메모리 삭제
	}

	void add(int x)
	{	/*currentSize >= sizeMax
		 *	cout << "error" << endl;
		 *	return;
		 *
		 *	contains(x) == true
		 *		cout << "error" << endl;
		 *		return;
		 *
		 *	data[currentSize] = x
		 *	currentSize++;
		 */

		if(currentSize >= sizeMax)	//집합의 최대 원소 개수를 넘을 경우 "error" 출력
		{
			cout << "error" << endl;
			return;
		}
		if(contains(x) == true)	//집합에 중복되는 원소가 있을 경우 "error" 출력
		{
			cout << "error" << endl;
			return;
		}
		data[currentSize] = x;	//입력된 수를 그 위치의 배열의 수로 저장
		currentSize++;	//다음 위치의 배열에 수가 저장되도록 currentSize값을 증가시킴

	}
	//data = (1, 2, 3)
	bool contains(int x)
	{	/*
		 *	for i = 0~currentSize-1
		 *		data[i] == x
		 *		return true;
		 *		return false;
		 */
		for(int i = 0; i < currentSize; i++)	//중복되는 원소가 있는지 확인하는 반복문 형성
		{
			if(data[i] == x)
				return true;	//겹치는 수가 있을 경우 true를 반환한다

		}
		return false;	//겹치는 수가 없을 경우 false를 반환한다
	}
};



#endif /* MYSET_H_ */
