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
//				char nextTalk[] = { 'い','き','な','り','で','悪','い','ん','だ','け','ど',
//									'僕','の','こ','と','を','導','い,','て','く','れ','な','い','か','な','？' };
//				talk[i] = nextTalk[i];
//				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
//					numberOfTimes = 1;
//					for (int i = 0; i < 50; i++) {
//						talk[i] = 0;
//					}
//				}
//			}
//			else if (numberOfTimes == 1 && talk[i] == 0) {
//				char nextTalk[] = { '助','か','る','よ','。','ち','ょ','う','ど','君','み','た','い','な',
//									'俯','瞰','し','て','見','れ','る','視','点','が','欲','し','く','て','ね' };
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
		DrawFormatString(150, 200, GetColor(25, 25, 25), "いきなりで悪いが");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "私のことを導いてはくれないか？");
	}
	if (numberOfTimes == 1) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "助かるよ、ちょうど");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "君みたいな俯瞰して見れる視点が欲しくてね");
	}
	if (numberOfTimes == 3) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "このままだとゴールできない");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "左シフトを押してくれ、それはキーボードに対応している");
	}
	if (numberOfTimes == 4) {
		DrawFormatString(150, 200, GetColor(25, 25, 25), "その対応してるキーの適当な場所を押すと");
		DrawFormatString(150, 250, GetColor(25, 25, 25), "ゴールに向かうのに必要な壁を作れるんだ");
	}
	DrawRotaGraph(50, 250, 5.0, 0.0, playerGh, true);
}