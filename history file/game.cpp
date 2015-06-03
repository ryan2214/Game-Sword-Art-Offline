#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <string>
#include "Vfw.h"
#pragma comment (lib, "Vfw32.lib")

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)

using namespace std;
#define inter 10

void my_putimg(int dstX, int dstY, IMAGE *pimg, int avoid_color, int deviation, int tp, int originx);
int main();
int bgm(int a);
int sound(int a);
int abs(int a);
int enemyhp[1000] = { 0 };
int originx = 0;
float jumptime = 0;
float hpper = 1;
int combo = 0;
int first = 200;  //初次进入循环
IMAGE background,wbackground, welcome, player, skillpic250,skillpic300, enemyplayer,hpUI;
POINT pt;    //定义清理图像指针

void M_clear(POINT pt, IMAGE *bk)//pt上一个动作图片的输出坐标，bk背景图片
{
	IMAGE clear;
	SetWorkingImage(bk);//设定当前的绘图设备为背景图片
	getimage(&clear, pt.x, pt.y, background.getwidth(), background.getheight());//获取图像
	SetWorkingImage();//设定回默认绘图窗口
	putimage(pt.x, pt.y, &clear);//输出
}

class movable
{
public:
	int x;
	int y;
	int hp;        //当前hp
	int level;    
	int maxhp;     //hp上限
	int attack;    //攻击力
	int dir;       //0为向左，1为向右
	int still;
	int run;
	int runstate;
	int skillstate;
	int skilltype;
	bool jump;
	int movespeed;
};
movable kirito, enemy;

void datagive()
{
	kirito.x = 300;            //初始化kirito数据
	kirito.y = 400;
	kirito.dir = 1;
	kirito.level = 1;
	kirito.maxhp = 100;
	kirito.hp = 50;
	kirito.attack = 10;
	kirito.still = 1;
	kirito.run = 0;
	kirito.runstate = 1;
	kirito.skilltype = 0;
	kirito.skillstate = 0;
	kirito.movespeed = 10;//单位px

	enemy.x = 500;            //初始化enemy数据
	enemy.y = 400;
	enemy.dir = 0;
	enemy.level = 1;
	enemy.maxhp = 100;
	enemy.hp = 100;
	enemy.attack = 10;
	enemy.still = 1;
	enemy.run = 0;
	enemy.runstate = 1;
	enemy.skilltype = 0;
	enemy.skillstate = 0;
	enemy.movespeed = 10;
	loadimage(&enemyplayer, "pic/enemylrunning2.jpg");
}

void jump()
{
	kirito.jump = 1;
	kirito.still = -1;
	jumptime = 40;
	if (kirito.x > 3016)kirito.x = 3016;    //地图边界
	if (kirito.x < 10)kirito.x = 10;
	
	switch (kirito.dir){
	case 0:loadimage(&player, "pic/ll4.jpg"); break;
	case 1:loadimage(&player, "pic/rr4.jpg"); break;
	}
	my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
}

void jump_fly()
{
	kirito.still = -1;
	switch (kirito.dir){
	case 0:kirito.x-=kirito.movespeed; break;
	case 1:kirito.x+=10; break;
	}
	if (kirito.x > 3016)kirito.x = 3016;    //地图边界
	if (kirito.x < 10)kirito.x = 10;
	
	kirito.y = (int)((20 - jumptime)*(20 - jumptime)*0.125+350);

}


void rightmove()
{
	kirito.x += kirito.movespeed;
	if (kirito.x > 3016)kirito.x = 3016;
	kirito.dir = 1;
	kirito.run++;
	if (kirito.run >= 17)kirito.run = 1;
	kirito.still = -5;
	if (kirito.run >= 4)kirito.runstate = 2;
	if (kirito.run >= 8)kirito.runstate = 3;
	if (kirito.run >= 12)kirito.runstate = 4;
	if (kirito.run >= 16)kirito.runstate = 1;
	switch (kirito.runstate){
	case 1:loadimage(&player, "pic/rr1.jpg"); break;
	case 2:loadimage(&player, "pic/rr2.jpg"); break;
	case 3:loadimage(&player, "pic/rr3.jpg"); break;
	case 4:loadimage(&player, "pic/rr4.jpg"); break;
	}
	my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
}

void leftmove()
{
	kirito.x -= kirito.movespeed;
	if (kirito.x < 10)kirito.x = 10;       //地图左边界
	kirito.dir = 0;                        //方向变为向左
	kirito.run++;
	if (kirito.run >= 17)kirito.run = 1;
	kirito.still = -5;
	if (kirito.run >= 4)kirito.runstate = 2;       //根据run判断runstate
	if (kirito.run >= 8)kirito.runstate = 3;
	if (kirito.run >= 12)kirito.runstate = 4;
	if (kirito.run >= 16)kirito.runstate = 1;
	switch (kirito.runstate){                           //根据runstate贴图
	case 1:loadimage(&player, "pic/ll1.jpg"); break;
	case 2:loadimage(&player, "pic/ll2.jpg"); break;
	case 3:loadimage(&player, "pic/ll3.jpg"); break;
	case 4:loadimage(&player, "pic/ll4.jpg"); break;
	}
	my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
}

