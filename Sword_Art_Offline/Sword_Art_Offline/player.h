#pragma once
#include <graphics.h>

using namespace std;

typedef class __PLAYER
{
public:							/*������������*/
	__PLAYER();				//Ĭ���ǿ�
	~__PLAYER();
public:
	int getX();		     //��ȡλ��
	int getY();
	int getMovespd();       //��ȡ�ƶ��ٶ�
	int getAttack();        //��ȡ������
	int getHp();            //��ȡ��ǰhp
	int getSkill();         //��ȡ��ǰ�ͷż��ܱ��
	int getCombo();         //��ȡ��ǰ����ֵ
	void meleeAttack(int[],int[],int);     //��ͨ�ι���
	void damage(int);       //�ܵ��˺�
	void jump();		    //��Ծ
	void moveX(IMAGE player);//�����ƶ�
	void startJump();       //����
	void useSkill(int);     //�ͷż���
	void still(int ox, IMAGE player);//��ֹ��̬
	void skillEffect(IMAGE,IMAGE,IMAGE);//����������Ч����
	bool stillJudge();      //�ж��Ƿ�ֹ
	bool jumpJudge();       //�ж��Ƿ���Ծ
	bool getDir();          //��ȡ����

	//��ʼ���ú���
	void teleport(int, int);//������Ҵ���
	void setDir(bool);      //���÷���
	void setHp(int);        //����Hpֵ
	void setMaxHp(int);     //����MaxHpֵ
	void setAttack(int);    //����attackֵ
	void setSpd(int);       //�����ƶ��ٶ�
	void setCombo(int);     //�����������
	void setSkillState(int);//���ü����ͷ�״̬
	void setSkillType(int); //���ü�������
	
protected:		/****�������****/
	int hp;                 //��ǰ����ֵ
	int maxhp;              //�������ֵ
	int hpregen;            //ÿ֡ս���ظ�hp��ע:FPS=100��
	int movespd;            //ÿ���ƶ�������
	int attack;             //������
	int x;                  //λ��
	int y;
	bool dir;               //0->�� 1->��
	int combo;              //����״̬
	int jumpState;          //��Ծ����
	int runState;           //�ܶ�����
	int skillState;         //�����ͷŹ���
	int skillType;          //��ǰ�ͷŵļ��ܱ��
	bool isRun;             //�ܶ�
	bool isJump;            //��Ծ
	bool attacking;         //�Ƿ��ڹ���״̬
	
}kirito;
