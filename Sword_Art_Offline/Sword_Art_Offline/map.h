#pragma once

#include <iostream>

#define maxenemy 1

using namespace std;

typedef class __MAP
{
public:							/*������������*/
	__MAP();				//Ĭ���ǿ�
	__MAP(int);	//���ڼ��ص�ͼ
	~__MAP();
public:
	int getEnemyX(int);   //���ݵ��˱�Ż�ȡ����λ��
	int getEnemyHp(int);  //���ݱ�Ż�ȡ����Hp
	int getEnemyNum();      //��ȡ��ǰ��������
	void setEnemyX(int, int); //�ı䶨��ŵ��˵�λ��
	void setEnemyHp(int, int);//�ı䶨��ŵ��˵�Hp
	void setEnemyNum(int);    //���õ�ǰ��������
protected:		/****�������****/
	int x;               //λ��  
	int y;
	int level;             //��ͼ��ǰ����
	static int enemynum;          //�����ǵ�����
	int enemyx[maxenemy];  //�����ǵ�λ��
	int enemyHp[maxenemy]; //�����ǵ�Hp
}map;
