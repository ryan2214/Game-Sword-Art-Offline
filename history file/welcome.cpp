#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <WinUser.h>
#define maxx 1072
#define maxy 600
using namespace std;

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)

int bgm(int a);
int sound(int a);
int game(int a);
int flagstart = 0;
int flagsound = 1;
int blink=1,count=0;
char blank[47] = "                                              ";


void headline(char *a,char *d)
{
	settextstyle(112, 30, _T("SAO UI"));	// ���ô��������
	settextcolor(WHITE);
	outtextxy(200, 180, a);

	if (blink == 1||flagstart==1){
		if (flagstart == 1)settextcolor(YELLOW);
		settextstyle(50, 13, _T("SAO UI"));   //����tip����
		outtextxy(411, 400, d);
	}
	else{
		settextstyle(50, 13, _T("SAO UI"));
		outtextxy(411, 400,blank);
	}                                      //ʵ��tip����˸
	settextcolor(YELLOW);
	setlinecolor(BLACK);
	settextstyle(30, 8, _T("SAO UI"));	// ��������Ϊ��������
}
void clearline(int i)
{
	line(i,0, i,599);
	line(i + 536, 0, i + 536, 599);
	line(i - 536, 0, i - 536, 599);
}                                         //ʵ�ֱ����հ���ɨ��
int main()
{
	
	HWND
		hw = GetHWnd();
	// ���������������
	srand((unsigned)time(NULL));

	// ��ʼ��ͼ��ģʽ
	initgraph(maxx, maxy);
	POINT pt;
	int  x, y;
	char c, linea[] = "s w o r d    a r t    o f f l i n e";
	char nChar;
	char tip[] = "PRESS ENTER TO START";
	
	//bgm(0);
	settextstyle(30, 8, _T("SAO UI"));	// ���������ʼ��

	// ���ñ�����ĸ��ɫ
	settextcolor(YELLOW);
	setlinecolor(BLACK);
	
	for (int i = 0; i <= maxx-1; i++)
	{
		hw = GetHWnd();
		// �����λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 134) * 8;
			y = (rand() % 20) * 30;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}
		
		// ���߲���������
		clearline(i);
		count++;
		if (count == 50){
			blink = -blink;
			count = 0;
		}

		// ��ȡ���λ��
		GetCursorPos(&pt);
		ScreenToClient(hw, &pt);
		if (pt.x >= 411 && pt.y >= 400 && pt.x <= 679 && pt.y <= 450){
			flagstart = 1;
			if (flagsound == 1){
				sound(1);
				flagsound = 0;
			}
			if (KEY_DOWN(VK_LBUTTON)){
				sound(0);
                game(1);
			}
			
		}
		else{
			flagstart = 0;
			flagsound = 1;
		}
		headline(linea,tip);
		
		

		Sleep(10);					// ��ʱ
		if (i >= maxx-1)	i = -1;		// ѭ������
		if (_kbhit())
			switch (nChar = _getch()){
			
			case VK_RETURN:{
				
				sound(0);
				
				game(1); 
			}//��ʼ����Ϸ���ݶ���
			
			case VK_ESCAPE:{
				bgm(9);
				closegraph();// ��ESC���˳�
				return 0;
			}
		}
			
		
	}

	// �ر�ͼ��ģʽ
	closegraph();
}