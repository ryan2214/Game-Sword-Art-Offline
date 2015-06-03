#pragma once

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "enemy.h"
#include "player.h"
#include "skilllist.h"

using namespace std;

typedef class __MAINFRAME
{
public:					/*���졢��������*/
	__MAINFRAME();
	~__MAINFRAME();
public:					/*����*/
	void welcomeInit();	    //��ʼ����ӭ����
	void saoMode();	        //SAOģʽ
	void unlimitedMode();	//����ģʽ
	//void cgShow();          //CG����
	//void composerShow();    //������Ա
	void gameExit();	    //�˳���Ϸ
	void bgm(int);          //����bgm
	void sound(int);        //������Ч
	static void my_putimg(int,int,IMAGE*,int,int,int);//����ͼƬ������͸��&͸���ȿɵ���
protected:
	__PLAYER kirito;	     //������ݿ�
	__ENEMY enemy;           //�������ݿ�
	__SKILLLIST skillList;   //�������ݿ�
}mainFrame;
