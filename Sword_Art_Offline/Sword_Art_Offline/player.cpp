#include "player.h"
#include "skilllist.h"

__PLAYER::__PLAYER() {}

__PLAYER::~__PLAYER() {}

int kirito::getx()	     //��ȡλ��
{
	return x;
}

int kirito::gety()
{
	return y;
}

int kirito::getmovespd()//��ȡ�ƶ��ٶ�
{
	return movespeed;
}
	
int kirito::getattack()        //��ȡ������
{
	return attack;
}

int kirito::gethp()            //��ȡ��ǰhp
{
	return hp;
}

int kirito::getskill()         //��ȡ��ǰ�ͷż��ܱ��
{
	return skilltype;
}

int kirito::getcombo()         //��ȡ��ǰ����ֵ
{
	return combo;
}

void kirito::teleport(int x1, int y1)	//������Ҵ���
{
	x = x1;
	y = y1;
}

void kirito::jump(int state)		    //��Ծ
{
	switch (state){
	case 1:y -= 40, isJump = true; break;
	case 2:y -= 30; break;
	case 3:y -= 20; break;
	case 4:y -= 10; break;
	case 5:break;
	case 6:y += 10; break;
	case 7:y += 20; break;
	case 8:y += 30; break;
	case 9:y += 40, isJump = false;; break;
	default:break;
	}
}

void kirito::movex()		//�����ƶ� 
{
	switch (getdir()){
	case 0:x -= getmovespd(); break;
	case 1:x += getmovespd(); break;
	}
}

void kirito::castskill(int skillnum)    //�ͷż��ܣ����ܱ�ţ�
{
	if (__SKILLLIST::ableToCast(skillnum))
}
bool stilljudge();      //�ж��Ƿ�ֹ
bool lifejudge();       //���ȷ��