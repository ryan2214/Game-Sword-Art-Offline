#pragma once

using namespace std;

typedef class __PLAYER
{
public:							/*������������*/
	__PLAYER();				//Ĭ���ǿ�
	~__PLAYER();
public:
	int getx();		     //��ȡλ��
	int gety();
	int getmovespd();       //��ȡ�ƶ��ٶ�
	int getattack();        //��ȡ������
	int gethp();            //��ȡ��ǰhp
	int getskill();         //��ȡ��ǰ�ͷż��ܱ��
	int getcombo();         //��ȡ��ǰ����ֵ
	void teleport(int,int);	//������Ҵ���
	void damage(int);       //�ܵ��˺�
	void heal(int);         //�ܵ�����
	void jump(int);		    //��Ծ
	void movex();		    //�����ƶ�
	void setdir(bool);      //���÷���
	void castskill(int);    //�ͷż��ܣ����ܱ�ţ�
	bool stilljudge();      //�ж��Ƿ�ֹ
	bool lifejudge();       //���ȷ��
	bool getdir();          //��ȡ����
protected:		/****�������****/
	int hp;                 //��ǰ����ֵ
	int maxhp;              //�������ֵ
	int hpregen;            //ÿ֡ս���ظ�hp��ע:FPS=100��
	int movespeed;          //ÿ���ƶ�������
	int attack;             //������
	int x;                  //λ��
	int y;
	bool dir;               //0->�� 1->��
	int combo;              //����״̬
	bool isRun;             //�ܶ�
	bool isJump;            //��Ծ
	bool attacking;         //�Ƿ��ڹ���״̬
	int skilltype;          //��ǰ�ͷŵļ��ܱ��
}kirito;
