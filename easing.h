#pragma once
#include "DxLib.h"

class Easing
{
public:
	// 画像などのリソースデータの変数宣言と読み込み
	int nextGh;
	int MenuGh ;
	int GamePlayGh ;
	int GraphicGh ;
	int SettingGh ;
	int SoundGh ;
	int EscGh ;
	int BackGh ;
	int Back2Gh ;

	//メンバ変数

	int isEscape = 0;

	int flag[100];
	int randx[100];
	int randy[100];

	int LongX; int LongY;
	int hafuX; int hafuY;
	int LongXL; int LongYL;
	int pxLx; int pyLy;

	int maxCircle = 97; int maxCircle2 = 100;

	int frame = 0; int maxFrame = 1;

	float downSpeed[100];

	int redColor[100] = { 100 }; int lowRedColor[100];
	int greenColor[100] = { 0 }; int lowGreenColor[100];
	int blueColor[100] = { 255 }; int lowBlueColor[100];

	int whatColor[100];
	int pal = 127; int pal2; int pal3; int pal4; int pal5;

	double time; double time2; double time3; double time4; double time5;
	double maxTime = 100; double maxTime2 = 102; double maxTime3 = 104;
	double maxTime4 = 106; double maxTime5 = 107; double waitTimer = 50;
	double nextX; double nextX2; double nextX3;
	double startX = -150; double finalX = 245;

	int nexTimer = 500;

	int isOnly = 0; int fastTimer; int invsrc = 0;

	double x1, x2, x3, x4, x5, x6; int y1, y2, y3, y4, y5, y6;
	int isSelect = 0;
	int playerPosX = 500; int playerPosY = 200; int radius = 10;
	int isHit, isHit2, isHit3, isHit4, isHit5, isHit6;

	int reFlag = 0; int reFlag2 = 0;

	//関数の制作
	void EasingMove( int px, int py);
	void EasingLong(char* keys, char* oldkeys);
	void EasingDraw();

	double easeInOutCubic(double x);
	
	Easing();

};