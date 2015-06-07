#include "mainframe.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include "Vfw.h"
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "Vfw32.lib")

__MAINFRAME::__MAINFRAME()
{
	originx = 0;
}

__MAINFRAME::~__MAINFRAME() {}

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)  //��ⰴ���������

#define maxx 1072       //��ʼ����Ļ���
#define maxy 600
#define inter 10        //��ʼ��Sleep�ļ��

void main()
{
	__MAINFRAME mainFrame;
	mainFrame.welcomeInit();
}

void headLine(char *SAO, char *ETS,char *blank,bool flagstart,bool blink)
{
	settextstyle(112, 30, _T("SAO UI"));	// ���ô��������
	settextcolor(WHITE);
	outtextxy(200, 180, SAO);

	if (blink == 1 || flagstart == 1){
		if (flagstart == 1)settextcolor(YELLOW);
		settextstyle(50, 13, _T("SAO UI"));   //����ETS����
		outtextxy(411, 400, ETS);
	}
	else{
		settextstyle(50, 13, _T("SAO UI"));
		outtextxy(411, 400, blank);
	}                                      //ʵ��ETS����˸
	settextcolor(YELLOW);
	setlinecolor(BLACK);
	settextstyle(30, 8, _T("SAO UI"));	// ��������Ϊ��������
}

void clearline(int i)                    //ʵ�ֱ����հ���ɨ��
{
	line(i, 0, i, 599);
	line(i + 536, 0, i + 536, 599);
	line(i - 536, 0, i - 536, 599);
}

void M_clear(POINT pt, IMAGE *bk, IMAGE pic)//pt��һ������ͼƬ��������꣬bk����ͼƬ
{
	IMAGE clear;
	SetWorkingImage(bk);//�趨��ǰ�Ļ�ͼ�豸Ϊ����ͼƬ
	getimage(&clear, pt.x, pt.y, pic.getwidth(), pic.getheight());//��ȡͼ��
	SetWorkingImage();//�趨��Ĭ�ϻ�ͼ����
	putimage(pt.x, pt.y, &clear);//���
}

void __MAINFRAME::stillput(bool dir,int x,int y,int ox, IMAGE *player,int type)
{
	switch (type){
	case 0:{
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
	}break;
	case 1:{
		switch (dir){
		case 0:{
			loadimage(player, "pic/les.jpg");
			mainFrame::M_putimg(x, y,player, WHITE, 100, ox);
		}break;
		case 1:{
			loadimage(player, "pic/res.jpg");
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
		}break;
		}
	}break;

	}
}

void __MAINFRAME::skillEffect(IMAGE player, IMAGE pic250, IMAGE pic300)
{

}


void mainFrame::copy_img(IMAGE* img1, IMAGE* img2)
{
	//copy img2 to img1
	IMAGE* now_working = GetWorkingImage();
	Resize(img1, img2->getwidth(), img2->getheight());
	SetWorkingImage(img2);
	getimage(img1, 0, 0, img1->getwidth(), img1->getheight());
	SetWorkingImage(now_working);
}

int mainFrame::getOriginx()
{
	return originx;
}

void mainFrame::setOriginx(int num)
{
	originx = num;
}

void mainFrame::screenMove(int x,int spd)
{
	if (x > (500 - originx)){              //���ƶ��߽�
		originx -= spd;              //��Ļ����λ�øı�
	}
	if (x < (120 - originx)){              //���ƶ��߽�
		originx -=spd;
	}

	if (originx > 0)originx = 0;           //����originx>=0
	if (originx < -2144)originx = -2144;     //����originx<=2144
	setorigin(originx, 0);                 //����ԭ��
}

