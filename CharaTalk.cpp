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
	//DrawGraph(0, 0, filtaGh, true);

	if (numberOfTimes == 0) {
		DrawFormatString(150, 600, GetColor(255, 255, 255), "初めまして！私はガイド！よろしくね！");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "いきなりだけどもチュートリアルを始めるよ！");
	}
	if (numberOfTimes == 1) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "↑↓←→で移動！　英数キーで【ブロックを配置】できるよ！");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "それじゃあ実際にやってみよう！");
	}
	if (numberOfTimes == 3) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "このままだとゴールできない,,!ブロックを配置してみよう！");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "ヒント:左シフトを押すとマップに対応したキーの位置がわかるよ！");
	}
	if (numberOfTimes == 4) {
		DrawFormatString(150, 600, GetColor (255, 255, 255), "その対応してるキーの適当な場所を押すと,ゴールに向かうのに");
		DrawFormatString(150, 642, GetColor (255, 255, 255), "必要な壁を作れるんだ!");
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
	DrawFormatString (826, 655, GetColor (255, 255, 255), "SPACE▼");
	SetFontSize (23);
	
}