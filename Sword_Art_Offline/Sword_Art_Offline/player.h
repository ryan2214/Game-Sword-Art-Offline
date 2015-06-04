#pragma once
#include <graphics.h>

using namespace std;

typedef class __PLAYER
{
public:							/*构造析构函数*/
	__PLAYER();				//默认是空
	~__PLAYER();
public:
	int getX();		     //获取位置
	int getY();
	int getMovespd();       //获取移动速度
	int getAttack();        //获取攻击力
	int getHp();            //获取当前hp
	int getSkill();         //获取当前释放技能编号
	int getCombo();         //获取当前连击值
	void meleeAttack(int[],int[],int);     //普通の攻击
	void damage(int);       //受到伤害
	void jump();		    //跳跃
	void moveX(IMAGE player);//基本移动
	void startJump();       //跳起
	void useSkill(int);     //释放技能
	void still(int ox, IMAGE player);//静止姿态
	void skillEffect(IMAGE,IMAGE,IMAGE);//技能姿势特效绘制
	bool stillJudge();      //判断是否静止
	bool jumpJudge();       //判断是否跳跃
	bool getDir();          //获取方向

	//初始化用函数
	void teleport(int, int);//用于玩家传送
	void setDir(bool);      //设置方向
	void setHp(int);        //设置Hp值
	void setMaxHp(int);     //设置MaxHp值
	void setAttack(int);    //设置attack值
	void setSpd(int);       //设置移动速度
	void setCombo(int);     //设置连击情况
	void setSkillState(int);//设置技能释放状态
	void setSkillType(int); //设置技能类型
	
protected:		/****玩家属性****/
	int hp;                 //当前生命值
	int maxhp;              //最大生命值
	int hpregen;            //每帧战斗回复hp（注:FPS=100）
	int movespd;            //每次移动像素数
	int attack;             //攻击力
	int x;                  //位置
	int y;
	bool dir;               //0->左 1->右
	int combo;              //连击状态
	int jumpState;          //跳跃过程
	int runState;           //跑动过程
	int skillState;         //技能释放过程
	int skillType;          //当前释放的技能编号
	bool isRun;             //跑动
	bool isJump;            //跳跃
	bool attacking;         //是否处于攻击状态
	
}kirito;