void mainFrame::welcomeInit()
{
	bool flagstart = false;
	bool flagsound = true;
	bool blink = true;
	int tic = 0;
	char blank[47] = "                                              ";
	HWND hw = GetHWnd();
	
	// ���������������
	srand((unsigned)time(NULL));

	// ��ʼ��ͼ��ģʽ
	initgraph(maxx, maxy);
	POINT pt;								 //���λ��
	int  x, y;
	char c;								     //�����ĸ
	char headline[] = "s w o r d    a r t    o f f l i n e";
	char ETS[] = "PRESS ENTER TO START";
	
	//bgm(0);                                  //����crossing_field.mp3
	
	settextstyle(30, 8, _T("SAO UI"));       //��ʼ�������������ĸ��ɫ
	settextcolor(YELLOW);
	setlinecolor(BLACK);

	for (int i = 0; i <= maxx - 1; i++)     /***********��ѭ����ʼ***********/
	{
		hw = GetHWnd();
		//��ʱ�ñ���
		tic++;
		// �����λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 134) * 8;//���������
			y = (rand() % 20) * 30;//���������
			c = (rand() % 26) + 65;//�����ĸ
			outtextxy(x, y, c);
		}

		// ���߲���������
		clearline(i);
		//ETS��˸
		if (tic == 50){
			blink = !blink;
			tic = 0;
		}

		//��ȡ���λ��
		GetCursorPos(&pt);
		//����ȡ���������Ļλ��ת��Ϊ������λ��
		ScreenToClient(hw, &pt);
		//ETS�������Ӧ�ж�
		if (pt.x >= 411 && pt.y >= 400 && pt.x <= 679 && pt.y <= 450){
			flagstart = 1;
			if (flagsound == 1){
				sound(1);
				flagsound = 0;
			}
			if (KEY_DOWN(VK_LBUTTON)){
				sound(0);
				bgm(9);
				unlimitedMode();
			}

		}
		else{
			flagstart = 0;
			flagsound = 1;
		}
		
		headLine(headline, ETS,blank,flagstart,blink);//��������ETS

		Sleep(10);	                        // ��ʱ(����FPSΪ100��

		if (i >= maxx - 1)	i = -1;		    // ѭ������

		if (KEY_DOWN(VK_RETURN)){           //ENTER����ʼ����Ϸ���ݶ���
			sound(0);
			bgm(9);
		    unlimitedMode();
		}
		if (KEY_DOWN(VK_ESCAPE)){           //��ESC���˳�
			bgm(9);
			gameExit();
		}
	}/******************��ѭ������*******************/

	// �ر�ͼ��ģʽ
	closegraph();
}

int mainFrame::unlimitedMode()
{
	IMAGE background, wbackground, welcome, player, skillpic250, skillpic300, enemyplayer, hpUI;
	POINT pt;    //��������ͼ��ָ��
	pt.x = 0;   //����ͼ��ָ�븳ֵ
	pt.y = 0;
	
	//link start!
	//HWND hwnd = MCIWndCreate(GetHWnd(), NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOMENU | MCIWNDF_NOPLAYBAR, NULL);
	////MCIWndOpen(hwnd, "avi\\loadgame.wmv", NULL);
	//MCIWndPlay(hwnd);
	//Sleep(17000);

	settextstyle(30, 8, _T("SAO UI"));       //��ʼ�������������ĸ��ɫ
	settextcolor(YELLOW);
	setlinecolor(BLACK);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	setorigin(originx, 0);//���ó�ʼԭ��

	// ����ͨ��ͼƬ
	loadimage(&welcome, "pic/welcome.jpg");
	loadimage(&background, "pic/blank.jpg");	// ��ȷ����ͼƬ�� 1072*600 ����
	loadimage(&hpUI, "pic/hp_bar.jpg");
	loadimage(&wbackground, "pic/whitebk.jpg");

	// ���BGM
	int m = ((rand() % 6) + 2);
	bgm(m);

	//����ʱ���ò���
	int tik = 0;
	int comboclear = 0;

	//����ɣ��ҵ���ʿ
	__PLAYER kirito;
	//Ϊ���ս���ҵ�Ůʿ
	__PLAYER enemy;
	enemy.teleport(500, 400);
	enemy.setDir(0);
	//��������
		
	//��ʼ������ͼ
	BeginBatchDraw();  

	while (1){      /**********************************��Ϸ��ѭ��******************************/

		//����ͼ
		putimage(0, 0, &background);

		//�����ж�
		if (kirito.getHp() <= 0)kirito.teleport(0,600);  
		if (enemy.getHp() <= 0)enemy.teleport(0,600);
		//Ħ����
		if(kirito.getMovespd()>0&&!kirito.jumpJudge())
			kirito.setSpd(kirito.getMovespd() - 1);
		if (kirito.getMovespd()<0&&!kirito.jumpJudge())
			kirito.setSpd(kirito.getMovespd() + 1);
		
		//kirito�ƶ�
		kirito.moveX();

		//�������λ�ã��ƶ���Ļ
		screenMove(kirito.getX(), kirito.getMovespd());

		//���м�������ʱִ��
		if (_kbhit()){

			if (KEY_DOWN('J') && kirito.stillJudge()&&(!kirito.coolingJudge())){                 //��ͨ����"J"
				kirito.meleeAttack(enemy.getX(),enemy.getHp(),enemy,&player,&enemyplayer,&skillpic250,&skillpic300,originx);
				sound(2);
			}

			else{
				if (KEY_DOWN(VK_SPACE) && (!kirito.jumpJudge())){        //��Space��Ծ
					kirito.startJump();
				}

					                     
				if (KEY_DOWN('A')){                                       //��A�����ƶ�
					kirito.setDir(0);         //�ı䷽��
					kirito.setStill(-5);         //��ʼ�ܶ�
					kirito.setRunState(1);	 //ʹrunStateΪ1
					kirito.setSpd(-10);         //ʹkirito����ٶ�
					if (KEY_DOWN(VK_SHIFT))     //���shiftʳ�ø���
						kirito.setSpd(-15);
					}
				if (KEY_DOWN('D')){                                       //��D�����ƶ�
					kirito.setDir(1);         //�ı䷽��
					kirito.setStill(-5);         //��ʼ�ܶ�
					kirito.setRunState(1);	 //ʹrunStateΪ1
					kirito.setSpd(10);
					if (KEY_DOWN(VK_SHIFT))
						kirito.setSpd(15);
					}
					
				if (KEY_DOWN(VK_ESCAPE)){
					bgm(9);
					return 0;
				}//ESC�˳�
				}
		}

		//��kirito������Ծ״̬������Yֵ�ı�ͻ�ͼ
		if (kirito.jumpJudge()){    
			kirito.jump();
			switch (kirito.getDir()){
			case 0:loadimage(&player, "pic/ll4.jpg"); break;
			case 1:loadimage(&player, "pic/rr4.jpg"); break;
			}
			M_putimg(kirito.getX(), kirito.getY(), &player, WHITE, 100, originx);
			
		}
		//��kirito�����ܶ�״̬�������ܲ���ͼ
		if (kirito.runJudge() && !kirito.jumpJudge() && !kirito.stillJudge()){
			kirito.running(&player, originx);
		}
		//�����ͷ�ʱ�����ƺ���Ч����
		kirito.skillEffect(&skillpic250,&skillpic300,originx);
	
		//between
		if (!kirito.stillJudge()){
			kirito.setStill(kirito.getStill() + 1);
			M_putimg(kirito.getX(), kirito.getY(), &player, WHITE, 100, originx);
		}
		//��ֹʱ��putimg
		if (kirito.stillJudge() && !(kirito.getSkillState()) && !kirito.jumpJudge()){
			kirito.setRunState(1);
			kirito.setSkillType(0);
			kirito.setRun(0);
			comboclear++;
			if (comboclear == 20){
				comboclear = 0;
				kirito.setCombo(0);
			}
			stillput(kirito.getDir(),kirito.getX(),kirito.getY(),originx, &player,0);   //��ֹ��ɫͼƬ
		}
		
		if (enemy.stillJudge()){
			stillput(enemy.getDir(),enemy.getX(), enemy.getY(), originx, &enemyplayer,1);  //��ֹ����ͼƬ
		}

		//��ȴʱ�����
		if (kirito.coolingJudge())
			kirito.coolingDown();
		if (kirito.getSkillState() > 0)
			kirito.skillStateMove(); 

        FlushBatchDraw();      //���ƽ�����
		Sleep(inter);          //����֡��
		//M_clear(pt, &background,background);    //��ջ���
		cleardevice();

	}//***************************************��ѭ������*******************************************

	closegraph();
	
}

