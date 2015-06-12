#include "mainframe.h"
#include "player.h"
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include "Vfw.h"
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "Vfw32.lib")

#define INIT_ORIGINX 0
#define INIT_FLOOR 1
#define INIT_ROOM 1
#define INIT_LEFTLIMIT 0
#define INIT_RIGHTLIMIT 3216
#define INIT_BGM true
#define INIT_SOUND true

MAINFRAME::MAINFRAME()
{
	originx = INIT_ORIGINX;
	floor = INIT_FLOOR;
	room = INIT_ROOM;
	leftlimit = INIT_LEFTLIMIT;
	rightlimit = INIT_RIGHTLIMIT;
	BGM = INIT_BGM;
	SOUND = INIT_SOUND;
}

MAINFRAME::~MAINFRAME() {}

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)  //��ⰴ���������

#define maxx 1072       //��ʼ����Ļ���
#define maxy 600
#define inter 10        //��ʼ��Sleep�ļ��

void main()
{
	MAINFRAME mainFrame;
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

void MAINFRAME::stillput(bool dir,int x,int y,int ox, IMAGE *player,int type)
{
	switch (type){
	case 0:{
		switch (dir){
		case 0:{
			loadimage(player, "pic/lstill.jpg",180,185,true);
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
		}break;
		case 1:{
			loadimage(player, "pic/rstill.jpg", 180, 185, true);
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
		}break;
		}
	}break;
	case 1:{
		switch (dir){
		case 0:{
			loadimage(player, "pic/les.jpg", 180, 185, true);
			mainFrame::M_putimg(x, y,player, WHITE, 100, ox);
		}break;
		case 1:{
			loadimage(player, "pic/res.jpg", 180, 185, true);
			mainFrame::M_putimg(x, y, player, WHITE, 100, ox);
		}break;
		}
	}break;

	}
}

void MAINFRAME::copy_img(IMAGE* img1, IMAGE* img2)
{
	//copy img2 to img1
	IMAGE* now_working = GetWorkingImage();
	Resize(img1, img2->getwidth(), img2->getheight());
	SetWorkingImage(img2);
	getimage(img1, 0, 0, img1->getwidth(), img1->getheight());
	SetWorkingImage(now_working);
}

int MAINFRAME::getOriginx()
{
	return originx;
}

void MAINFRAME::setOriginx(int num)
{
	originx = num;
}

void MAINFRAME::screenMove(int x, int spd)
{
	if (x > (700 - originx)){              //���ƶ��߽�
		originx -= abs(spd);              //��Ļ����λ�øı�
	}
	if (x < (200 - originx)){              //���ƶ��߽�
		originx +=abs(spd);
	}

	if (originx > 0)originx = 0;           //����originx>=0
	if (originx < -(rightlimit - 1072))originx = -(rightlimit - 1072);     //����originx<=2144
	setorigin(originx, 0);                 //����ԭ��
}

void MAINFRAME::welcomeInit()
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
		if (KEY_DOWN('Q')){           //��Q���˳�
			bgm(9);
			gameExit();
		}
	}/******************��ѭ������*******************/

	// �ر�ͼ��ģʽ
	closegraph();
}

