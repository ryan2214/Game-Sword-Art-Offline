#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "player.h"

using namespace std;

typedef class MAINFRAME
{
public:					/*构造、析构函数*/
	MAINFRAME();
	~MAINFRAME();
public:					/*功能*/
	void welcomeInit();				 //初始化欢迎界面
	//void saoMode();				 //SAO模式
	int unlimitedMode();			 //无限模式
	void gameExit();				 //退出游戏
	void bgm(int);					 //播放bgm
	void sound(int);				 //播放音效
	void setOriginx(int);			 //重设绘图原点
	int getOriginx();				 //获取绘图原点
	void sceneChange(PLAYER*, bool,IMAGE*); //场景转换
	void screenMove(int,int);		 //屏幕适应性移动
	void hpUI(int*, int*);			 //kiritoのHPのUI
	void otherUI(PLAYER*);					//其他的UI
	void enemyHpUI(int*, int*,int*,int*); //敌人のHP
	void stillput(bool,int,int,int, IMAGE*,int);		 //静止时图片加载
	static void M_putimg(int,int,IMAGE*,int,int,int);//绘制图片（背景透明&透明度可调）
	static void HPCAO_putimg(int, int, IMAGE*, int, int, int);
	static void copy_img(IMAGE*, IMAGE*);			//复制图片，机巧图片不会受伤
protected:
	int originx;
	int floor;
	int room;
	int leftlimit;
	int rightlimit;
	bool BGM;
	bool SOUND;
	PLAYER kirito;	     //玩家数据库
}mainFrame;
