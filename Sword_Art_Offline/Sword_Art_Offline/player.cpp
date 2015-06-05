#include "player.h"
#include "enemy.h"
#include "map.h"
#include "mainframe.h"
#include "skilllist.h"

__PLAYER::__PLAYER()
{
	teleport(300, 400);            //��ʼ��__PLAYER����
	setDir(1);
	setMaxHp(100);
	setHp(50);
	setAttack(10);
	setSpd(0);
	setSkillState(0);
	setSkillType(0);
	isRun = false;
	isJump = false;
	attacking = false;
	runState = 0;
	still = 1;
}

__PLAYER::~__PLAYER() {}

int __PLAYER::getX()	     //��ȡλ��
{
	return x;
}

int __PLAYER::getY()
{
	return y;
}

int __PLAYER::getMovespd()//��ȡ�ƶ��ٶ�
{
	return movespd;
}
	
int __PLAYER::getAttack()        //��ȡ������
{
	return attack;
}

int __PLAYER::getHp()            //��ȡ��ǰhp
{
	return hp;
}

int __PLAYER::getCombo()         //��ȡ��ǰ����ֵ
{
	return combo;
}

int __PLAYER::getSkill()
{
	return skillType;
}

void __PLAYER::jump()		    //��Ծ
{
	y = (int)((20 - jumpState)*(20 - jumpState)*0.125 + 350);
	jumpState++;
	if (jumpState > 40){
		jumpState = 0;
		isJump = false;
	}
}

void __PLAYER::moveX(IMAGE* player)		//�����ƶ� 
{
	isRun = true;
	if (movespd != 0)
		still = -1;
	if (runState < 16)runState++;
	x += movespd; 
	if (x < 10){
		x = 10 - (10 - x);
		movespd = -movespd;
	}
	if (x > 3016){
		x = 3016 - (3016 - x);
		movespd = -movespd;
	}
	if (runState > 12&&runState<=16)loadimage(player, "pic/ll4.jpg");
	if (runState > 8&&runState<13)loadimage(player, "pic/ll3.jpg");
	if (runState > 4&&runState<9)loadimage(player, "pic/ll2.jpg");
	if (runState > 0&&runState<5)loadimage(player, "pic/ll1.jpg");
	if (runState = 16)runState = 1;
}

bool __PLAYER::stillJudge()     //�ж��Ƿ�ֹ
{
	if (still==1)
		return true;
	else
		return false;
}

bool __PLAYER::attackJudge()
{
	return attacking;
}

bool __PLAYER::jumpJudge()
{
	if (isJump)
		return true;
	else 
		return false;
}

bool __PLAYER::getDir()
{
	return dir;
}

void __PLAYER::startJump()
{
	isJump = true;
	jumpState = 1;
}

void __PLAYER::useSkill(int skillnum)
{
	switch (skillnum){
	case 1:skillType = 1, skillState = 1; break;
	default:break;
	}
}

void __PLAYER::meleeAttack(int enemy[], int enemyhp[], int num)
{
	attacking = true;
	skillType = 1;
	skillState = 1;
	//�����ж�
	switch (dir){
	case 0:{
		for (int i = 0; i < num; i++){
			if ((x - enemy[i]) <= 100)
				map.setEnemyHp(i, enemyhp[i] - attack);
		}
	}break;
	case 1:{
		for (int i = 0; i < num; i++){
			if ((enemy[i] - x) <= 100)
				map.setEnemyHp(i, enemyhp[i] - attack);
		}
	}break;
	}
	
	
}

int __PLAYER::getStill()
{
	return still;
}

//��ʼ���ú���

void __PLAYER::teleport(int x1, int y1)	//������Ҵ���
{
	x = x1;
	y = y1;
}

void __PLAYER::setHp(int num)
{
	hp = num;
}

void __PLAYER::setAttack(int num)
{
	attack = num;
}

void __PLAYER::setMaxHp(int num)
{
	maxhp = num;
}

void __PLAYER::setSpd(int num)
{
	movespd = num;
}

void __PLAYER::setDir(bool num)
{
	dir = num;
}

void __PLAYER::setCombo(int num)
{
	combo = num;
}

void __PLAYER::setSkillState(int num)
{
	skillState = num;
}

void __PLAYER::setSkillType(int num)
{
	skillType = num;
}

void __PLAYER::setStill(int num)
{
	still = num;
}

void __PLAYER::setRunState(int num)
{
	runState = num;
}