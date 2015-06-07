#include "player.h"
#include "mainframe.h"

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)

__PLAYER::__PLAYER()
{
	teleport(300, 400);            //初始化__PLAYER数据
	setDir(1);
	setMaxHp(100);
	setHp(50);
	setAttack(10);
	setSpd(0);
	setSkillState(0);
	setSkillType(0);
	isRun = false;
	isJump = false;
	coolDown = 0;
	runState = 0;
	still = 1;
	run = 0;
	combo = 0;
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

void __PLAYER::running(IMAGE* player, int ox)
{
	switch (dir){
	case 1:{
		run++;
		if (run >= 17)run = 1;

		if (run >= 4)runState = 2;
		if (run >= 8)runState = 3;
		if (run >= 12)runState = 4;
		if (run >= 16)runState = 1;
		switch (runState){
		case 1:loadimage(player, "pic/rr1.jpg"); break;
		case 2:loadimage(player, "pic/rr2.jpg"); break;
		case 3:loadimage(player, "pic/rr3.jpg"); break;
		case 4:loadimage(player, "pic/rr4.jpg"); break;
		}
		mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
	}break;
	case 0:{
		run++;
		if (run >= 17)run = 1;

		if (run >= 4)runState = 2;
		if (run >= 8)runState = 3;
		if (run >= 12)runState = 4;
		if (run >= 16)runState = 1;
		switch (runState){
		case 1:loadimage(player, "pic/ll1.jpg"); break;
		case 2:loadimage(player, "pic/ll2.jpg"); break;
		case 3:loadimage(player, "pic/ll3.jpg"); break;
		case 4:loadimage(player, "pic/ll4.jpg"); break;
		}
		mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
	}break;
	}
}

void __PLAYER::moveX()		//基本移动 
{
	x += movespd; 
	
	switch (dir){
	case 1:{
		if (x > 3016){
			x = 3016;
			
		}
	}break;
	case 0:{
		if (x <10){
			x = 10;
			
		}
	}break;
	}
}

bool __PLAYER::stillJudge()     //判断是否静止
{
	if (still==1)
		return true;
	else
		return false;
}

bool __PLAYER::runJudge()
{
	if(isRun)
		return true;
	return false;
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

void __PLAYER::meleeAttack(int enemyx, int enemyhp,__PLAYER enemy, IMAGE *player, IMAGE *enemyplayer, IMAGE *skillpic250, IMAGE *skillpic300, int originx)
{
	skillType = 1;
	skillState = 7;
	coolDown = 10;
	//攻击判定
	combo++;
	still = -10;
	switch (dir){
	case 0:{
		if ((x - enemy.getX()) <= 500 && (x - enemy.getX()) >= 0){         /****击中判断****/
			enemy.setHp(enemy.getHp()-attack);                                         //击中造成伤害
			enemy.setStill(-5);                                                  //击中造成僵直
			enemy.teleport(enemy.getX() - 10,enemy.getY());                                                     //击中造成击退
			loadimage(enemyplayer, "pic/enemylrunning3.jpg");                 //加载被击中时姿势
			mainFrame::M_putimg(enemy.x, enemy.y, enemyplayer, WHITE, 100, originx); /****击中判断结束****/
		}

		switch (combo){
		case 1:{
			loadimage(player, "pic/lattack1.jpg");
			loadimage(skillpic250, "pic/lcut1.jpg");
			mainFrame::M_putimg(x, y, player, WHITE,100, originx);
		}break;
		case 2:{
			loadimage(player, "pic/lattack2.jpg");
			loadimage(skillpic250, "pic/lcut2.jpg");
			x -= 100;
			if (x < 10)x = 10;
			mainFrame::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 3:{
			loadimage(player, "pic/lattack3.jpg");
			loadimage(skillpic300, "pic/lcut3.jpg");
			x -= 10;
			if (x < 10)x = 10;
			mainFrame::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	case 1:{
		if ((x - enemy.x) <= 100 && (x - enemy.x) >= 0){         /****击中判断****/
			enemy.hp -= attack;                                         //击中造成伤害
			enemy.still = -5;                                                  //击中造成僵直
			enemy.x -= 10;                                                     //击中造成击退
			/****击中判断结束****/
		}

		switch (combo){
		case 1:{
			loadimage(player, "pic/lattack1.jpg");
			loadimage(skillpic250, "pic/lcut1.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 2:{
			loadimage(player, "pic/lattack2.jpg");
			loadimage(skillpic250, "pic/lcut2.jpg");
			x += 100;
			if (x > 3016)x = 3016;
			mainFrame::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 3:{
			loadimage(player, "pic/lattack3.jpg");
			loadimage(skillpic300, "pic/lcut3.jpg");
			x += 10;
			if (x > 3016)x = 3016;
			mainFrame::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	}
}

int __PLAYER::getStill()
{
	return still;
}

void __PLAYER::restill()
{
	if (still<1)
		still++;
	if (still == 1){
		isRun = false;
		run = 0;
		runState = 0;
	}
}

int __PLAYER::getSkillState()
{
	return skillState;
}

int __PLAYER::getRunState()
{
	return runState;
}

void __PLAYER::skillEffect(IMAGE *skillpic250, IMAGE *skillpic300, int ox)
{
	switch (skillType){               //判断技能种类(0为无技能)
	case 1:{                            //普通攻击
		switch (combo){                 //根据combo判断技能图片
		case 1:{
			y -= 25;                //技能图片位置修正
			x -= 85;
			loadimage(skillpic250, "pic/lcut1.jpg");
			mainFrame::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
			y += 25;                 //技能图片位置修正后还原
			x += 85;
		}break;
		case 2:{
			y -= 50;
			x -= 65;
			loadimage(skillpic250, "pic/lcut2.jpg");
			mainFrame::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
			y += 50;
			x += 65;
		}break;
		case 3:{
			y -= 80;
			x -= 105;
			loadimage(skillpic300, "pic/lcut3.jpg");
			mainFrame::M_putimg(x, y, skillpic300, WHITE, 10 * skillState, ox);
			y += 80;
			x += 105;
			if (combo == 3 && skillState == 1)combo = 0;
		}break;
		}
	}
	}
}

void __PLAYER::startRun()
{
	isRun = true;
}

void __PLAYER::coolingDown()
{
	coolDown--;
	if (coolDown < 0)
		coolDown = 0;
}

bool __PLAYER::coolingJudge()
{
	if (coolDown > 0)
		return true;
	return false;
}

void __PLAYER::skillStateMove()
{
	if (skillState > 0)
		skillState--;
	if (skillState < 0)
		skillState = 0;

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

void __PLAYER::setRunState(int num)
{
	runState = num;
	if (num > 0)
		isRun = true;
	
}

void __PLAYER::setRun(int num)
{
	run = num;
	if (num == 0)
		isRun = 0;
}