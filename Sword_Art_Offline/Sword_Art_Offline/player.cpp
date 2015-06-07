#include "player.h"
#include "mainframe.h"

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

void __PLAYER::moveX(IMAGE* player,int ox)		//�����ƶ� 
{
		still = -10;
	
	x += movespd; 
	if (x < 10){
		x = 10 - (10 - x);
		movespd = -movespd;
	}
	if (x > 3016){
		x = 3016 - (3016 - x);
		movespd = -movespd;
	}
	if (isRun)
	{
		switch (runState){
		case 1:
		case 2:
		case 3:{
			loadimage(player, "pic/rr1.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
			runState++;
		}break;
		case 4:
		case 5:
		case 6:{
			loadimage(player, "pic/rr2.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
			runState++;
		}break;
		case 7:
		case 8:
		case 9:{
			loadimage(player, "pic/rr3.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
			runState++;
		}break;
		case 10:
		case 11:
		case 12:{
			loadimage(player, "pic/rr4.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
			runState++;
		}break;
		}
		if (runState == 13)runState = 1;
		
	}
}

bool __PLAYER::stillJudge()     //�ж��Ƿ�ֹ
{
	if (still==1)
		return true;
	else
		return false;
}

bool __PLAYER::runJudge()
{
	return isRun;
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

void __PLAYER::meleeAttack(int enemyx, int enemyhp,__PLAYER enemy, IMAGE *player, IMAGE *enemyplayer, IMAGE *skillpic250, IMAGE *skillpic300, int originx)
{
	attacking = true;
	skillType = 1;
	skillState = 1;
	//�����ж�
	combo++;
	still = -10;
	switch (dir){
	case 0:{
		if ((x - enemy.x) <= 100 && (x - enemy.x) >= 0){         /****�����ж�****/
			enemy.hp -= attack;                                         //��������˺�
			enemy.still = -5;                                                  //������ɽ�ֱ
			enemy.x -= 10;                                                     //������ɻ���
		 /****�����жϽ���****/
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
		if ((x - enemy.x) <= 100 && (x - enemy.x) >= 0){         /****�����ж�****/
			enemy.hp -= attack;                                         //��������˺�
			enemy.still = -5;                                                  //������ɽ�ֱ
			enemy.x -= 10;                                                     //������ɻ���
			/****�����жϽ���****/
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
	if (still < 1)
		still++;
	if (still == 1){
		isRun = false;
		skillType = 0;
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
	switch (skillType){               //�жϼ�������(0Ϊ�޼���)
	case 1:{                            //��ͨ����
		switch (combo){                 //����combo�жϼ���ͼƬ
		case 1:{
			y -= 25;                //����ͼƬλ������
			x -= 85;
			loadimage(skillpic250, "pic/lcut1.jpg");
			mainFrame::M_putimg(x, y, skillpic250, WHITE, 10 * skillState, ox);
			y += 25;                 //����ͼƬλ��������ԭ
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
	if (num > 0)
		isRun = true;
}