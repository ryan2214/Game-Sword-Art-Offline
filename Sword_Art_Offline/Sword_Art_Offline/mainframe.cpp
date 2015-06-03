#include "mainframe.h"
#pragma comment (lib, "winmm.lib")

__MAINFRAME::__MAINFRAME() {}

__MAINFRAME::~__MAINFRAME() {}

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)  //��ⰴ���������

#define maxx 1072       //��ʼ����Ļ���
#define maxy 600
#define inter 10        //��ʼ��Sleep�ļ��


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
