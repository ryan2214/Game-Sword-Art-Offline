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
	int getEnemyX(int);   //���ݵ��˱�Ż�ȡ����λ��
	int getEnemyNum;      //��ȡ��ǰ��������
	void setEnemyNum(int);//���õ�ǰ��������
protected:		/****�������****/
	int x;               //λ��
	int y;
	int level;             //��ͼ��ǰ����
	int enemynum;          //�����ǵ�����
	int enemyx[maxenemy];  //�����ǵ�λ��
}map;
