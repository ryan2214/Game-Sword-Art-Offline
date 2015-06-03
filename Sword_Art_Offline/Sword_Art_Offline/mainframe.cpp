#include "mainframe.h"
#pragma comment (lib, "winmm.lib")

__MAINFRAME::__MAINFRAME() {}

__MAINFRAME::~__MAINFRAME() {}

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)  //检测按键和鼠标点击

#define maxx 1072       //初始化屏幕宽高
#define maxy 600
#define inter 10        //初始化Sleep的间隔


void headLine(char *SAO, char *ETS,char *blank,bool flagstart,bool blink)
{
	settextstyle(112, 30, _T("SAO UI"));	// 设置大标题字体
	settextcolor(WHITE);
	outtextxy(200, 180, SAO);

	if (blink == 1 || flagstart == 1){
		if (flagstart == 1)settextcolor(YELLOW);
		settextstyle(50, 13, _T("SAO UI"));   //设置ETS字体
		outtextxy(411, 400, ETS);
	}
	else{
		settextstyle(50, 13, _T("SAO UI"));
		outtextxy(411, 400, blank);
	}                                      //实现ETS的闪烁
	settextcolor(YELLOW);
	setlinecolor(BLACK);
	settextstyle(30, 8, _T("SAO UI"));	// 重新设置为背景字体
}

void clearline(int i)                    //实现背景空白行扫描
{
	line(i, 0, i, 599);
	line(i + 536, 0, i + 536, 599);
	line(i - 536, 0, i - 536, 599);
}

void copy_img(IMAGE* img1, IMAGE* img2)
{
	//copy img2 to img1
	IMAGE* now_working = GetWorkingImage();
	Resize(img1, img2->getwidth(), img2->getheight());
	SetWorkingImage(img2);
	getimage(img1, 0, 0, img1->getwidth(), img1->getheight());
	SetWorkingImage(now_working);
}

void main()
{
	__MAINFRAME mainFrame;
	mainFrame.welcomeInit();
}

void mainFrame::welcomeInit()
{
	bool flagstart = false;
	bool flagsound = true;
	bool blink = true;
	int tic = 0;
	char blank[47] = "                                              ";
	HWND hw = GetHWnd();
	
	// 设置随机函数种子
	srand((unsigned)time(NULL));

	// 初始化图形模式
	initgraph(maxx, maxy);
	POINT pt;								 //鼠标位置
	int  x, y;
	char c;								     //随机字母
	char headline[] = "s w o r d    a r t    o f f l i n e";
	char ETS[] = "PRESS ENTER TO START";
	
	bgm(0);                                  //播放crossing_field.mp3
	
	settextstyle(30, 8, _T("SAO UI"));       //初始化背景字体和字母颜色
	settextcolor(YELLOW);
	setlinecolor(BLACK);

	for (int i = 0; i <= maxx - 1; i++)     /***********主循环开始***********/
	{
		hw = GetHWnd();
		//计时用变量
		tic++;
		// 在随机位置显示三个随机字母
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 134) * 8;//随机横坐标
			y = (rand() % 20) * 30;//随机纵坐标
			c = (rand() % 26) + 65;//随机字母
			outtextxy(x, y, c);
		}

		// 画线擦掉像素行
		clearline(i);
		//ETS闪烁
		if (tic == 50){
			blink = !blink;
			tic = 0;
		}

		//获取鼠标位置
		GetCursorPos(&pt);
		//将获取到的鼠标屏幕位置转换为窗口内位置
		ScreenToClient(hw, &pt);
		//ETS的鼠标响应判断
		if (pt.x >= 411 && pt.y >= 400 && pt.x <= 679 && pt.y <= 450){
			flagstart = 1;
			if (flagsound == 1){
				sound(1);
				flagsound = 0;
			}
			if (KEY_DOWN(VK_LBUTTON)){
				sound(0);
				//unlimitedMode();
			}

		}
		else{
			flagstart = 0;
			flagsound = 1;
		}
		
		headLine(headline, ETS,blank,flagstart,blink);//输出标题和ETS

		Sleep(10);	                        // 延时(控制FPS为100）

		if (i >= maxx - 1)	i = -1;		    // 循环处理

		if (KEY_DOWN(VK_RETURN)){           //ENTER键开始新游戏（暂定）
			sound(0);
			//unlimitedMode();
		}
		if (KEY_DOWN(VK_ESCAPE)){           //按ESC键退出
			bgm(9);
			gameExit();
		}
	}/******************主循环结束*******************/

	// 关闭图形模式
	closegraph();
}

