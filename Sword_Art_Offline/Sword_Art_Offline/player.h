#pragma once

using namespace std;

typedef class __PLAYER
{
public:							/*构造析构函数*/
	__PLAYER();				//默认是空
	~__PLAYER();
public:
	int getx();		     //获取位置
	int gety();
	int getmovespd();       //获取移动速度
	int getattack();        //获取攻击力
	int gethp();            //获取当前hp
	int getskill();         //获取当前释放技能编号
	int getcombo();         //获取当前连击值
	void teleport(int,int);	//用于玩家传送
	void damage(int);       //受到伤害
	void heal(int);         //受到治疗
	void jump(int);		    //跳跃
	void movex();		    //基本移动
	void setdir(bool);      //设置方向
	void castskill(int);    //释放技能（技能编号）
	bool stilljudge();      //判断是否静止
	bool lifejudge();       //存活确认
	bool getdir();          //获取方向
protected:		/****玩家属性****/
	int hp;                 //当前生命值
	int maxhp;              //最大生命值
	int hpregen;            //每帧战斗回复hp（注:FPS=100）
	int movespeed;          //每次移动像素数
	int attack;             //攻击力
	int x;                  //位置
	int y;
	bool dir;               //0->左 1->右
	int combo;              //连击状态
	bool isRun;             //跑动
	bool isJump;            //跳跃
	bool attacking;         //是否处于攻击状态
	int skilltype;          //当前释放的技能编号
}kirito;