void MAINFRAME::sceneChange(PLAYER *player,bool dir,IMAGE *background)
{
	
	switch (dir)
	{
	case 0:{
		room--;
		if (room < 0){
			room = 0;
			break;
		}
		
		switch (room){
		case 0:{
			loadimage(background, "pic/composer.jpg");
			rightlimit = 1072;
			bgm(10);
			bgm(8);
		}break;
		case 1:{
			loadimage(background, "pic/blank.jpg");
			rightlimit = 3216;
			bgm(10);
			int num1 = rand() % 2;
			switch (num1){
			case 0:bgm(2); break;
			case 1:bgm(6); break;
			}
		}break;
		case 2:{
			loadimage(background, "pic/underground.jpg");
			rightlimit = 2144;
			bgm(10);
			int num2 = rand() % 3;
			switch (num2){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 3:{
			loadimage(background, "pic/underground.jpg");
			rightlimit = 2144;
			bgm(10);
			int num3 = rand() % 3;
			switch (num3){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 4:{
			loadimage(background, "pic/underground.jpg");
			rightlimit = 2144;
			bgm(10);
			int num4 = rand() % 3;
			switch (num4){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 5:{
			loadimage(background, "pic/boss room.jpg");
			rightlimit = 1072;
			bgm(10);
			int num5 = rand() % 2;
			switch (num5){
			case 0:bgm(4); break;
			case 1:bgm(5); break;
			}
		}break;
		}
		originx = -(rightlimit - 1072);
		(*player).teleport(rightlimit-280, 400);
	}break;
	case 1:{
		room++;
		if (room > 5){
			room = 5;
			break;
		}
		
		switch (room){
		case 0:{
			loadimage(background, "pic/composer.jpg");
			rightlimit = 1072;
			bgm(10);
			bgm(8);
		}break;
		case 1:{
			loadimage(background, "pic/blank.jpg");
			rightlimit = 3216;
			bgm(10);
			int num1 = rand() % 2;
			switch (num1){
			case 0:bgm(2); break;
			case 1:bgm(6); break;
			}
		}break;
		case 2:{
			loadimage(background, "pic/underground-2.jpg");
			rightlimit = 2144;
			bgm(10);
			int num2 = rand() % 3;
			switch (num2){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 3:{
			loadimage(background, "pic/underground-2.jpg");
			rightlimit = 2144;
			bgm(10);
			int num3 = rand() % 3;
			switch (num3){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 4:{
			loadimage(background, "pic/underground.jpg");
			rightlimit = 2144;
			bgm(10);
			int num4 = rand() % 3;
			switch (num4){
			case 0:bgm(1); break;
			case 1:bgm(3); break;
			case 2:bgm(7); break;
			}
		}break;
		case 5:{
			loadimage(background, "pic/boss room.jpg");
			rightlimit = 1072;
			bgm(10);
			int num5 = rand() % 2;
			switch (num5){
			case 0:bgm(4); break;
			case 1:bgm(5); break;
			}
		}break;
		}
		originx = 0;
		(*player).teleport(100, 400);
	}break;
	}

	
}

int  MAINFRAME::unlimitedMode()
{
	IMAGE background, wbackground, welcome, player, skillpic250, skillpic300, enemyplayer, hpUI;
	POINT pt;    //��������ͼ��ָ��
	pt.x = 0;   //����ͼ��ָ�븳ֵ
	pt.y = 0;
	
	//link start!
	//HWND hwnd = MCIWndCreate(GetHWnd(), NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOMENU | MCIWNDF_NOPLAYBAR, NULL);
	//MCIWndOpen(hwnd, "avi\\loadgame.wmv", NULL);
	//MCIWndPlay(hwnd);
	//Sleep(17000);

	settextstyle(30, 8, _T("SAO UI"));       //��ʼ�������������ĸ��ɫ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	//setbkmode(TRANSPARENT);

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	setorigin(originx, 0);//���ó�ʼԭ��

	// ����ͨ��ͼƬ
	loadimage(&background, "pic/blank.jpg");	// ��ȷ����ͼƬ�� 1072*600 ����
	loadimage(&wbackground, "pic/whitebk.jpg");
	//������room=0,������Աͷ�񶶶�


	// ���BGM
	int m = rand() % 2;
	switch (m){
	case 0:bgm(2); break;
	case 1:bgm(6); break;
	}

	//����ʱ���ò���
	int tik = 0;
	int comboclear = 0;
	int mobRefresh = 0;
	int AIAttackReady = 0;

	//����ɣ��ҵ���ʿ
	PLAYER kirito;
	//Ϊ���ս���ҵ�Ůʿ
	PLAYER enemy;
	enemy.setHp(100);
	enemy.teleport(0, -200);
	//��������
		
	//��ʼ������ͼ
	BeginBatchDraw();  

	while (1){      /**********************************��Ϸ��ѭ��******************************/

		//����ͼ
		putimage(0, 0, &background);

		//�����ж�
		if (kirito.getHp() <= 0){
			kirito.setHp(0);
			kirito.teleport(kirito.getX(), -200);
		}
		if ((enemy.getHp() <= 0) && (mobRefresh == 0) && room != 1 && room != 0){
			enemy.teleport(0, -200);
			kirito.expAdd(10 * enemy.getLev());
			mobRefresh = 100;
		}
		//����ˢ���ж�
		if (mobRefresh > 0){
			mobRefresh--;
			if (mobRefresh == 1&&room!=1&&room!=0){
				switch (room){
					case 2:
					case 3:
					case 4:{
						int newx = (rand() % rightlimit - 180);
						enemy.teleport(newx, 400);                        //�����λ��
						int newdir = (rand() % 2);
						enemy.setDir(newdir);                             //����·���
						int newhp = (rand() % (kirito.getLev() * 30));
						enemy.setMaxHp(kirito.getLev() * 300 + newhp);	  //�����HP
						enemy.setHp(enemy.getMaxHp());
						enemy.setAttack(kirito.getLev() * 25 + 30);	
						enemy.setLevel(kirito.getLev());
																			//�¹���
					}break;
					case 5:{
						int newx = (rand() % rightlimit - 180);
						enemy.teleport(newx, 400);                        //�����λ��
						int newdir = (rand() % 2);
						enemy.setDir(newdir);                             //����·���
						int newhp = (rand() % (kirito.getLev() * 300));
						enemy.setMaxHp(kirito.getLev() * 1000 + newhp);	  //�����HP
						enemy.setHp(enemy.getMaxHp());
						enemy.setAttack(kirito.getLev() * 100 + 30);			//�¹���
						enemy.setLevel(kirito.getLev());
					}break;
				}
			}
		}
		//Ħ����(Kirito��enemy)
		if(kirito.getMovespd()>0&&!kirito.jumpJudge())
			kirito.setSpd(kirito.getMovespd() - 1);
		if (kirito.getMovespd()<0&&!kirito.jumpJudge())
			kirito.setSpd(kirito.getMovespd() + 1);
		if (enemy.getMovespd()>0 && !enemy.jumpJudge())
			enemy.setSpd(enemy.getMovespd() - 1);
		if (enemy.getMovespd()<0 && !enemy.jumpJudge())
			enemy.setSpd(enemy.getMovespd() + 1);
		//HP�����ظ�
		if (kirito.getHp()<kirito.getMaxHp() && kirito.getHp()>0)
		kirito.hpRege();
		//HPUI
		int khp = kirito.getHp(), kmhp = kirito.getMaxHp();
		mainFrame::hpUI(&khp, &kmhp);
		int ehp = enemy.getHp(), emhp = enemy.getMaxHp(), ex = enemy.getX(),ey=enemy.getY();
		enemyHpUI(&ehp, &emhp, &ex,&ey);
		//������UI
		otherUI(&kirito);
		//�����ж�
		kirito.levelUpCheck();
		//kirito�ƶ�
		kirito.moveX(&leftlimit,&rightlimit);
		//enemy�ƶ�
		int kx = kirito.getX();
		enemy.AIFind(&kx);
		enemy.moveX(&leftlimit, &rightlimit);
		if (AIAttackReady >= 50&&enemy.stillJudge()){
			enemy.AIAttack(&kirito);
			AIAttackReady = 0;
		}
		AIAttackReady++;
		//�������λ�ã��ƶ���Ļ
		screenMove(kirito.getX(), kirito.getMovespd());

		//��ֹ����ͼƬ
		if (enemy.stillJudge()){
			stillput(enemy.getDir(), enemy.getX(), enemy.getY(), originx, &enemyplayer, 1); 
		}

		//���м�������ʱִ��
		if (_kbhit()){

			if (KEY_DOWN('J') && (!kirito.coolingJudge()) && (!kirito.jumpJudge()) && (!kirito.runJudge())){
				int ex = enemy.getX(), eh = enemy.getHp();		//�ñ�����ȡֵ����															//��ͨ����"J"
				kirito.meleeAttack(&ex, &eh, &enemy, &player, &enemyplayer, &skillpic250, &skillpic300, originx);
				sound(2);
			}

			if (KEY_DOWN('K') && kirito.stillJudge() && (!kirito.coolingJudge())){
				int ex = enemy.getX(), eh = enemy.getHp();																	//���ٳ��"K"
				kirito.sonicLeap(&ex, &eh, &enemy, &player, &enemyplayer, &skillpic250, &skillpic300, originx);
				sound(2);
			}
			if (KEY_DOWN('L') && kirito.stillJudge() && (!kirito.coolingJudge())){
				int ex = enemy.getX(), eh = enemy.getHp();																	//ˮƽ�ķ�ն"L"
				kirito.horizontalSquare(&ex, &eh, &enemy, &player, &enemyplayer, &skillpic250, &skillpic300, originx);
				sound(2);
			}
			else if(kirito.getCombo()==0&&kirito.getSkillState()==0&&kirito.getSkillType()==0){
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
				if (KEY_DOWN('W')){					//����ת��
					if (kirito.getX() - leftlimit <= 50){
						sceneChange(&kirito, 0, &background);
						enemy.setHp(-1);
						mobRefresh = 100;
						enemy.teleport(0, -200);
					}
					if (rightlimit - kirito.getX() <= 230){
						sceneChange(&kirito, 1, &background);
						enemy.setHp(-1);
						mobRefresh = 100;
						enemy.teleport(0, -200);
					}
				}
				if (KEY_DOWN(VK_ESCAPE)){			//ESC�˳�
					bgm(10);
					return 0;
				}
				if (KEY_DOWN('R')){
					kirito.respawn();
				}
				}
		}

		//��kirito������Ծ״̬������Yֵ�ı�ͻ�ͼ
		if (kirito.jumpJudge()){    
			kirito.jump();
			switch (kirito.getDir()){
			case 0:loadimage(&player, "pic/ll4.jpg"); break;
			case 1:loadimage(&player, "pic/rr4.jpg"); break;
			}
			kirito.setCombo(0);
			kirito.setSkillType(0);
			kirito.setSkillState(0);
			M_putimg(kirito.getX(), kirito.getY(), &player, WHITE, 100, originx);
			
		}
		//��kirito�����ܶ�״̬�������ܲ���ͼ
		if (kirito.runJudge() && !kirito.jumpJudge() && !kirito.stillJudge()){
			kirito.running(&player, originx);
		}
		//�����ͷ�ʱ�����ƺ���Ч����
		kirito.skillEffect(&skillpic250,&skillpic300,&player,&enemyplayer,&enemy,originx);
	
		//between
		if (!kirito.stillJudge()){
			kirito.setStill(kirito.getStill() + 1);
			M_putimg(kirito.getX(), kirito.getY(), &player, WHITE, 100, originx);
		}
		if (!enemy.stillJudge()){
			enemy.setStill(enemy.getStill() + 1);
			M_putimg(enemy.getX(), enemy.getY(), &enemyplayer, WHITE, 100, originx);
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

void MAINFRAME::bgm(int song)
{
	if (BGM)
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
	case 8:{
		mciSendString(TEXT("open bgm/X.U..mp3 alias MySong"), NULL, 0, NULL);
		mciSendString(TEXT("play MySong"), NULL, 0, NULL);
	}break;

	case 10:{
		mciSendString(TEXT("close MySong"), NULL, 0, NULL);
	}
	case 9:{
		mciSendString(TEXT("stop MySong"), NULL, 0, NULL);
	}
	default:break;
	}
}

void MAINFRAME::sound(int soundtype)
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
	
	default:break;
	}
}

void MAINFRAME::gameExit()
{
	bgm(9);
	closegraph();
}

void MAINFRAME::hpUI(int *hp, int *maxHp)
{
	IMAGE hpTIAO, hpCAO;
	float hpRatio = (1.0*(*hp)) / (1.0*(*maxHp));
	int hpPix = hpRatio * 258;
	char hps[30] = "\0";

	if (hpRatio > 0.66)								//����Ѫ��������Ӧ��ɫ��hpTIAO
		loadimage(&hpTIAO, "pic/hp_green.jpg",hpPix,24,true);
	if (hpRatio > 0.33&&hpRatio <= 0.66)
		loadimage(&hpTIAO, "pic/hp_yellow.jpg", hpPix, 24, true);
	if (hpRatio <= 0.33)
		loadimage(&hpTIAO, "pic/hp_red.jpg", hpPix, 24, true);
	loadimage(&hpCAO, "pic/hp_bar.jpg");			//����hpCAO
	sprintf_s(hps, "%d / %d",*hp,*maxHp);
	//ͼ�����
	if (hp > 0){
		M_putimg(75 - originx, 12, &hpTIAO, WHITE, 100, originx);
		HPCAO_putimg(0 - originx, 0, &hpCAO, WHITE, 80, originx);
		outtextxy(250-originx,30,hps);
	}
}

void MAINFRAME::otherUI(PLAYER* player)
{
	char movespd[20];
	char still[20];
	char combo[10];
	char skilltype[20];
	char skillstate[20];
	char level[30];
	char exp[30];
	char atk[30];
	sprintf_s(movespd, "MOVESPD:%d", (*player).getMovespd());
	sprintf_s(still, "STILL:%d", (*player).getStill());
	sprintf_s(combo, "COMBO:%d", (*player).getCombo());
	sprintf_s(skilltype, "SKILLTYPE:%d", (*player).getSkillType());
	sprintf_s(skillstate, "SKILLSTATE:%d", (*player).getSkillState());
	sprintf_s(level, "LEVEL:%d", (*player).getLev());
	sprintf_s(exp, "EXP:%d / %d", (*player).getExp(), 25*(*player).getLev()*(*player).getLev() + (*player).getLev() * 5 + 20);
	sprintf_s(atk, "ATTACK:%d", (*player).getAttack());
	outtextxy(-originx, 50, movespd);
	outtextxy(-originx, 90, still);
	outtextxy(-originx, 130, combo);
	outtextxy(-originx, 170, skilltype);
	outtextxy(-originx, 210, skillstate);
	outtextxy(-originx, 250, level);
	outtextxy(-originx, 290, exp);
	outtextxy(-originx, 330, atk);
}

void MAINFRAME::enemyHpUI(int *hp, int *maxHp,int *x,int *y)
{
	IMAGE hpTIAO;
	float hpRatio = (1.0*(*hp)) / (1.0*(*maxHp));
	int hpPix = hpRatio * 180;
	char hpNum[20];
	sprintf_s(hpNum, "%d / %d", *hp,*maxHp);
	if (hpRatio > 0.66)								//����Ѫ��������Ӧ��ɫ��hpTIAO
		loadimage(&hpTIAO, "pic/hp_enemy_green.jpg", hpPix, 24, true);
	if (hpRatio > 0.33&&hpRatio <= 0.66)
		loadimage(&hpTIAO, "pic/hp_enemy_yellow.jpg", hpPix, 24, true);
	if (hpRatio <= 0.33)
		loadimage(&hpTIAO, "pic/hp_enemy_red.jpg", hpPix, 24, true);
	//ͼ�����
	M_putimg(*x, *y-20, &hpTIAO, WHITE, 100, originx);
	outtextxy(*x+180, *y - 20, hpNum);
}

void MAINFRAME::M_putimg(int dstX, int dstY, IMAGE *pimg, int avoid_color, int tp, int originx)
{
	//�ų���ɫavoid_color,�ݲ�Ϊdeviation��͸����tp(transparency)��0��100
	setorigin(originx, 0);
	int x, y, num;
	int deviation = 100;
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

void MAINFRAME::HPCAO_putimg(int dstX, int dstY, IMAGE *pimg, int avoid_color, int tp, int originx)
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