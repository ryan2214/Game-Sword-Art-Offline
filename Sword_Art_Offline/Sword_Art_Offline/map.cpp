
#include "map.h"

__MAP::__MAP()
{
	x = 0;              //λ��
	y = 0;
	level = 1;             //��ͼ��ǰ����
	enemynum = 0;          //�����ǵ�����
	enemyx[maxenemy] = { 0 };  //�����ǵ�λ��
	enemyHp[maxenemy] = { 0 };        //���˵�Hp
}
__MAP::~__MAP(){}

int map::getEnemyX(int num)  //���ݵ��˱�Ż�ȡ����λ��
{
	return enemyx[num];
}

int getEnemyHp(int num)  //���ݱ�Ż�ȡ����Hp
{
	return enemyHp[num];
}
int getEnemyNum;      //��ȡ��ǰ��������
void setEnemyX(int, int); //�ı䶨��ŵ��˵�λ��
void setEnemyHp(int, int);//�ı䶨��ŵ��˵�Hp
void setEnemyNum(int);    //���õ�ǰ��������