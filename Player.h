#pragma once
#include "DxLib.h"


class Player
{
public:
	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int block = LoadGraph("test.png");

	//�����o�ϐ�
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

	//�֐�����
	void Move(char* keys,char*oldkeys, int map[][14]);
	void Draw();

	Player(int x, int y, int r, int speed,int isPlayerStop);
};