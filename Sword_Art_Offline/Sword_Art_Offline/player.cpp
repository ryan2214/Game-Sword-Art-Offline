#include "player.h"
#include "skilllist.h"

__PLAYER::__PLAYER() {}

__PLAYER::~__PLAYER() {}

int kirito::getx()	     //获取位置
{
	return x;
}

int kirito::gety()
{
	return y;
}

int kirito::getmovespd()//获取移动速度
{
	return movespeed;
}
	
int kirito::getattack()        //获取攻击力
{
	return attack;
}

int kirito::gethp()            //获取当前hp
{
	return hp;
}

int kirito::getskill()         //获取当前释放技能编号
{
	return skilltype;
}

int kirito::getcombo()         //获取当前连击值
{
	return combo;
}

void kirito::teleport(int x1, int y1)	//用于玩家传送
{
	x = x1;
	y = y1;
}

void kirito::jump(int state)		    //跳跃
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

void kirito::movex()		//基本移动 
{
	switch (getdir()){
	case 0:x -= getmovespd(); break;
	case 1:x += getmovespd(); break;
	}
}

void kirito::castskill(int skillnum)    //释放技能（技能编号）
{
	if (__SKILLLIST::ableToCast(skillnum))
}
bool stilljudge();      //判断是否静止
bool lifejudge();       //存活确认