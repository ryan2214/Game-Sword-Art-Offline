#include <graphics.h>
#pragma comment (lib, "winmm.lib")

int sound(int a)
{
	switch (a){
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

	return 0;
}