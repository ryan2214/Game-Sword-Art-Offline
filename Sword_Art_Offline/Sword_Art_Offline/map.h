#pragma once

#include <iostream>

#define maxenemy 100

using namespace std;

typedef class __MAP
{
public:							/*������������*/
	__MAP();				//Ĭ���ǿ�
	__MAP(int);	//���ڼ��ص�ͼ
	~__MAP();
public:
	int getenemyx(int);   //���ݵ��˱�Ż�ȡ����λ��
	int getplayerx();     //��ȡ���λ��
protected:		/****�������****/
	int x;               //λ��
	int y;
	int level;             //��ͼ��ǰ����
	int enemyx[maxenemy];  //�����ǵ�λ��
	int playerx;          //���λ��

}map;