void meleeattack()
{
	combo++;
	kirito.skilltype = 1;
	kirito.skillstate = 10;
	kirito.still = -10;
	switch (kirito.dir){
	case 0:{ 
		if ((kirito.x - enemy.x) <= 100 && (kirito.x - enemy.x) >= 0){         /****击中判断****/
			enemy.hp -= kirito.attack;                                         //击中造成伤害
			enemy.still = -5;                                                  //击中造成僵直
			enemy.x -= 10;                                                     //击中造成击退
			loadimage(&enemyplayer, "pic/enemylrunning3.jpg");                 //加载被击中时姿势
			my_putimg(enemy.x, enemy.y, &enemyplayer, WHITE, 20, 100, originx); /****击中判断结束****/
		}

		switch (combo){
		case 1:{
			loadimage(&player, "pic/lattack1.jpg");
			loadimage(&skillpic250, "pic/lcut1.jpg");
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
		}break;
		case 2:{
			loadimage(&player, "pic/lattack2.jpg");
			loadimage(&skillpic250, "pic/lcut2.jpg");
			kirito.x -= 100;
			if (kirito.x < 10)kirito.x = 10;
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
		}break;
	    case 3:{
		    loadimage(&player, "pic/lattack3.jpg");
		    loadimage(&skillpic300, "pic/lcut3.jpg");
			kirito.x -= 10;
			if (kirito.x < 10)kirito.x = 10;
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
	    }break;
	    }
    }break;
	case 1:{
		if ((kirito.x - enemy.x) <= 100 && (kirito.x - enemy.x) >= 0){         /****击中判断****/
			enemy.hp -= kirito.attack;                                         //击中造成伤害
			enemy.still = -5;                                                  //击中造成僵直
			enemy.x -= 10;                                                     //击中造成击退
			loadimage(&enemyplayer, "pic/enemylrunning3.jpg");                 //加载被击中时姿势
			my_putimg(enemy.x, enemy.y, &enemyplayer, WHITE, 20, 100, originx); /****击中判断结束****/
		}

		switch (combo){
		case 1:{
			loadimage(&player, "pic/lattack1.jpg");
			loadimage(&skillpic250, "pic/lcut1.jpg");
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
		}break;
		case 2:{
			loadimage(&player, "pic/lattack2.jpg");
			loadimage(&skillpic250, "pic/lcut2.jpg");
			kirito.x -= 100;
			if (kirito.x < 10)kirito.x = 10;
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
		}break;
		case 3:{
			loadimage(&player, "pic/lattack3.jpg");
			loadimage(&skillpic300, "pic/lcut3.jpg");
			kirito.x -= 10;
			if (kirito.x < 10)kirito.x = 10;
			my_putimg(kirito.x, kirito.y, &player, WHITE, 50, 100, originx);
		}break;
		}
	}break;
		}
	sound(2);
}

void stillkirito()
{
	switch (kirito.dir){
	case 0:{
		loadimage(&player, "pic/lstill.jpg");
		my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
	}break;
	case 1:{
		loadimage(&player, "pic/rstill.jpg");
		my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
	}break;
	default:break;
	}
}

void hpUIrefresh()
{
	hpper = kirito.hp / kirito.maxhp;
	if (hpper>= 0.6)       //根据血量判断血条颜色
		setfillcolor(GREEN);              
	if (hpper >= 0.3 && hpper<0.6)
		setfillcolor(YELLOW);
	if (hpper < 0.3)
		setfillcolor(RED);
	solidrectangle(72 - originx, 10, 258 * hpper + 72 - originx, 34);   //填充hp
    my_putimg(-10 - originx, -20, &hpUI, WHITE, 20, 80, originx);  //hp&hpUI
	
}

void screenmove()
{
	if (kirito.x > (500 - originx)){              //右移动边界
		originx -= kirito.movespeed;              //屏幕区域位置改变
	}
	if (kirito.x < (120 - originx)){              //左移动边界
		originx += kirito.movespeed;
	}

	if (originx > 0)originx = 0;           //限制originx>=0
	if (originx < -2144)originx = -2144;     //限制originx<=2144
	setorigin(originx, 0);                 //重设原点
}

