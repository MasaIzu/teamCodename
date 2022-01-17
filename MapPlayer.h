#pragma once
#include "DxLib.h"
#include"Scene.h"
#include"Map.h"

class Player
{
public:

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
	int playerPosOldX; int playerPosOldY;

	int isPlayerStop; int isHitKey;

	int isGoal; int isPlayerAlive;

	
public:
	Map MAP;
	Scene SCENE;
	//関数制作
	void Move(char* keys, char* oldkeys, int map[][14]);
	void Draw(int map[][14], int block, int goal, int needle,int key);

	Player(int x, int y, int r, int speed);

};