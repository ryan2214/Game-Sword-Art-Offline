#include "mainframe.h"

__MAP::__MAP()
{
	x = 0;              //位置
	y = 0;
	level = 1;             //地图当前层数
	enemynum = 0;          //敌人们的数量
	enemyx[maxenemy] = { 0 };  //敌人们的位置
}