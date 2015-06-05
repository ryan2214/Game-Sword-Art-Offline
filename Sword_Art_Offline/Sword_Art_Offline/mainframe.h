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
public:					/*���졢��������*/
	__MAINFRAME();
	~__MAINFRAME();
public:					/*����*/
	void welcomeInit();	    //��ʼ����ӭ����
	//void saoMode();	        //SAOģʽ
	void unlimitedMode();	//����ģʽ
	void gameExit();	    //�˳���Ϸ
	void bgm(int);          //����bgm
	void sound(int);        //������Ч
	void setOriginx(int);   //�����ͼԭ��
	int getOriginx();      //��ȡ��ͼԭ��
	void screenMove(int,int);      //��Ļ��Ӧ���ƶ�
	static void M_putimg(int,int,IMAGE*,int,int,int);//����ͼƬ������͸��&͸���ȿɵ���
	static void copy_img(IMAGE*, IMAGE*); //����ͼƬ������ͼƬ��������
protected:
	int originx;
	__PLAYER kirito;	     //������ݿ�
	__ENEMY enemy;           //�������ݿ�
	__SKILLLIST skillList;   //�������ݿ�
	__MAP map;
}mainFrame;
