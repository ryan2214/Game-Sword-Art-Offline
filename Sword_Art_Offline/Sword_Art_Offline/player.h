#pragma once
#include <graphics.h>

using namespace std;

typedef class PLAYER
{
public:							/*������������*/
	PLAYER();				//Ĭ���ǿ�
	~PLAYER();
public:
	int getX();		     //��ȡλ��
	int getY();
	int getMovespd();       //��ȡ�ƶ��ٶ�
	int getAttack();        //��ȡ������
	int getHp();            //��ȡ��ǰhp
	int getSkill();         //��ȡ��ǰ�ͷż��ܱ��
	int getCombo();         //��ȡ��ǰ����ֵ
	void meleeAttack(int*, int*, PLAYER*, IMAGE*, IMAGE*, IMAGE*, IMAGE*, int);     //��ͨ�ι���
	void damage(int);       //�ܵ��˺�
	void jump();		    //��Ծ
	void running(IMAGE*, int);         //�ܶ�
	void moveX(); //������(hua)��
	void startJump();       //����
	void useSkill(int);     //�ͷż���
	bool stillJudge();      //�ж��Ƿ�ֹ
	bool jumpJudge();       //�ж��Ƿ���Ծ
	bool runJudge();        //�ж��Ƿ��ܶ�
	bool coolingJudge();    //�ж��Ƿ�����ȴ
	bool getDir();          //��ȡ����
	int getStill();
	void restill();         //�ָ���ֹ
	int getSkillState();    //��ȡ����״̬
	int getRunState();      //��ȡ�ܶ�״̬
	void skillEffect(IMAGE*,IMAGE*,int);     //�����ܼ��ؼ�
	void startRun();        //��ʼ�ܶ�
	void coolingDown();     //��ȴ�ָ�
	void skillStateMove();  //����skillState
	

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
	void setStill(int);        //ʹ��ֹ
	void setRunState(int);   //�����ܶ��׶�
	void setRun(int);       //����runֵ
	
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
	int run;
	int coolDown;
	int skillState;         //�����ͷŹ���
	int skillType;          //��ǰ�ͷŵļ��ܱ��
	int still;              //sanֵ
	bool isRun;             //�ܶ�
	bool isJump;            //��Ծ
	bool cooling;         //�Ƿ��ڹ���״̬

}kirito,enemy;
