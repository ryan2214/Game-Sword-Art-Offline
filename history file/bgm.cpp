#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include <graphics.h>
#pragma comment (lib, "winmm.lib")

int bgm(int a)
{
	switch (a){
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
	
	return 0;
}