#pragma once

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "enemy.h"
#include "player.h"
#include "skilllist.h"
#include "map.h"

using namespace std;

typedef class __MAINFRAME
{
public:					/*构造、析构函数*/
	__MAINFRAME();
	~__MAINFRAME();
public:					/*功能*/
	void welcomeInit();	    //初始化欢迎界面
	//void saoMode();	        //SAO模式
	void unlimitedMode();	//无限模式
	void gameExit();	    //退出游戏
	void bgm(int);          //播放bgm
	void sound(int);        //播放音效
	void setOriginx(int);   //重设绘图原点
	int getOriginx();      //获取绘图原点
	void screenMove(int,int);      //屏幕适应性移动
	static void M_putimg(int,int,IMAGE*,int,int,int);//绘制图片（背景透明&透明度可调）
	static void copy_img(IMAGE*, IMAGE*); //复制图片，机巧图片不会受伤
protected:
	int originx;
	__PLAYER kirito;	     //玩家数据库
	__ENEMY enemy;           //敌人数据库
	__SKILLLIST skillList;   //技能数据库
	__MAP map;
}mainFrame;