void between()
{
	if (kirito.still <= 0){
		kirito.still++;
		my_putimg(kirito.x, kirito.y, &player, WHITE, 20, 100, originx);
		if (kirito.jump){
			jump_fly();
		}

		switch (kirito.skilltype){               //判断技能种类(0为无技能)
		case 1:{                            //普通攻击
			switch (combo){                 //根据combo判断技能图片
			case 1:{
				kirito.y -= 25;                //技能图片位置修正
				kirito.x -= 85;
				switch (kirito.skillstate){
				case 10:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 90, originx); break;
				case 9:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 80, originx); break;
				case 8:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 70, originx); break;
				case 7:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 60, originx); break;
				case 5:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 50, originx); break;
				case 4:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 40, originx); break;
				case 3:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 30, originx); break;
				case 2:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 20, originx); break;
				case 1:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 10, originx); break;
				}
				kirito.y += 25;                 //技能图片位置修正后还原
				kirito.x += 85;
			}break;
			case 2:{
				kirito.y -= 50;
				kirito.x -= 65;
				switch (kirito.skillstate){
				case 10:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 90, originx); break;
				case 9:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 80, originx); break;
				case 8:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 70, originx); break;
				case 7:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 60, originx); break;
				case 5:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 50, originx); break;
				case 4:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 40, originx); break;
				case 3:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 30, originx); break;
				case 2:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 20, originx); break;
				case 1:my_putimg(kirito.x, kirito.y, &skillpic250, WHITE, 20, 10, originx); break;
				}
				kirito.y += 50;
				kirito.x += 65;
			}break;
			case 3:{
				kirito.y -= 80;
				kirito.x -= 105;
				switch (kirito.skillstate){
				case 10:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 90, originx); break;
				case 9:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 80, originx); break;
				case 8:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 70, originx); break;
				case 7:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 60, originx); break;
				case 5:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 50, originx); break;
				case 4:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 40, originx); break;
				case 3:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 30, originx); break;
				case 2:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 20, originx); break;
				case 1:my_putimg(kirito.x, kirito.y, &skillpic300, WHITE, 20, 10, originx); break;
				}
				kirito.y += 80;
				kirito.x += 105;
				if (combo == 3&&kirito.skillstate==1)combo = 0;
			}break;
			}
			
		}break;
		default:break;
		}
	}
}

int game(int a)
{
	// 初始化绘图窗口(welcome已完成）
	
	//link start!
	//HWND hwnd = MCIWndCreate(GetHWnd(), NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOMENU | MCIWNDF_NOPLAYBAR, NULL);
	//MCIWndOpen(hwnd, "avi\\loadgame.wmv", NULL);
	//MCIWndPlay(hwnd);
	//Sleep(17000);
	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	
	setorigin(originx, 0);//设置初始原点

	// 加载图片
	loadimage(&welcome, "pic/welcome.jpg");
	loadimage(&background, "pic/blank.jpg");	// 请确保该图片是 1072*600 像素
	loadimage(&hpUI, "pic/hp_bar.jpg");
	loadimage(&wbackground, "pic/whitebk.jpg");
	
	datagive();//赋予角色属性值
	
	/*int refreshtime=500;//怪物刷新
	int refreshnum=2;
	int refreshmax = 10;*/

	int comboclear=0;

    pt.x = 0;   //清理图像指针赋值
	pt.y = 0;

	BeginBatchDraw();  //开始批量绘图

	while (1){      //**********************************游戏主循环******************************
		
		if (first >= 0){
			//Welcome to Sword Art Online
			my_putimg(250, 250, &welcome, WHITE, 20, first, originx);
			first--;
			if (first == 199){
				sound(3);
			}
		}
		if (first == -1){
			//随机BGM
			int m = ((rand() % 7) + 1);
			bgm(m);
			first = -2;
		}
		//检测人物位置，移动屏幕
		screenmove();
		//加载敌人图像（测试用）
		loadimage(&enemyplayer, "pic/enemylrunning2.jpg");
		my_putimg(enemy.x, enemy.y, &enemyplayer, WHITE, 20, 100, originx);
		//hpUI刷新（暂时无法正常显示）
		hpUIrefresh();
		
		if (kirito.hp <= 0)kirito.y = 650;  //死亡判定
		if (enemy.hp <= 0)enemy.y = 650;
		
		//当有键盘输入时执行
		if (_kbhit()){

			if (KEY_DOWN('J')&&kirito.still>0){                      //普通攻击"J"
				meleeattack();
			}
			
			else{
				if (KEY_DOWN(VK_SPACE) && kirito.jump == 0){       //按Space跳跃
					jump();
				}

				if (kirito.jump == 0){                     //跳跃状态时AD不可用
					if (KEY_DOWN('A')){                    //向左移动
						leftmove();
					}
					if (KEY_DOWN('D')){                       //向右移动
						rightmove();
					}
				}
				if (KEY_DOWN(VK_ESCAPE)) return 0;
			}
		}
			

		//无按键输入时或kirito.jump=1时
		between();
		
			
		if (kirito.still == 1){                    //静止时
			kirito.runstate = 1;
			kirito.skilltype = 0;
			kirito.run = 0;
			comboclear++;
			if (comboclear == 20){
				comboclear = 0;
				combo = 0;
			}
			stillkirito();              //静止角色图片
		}
		
		//技能通用CD计算用参数
		if (kirito.skillstate>0)
		    kirito.skillstate--;
		
		//跳跃时间计算与结束
		if (jumptime > 0) 
			jumptime--;
		if (jumptime == 0){
			kirito.jump = 0;
			kirito.y = 400;
		}
		
		FlushBatchDraw();      //绘制结果输出
		Sleep(inter);          //控制帧率
		M_clear(pt, &background);    //清空画面
		
		
	}//***************************************主循环结束*******************************************

	closegraph();

}

