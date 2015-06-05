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
}

__PLAYER::~__PLAYER() {}

int kirito::getX()	     //获取位置
{
	return x;
}

int kirito::getY()
{
	return y;
}

int kirito::getMovespd()//获取移动速度
{
	return movespd;
}
	
int kirito::getAttack()        //获取攻击力
{
	return attack;
}

int kirito::getHp()            //获取当前hp
{
	return hp;
}

int kirito::getCombo()         //获取当前连击值
{
	return combo;
}

int kirito::getSkill()
{
	return skillType;
}

void kirito::jump()		    //跳跃
{
	switch (jumpState){
	case 1:y -= 40,jumpState++; break;
	case 2:y -= 30, jumpState++; break;
	case 3:y -= 20, jumpState++; break;
	case 4:y -= 10, jumpState++; break;
	case 5:jumpState++; break;
	case 6:y += 10, jumpState++; break;
	case 7:y += 20, jumpState++; break;
	case 8:y += 30, jumpState++; break;
	case 9:y += 40, isJump = false,jumpState=0; break;
	default:break;
	}
}

void kirito::moveX(IMAGE player)		//基本移动 
{
	isRun = true;
	if (runState <= 16)runState++;
	switch (kirito::getDir()){
	case 0:{
		x -= kirito::getMovespd(); 
		if (kirito::runState > 12)loadimage(&player, "pic/ll4.jpg");
		else if (kirito::runState > 8)loadimage(&player, "pic/ll3.jpg");
		else if (kirito::runState > 4)loadimage(&player, "pic/ll2.jpg");
		else if (kirito::runState > 0)loadimage(&player, "pic/ll1.jpg");
	}break;
	case 1:{
		x += getMovespd();
		if (kirito::runState > 12)loadimage(&player, "pic/rr4.jpg");
		else if (kirito::runState > 8)loadimage(&player, "pic/rr3.jpg");
		else if (kirito::runState > 4)loadimage(&player, "pic/rr2.jpg");
		else if (kirito::runState > 0)loadimage(&player, "pic/rr1.jpg");
	}break;
	}
	if (runState = 17)runState = 1;
}

bool kirito::stillJudge()     //判断是否静止
{
	if (isRun || isJump || attacking)
		return false;
	else
		return true;
}

bool kirito::jumpJudge()
{
	if (isJump)return true;
	else return false;
}

bool kirito::getDir()
{
	return dir;
}

void kirito::startJump()
{
	isJump = 1;
	jumpState = 1;
}

void kirito::useSkill(int skillnum)
{
	switch (skillnum){
	case 1:skillType = 1, skillState = 1, combo = 1; break;
	default:break;
	}
}

void kirito::still(int ox, IMAGE player)
{
	switch (dir){
	case 0:{
		loadimage(&player, "pic/lstill.jpg");
		mainFrame::M_putimg(x, y, &player, WHITE, 100, ox);
	}break;
	case 1:{
		loadimage(&player, "pic/rstill.jpg");
		mainFrame::M_putimg(x, y, &player, WHITE, 100, ox);
	}break;
	}
}

void kirito::skillEffect(IMAGE player,IMAGE pic250,IMAGE pic300)
{

}

void kirito::meleeAttack(int enemy[],int enemyhp[],int num)
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

//初始化用函数

void kirito::teleport(int x1, int y1)	//用于玩家传送
{
	x = x1;
	y = y1;
}

void kirito::setHp(int num)
{
	hp = num;
}

void kirito::setAttack(int num)
{
	attack = num;
}

void kirito::setMaxHp(int num)
{
	maxhp = num;
}

void kirito::setSpd(int num)
{
	movespd = num;
}

void kirito::setDir(bool num)
{
	dir = num;
}

void kirito::setCombo(int num)
{
	combo = num;
}

void kirito::setSkillState(int num)
{
	skillState = num;
}

void kirito::setSkillType(int num)
{
	skillType = num;
}