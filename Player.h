#pragma once
#include "DxLib.h"


class Player
{
public:
	// 画像などのリソースデータの変数宣言と読み込み
	int block = LoadGraph("test.png");

	//メンバ変数
	int x;
	int y;
	int r;
	int speed;

	int rightTopX, rightTopY;
	int rightBottomX, rightBottomY;
	int leftTopX, leftTopY;
	int leftBottomX, leftBottomY;

	int rightTopOldX, rightTopOldY;
	int rightBottomOldX, rightBottomOldY;
	int leftTopOldX, leftTopOldY;
	int leftBottomOldX, leftBottomOldY;

	int playerPosOldX;
	int playerPosOldY;

	int isPlayerStop; int isHitKey;

	//関数制作
	void Move(char* keys,char*oldkeys, int map[][14]);
	void Draw();

	Player(int x, int y, int r, int speed,int isPlayerStop);
};