/*
 * mySet.cpp
 *
 *  Created on: 2016. 11. 10.
 *      Author: 이선민
 */
#include<iostream>
#include "mySet.h"
using namespace std;

int main()
{
	mySet s;
	mySet r(3, "set1");	//

	//class내의 add함수 호출
 	r.add(1);
	r.add(2);
	r.add(2);	//error
	r.add(3);
	r.add(4);	//error
	r.add(5);	//error


	cout << r.contains(1) <<endl;	//중복확인이 잘 되었는지 확인
	cout << r.contains(2) <<endl;
	cout << r.contains(3) <<endl;


	return 0;
}



