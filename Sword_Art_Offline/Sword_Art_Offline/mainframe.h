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
	bool welcomeInit();				 //初始化欢迎界面
	//void saoMode();				 //SAO模式(未实现)
	void unlimitedMode();			 	//无限模式
	void gameExit();				 //退出游戏
	void bgm(int);					 //播放bgm
	void sound(int);				 //播放音效
	void setOriginx(int);			 	//重设绘图原点
	int getOriginx();				 //获取绘图原点
	void sceneChange(PLAYER*, int,IMAGE*); 		//场景转换
	void screenMove(int,int);		 	//屏幕适应性移动
	void hpUI(int*, int*);				 //kiritoのHPのUI
	void otherUI(PLAYER*);				//其他的UI
	void achievement(PLAYER*);			//成就显示
	void credit(IMAGE*,IMAGE*,IMAGE*,int*);		//制作人员
	void roadBar(IMAGE*);				//路标
	void enemyHpUI(int*, int*,int*,int*); 		//敌人のHP
	void bossHpUI(int*, int*, int*, int*);		//BOSSのHP
	void loadOrNew();				//选择读档或者开始新游戏(未实现)
	void stillput(bool,int,int,int, IMAGE*,int);		 //静止时图片加载
	int fileRead();						//读取文件
	static void M_putimg(int,int,IMAGE*,int,int,int);//绘制图片（背景透明&透明度可调）
	static void HPCAO_putimg(int, int, IMAGE*, int, int, int);
	static void copy_img(IMAGE*, IMAGE*);			//复制图片，机巧图片不会受伤
protected:
	int originx;						//绘图原点
	int floor;						//当前层数
	int highfloor;						//所达最高层数
	int mobslaynum;						//所消灭怪物数量
	int deathtime;						//死亡次数
	int room;						//房间编号
	int leftlimit;						//房间左边界
	int rightlimit;						//房间右边界
	bool BGM;						//是否播放BGM
	bool SOUND;						//是否播放音效（MAINFRAME内的音效）
	PLAYER kirito;	     					//玩家数据库
}mainFrame;
