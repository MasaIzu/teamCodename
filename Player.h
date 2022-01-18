#pragma once
#include "DxLib.h"
#include"Map.h"

class Player
{
public:

	int block;
	int goal;
	int needle;
	int kagi;

	//ƒƒ“ƒo•Ï”
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
	int playerPosOldX; int playerPosOldY;

	int isPlayerStop; int isHitKey;

	int isGoal; int isPlayerAlive; int isKeyAlive;

	
public:
	Map MAP;

	//ŠÖ”§ì
	void Move(char* keys, char* oldkeys, int map[][14]);
	void Draw(int map[][14]);

	Player(int x, int y, int r, int speed);

};