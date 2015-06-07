#pragma once

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "player.h"

using namespace std;

typedef class __MAINFRAME
{
public:					/*构造、析构函数*/
	__MAINFRAME();
	~__MAINFRAME();
public:					/*功能*/
	void welcomeInit();				 //初始化欢迎界面
	//void saoMode();				 //SAO模式
	int unlimitedMode();			 //无限模式
	void gameExit();				 //退出游戏
	void bgm(int);					 //播放bgm
	void sound(int);				 //播放音效
	void setOriginx(int);			 //重设绘图原点
	int getOriginx();				 //获取绘图原点
	void screenMove(int,int);		 //屏幕适应性移动
	void stillput(bool,int,int,int, IMAGE*,int);		 //静止时图片加载
	void skillEffect(IMAGE, IMAGE, IMAGE);		   	//技能特效加载
	static void M_putimg(int,int,IMAGE*,int,int,int);//绘制图片（背景透明&透明度可调）
	static void copy_img(IMAGE*, IMAGE*);			//复制图片，机巧图片不会受伤
protected:
	int originx;
	__PLAYER kirito;	     //玩家数据库
}mainFrame;
