#pragma once
#include"struct.h"
#include"easing.h"

class ChangeSc
{
public:
	int changeScAnm[7];	//�摜�i�[
	int strAnm[6];

	int isChangeSc;	//�C�[�W���O�֐��Ɠ����̃t�F�[�Y
	int faze;
	int time;
	int time2;
	int waitTime;
	int maxTime;
	int maxtime2;
	int isChangeScene;

	float randomX;	//�V�F�C�N�Ŏg���܂��B���߂�Ȃ������߂�Ȃ������߂�Ȃ���
	float randomY;

	Pos rightP;	//�ʒu
	Pos leftP;
	Pos topP;
	Pos botP;
	Pos strP;

	Easing easing;	//���

	void Update ();	//���t���[���̍X�V
	void Draw ();	//�`��

	ChangeSc ();	//�R���X�g���N�^

};

