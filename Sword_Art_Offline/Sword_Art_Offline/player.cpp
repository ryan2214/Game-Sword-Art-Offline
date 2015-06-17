#include "player.h"
#include "mainframe.h"
#include <math.h>

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)

#define INIT_X 300
#define INIT_Y 400
#define INIT_DIR 1
#define INIT_MAXHP 250
#define INIT_HP 250
#define INIT_ATTACK 50
#define INIT_MOVESPD 0
#define INIT_SKILLSTATE 0
#define INIT_SKILLTYPE 0
#define INIT_ISRUN false
#define INIT_ISJUMP false
#define INIT_COOLDOWN 0
#define INIT_RUNSTATE 0
#define INIT_JUMPSTATE 0
#define INIT_STILL 1
#define INIT_RUN 0
#define INIT_COMBO 0
#define INIT_EXP 0
#define INIT_LEVEL 1
#define INIT_HPRE 0.1

#define INIT_SONICLEAP_RANGE 800
#define INIT_MELEEATTACK_RANGE 150
#define INIT_HS_RANGE 200

#define INIT_FINDRANGE 500

PLAYER::PLAYER()
{
	x = INIT_X;            //初始化__PLAYER数据
	y = INIT_Y;
	dir = INIT_DIR;
	maxhp = INIT_MAXHP;
	hp = maxhp;
	attack = INIT_ATTACK;
	movespd = INIT_MOVESPD;
	skillState = INIT_SKILLSTATE;
	skillType = INIT_SKILLTYPE;
	isRun = INIT_ISRUN;
	isJump = INIT_ISJUMP;
	coolDown = INIT_COOLDOWN;
	runState = INIT_RUNSTATE;
	jumpState = INIT_JUMPSTATE;
	still = INIT_STILL;
	run = INIT_RUN;
	combo = INIT_COMBO;
	exp = INIT_EXP;
	level = INIT_LEVEL;
	hpregen = INIT_HPRE;
	type = 0;
	SOUND = true;
}

PLAYER::~PLAYER() {}

int PLAYER::getX()	     //获取位置
{
	return x;
}

int PLAYER::getY()
{
	return y;
}

int PLAYER::getMovespd()//获取移动速度
{
	return movespd;
}
	
int PLAYER::getAttack()        //获取攻击力
{
	return attack;
}

float PLAYER::getHp()            //获取当前hp
{
	return hp;
}

int PLAYER::getCombo()         //获取当前连击值
{
	return combo;
}

int PLAYER::getSkill()
{
	return skillType;
}

int PLAYER::getRun()
{
	return run;
}

void PLAYER::jump()		    //跳跃
{
	y = (int)((15 - jumpState)*(15 - jumpState)*0.6 + 265);
	jumpState++;
	if (jumpState > 30){
		jumpState = 0;
		isJump = false;
	}
}

