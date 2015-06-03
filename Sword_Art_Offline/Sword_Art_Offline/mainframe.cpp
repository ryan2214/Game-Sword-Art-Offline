#include "mainframe.h"
#include "enemy.h"
#pragma comment (lib, "winmm.lib")

__MAINFRAME::__MAINFRAME() {}

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

void copy_img(IMAGE* img1, IMAGE* img2)
{
	//copy img2 to img1
	IMAGE* now_working = GetWorkingImage();
	Resize(img1, img2->getwidth(), img2->getheight());
	SetWorkingImage(img2);
	getimage(img1, 0, 0, img1->getwidth(), img1->getheight());
	SetWorkingImage(now_working);
}

void M_clear(POINT pt, IMAGE *bk,IMAGE pic)//pt��һ������ͼƬ��������꣬bk����ͼƬ
{
	IMAGE clear;
	SetWorkingImage(bk);//�趨��ǰ�Ļ�ͼ�豸Ϊ����ͼƬ
	getimage(&clear, pt.x, pt.y, pic.getwidth(), pic.getheight());//��ȡͼ��
	SetWorkingImage();//�趨��Ĭ�ϻ�ͼ����
	putimage(pt.x, pt.y, &clear);//���
}

int mainFrame::getOriginx()
{
	return originx;
}

void mainFrame::screenMove(int x,int spd)
{
	if (x > (500 - getOriginx())){              //���ƶ��߽�
		setOriginx(getOriginx() - spd);              //��Ļ����λ�øı�
	}
	if (x < (120 - getOriginx())){              //���ƶ��߽�
		setOriginx(getOriginx() + spd);
	}

	if (getOriginx() > 0)setOriginx(0);           //����originx>=0
	if (getOriginx() < -2144)setOriginx(- 2144);     //����originx<=2144
	setorigin(getOriginx(), 0);                 //����ԭ��
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
	
	bgm(0);                                  //����crossing_field.mp3
	
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
				//unlimitedMode();
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
			//unlimitedMode();
		}
		if (KEY_DOWN(VK_ESCAPE)){           //��ESC���˳�
			bgm(9);
			gameExit();
		}
	}/******************��ѭ������*******************/

	// �ر�ͼ��ģʽ
	closegraph();
}

void mainFrame::dataInit()
{
	kirito.teleport(300,400);            //��ʼ��kirito����
	kirito.setDir(1);
	kirito.setMaxHp(100);
	kirito.setHp(50);
	kirito.setAttack(10);
	kirito.setSpd(10);     //��λpx
	kirito.setSkillState(0);

	enemy.teleport(500, 400);            //��ʼ��enemy����
	enemy.setDir(0);
	enemy.setMaxHp(100);
	enemy.setHp(50);
	enemy.setAttack(10);
	enemy.setSpd(10);
	enemy.setSkillState(0);
}

void mainFrame::unlimitedMode()
{
	IMAGE background, wbackground, welcome, player, skillpic250, skillpic300, enemyplayer, hpUI;
	POINT pt;    //��������ͼ��ָ��
	int comboclear = 0;
	
	//link start!
	//HWND hwnd = MCIWndCreate(GetHWnd(), NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOMENU | MCIWNDF_NOPLAYBAR, NULL);
	//MCIWndOpen(hwnd, "avi\\loadgame.wmv", NULL);
	//MCIWndPlay(hwnd);
	//Sleep(17000);

		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

		setorigin(originx, 0);//���ó�ʼԭ��

		// ����ͼƬ
		loadimage(&welcome, "pic/welcome.jpg");
		loadimage(&background, "pic/blank.jpg");	// ��ȷ����ͼƬ�� 1072*600 ����
		loadimage(&hpUI, "pic/hp_bar.jpg");
		loadimage(&wbackground, "pic/whitebk.jpg");

		dataInit();//�����ɫ����ֵ

		pt.x = 0;   //����ͼ��ָ�븳ֵ
		pt.y = 0;

		//���BGM
		int m = ((rand() % 7) + 1);
		bgm(m);
		BeginBatchDraw();  //��ʼ������ͼ

		while (1){      //**********************************��Ϸ��ѭ��******************************

			//�������λ�ã��ƶ���Ļ
			screenMove(kirito.getX(),kirito.getMovespd());

			if (kirito.getHp() <= 0)kirito.teleport(0,600);  //�����ж�
			if (enemy.getHp() <= 0)enemy.teleport(0,600);

			//���м�������ʱִ��
			if (_kbhit()){

				if (KEY_DOWN('J') && (!kirito.stillJudge())){                 //��ͨ����"J"
					kirito.useSkill(1);
				}

				else{
					if (KEY_DOWN(VK_SPACE) && (!kirito.stillJudge())){        //��Space��Ծ
						kirito.startJump();
					}

					                     
					if (KEY_DOWN('A')){                                       //��A�����ƶ�
						kirito.setDir(0);
						kirito.moveX(player);
						}
					if (KEY_DOWN('D')){                                       //��D�����ƶ�
						kirito.setDir(1);
						kirito.moveX(player);
						}
					
					if (KEY_DOWN(VK_ESCAPE)) closegraph();                    //ESC�˳�
				}
			}

			if (kirito.jumpJudge()){    //��kirito������Ծ״̬������Yֵ�ı�
				kirito.jump();
			}
			if (kirito.getSkill() > 0){
				switch (kirito.getSkill()){
				case 1:{
					switch (kirito.getCombo()){
					case 1:break;
					}
				}break;
				}
			}
				
            if (kirito.stillJudge()){                    //��ֹʱ
				comboclear++;
				if (comboclear == 20){
					comboclear = 0;
					kirito.setCombo(0);
				}
				kirito.still(kirito.getDir(), kirito.getX(), kirito.getY(), originx, player);   //��ֹ��ɫͼƬ
			}
			if (enemy.stillJudge()){
				kirito.still(enemy.getDir(), enemy.getX(), enemy.getY(), originx, enemyplayer);
			}

			FlushBatchDraw();      //���ƽ�����
			Sleep(inter);          //����֡��
			M_clear(pt, &background,background);    //��ջ���


		}//***************************************��ѭ������*******************************************

		closegraph();
	
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
	copy_img(&tempimg, pimg);//����ԭͼ
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
