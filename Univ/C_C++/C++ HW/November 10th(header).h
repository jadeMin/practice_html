/*
 * mySet.h
 *
 *  Created on: 2016. 11. 10.
 *      Author: �̼���
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
		cout << "default constructor" << endl;	//mySet�Լ��� ����Ǵ��� Ȯ���� �� �ֵ��� ���
		name = "default";	//default��� �̸��� ����
		sizeMax = 3;	//�ִ� ������ ������ 3���� ����
		data = new int[sizeMax];	//���� �޸� �Ҵ�
		currentSize = 0;	//���� ������ ������ 0���� �ʱ�ȭ
	}

	mySet(int n, string str)
	{
		cout << "constructor-2" << endl;	//�Լ��� ����Ǵ��� Ȯ���� �� �ֵ��� ���
		name = str;	//str�̶�� �̸� ����
		sizeMax = n;	//������ ������ n���� ����
		data = new int[sizeMax];	//���� �޸� �Ҵ�
		currentSize = 0;	//���� ������ ������ 0���� �ʱ�ȭ
	}

	~mySet()	//�Ҹ��� �Լ��� ����
	{
		cout << "�Ҹ���-" << name << endl;	//�Ҹ��ڸ� ȣ���Ͽ� �� �� �Լ��� �Ҹ�
		delete [] data;	//���� �޸� ����
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

		if(currentSize >= sizeMax)	//������ �ִ� ���� ������ ���� ��� "error" ���
		{
			cout << "error" << endl;
			return;
		}
		if(contains(x) == true)	//���տ� �ߺ��Ǵ� ���Ұ� ���� ��� "error" ���
		{
			cout << "error" << endl;
			return;
		}
		data[currentSize] = x;	//�Էµ� ���� �� ��ġ�� �迭�� ���� ����
		currentSize++;	//���� ��ġ�� �迭�� ���� ����ǵ��� currentSize���� ������Ŵ

	}
	//data = (1, 2, 3)
	bool contains(int x)
	{	/*
		 *	for i = 0~currentSize-1
		 *		data[i] == x
		 *		return true;
		 *		return false;
		 */
		for(int i = 0; i < currentSize; i++)	//�ߺ��Ǵ� ���Ұ� �ִ��� Ȯ���ϴ� �ݺ��� ����
		{
			if(data[i] == x)
				return true;	//��ġ�� ���� ���� ��� true�� ��ȯ�Ѵ�

		}
		return false;	//��ġ�� ���� ���� ��� false�� ��ȯ�Ѵ�
	}
};



#endif /* MYSET_H_ */