void mainFrame::saoMode()
{

}

void mainFrame::unlimitedMode()
{

}

void mainFrame::bgm(int song)
{
	switch (song){
	case 0:{
		mciSendString(TEXT("open bgm/crossing_field.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 1:{
		mciSendString(TEXT("open bgm/Swordland.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 2:{
		mciSendString(TEXT("open bgm/The_First_Town.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 3:{
		mciSendString(TEXT("open bgm/Survive_The_Swordland.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 4:{
		mciSendString(TEXT("open bgm/Luminous_Sword.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 5:{
		mciSendString(TEXT("open bgm/light_your_sword.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 6:{
		mciSendString(TEXT("open bgm/Everyday_Life.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 7:{
		mciSendString(TEXT("open bgm/She_has_to_overcome_her_fear.mp3 alias Mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;


	case 9:{
		mciSendString(TEXT("stop MySong"), NULL, 0, NULL);
	}
	default:break;
	}
}

void mainFrame::sound(int soundtype)
{
	switch (soundtype){
	case 0:{
		PlaySound("sound/boot.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 1:{
		PlaySound("sound/press.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 2:{
		PlaySound("sound/melee.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 3:{
		PlaySound("sound/welcome.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 9:{
		mciSendString(TEXT("stop MySong"), NULL, 0, NULL);
	}
	default:break;
	}
}

void mainFrame::gameExit()
{
	closegraph();
}

void mainFrame::my_putimg(int dstX, int dstY, IMAGE *pimg, int avoid_color, int tp, int originx)
{
	//排除颜色avoid_color,容差为deviation；透明度tp(transparency)从0到100
	setorigin(originx, 0);
	int x, y, num;
	int deviation = 10;
	int R, G, B;//记录贴图某点色彩
	//记录排除颜色色彩
	int avoid_r = GetRValue(avoid_color);
	int avoid_g = GetGValue(avoid_color);
	int avoid_b = GetBValue(avoid_color);
	IMAGE pSrcImg;//背景图
	IMAGE tempimg;//临时贴图
	copy_img(&tempimg, pimg);//保护原图
	SetWorkingImage(NULL);//对默认绘图窗口的绘图操作
	getimage(&pSrcImg, dstX, dstY, pimg->getwidth(), pimg->getheight());

	//透明度容错
	if (tp<0)
	{
		tp = 0;
	}
	else if (tp>100)
	{
		tp = 100;
	}

    // 获取背景指向显存的指针
	DWORD* bk_pMem = GetImageBuffer(&pSrcImg);

	//贴图指向显存的指针
	DWORD* pMem = GetImageBuffer(&tempimg);

    for (y = 0; y<pimg->getheight(); y++)
	{
		for (x = 0; x<pimg->getwidth(); x++)
		{
			num = y*pimg->getwidth() + x;
			R = GetRValue(pMem[num]);
			G = GetGValue(pMem[num]);
			B = GetBValue(pMem[num]);
			if ((abs(R - avoid_r) <= deviation) && (abs(G - avoid_g) <= deviation) && (abs(B - avoid_b) <= deviation))
			{
				pMem[num] = bk_pMem[num];
			}
			else
			{
				pMem[num] = RGB((R*tp + GetRValue(bk_pMem[num])*(100 - tp)) / 100, (G*tp + GetGValue(bk_pMem[num])*(100 - tp)) / 100, (B*tp + GetBValue(bk_pMem[num])*(100 - tp)) / 100);
			}
		}
	}
	putimage(dstX, dstY, &tempimg);
}
