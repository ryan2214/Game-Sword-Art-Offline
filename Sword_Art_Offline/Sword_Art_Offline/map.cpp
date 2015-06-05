
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

int map::getEnemyX(int num)  //���ݵ��˱�Ż�ȡ����λ��
{
	return enemyx[num];
}

int map::getEnemyHp(int num)  //���ݱ�Ż�ȡ����Hp
{
	return enemyHp[num];
}

int map::getEnemyNum()     //��ȡ��ǰ��������
{
	return enemynum;
}

void map::setEnemyX(int num, int x) //�ı䶨��ŵ��˵�λ��
{
	enemyx[num] = x;
}

void map::setEnemyHp(int num, int hp)//�ı䶨��ŵ��˵�Hp
{
	enemyHp[num] = hp;
}

void map::setEnemyNum(int num)    //���õ�ǰ��������
{
	enemynum = num;
}

int __MAP::enemynum = 0;