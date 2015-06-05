#pragma once

#include <iostream>

#define maxenemy 1

using namespace std;

typedef class __MAP
{
public:							/*构造析构函数*/
	__MAP();				//默认是空
	__MAP(int);	//用于加载地图
	~__MAP();
public:
	int getEnemyX(int);   //根据敌人编号获取敌人位置
	int getEnemyHp(int);  //根据编号获取敌人Hp
	int getEnemyNum();      //获取当前敌人数量
	void setEnemyX(int, int); //改变定编号敌人的位置
	void setEnemyHp(int, int);//改变定编号敌人的Hp
	void setEnemyNum(int);    //设置当前敌人数量
protected:		/****玩家属性****/
	int x;               //位置  
	int y;
	int level;             //地图当前层数
	static int enemynum;          //敌人们的数量
	int enemyx[maxenemy];  //敌人们的位置
	int enemyHp[maxenemy]; //敌人们的Hp
}map;
