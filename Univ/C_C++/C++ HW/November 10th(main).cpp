/*
 * mySet.cpp
 *
 *  Created on: 2016. 11. 10.
 *      Author: �̼���
 */
#include<iostream>
#include "mySet.h"
using namespace std;

int main()
{
	mySet s;
	mySet r(3, "set1");	//

	//class���� add�Լ� ȣ��
 	r.add(1);
	r.add(2);
	r.add(2);	//error
	r.add(3);
	r.add(4);	//error
	r.add(5);	//error


	cout << r.contains(1) <<endl;	//�ߺ�Ȯ���� �� �Ǿ����� Ȯ��
	cout << r.contains(2) <<endl;
	cout << r.contains(3) <<endl;


	return 0;
}



