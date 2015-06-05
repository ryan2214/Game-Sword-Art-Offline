
#include "map.h"

__MAP::__MAP()
{
	x = 0;              //λ��
	y = 0;
	level = 1;             //��ͼ��ǰ����
	enemyx[maxenemy] = { 0 };  //�����ǵ�λ��
	enemyHp[maxenemy] = { 0 };        //���˵�Hp
	enemynum++;
}

__MAP::~__MAP()
{
	enemynum--;
}

int __MAP::getEnemyX(int num)  //���ݵ��˱�Ż�ȡ����λ��
{
	return enemyx[num];
}

int __MAP::getEnemyHp(int num)  //���ݱ�Ż�ȡ����Hp
{
	return enemyHp[num];
}

int __MAP::getEnemyNum()     //��ȡ��ǰ��������
{
	return enemynum;
}

void __MAP::setEnemyX(int num, int x) //�ı䶨��ŵ��˵�λ��
{
	enemyx[num] = x;
}

void __MAP::setEnemyHp(int num, int hp)//�ı䶨��ŵ��˵�Hp
{
	enemyHp[num] = hp;
}

void __MAP::setEnemyNum(int num)    //���õ�ǰ��������
{
	enemynum = num;
}

int __MAP::enemynum = 0;