void PLAYER::running(IMAGE* player, int ox,PLAYER *p)
{
	switch ((*p).getType()){
	case 0:{
		switch ((*p).getDir()){
		case 1:{
			(*p).setRun((*p).getRun() + 1);
			if ((*p).getRun() >= 17)(*p).setRun(1);

			if ((*p).getRun() >= 4)(*p).setRunState(2);
			if ((*p).getRun() >= 8)(*p).setRunState(3);
			if ((*p).getRun() >= 12)(*p).setRunState(4);
			if ((*p).getRun() >= 16)(*p).setRunState(1);
			switch ((*p).getRunState()){
			case 1:loadimage(player, "pic/rr1.jpg", 180, 185, true); break;
			case 2:loadimage(player, "pic/rr2.jpg", 180, 185, true); break;
			case 3:loadimage(player, "pic/rr3.jpg", 180, 185, true); break;
			case 4:loadimage(player, "pic/rr4.jpg", 180, 185, true); break;
			}
			MAINFRAME::M_putimg((*p).getX(), (*p).getY(), player, WHITE, 100, ox);
		}break;
		case 0:{
			(*p).setRun((*p).getRun() + 1);
			if ((*p).getRun() >= 17)(*p).setRun(1);

			if ((*p).getRun() >= 4)(*p).setRunState(2);
			if ((*p).getRun() >= 8)(*p).setRunState(3);
			if ((*p).getRun() >= 12)(*p).setRunState(4);
			if ((*p).getRun() >= 16)(*p).setRunState(1);
			switch ((*p).getRunState()){
			case 1:loadimage(player, "pic/ll1.jpg", 180, 185, true); break;
			case 2:loadimage(player, "pic/ll2.jpg", 180, 185, true); break;
			case 3:loadimage(player, "pic/ll3.jpg", 180, 185, true); break;
			case 4:loadimage(player, "pic/ll4.jpg", 180, 185, true); break;
			}
			MAINFRAME::M_putimg((*p).getX(), (*p).getY(), player, WHITE, 100, ox);
		}break;
		}
	}break;
	case 9:{
		switch ((*p).getDir()){
		case 1:{
			(*p).setRun((*p).getRun() + 1);
			if ((*p).getRun() >= 17)(*p).setRun(1);

			if ((*p).getRun() >= 4)(*p).setRunState(2);
			if ((*p).getRun() >= 8)(*p).setRunState(3);
			if ((*p).getRun() >= 12)(*p).setRunState(4);
			if ((*p).getRun() >= 16)(*p).setRunState(1);
			switch ((*p).getRunState()){
			case 1:loadimage(player, "pic/enemyrrunning1.jpg", 180, 185, true); break;
			case 2:loadimage(player, "pic/enemyrrunning2.jpg", 180, 185, true); break;
			case 3:loadimage(player, "pic/enemyrrunning3.jpg", 180, 185, true); break;
			case 4:loadimage(player, "pic/enemyrrunning4.jpg", 180, 185, true); break;
			}
			MAINFRAME::M_putimg((*p).getX(), (*p).getY(), player, WHITE, 100, ox);
		}break;
		case 0:{
			(*p).setRun((*p).getRun() + 1);
			if ((*p).getRun() >= 17)(*p).setRun(1);

			if ((*p).getRun() >= 4)(*p).setRunState(2);
			if ((*p).getRun() >= 8)(*p).setRunState(3);
			if ((*p).getRun() >= 12)(*p).setRunState(4);
			if ((*p).getRun() >= 16)(*p).setRunState(1);
			switch ((*p).getRunState()){
			case 1:loadimage(player, "pic/enemylrunning1.jpg", 180, 185, true); break;
			case 2:loadimage(player, "pic/enemylrunning2.jpg", 180, 185, true); break;
			case 3:loadimage(player, "pic/enemylrunning3.jpg", 180, 185, true); break;
			case 4:loadimage(player, "pic/enemylrunning4.jpg", 180, 185, true); break;
			}
			MAINFRAME::M_putimg((*p).getX(), (*p).getY(), player, WHITE, 100, ox);
		}break;
		}
	}break;
	}
	
}

void PLAYER::moveX(int *leftlimit,int *rightlimit)		//基本移动 
{
	x += movespd; 
	
	switch (dir){
	case 1:{
		if (x > (*rightlimit - 190)){
			x = (*rightlimit - 190);
			
		}
	}break;
	case 0:{
		if (x <(10 + *leftlimit)){
			x = (10 + *leftlimit);
			
		}
	}break;
	}
}

bool PLAYER::stillJudge()     //判断是否静止
{
	if (still==1)
		return true;
	else  if (still<1)
		return false;
}

bool PLAYER::runJudge()
{
	if(isRun)
		return true;
	return false;
}

bool PLAYER::jumpJudge()
{
	if (isJump)
		return true;
	else 
		return false;
}

bool PLAYER::getDir()
{
	return dir;
}

void PLAYER::startJump()
{
	isJump = true;
	jumpState = 1;
	soundEffect(5);
}

