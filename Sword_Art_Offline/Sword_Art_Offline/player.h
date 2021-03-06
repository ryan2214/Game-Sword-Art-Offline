#pragma once
#include <graphics.h>

using namespace std;

typedef class PLAYER
{
public:							/*构造析构函数*/
	PLAYER();				//默认是空
	~PLAYER();
public:
	int getX();		     //获取位置
	int getY();
	int getMovespd();       //获取移动速度
	int getAttack();        //获取攻击力
	float getHp();            //获取当前hp
	int getSkill();         //获取当前释放技能编号
	int getCombo();         //获取当前连击值
	void meleeAttack(int*, int*, PLAYER*, IMAGE*, IMAGE*, IMAGE*, IMAGE*, int);     //普通の攻击
	void sonicLeap(int*, int*, PLAYER*, IMAGE*, IMAGE*, IMAGE*, IMAGE*, int);		//音速冲击
	void horizontalSquare(int*, int*, PLAYER*, IMAGE*, IMAGE*, IMAGE*, IMAGE*, int);//水平四方斩
	void damage(int);      			 //受到伤害
	void jump();		   		 //跳跃
	void running(IMAGE*, int,PLAYER*);         //跑动
	void moveX(int*,int*); 			//基本移(hua)动
	void startJump();      			 //跳起
	void useSkill(int);    			 //释放技能
	bool stillJudge();      		//判断是否静止
	bool jumpJudge();       		//判断是否跳跃
	bool runJudge();       			 //判断是否跑动
	bool coolingJudge();   			 //判断是否处于冷却
	bool getDir();          		//获取方向
	int getStill();				//获取still值
	void restill();         		//恢复静止
	int getSkillState();    		//获取技能状态
	int getSkillType();			//获取技能类型
	int getRunState();     			//获取跑动状态
	void skillEffect(IMAGE*,IMAGE*,IMAGE*,IMAGE*,PLAYER*,int);     //给技能加特技
	void startRun();       			 //开始跑动
	void coolingDown();    			 //冷却恢复
	void skillStateMove();  		//计算skillState
	float getMaxHp();        		 //获取最大hp
	void AIFind(int*);			//enemy追踪玩家
	void AIAttack(PLAYER*,IMAGE*);          //enemy攻击玩家
	int getLev();				//获取等级
	void levelUp();				//升级啦hhhhh
	void statRefresh();			//根据等级刷新数值
	int getExp();				//获取当前exp
	void expAdd(int);			//经验增加
	void levelUpCheck();		//检测是否升级
	void hpRege();				//被动HP回复
	void respawn();				//复活，经验损失10%
	int getType();				//获取种类
	int getRun();				//获取run值
	void bossAttack(int*, int*, PLAYER*, IMAGE*, IMAGE*, int);//BOSS的攻击
	bool getSound();			//获取sound值
	//初始化用函数
	void teleport(int, int);//用于玩家传送
	void setDir(bool);      //设置方向
	void setHp(float);        //设置Hp值
	void setMaxHp(float);     //设置MaxHp值
	void setAttack(int);    //设置attack值
	void setSpd(int);       //设置移动速度
	void setCombo(int);     //设置连击情况
	void setSkillState(int);//设置技能释放状态
	void setSkillType(int); //设置技能类型
	void setStill(int);        //使静止
	void setRunState(int);   //设置跑动阶段
	void setRun(int);       //设置run值
	void setLevel(int);     //设置等级
	void setExp(int);		//设置经验值
	void setType(int);		//设置种类
	void soundEffect(int);	//声效
	void setSound(bool);	//设定音效开关状态
	
protected:		/****玩家属性****/
	float hp;                		 //当前生命值
	float maxhp;            		  //最大生命值
	int exp;				//经验值
	int level;				//等级
	float hpregen;          		  //每帧战斗回复hp（注:FPS约100）
	int movespd;           			 //每次移动像素数
	int attack;            			 //攻击力
	int x;                   		 //位置
	int y;
	bool dir;              			 //0->左 1->右
	int combo;             			 //连击状态
	int jumpState;         			 //跳跃过程
	int runState;          			 //跑动过程
	int run;				//跑动核心参数
	int coolDown;				//技能冷却判断
	int skillState;         		//技能释放过程
	int skillType;          		//当前释放的技能编号
	int still;             			 //san值
	bool isRun;            			 //跑动
	bool isJump;           			 //跳跃
	bool cooling;        			 //是否处于攻击状态
	int type;				//0玩家；1-9普通敌人；10BOSS
	bool SOUND;				//音效开关

}kirito,enemy;
