
#include "map.h"

__MAP::__MAP()
{
	x = 0;              //位置
	y = 0;
	level = 1;             //地图当前层数
	enemynum = 0;          //敌人们的数量
	enemyx[maxenemy] = { 0 };  //敌人们的位置
	enemyHp[maxenemy] = { 0 };        //敌人的Hp
}
__MAP::~__MAP(){}

int map::getEnemyX(int num)  //根据敌人编号获取敌人位置
{
	return enemyx[num];
}

int getEnemyHp(int num)  //根据编号获取敌人Hp
{
	return enemyHp[num];
}
int getEnemyNum;      //获取当前敌人数量
void setEnemyX(int, int); //改变定编号敌人的位置
void setEnemyHp(int, int);//改变定编号敌人的Hp
void setEnemyNum(int);    //设置当前敌人数量