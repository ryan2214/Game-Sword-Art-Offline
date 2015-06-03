#pragma once

#include <iostream>

#define maxenemy 100

using namespace std;

typedef class __MAP
{
public:							/*构造析构函数*/
	__MAP();				//默认是空
	__MAP(int);	//用于加载地图
	~__MAP();
public:
	int getenemyx(int);   //根据敌人编号获取敌人位置
	int getplayerx();     //获取玩家位置
protected:		/****玩家属性****/
	int x;               //位置
	int y;
	int level;             //地图当前层数
	int enemyx[maxenemy];  //敌人们的位置
	int playerx;          //玩家位置

}map;
