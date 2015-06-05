#include "player.h"
#include "enemy.h"
#include "map.h"
#include "mainframe.h"
#include "skilllist.h"

__PLAYER::__PLAYER()
{
	teleport(300, 400);            //初始化__PLAYER数据
	setDir(1);
	setMaxHp(100);
	setHp(50);
	setAttack(10);
	setSpd(10);     //单位px
	setSkillState(0);
	setSkillType(0);
	isRun = false;
	isJump = false;
	attacking = false;
	runState = 0;
}

__PLAYER::~__PLAYER() {}

int __PLAYER::getX()	     //获取位置
{
	return x;
}

int __PLAYER::getY()
{
	return y;
}

int __PLAYER::getMovespd()//获取移动速度
{
	return movespd;
}
	
int __PLAYER::getAttack()        //获取攻击力
{
	return attack;
}

int __PLAYER::getHp()            //获取当前hp
{
	return hp;
}

int __PLAYER::getCombo()         //获取当前连击值
{
	return combo;
}

int __PLAYER::getSkill()
{
	return skillType;
}

void __PLAYER::jump()		    //跳跃
{
	y = (int)((20 - jumpState)*(20 - jumpState)*0.125 + 350);
	jumpState++;
	if (jumpState > 40){
		jumpState = 0;
		isJump = false;
	}
}

void __PLAYER::moveX(IMAGE* player)		//基本移动 
{
	isRun = true;
	if (runState <= 16)runState++;
	switch (dir){
	case 0:{
		x -= movespd; 
		if (x < 10)x = 10;
		if (runState > 12)loadimage(player, "pic/ll4.jpg");
		else if (runState > 8)loadimage(player, "pic/ll3.jpg");
		else if (runState > 4)loadimage(player, "pic/ll2.jpg");
		else if (runState > 0)loadimage(player, "pic/ll1.jpg");
	}break;
	case 1:{
		x += movespd;
		if (x > 3016)x = 3016;
		if (runState > 12)loadimage(player, "pic/rr4.jpg");
		else if (runState > 8)loadimage(player, "pic/rr3.jpg");
		else if (runState > 4)loadimage(player, "pic/rr2.jpg");
		else if (runState > 0)loadimage(player, "pic/rr1.jpg");
	}break;
	}
	if (runState = 17)runState = 1;
}

bool __PLAYER::stillJudge()     //判断是否静止
{
	if (still==1)
		return false;
	else
		return true;
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

void __PLAYER::stillput(int ox, IMAGE* player)
{
	switch (dir){
	case 0:{
		loadimage(player, "pic/lstill.jpg");
		mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
	}break;
	case 1:{
		loadimage(player, "pic/rstill.jpg");
		mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
	}break;
	}
}

void __PLAYER::skillEffect(IMAGE player, IMAGE pic250, IMAGE pic300)
{

}

void __PLAYER::meleeAttack(int enemy[], int enemyhp[], int num)
{
	attacking = true;
	skillType = 1;
	skillState = 1;
	//攻击判定
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

//初始化用函数

void __PLAYER::teleport(int x1, int y1)	//用于玩家传送
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