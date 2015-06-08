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
public:					/*���졢��������*/
	MAINFRAME();
	~MAINFRAME();
public:					/*����*/
	void welcomeInit();				 //��ʼ����ӭ����
	//void saoMode();				 //SAOģʽ
	int unlimitedMode();			 //����ģʽ
	void gameExit();				 //�˳���Ϸ
	void bgm(int);					 //����bgm
	void sound(int);				 //������Ч
	void setOriginx(int);			 //�����ͼԭ��
	int getOriginx();				 //��ȡ��ͼԭ��
	void screenMove(int,int);		 //��Ļ��Ӧ���ƶ�
	void hpUI(int*, int*);			 //kirito��HP��UI
	void enemyHpUI(int*, int*,int*,int*); //���ˤ�HP
	void stillput(bool,int,int,int, IMAGE*,int);		 //��ֹʱͼƬ����
	void skillEffect(IMAGE, IMAGE, IMAGE);		   	//������Ч����
	static void M_putimg(int,int,IMAGE*,int,int,int);//����ͼƬ������͸��&͸���ȿɵ���
	static void copy_img(IMAGE*, IMAGE*);			//����ͼƬ������ͼƬ��������
protected:
	int originx;
	PLAYER kirito;	     //������ݿ�
}mainFrame;
