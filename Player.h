#pragma once
#include "DxLib.h"
#include"Easing.h"
#include"Map.h"

class Player
{
public:

	//メンバ変数
	int x;int y;int r;int speed;

	int rightTopX, rightTopY;
	int rightBottomX, rightBottomY;
	int leftTopX, leftTopY;
	int leftBottomX, leftBottomY;

	int rightTopOldX, rightTopOldY;
	int rightBottomOldX, rightBottomOldY;
	int leftTopOldX, leftTopOldY;
	int leftBottomOldX, leftBottomOldY;
	int oldX; int oldY;

	int isPlayerStop; int isHitKey;

	int isGoal; int isPlayerAlive; int isKeyAlive;

	int Start, Final, oldFinal; double time, maxTime;

	int playerPosX, playerPosY, playerPosOldX, playerPosOldY; int isPush;
	int playerLeftTopX, playerLeftTopY, oldPlayerLeftTopX, oldPlayerLeftTopY;
	
	int keyCount; int onaCount; int playerCount; int trapCount;
private:
	Easing* easing;
	Map MAP;
public:
	//関数制作
	void Move(char* keys, char* oldkeys, int map[6][14]);
	void Draw();

	Player();

};