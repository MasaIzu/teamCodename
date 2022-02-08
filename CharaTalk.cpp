#include "CharaTalk.h"
#include "DxLib.h"

CharaTalk::CharaTalk() {

	for (int i = 0; i < 50; i++) {
		talk[i] = 0;
	}
	isOnly = 0; numberOfTimes = 0; goGame = 0;
	filtaGh = LoadGraph("filta.png");
	playerGh[6] = {};
	playerAnmC = 0;
	waitTimer = 0;

	LoadDivGraph ("denkiChanAnm.png",
				  6,6,1,64,64,
				  playerGh);
}

void CharaTalk::CharContents(char* keys, char* oldkeys) {
	
	if (numberOfTimes == 0) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			numberOfTimes = 1;
		}
	}
	else if (numberOfTimes == 1) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			goGame = 1;
			numberOfTimes = 2;
		}
	}
	else if (numberOfTimes == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			numberOfTimes = 4;
		}
	}
	else if (numberOfTimes == 4) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			goGame = 0;
			numberOfTimes = 5;
		}
	}
}

//void CharaTalk::CharContents(char* keys, char* oldkeys, int scene) {
//	if (scene == 1) {
//		for (int i = 0; i < 50; i++) {
//			if (numberOfTimes == 0 && talk[i] == 0) {
//				char nextTalk[] = { '��','��','��','��','��','��','��','��','��','��','��',
//									'�l','��','��','��','��','��','��,','��','��','��','��','��','��','��','�H' };
//				talk[i] = nextTalk[i];
//				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
//					numberOfTimes = 1;
//					for (int i = 0; i < 50; i++) {
//						talk[i] = 0;
//					}
//				}
//			}
//			else if (numberOfTimes == 1 && talk[i] == 0) {
//				char nextTalk[] = { '��','��','��','��','�B','��','��','��','��','�N','��','��','��','��',
//									'��','��','��','��','��','��','��','��','�_','��','�~','��','��','��','��' };
//				talk[i] = nextTalk[i];
//				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
//					scene = 2;
//					for (int i = 0; i < 50; i++) {
//						talk[i] = 0;
//					}
//				}
//			}
//		}
//	}
//}


void CharaTalk::CharDraw() {
	SetFontSize(23);
	//DrawGraph(0, 0, filtaGh, true);

	if (numberOfTimes == 0) {
		DrawFormatString(150, 600, GetColor(255, 255, 255), "���߂܂��āI���̓K�C�h�I��낵���ˁI");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "�����Ȃ肾���ǂ��`���[�g���A�����n�߂��I");
	}
	if (numberOfTimes == 1) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "���������ňړ��I�@�p���L�[�Ły�u���b�N��z�u�z�ł����I");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "���ꂶ�Ⴀ���ۂɂ���Ă݂悤�I");
	}
	if (numberOfTimes == 3) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "���̂܂܂��ƃS�[���ł��Ȃ�,,!�u���b�N��z�u���Ă݂悤�I");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "�q���g:���V�t�g�������ƃ}�b�v�ɑΉ������L�[�̈ʒu���킩���I");
	}
	if (numberOfTimes == 4) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "���̑Ή����Ă�L�[�̓K���ȏꏊ��������,�S�[���Ɍ������̂�");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "�K�v�ȕǂ������!");
	}
	

	if ( playerAnmC < 5 ) {
		if ( waitTimer == 0 ) {
			playerAnmC++;
		}
		else {
			waitTimer++;
		}
	}
	else {
		playerAnmC = 0;
		waitTimer++;
	}

	if ( waitTimer >= 120 ) {
		waitTimer = 0;
	}
	DrawRotaGraph(80, 650, 2.0, 0.0, playerGh[playerAnmC], true);
	DrawBox (20, 580, 876, 680, 0xffffff, false);
	SetFontSize (12);
	DrawFormatString (826, 655, GetColor (255, 255, 255), "SPACE��");
	SetFontSize (23);
	
}