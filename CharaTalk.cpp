#include "CharaTalk.h"
#include "DxLib.h"

CharaTalk::CharaTalk() {

	for (int i = 0; i < 50; i++) {
		talk[i] = 0;
	}
	isOnly = 0; numberOfTimes = 0; goGame = 0;
	filtaGh = LoadGraph("filta.png");
	playerGh = LoadGraph("chara1.png");
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
	DrawGraph(0, 0, filtaGh, true);

	if (numberOfTimes == 0) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "�����Ȃ�ň�����");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "���̂��Ƃ𓱂��Ă͂���Ȃ����H");
	}
	if (numberOfTimes == 1) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "�������A���傤��");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "�N�݂����Ș��Ղ��Č���鎋�_���~�����Ă�");
	}
	if (numberOfTimes == 3) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "���̂܂܂��ƃS�[���ł��Ȃ�");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "���V�t�g�������Ă���A����̓L�[�{�[�h�ɑΉ����Ă���");
	}
	if (numberOfTimes == 4) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "���̑Ή����Ă�L�[�̓K���ȏꏊ��������");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "�S�[���Ɍ������̂ɕK�v�ȕǂ������");
	}
	DrawRotaGraph(50, 250, 5.0, 0.0, playerGh, true);
}