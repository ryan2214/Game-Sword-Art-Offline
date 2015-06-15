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
	bool welcomeInit();				 //��ʼ����ӭ����
	//void saoMode();				 //SAOģʽ(δʵ��)
	void unlimitedMode();			 	//����ģʽ
	void gameExit();				 //�˳���Ϸ
	void bgm(int);					 //����bgm
	void sound(int);				 //������Ч
	void setOriginx(int);			 	//�����ͼԭ��
	int getOriginx();				 //��ȡ��ͼԭ��
	void sceneChange(PLAYER*, int,IMAGE*); 		//����ת��
	void screenMove(int,int);		 	//��Ļ��Ӧ���ƶ�
	void hpUI(int*, int*);				 //kirito��HP��UI
	void otherUI(PLAYER*);				//������UI
	void achievement(PLAYER*);			//�ɾ���ʾ
	void credit(IMAGE*,IMAGE*,IMAGE*,int*);		//������Ա
	void roadBar(IMAGE*);				//·��
	void enemyHpUI(int*, int*,int*,int*); 		//���ˤ�HP
	void bossHpUI(int*, int*, int*, int*);		//BOSS��HP
	void loadOrNew();				//ѡ��������߿�ʼ����Ϸ(δʵ��)
	void stillput(bool,int,int,int, IMAGE*,int);		 //��ֹʱͼƬ����
	int fileRead();						//��ȡ�ļ�
	static void M_putimg(int,int,IMAGE*,int,int,int);//����ͼƬ������͸��&͸���ȿɵ���
	static void HPCAO_putimg(int, int, IMAGE*, int, int, int);
	static void copy_img(IMAGE*, IMAGE*);			//����ͼƬ������ͼƬ��������
protected:
	int originx;						//��ͼԭ��
	int floor;						//��ǰ����
	int highfloor;						//������߲���
	int mobslaynum;						//�������������
	int deathtime;						//��������
	int room;						//������
	int leftlimit;						//������߽�
	int rightlimit;						//�����ұ߽�
	bool BGM;						//�Ƿ񲥷�BGM
	bool SOUND;						//�Ƿ񲥷���Ч��MAINFRAME�ڵ���Ч��
	PLAYER kirito;	     					//������ݿ�
}mainFrame;
