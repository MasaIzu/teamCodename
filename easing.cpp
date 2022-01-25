#include"easing.h"
#include<math.h>

double Easing::easeInOutCubic(double x) {
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

double Easing::easeInBack(double x,double back) {
	const double c1 = back;
	const double c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}

void Easing::EasingMove(int px, int py) {

	//イージングの動き制御
	//	メニュー画面
	if (isEscape == 1) {
		maxTime = 30; maxTime2 = 50; maxTime3 = 60; maxTime4 = 70; maxTime5 = 75;
		y1 = 20; y2 = 80; y3 = 120; y4 = 160; y5 = 200; y6 = 330;
		if (isSelect == 1) {
			if (time <= maxTime) {
				time++;
			}
			if (time2 <= maxTime2) {
				time2++;
			}
			if (time3 <= maxTime3) {
				time3++;
			}
			if (time4 <= maxTime4) {
				time4++;
			}
			if (time5 <= maxTime5) {
				time5++;
			}
			startX = -200; finalX = 10;
			x1 = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
			x2 = (startX - 20) + (finalX - (startX - 20)) * easeInOutCubic(time2 / maxTime2);
			x3 = (startX - 40) + (finalX - (startX - 40)) * easeInOutCubic(time3 / maxTime3);
			x4 = (startX - 60) + (finalX - (startX - 60)) * easeInOutCubic(time4 / maxTime4);
			x5 = (startX - 80) + (finalX - (startX - 80)) * easeInOutCubic(time5 / maxTime5);
			x6 = startX + (finalX + 5 - startX) * easeInOutCubic(time / maxTime);
		}
		else if (isSelect == 2) {
			if (time <= maxTime) {
				time++;
			}
			if (time2 <= maxTime2) {
				time2++;
			}
			if (time3 <= maxTime3) {
				time3++;
			}
			if (time4 <= maxTime4) {
				time4++;
			}
			if (time5 <= maxTime5) {
				time5++;
			}
			startX = 10; finalX = -200;
			x1 = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
			x2 = startX + (finalX - startX) * easeInOutCubic(time2 / (maxTime2 - 30));
			x3 = startX + (finalX - startX) * easeInOutCubic(time3 / (maxTime3 - 24));
			x4 = startX + (finalX - startX) * easeInOutCubic(time4 / (maxTime4 - 20));
			x5 = startX + (finalX - startX) * easeInOutCubic(time5 / (maxTime5 - 16));
			x6 = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
		}
		//矩形の当たり判定
		if (x2 < px && px < x2 + 132) {
			if (y2 < py && py < y2 + 43) {
				isHit2 = 1;
				pal2 = 255; pal3 = 120; pal4 = 120; pal5 = 120;
			}
			else {
				isHit2 = 0;
			}
		}
		else {
			isHit2 = 0;
		}
		if (x3 < px && px < x3 + 132) {
			if (y3 < py && py < y3 + 43) {
				isHit3 = 1;
				pal2 = 120; pal3 = 255; pal4 = 120; pal5 = 120;
			}
			else {
				isHit3 = 0;
			}
		}
		else {
			isHit3 = 0;
		}
		if (x4 < px && px < x4 + 132) {
			if (y4 < py && py < y4 + 43) {
				isHit4 = 1;
				pal2 = 120; pal3 = 120; pal4 = 255; pal5 = 120;
			}
			else {
				isHit4 = 0;
			}
		}
		else {
			isHit4 = 0;
		}
		if (x5 < px && px < x5 + 132) {
			if (y5 < py && py < y5 + 43) {
				isHit5 = 1;
				pal2 = 120; pal3 = 120; pal4 = 120; pal5 = 255;
			}
			else {
				isHit5 = 0;
			}
		}
		else {
			isHit5 = 0;
		}
		if (x6 - 10 < px && px < x6 + 90) {
			if (y6 < py && py < y6 + 53) {
				isHit6 = 1;
				pal2 = 120; pal3 = 120; pal4 = 120; pal5 = 120;
			}
			else {
				isHit6 = 0;
			}
		}
		else {
			isHit6 = 0;
		}
		if (isHit2 == 0 && isHit3 == 0 && isHit4 == 0 && isHit5 == 0 && isHit6 == 0) {
			pal2 = 255; pal3 = 255; pal4 = 255; pal5 = 255;
		}

	}
}

void Easing::EasingLong(char* keys, char* oldkeys) {

	if (isEscape == 0) {
		if (keys[KEY_INPUT_ESCAPE] == 1 && oldkeys[KEY_INPUT_ESCAPE] == 0) {
			isEscape = 1;
			time = 0; time2 = 0; time3 = 0; time4 = 0; time5 = 0;
			x1 = -200; x2 = -200; x3 = -200; x4 = -200; x5 = -200; x6 = -200;
			pal2 = 255; pal3 = 255; pal4 = 255; pal5 = 255;
		}
	}

	//メニューで使うキーたち
	if (isEscape == 1) {

		if (keys[KEY_INPUT_ESCAPE] == 1 && oldkeys[KEY_INPUT_ESCAPE] == 0) {
			if (isSelect == 0) {
				isSelect = 2;
				time = 0; time2 = 0; time3 = 0; time4 = 0; time5 = 0;
			}
			if (isSelect == 1) {
				if (x5 >= finalX) {
					time = 0; time2 = 0; time3 = 0; time4 = 0; time5 = 0;
					isSelect = 2;
				}
			}
			else if (isSelect == 2) {
				if (x5 <= finalX) {
					time = 0; time2 = 0; time3 = 0; time4 = 0; time5 = 0;
					isSelect = 1;
				}
			}
		}

		if (isHit6 == 1) {
			int Mouse = GetMouseInput();
			if (Mouse && MOUSE_INPUT_LEFT) {
				reFlag = 1;
				time = 0; time2 = 0; time3 = 0; time4 = 0; time5 = 0;
			}
		}
		if (reFlag == 1) {
			if (time <= maxTime) {
				time++;
			}
			if (time2 <= maxTime2) {
				time2++;
			}
			if (time3 <= maxTime3) {
				time3++;
			}
			if (time4 <= maxTime4) {
				time4++;
			}
			if (time5 <= maxTime5) {
				time5++;
			}
			startX = 10; finalX = -200;
			x1 = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
			x2 = startX + (finalX - startX) * easeInOutCubic(time2 / (maxTime2 - 30));
			x3 = startX + (finalX - startX) * easeInOutCubic(time3 / (maxTime3 - 24));
			x4 = startX + (finalX - startX) * easeInOutCubic(time4 / (maxTime4 - 20));
			x5 = startX + (finalX - startX) * easeInOutCubic(time5 / (maxTime5 - 16));
			x6 = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
			if (x5 <= finalX) {
				startX = -150; time = 0; nextX = -150;
				finalX = 245; waitTimer = 50; maxTime = 100;
				isEscape = 0; isSelect = 0; reFlag = 0;
			}
		}
	}
}

void Easing::EasingDraw() {

	if (isEscape == 1) {
		DrawBox(0, 0, x1 + 170, 600, GetColor(100, 100, 100), true);
		DrawBox(0, 0, x5 + 170, 600, GetColor(100, 100, 100), true);
		DrawGraph(x1, y1, MenuGh, true);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal2);
		DrawGraph(x2, y2, SettingGh, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal3);
		DrawGraph(x3, y3, GraphicGh, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal4);
		DrawGraph(x4, y4, SoundGh, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal5);
		DrawGraph(x5, y5, GamePlayGh, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (isHit6 == 0) {
			DrawGraph(x1, y6, BackGh, true);
		}
		else {
			DrawGraph(x1, y6, Back2Gh, true);
		}

	}

}

Easing::Easing() {
	// 画像などのリソースデータの変数宣言と読み込み
	nextGh = LoadGraph("push_space.png", true);
	MenuGh = LoadGraph("Menu.png", true);
	GamePlayGh = LoadGraph("GamePlay.png", true);
	GraphicGh = LoadGraph("Graphic.png", true);
	SettingGh = LoadGraph("Setting.png", true);
	SoundGh = LoadGraph("Sound.png", true);
	EscGh = LoadGraph("Esc.png", true);
	BackGh = LoadGraph("Back.png", true);
	Back2Gh = LoadGraph("Back2.png", true);
}

//void Easing::EasingPlayer(int player) {
//	player = startX + (finalX - startX) * easeInOutCubic(time / maxTime);
//}