void mainFrame::bgm(int song)
{
	switch (song){
	case 0:{
		mciSendString(TEXT("open bgm/crossing_field.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 1:{
		mciSendString(TEXT("open bgm/Swordland.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 2:{
		mciSendString(TEXT("open bgm/The_First_Town.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 3:{
		mciSendString(TEXT("open bgm/Survive_The_Swordland.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 4:{
		mciSendString(TEXT("open bgm/Luminous_Sword.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 5:{
		mciSendString(TEXT("open bgm/light_your_sword.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 6:{
		mciSendString(TEXT("open bgm/Everyday_Life.mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;
	case 7:{
		mciSendString(TEXT("open bgm/She_has_to_overcome_her_fear.mp3 alias MySong"), NULL, 0, NULL);
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
	bgm(9);
	closegraph();
}

void mainFrame::M_putimg(int dstX, int dstY, IMAGE *pimg, int avoid_color, int tp, int originx)
{
	//�ų���ɫavoid_color,�ݲ�Ϊdeviation��͸����tp(transparency)��0��100
	setorigin(originx, 0);
	int x, y, num;
	int deviation = 10;
	int R, G, B;//��¼��ͼĳ��ɫ��
	//��¼�ų���ɫɫ��
	int avoid_r = GetRValue(avoid_color);
	int avoid_g = GetGValue(avoid_color);
	int avoid_b = GetBValue(avoid_color);
	IMAGE pSrcImg;//����ͼ
	IMAGE tempimg;//��ʱ��ͼ
	mainFrame::copy_img(&tempimg, pimg);//����ԭͼ
	SetWorkingImage(NULL);//��Ĭ�ϻ�ͼ���ڵĻ�ͼ����
	getimage(&pSrcImg, dstX, dstY, pimg->getwidth(), pimg->getheight());

	//͸�����ݴ�
	if (tp<0)
	{
		tp = 0;
	}
	else if (tp>100)
	{
		tp = 100;
	}

	// ��ȡ����ָ���Դ��ָ��
	DWORD* bk_pMem = GetImageBuffer(&pSrcImg);

	//��ͼָ���Դ��ָ��
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
