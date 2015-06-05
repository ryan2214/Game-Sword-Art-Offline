
#include "map.h"

__MAP::__MAP()
{
	x = 0;              //位置
	y = 0;
	level = 1;             //地图当前层数
	enemyx[maxenemy] = { 0 };  //敌人们的位置
	enemyHp[maxenemy] = { 0 };        //敌人的Hp
	enemynum++;
}

__MAP::~__MAP()
{
	enemynum--;
}

int __MAP::getEnemyX(int num)  //根据敌人编号获取敌人位置
{
	return enemyx[num];
}

int __MAP::getEnemyHp(int num)  //根据编号获取敌人Hp
{
	return enemyHp[num];
}

int __MAP::getEnemyNum()     //获取当前敌人数量
{
	return enemynum;
}

void __MAP::setEnemyX(int num, int x) //改变定编号敌人的位置
{
	enemyx[num] = x;
}

void __MAP::setEnemyHp(int num, int hp)//改变定编号敌人的Hp
{
	enemyHp[num] = hp;
}

void __MAP::setEnemyNum(int num)    //设置当前敌人数量
{
	enemynum = num;
}

int __MAP::enemynum = 0;