void PLAYER::useSkill(int skillnum)
{
	switch (skillnum){
	case 1:skillType = 1, skillState = 1; break;
	default:break;
	}
}

void PLAYER::meleeAttack(int *enemyx, int *enemyhp, PLAYER *enemy, IMAGE *player, IMAGE *enemyplayer, IMAGE *skillpic250, IMAGE *skillpic300, int originx)
{
	skillType = 1;
	skillState = 10;
	coolDown = 10;
	//攻击判定
	combo++;
	still = -10;
	soundEffect(2);
	switch (dir){
	case 0:{
		if ((x - (*enemy).getX()) <= INIT_MELEEATTACK_RANGE && (x - (*enemy).getX()) >= 0){         /****击中判断****/
			(*enemy).setHp((*enemy).getHp() - attack);                                  //击中造成伤害
			(*enemy).setStill(-15);                                                 //击中造成僵直
			(*enemy).setSpd(-10);	
			(*enemy).setRun(0);														//击中造成击退
			if ((*enemy).getType()==9){
				loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
				MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, originx); /****击中判断结束****/
			}
			if ((*enemy).getType() == 10){
				loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
				MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, originx);
			}
		}

		switch (combo){
		case 1:{
			loadimage(player, "pic/lattack1.jpg");
			loadimage(skillpic250, "pic/lcut1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 2:{
			loadimage(player, "pic/lattack2.jpg");
			loadimage(skillpic250, "pic/lcut2.jpg");
			x -= 50;
			movespd = -10;
			if (x < 10)x = 10;
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 3:{
			loadimage(player, "pic/lattack3.jpg");
			loadimage(skillpic300, "pic/lcut3.jpg");
			movespd = -4 ;
			if (x < 10)x = 10;
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	case 1:{
		if (((*enemy).getX() - x) <= INIT_MELEEATTACK_RANGE && ((*enemy).getX() - x) >= 0){         /****击中判断****/
			(*enemy).setHp((*enemy).getHp() - attack);                                  //击中造成伤害
			(*enemy).setStill(-15);                                                 //击中造成僵直
			(*enemy).setSpd(10);
			(*enemy).setRun(0);		                   //击中造成击退
			if ((*enemy).getType() == 9){
				loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
				MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, originx); /****击中判断结束****/
			}
			if ((*enemy).getType() == 10){
				loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
				MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, originx);
			}
		}

		switch (combo){
		case 1:{
			loadimage(player, "pic/rattack1.jpg");
			loadimage(skillpic250, "pic/rcut1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 2:{
			loadimage(player, "pic/rattack2.jpg");
			loadimage(skillpic250, "pic/rcut2.jpg");
			x += 50;
			movespd = 10;
			if (x < 10)x = 10;
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		case 3:{
			loadimage(player, "pic/rattack3.jpg");
			loadimage(skillpic300, "pic/rcut3.jpg");
			movespd = 4;
			if (x < 10)x = 10;
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	
	}
}

void PLAYER::sonicLeap(int *enemyx, int *enemyhp, PLAYER *enemy, IMAGE *player, IMAGE *enemyplayer, IMAGE *skillpic250, IMAGE *skillpic300, int originx)
{
	skillType = 2;
	skillState = 50;
	coolDown = 50;
	//攻击判定
	combo++;
	soundEffect(8);
	still = -50;
	switch (dir){
	case 0:{
		switch (combo){
		case 1:{
			loadimage(player, "pic/lsonicleap-2.jpg");
			loadimage(skillpic250, "pic/lsonicleap-1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	case 1:{
		
		switch (combo){
		case 1:{
			loadimage(player, "pic/rsonicleap-2.jpg");
			loadimage(skillpic250, "pic/rsonicleap-1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;

	}
}

void PLAYER::horizontalSquare(int *enemyx, int *enemyhp, PLAYER *enemy, IMAGE *player, IMAGE *enemyplayer, IMAGE *skillpic250, IMAGE *skillpic300, int originx)
{
	skillType = 3;
	skillState = 50;
	coolDown = 50;
	//攻击判定
	combo++;
	still = -50;
	soundEffect(2);
	switch (dir){
	case 0:{
		switch (combo){
		case 1:{
			loadimage(player, "pic/fourdash-2.jpg");
			loadimage(skillpic250, "pic/fourdash-1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;
	case 1:{
		switch (combo){
		case 1:{
			loadimage(player, "pic/rfourdash-2.jpg");
			loadimage(skillpic250, "pic/rfourdash-1.jpg");
			MAINFRAME::M_putimg(x, y, player, WHITE, 100, originx);
		}break;
		}
	}break;

	}
}

int PLAYER::getStill()
{
	return still;
}

void PLAYER::restill()
{
	if (still<1)
		still++;
	if (still == 1){
		isRun = false;
		run = 0;
		runState = 0;
	}
}

int PLAYER::getSkillState()
{
	return skillState;
}

int PLAYER::getRunState()
{
	return runState;
}

void PLAYER::skillEffect(IMAGE *skillpic250, IMAGE *skillpic300, IMAGE *player, IMAGE *enemyplayer, PLAYER *enemy, int ox)
{
	switch (skillType){               //判断技能种类(0为无技能)
	case 1:{                            //普通攻击
		switch (dir){
		case 0:{
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				y -= 25;                //技能图片位置修正
				x -= 85;
				loadimage(skillpic250, "pic/lcut1.jpg", 250, 250, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
				y += 25;                 //技能图片位置修正后还原
				x += 85;
			}break;
			case 2:{
				y -= 50;
				x -= 65;
				loadimage(skillpic250, "pic/lcut2.jpg", 250, 250, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
				y += 50;
				x += 65;
			}break;
			case 3:{
				y -= 80;
				x -= 105;
				loadimage(skillpic300, "pic/lcut3.jpg", 300, 300, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 10 * skillState, ox);
				y += 80;
				x += 105;
				if (combo == 3 && skillState == 1)combo = 0;
			}break;
			}
		}break;
		case 1:{
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				y -= 25;                //技能图片位置修正
				x += 0;
				loadimage(skillpic250, "pic/rcut1.jpg", 250, 250, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
				y += 25;                 //技能图片位置修正后还原
				x -= 0;
			}break;
			case 2:{
				y -= 47;
				x += 0;
				loadimage(skillpic250, "pic/rcut2.jpg", 250, 250, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
				y += 47;
				x -= 0;
			}break;
			case 3:{
				y -= 82;
				x -= 0;
				loadimage(skillpic300, "pic/rcut3.jpg", 300, 300, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 10 * skillState, ox);
				y += 82;
				x += 0;
				if (combo == 3 && skillState == 1)combo = 0;
			}break;
			}
		}break;
		}

	}break;//技能1结束

	case 2:{                            //音速冲击
		switch (dir){
		case 0:{
			if (skillState <= 30)combo = 2;  //由skillState确定combo
			if (skillState <= 20)combo = 3;

			switch (combo){                 //根据combo判断技能图片
			case 1:{
				//技能图片位置修正
				loadimage(skillpic250, "pic/lsonicleap-1.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 5 * (skillState - 30), ox);
				//技能图片位置修正后还原
			}break;
			case 2:{
				if (skillState == 30){
					x -= 110;
					movespd = -80;
				}
				loadimage(player, "pic/lsonicleap-3.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);

				x -= 340;
				loadimage(skillpic300, "pic/sonicleap_flash.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 10 * (skillState - 20), ox);

				if ((x - (*enemy).getX()) <= INIT_SONICLEAP_RANGE && (x - (*enemy).getX()) >= 0){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-50);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				x += 340;
			}break;
			case 3:{
				if (skillState == 20)x -= 110;

				loadimage(player, "pic/lsonicleap-4.jpg", 354, 185, true);

				movespd = -2;
				if (skillState == 1){
					combo = 0;
					x += 110;
				}
				if (skillState == 1 || skillState == 0)
					loadimage(player, "pic/lstill.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
			}break;
			}
		}break;
		case 1:{
			if (skillState <= 30)combo = 2;  //由skillState确定combo
			if (skillState <= 20)combo = 3;
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				//技能图片位置修正
				loadimage(skillpic250, "pic/rsonicleap-1.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 5 * (skillState - 30), ox);
				//技能图片位置修正后还原
			}break;
			case 2:{
				if (skillState == 30){
					x -= 110;
					movespd = 80;
				}
				loadimage(player, "pic/rsonicleap-3.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);

				loadimage(skillpic300, "pic/sonicleap_flash.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 10 * (skillState - 20), ox);

				if (((*enemy).getX() - x) <= INIT_SONICLEAP_RANGE && ((*enemy).getX() - x) >= 0){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-50);                                                 //击中造成僵直
					(*enemy).setSpd(0);                    //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}

			}break;
			case 3:{
				if (skillState == 20)x -= 110;

				loadimage(player, "pic/rsonicleap-4.jpg", 354, 185, true);

				movespd = 2;
				if (skillState == 1){
					combo = 0;
					x += 110;
				}
				if (skillState == 1 || skillState == 0)
					loadimage(player, "pic/rstill.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
			}break;
			}
		}break;
		}

	}break;//技能2结束
	case 3:{                            //水平四方斩horizontalsquare
		switch (dir){
		case 0:{
			if (skillState <= 35)combo = 2;  //由skillState确定combo
			if (skillState <= 30)combo = 3;
			if (skillState <= 25)combo = 4;
			if (skillState <= 20)combo = 5;
			if (skillState <= 15)combo = 6;
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				//技能图片位置修正
				loadimage(skillpic250, "pic/fourdash-1.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 6 * (skillState - 35), ox);
				Sleep(30);
				//技能图片位置修正后还原
			}break;
			case 2:{                     //第1击
				if (skillState == 35){
					x -= 110;
					movespd = -150;
					soundEffect(6);
				}
				if (skillState < 34){
					movespd = 0;
					Sleep(10);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);            //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/fourdash-3.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				x -= 75;												//加特技
				loadimage(skillpic300, "pic/foursp-1.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 30), ox);
				x += 75;
			}break;
			case 3:{						//第2击
				if (skillState == 30){
					movespd = 150;
				}
				if (skillState < 29){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/fourdash-4.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				x -= 25;
				y -= 20;
				loadimage(skillpic300, "pic/foursp-2.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 25), ox);
				x += 25;
				y += 20;
			}break;
			case 4:{						//第3击
				if (skillState == 25){
					movespd = -150;
				}
				if (skillState < 24){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/fourdash-5.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				y -= 30;
				x -= 13;
				loadimage(skillpic300, "pic/foursp-3.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 20), ox);
				y += 30;
				x += 13;
			}break;
			case 5:{							//第4击
				if (skillState == 20){
					movespd = 150;
				}
				if (skillState < 19){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/fourdash-6.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);

				loadimage(skillpic300, "pic/foursp-4.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 15), ox);

			}break;
			case 6:{							//收尾

				loadimage(player, "pic/fourdash-6.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				if (skillState > 0 && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5-6.jpg", 340, 185, true);
				if (skillState>3 && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5-4.jpg", 340, 185, true);
				if ((skillState>6) && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5.jpg", 340, 185, true);
				MAINFRAME::M_putimg((*enemy).getX() - 110, y, skillpic300, WHITE, 6 * skillState, ox);

				if (skillState == 1){
					combo = 0;
					x += 110;
				}
				if (skillState == 1 || skillState == 0){
					loadimage(player, "pic/rstill.jpg", 180, 185, true);
					dir = 1;
				}
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
			}break;

			}
		}break;
		case 1:{
			if (skillState <= 35)combo = 2;  //由skillState确定combo
			if (skillState <= 30)combo = 3;
			if (skillState <= 25)combo = 4;
			if (skillState <= 20)combo = 5;
			if (skillState <= 15)combo = 6;
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				//技能图片位置修正
				loadimage(skillpic250, "pic/rfourdash-1.jpg", 180, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic250, WHITE, 6 * (skillState - 35), ox);
				Sleep(30);
				//技能图片位置修正后还原
			}break;
			case 2:{                     //第1击
				if (skillState == 35){
					x -= 110;
					movespd = +150;
					soundEffect(6);
				}
				if (skillState < 34){
					movespd = 0;
					Sleep(10);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);            //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/rfourdash-3.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				x += 75;												//加特技
				loadimage(skillpic300, "pic/rfoursp-1.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 30), ox);
				x -= 75;
			}break;
			case 3:{						//第2击
				if (skillState == 30){
					movespd = -150;
				}
				if (skillState < 29){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/rfourdash-4.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				x -= 25;
				y -= 20;
				loadimage(skillpic300, "pic/rfoursp-2.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 25), ox);
				x += 25;
				y += 20;
			}break;
			case 4:{						//第3击
				if (skillState == 25){
					movespd = 150;
				}
				if (skillState < 24){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemylhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg", 425, 425, true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/rfourdash-5.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				y -= 30;
				x += 13;
				loadimage(skillpic300, "pic/rfoursp-3.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 20), ox);
				y += 30;
				x -= 13;
			}break;
			case 5:{							//第4击
				if (skillState == 20){
					movespd = -150;
				}
				if (skillState < 19){
					movespd = 0;
					Sleep(30);
				}
				if ((x - (*enemy).getX()) <= INIT_HS_RANGE || ((*enemy).getX() - x) <= INIT_HS_RANGE){         /****击中判断****/
					(*enemy).setHp((*enemy).getHp() - (2 + logf(level))*attack*0.2);                                  //击中造成伤害
					(*enemy).setStill(-90);                                                 //击中造成僵直
					(*enemy).setSpd(0);												   //击中造成僵直
					if ((*enemy).getType() == 9){
						loadimage(enemyplayer, "pic/enemyrhit.jpg");                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y, enemyplayer, WHITE, 100, ox); /****击中判断结束****/
					}
					if ((*enemy).getType() == 10){
						loadimage(enemyplayer, "pic/GEdie-1.jpg",425,425,true);                   //加载被击中时姿势
						MAINFRAME::M_putimg((*enemy).x, (*enemy).y - 425 + 185, enemyplayer, WHITE, 100, ox);
					}
				}
				loadimage(player, "pic/rfourdash-6.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);

				loadimage(skillpic300, "pic/rfoursp-4.jpg", 340, 185, true);
				MAINFRAME::M_putimg(x, y, skillpic300, WHITE, 20 * (skillState - 15), ox);

			}break;
			case 6:{							//收尾

				loadimage(player, "pic/rfourdash-6.jpg", 354, 185, true);
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
				if (skillState > 0 && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5-6.jpg", 340, 185, true);
				if (skillState>3 && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5-4.jpg", 340, 185, true);
				if ((skillState>6) && (skillState < 10))
					loadimage(skillpic300, "pic/foursp-5.jpg", 340, 185, true);
				MAINFRAME::M_putimg((*enemy).getX() - 110, y, skillpic300, WHITE, 6 * skillState, ox);

				if (skillState == 1){
					combo = 0;
					x += 110;
				}
				if (skillState == 1 || skillState == 0){
					loadimage(player, "pic/lstill.jpg", 180, 185, true);
					dir = 0;
				}
				MAINFRAME::M_putimg(x, y, player, WHITE, 100, ox);
			}break;

			}
		}break;
		}

	}break;//技能2结束
	}
	
	
	
}

void PLAYER::startRun()
{
	isRun = true;
}

void PLAYER::coolingDown()
{
	coolDown--;
	if (coolDown < 0)
		coolDown = 0;
}

bool PLAYER::coolingJudge()
{
	if (coolDown > 0)
		return true;
	return false;
}

float PLAYER::getMaxHp()
{
	return maxhp;
}

void PLAYER::AIFind(int *xf)
{
	if (type != 10){
		if (*xf - x <= INIT_FINDRANGE && *xf - x > 100){
			dir = 1;         //改变方向
			still = -5;         //开始跑动
			runState = 1;	 //使runState为1
			movespd = 5;
			isRun = true;
		}
		if (x - *xf <= INIT_FINDRANGE && x - *xf > 100){
			dir = 0;         //改变方向
			still = -5;         //开始跑动
			runState = 1;	 //使runState为1
			movespd = -5;
			isRun = true;
		}
		if (x == *xf){
			movespd = 0;
			still = 1;
			runState = 0;
		}
	}
	if (type == 10){
		if (*xf - x <= INIT_FINDRANGE && *xf - x > 100){
			dir = 1;         //改变方向
		}
		if (x - *xf <= INIT_FINDRANGE && x - *xf > 100){
			dir = 0;         //改变方向
		}
	}
}

void PLAYER::AIAttack(PLAYER *player,IMAGE *enemy)
{
	if (((*player).getY() - y<100 && (*player).getY() - y>0) || (y - (*player).getY()<100 && y - (*player).getY() >= 0)&&run==0)
		switch (type)
	{
		case 1:
		case 2:
		case 9:{
			switch (dir){
			case 0:{
				loadimage(enemy, "pic/enemylattack.jpg");
				if ((x - (*player).getX()) <= INIT_MELEEATTACK_RANGE && (x - (*player).getX()) >= 0){         /****击中判断****/
					(*player).setHp(((*player).getHp() - attack));                                  //击中造成伤害
					(*player).setStill(-15);                                                 //击中造成僵直
					(*player).setSpd(-5);												   //击中造成击退
				}
			}break;
			case 1:{
				loadimage(enemy, "pic/enemyrattack.jpg");
				if (((*player).getX() - x) <= INIT_MELEEATTACK_RANGE && ((*player).getX() - x) >= 0){         /****击中判断****/
					(*player).setHp(((*player).getHp() - attack));                                  //击中造成伤害
					(*player).setStill(-15);                                                 //击中造成僵直
					(*player).setSpd(5);													 //击中造成击退
					skillType = 1;
				}
			}break;
			}
			still = -20;
		}break;
		case 10:{
			skillType = 1;
			skillState = 50;
			coolDown = 50;
			//攻击判定
			combo++;
			still = -50;
			soundEffect(9);
			switch (dir){
			case 0:{
				if ((x - (*player).getX()) <= 2*INIT_MELEEATTACK_RANGE && (x - (*player).getX()) >= 0){         /****击中判断****/
					(*player).setHp((*player).getHp() - attack);                                  //击中造成伤害
					(*player).setStill(-15);                                                 //击中造成僵直
					(*player).setSpd(-10);
					(*player).setRun(0);														//击中造成击退
					/****击中判断结束****/
				}

				switch (combo){
				case 1:{
					loadimage(enemy, "pic/GEattack1-1.jpg",425,425,true);
				}break;
				case 2:{
					loadimage(enemy, "pic/GEattack1-2.jpg",567,425,true);
				}break;
				case 3:{
					loadimage(enemy, "pic/GEattack3-1.jpg",425,510,true);
				}break;
				case 4:{
					loadimage(enemy, "pic/GEattack3-2.jpg",510,425,true);
				}break;
				}
				if (combo == 4)combo = 0;
			}break;
			case 1:{
				if (((*player).getX() - x) <= 2*INIT_MELEEATTACK_RANGE && ((*player).getX() - x) >= 0){         /****击中判断****/
					(*player).setHp((*player).getHp() - attack);                                  //击中造成伤害
					(*player).setStill(-15);                                                 //击中造成僵直
					(*player).setSpd(-10);
					(*player).setRun(0);														//击中造成击退
					/****击中判断结束****/
				}

				switch (combo){
				case 1:{
					loadimage(enemy, "pic/GErattack1-1.jpg", 425, 425, true);
				}break;
				case 2:{
					loadimage(enemy, "pic/GErattack1-2.jpg", 567, 425, true);
				}break;
				case 3:{
					loadimage(enemy, "pic/GErattack3-1.jpg", 425, 510, true);
				}break;
				case 4:{
					loadimage(enemy, "pic/GErattack3-2.jpg", 510, 425, true);
				}break;
				}
			}break;

			}
			if (combo == 4)combo = 0;
		}break;
	}
}

void PLAYER::levelUp()
{
	level++;
	statRefresh();
	hp = maxhp;
}

void PLAYER::statRefresh()
{
	attack = level * 20+30;
	maxhp = level * 250;
	hpregen = level*0.1;
}

int PLAYER::getExp()
{
	return exp;
}

int PLAYER::getLev()
{
	return level;
}

void PLAYER::setExp(int num)
{

	exp = num;
}

void PLAYER::expAdd(int num)
{
	exp += num;
}

void PLAYER::levelUpCheck()
{
	if (exp >= 25*level*level + level * 5 + 20)
		levelUp();
}

int PLAYER::getSkillType()
{
	return skillType;
}

void PLAYER::hpRege()
{
	hp += hpregen;
}

void PLAYER::respawn()
{
	exp = exp*0.9;
	if (exp < 25 * (level - 1)*(level - 1) + (level - 1) * 5 + 20)
		exp = 25 * (level - 1)*(level - 1) + (level - 1) * 5 + 20;
	attack = level * 20 + 30;
	maxhp = level * 250;
	hp = maxhp;
	hpregen = level*0.1;
	y = 400;
	soundEffect(7);
}

void PLAYER::skillStateMove()
{
	skillState--;
}

int PLAYER::getType()
{
	return type;
}

void PLAYER::soundEffect(int soundtype)
{
	if (SOUND)
		switch (soundtype){
		case 0:{
			PlaySound("sound/boot.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 1:{
			PlaySound("sound/press.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 2:{
			PlaySound("sound/melee_1.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 3:{
			PlaySound("sound/welcome.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 4:{
			PlaySound("sound/tele.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 5:{
			PlaySound("sound/jump.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 6:{
			PlaySound("sound/four.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 7:{
			PlaySound("sound/res.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 8:{
			PlaySound("sound/xiu.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		case 9:{
			PlaySound("sound/boom.wav", NULL, SND_FILENAME | SND_ASYNC);
		}break;
		default:break;
	}
}

bool PLAYER::getSound()
{
	return SOUND;
}

//初始化用函数

void PLAYER::teleport(int x1, int y1)	//用于玩家传送
{
	x = x1;
	y = y1;
	soundEffect(4);
}

void PLAYER::setHp(float num)
{
	hp = num;
}

void PLAYER::setAttack(int num)
{
	attack = num;
}

void PLAYER::setMaxHp(float num)
{
	maxhp = num;
}

void PLAYER::setSpd(int num)
{
	movespd = num;
}

void PLAYER::setDir(bool num)
{
	dir = num;
}

void PLAYER::setCombo(int num)
{
	combo = num;
}

void PLAYER::setSkillState(int num)
{
	skillState = num;
}

void PLAYER::setSkillType(int num)
{
	skillType = num;
}

void PLAYER::setStill(int num)
{
	still = num;
}

void PLAYER::setRunState(int num)
{
	runState = num;
	if (num > 0)
		isRun = true;
	
}

void PLAYER::setRun(int num)
{
	run = num;
	if (num == 0)
		isRun = 0;
}

void PLAYER::setLevel(int num)
{
	level = num;
}

void PLAYER::setType(int num)
{
	type = num;
}

void PLAYER::setSound(bool a)
{
	SOUND = a;
}