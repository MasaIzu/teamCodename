#include "ChangeSc.h"
#include "DxLib.h"

ChangeSc::ChangeSc () {

	this->faze = 0;
	this->isChangeSc = 0;	//チェンジスクリーンのフラグ
	this->topP.x = 0;
	this->topP.y = -300;
	this->botP.x = 0;
	this->botP.y = 300;
	this->leftP.x = -250;
	this->leftP.y = 0;
	this->rightP.x = 250;
	this->rightP.y = 0;
	this->time = 0;
	this->time2 = -10;
	this->maxTime = 20;
	this->maxtime2 = 30;
	this->randomX = 0;
	this->randomY = 0;
	this->strP.x = 0;
	this->strP.y = 0;
	this->waitTime = 0;
	this->isChangeScene = 0;
	this->titleFaze = 1;

	this->changeScAnm[6] = {};
	LoadDivGraph ("changeScAnm.png",
				  7, 7, 1, 896, 700,
				  changeScAnm);

	this->strAnm[5] = {};
	LoadDivGraph ("strAnm.png",
				  6, 6, 1, 496, 152,
				  strAnm);

}

//changeは移動量。baseは最初の位置。durationは移動時間で、timeが現在の経過時間

void ChangeSc::Update () {

	if ( titleFaze != 0 ) {
		if ( titleFaze == 1 ) {
			if ( time <= 10 ) {
				
				this->leftP.x = 0;
				this->rightP.x = 0;
				this->topP.y = 0;
				this->botP.y = 0;
				this->strP.x = 248;
				this->strP.y = 76;

			}
			else {
				waitTime++;
				if ( waitTime > 3 ) {
					titleFaze = 2;
					waitTime = 0;
					time = 0;
					time2 = 0;

				}
			}
		}
		else if (titleFaze == 2) {

			if ( time <= maxTime ) {
				this->leftP.x = easing.OutQuad (-220, 0, maxTime, time);
				this->rightP.x = easing.OutQuad (220, 0, maxTime, time);
				this->topP.y = easing.OutQuad (-300, 0, maxTime, time);
				this->botP.y = easing.OutQuad (300, 0, maxTime, time);
				this->strP.x = easing.InQuad (-248, 248, 20, time);
				this->strP.y = easing.OutQuad (-76, 76, 20, time);
			}
			else {
				time = 0;
				time2 = -10;
				isChangeSc = 0;
				waitTime = 0;
				titleFaze = 0;

			}
		}
		if ( titleFaze == 2 ) {
			time++;

		}

	}

	if ( isChangeSc == 1 ) {//アニメーション開始フェーズ
		if ( faze == 2 ) {
			time--;
		}
		else {
			if ( time < 20 ) {
				time++;
			}
			time2++;
		}

		if ( faze == 0 ) {	//初期化フェーズ
			faze = 1;
			time = 0;
		}
		else if ( faze == 1 ) {
			if ( time2 <= maxTime ) {
				this->leftP.x = easing.OutQuad (220, -220, maxTime, time2);	//changeは移動量。baseは最初の位置。durationは移動時間で、timeが現在の経過時間
				this->rightP.x = easing.OutQuad (-220, 220, maxTime, time2);
				this->topP.y = easing.OutQuad (300, -300, maxTime, time);
				this->botP.y = easing.OutQuad (-300, 300, maxTime, time);
			}
			else {
				time = 10;
				time2 = 0;
				faze = 2;
			}
		}
		else if ( faze == 2 ) {
			if ( time > 0 ) {

				randomX = (1 + rand ()) % time * 3 - time * 3 / 2;
				randomY = (1 + rand ()) % time * 3 - time * 3 / 2;
			}
			else {
				randomX = 0;
				randomY = 0;
				time = 0;
				time2 = -10;
				faze = 3;
			}
		}
		else if ( faze == 3 ) {
			if ( time <= 10 ) {
				this->strP.x = easing.OutQuad (248, 0, 10, time);
				this->strP.y = easing.InQuad (76, 0, 10, time);
			}
			else {

				waitTime++;
				if ( waitTime > 20 ) {
					faze = 4;
					waitTime = 0;
					time = 0;
					time2 = -10;
					isChangeScene = 1;
				}
			}

		}
		else if ( faze == 4 ) {
			if ( time <= 10 ) {
				this->strP.x = easing.InQuad (-248, 248, 10, time);
				this->strP.y = easing.OutQuad (-76, 76, 10, time);
			}
			else {
				waitTime++;
				if ( waitTime > 3 ) {
					faze = 5;
					waitTime = 0;
					time = 0;
					time2 = 0;
					
				}
			}

		}
		else if ( faze == 5 ) {
			if ( time2 <= maxTime ) {
				this->leftP.x = easing.OutQuad (-220, 0, maxTime, time2);
				this->rightP.x = easing.OutQuad (220, 0, maxTime, time2);
				this->topP.y = easing.OutQuad (-300, 0, maxTime, time);
				this->botP.y = easing.OutQuad (300, 0, maxTime, time);
			}
			else {
				time = 0;
				time2 = -10;
				isChangeSc = 0;
				waitTime = 0;
				faze = 0;
			}
		}
		else {
			isChangeSc = 0;
			isChangeScene = 0;
		}

	}

}

void ChangeSc::Draw () {
	if ( isChangeSc == 1 || titleFaze != 0) {
		DrawGraph (this->topP.x + randomX, this->topP.y + randomY, changeScAnm[3], true);
		DrawGraph (this->botP.x + randomX, this->botP.y + randomY, changeScAnm[4], true);
		DrawGraph (this->leftP.x + randomX, this->leftP.y + randomY, changeScAnm[1], true);
		DrawGraph (this->rightP.x + randomX, this->rightP.y + randomY, changeScAnm[2], true);
		if ( faze == 3 || faze == 4 || titleFaze != 0) {
			DrawModiGraph (-this->strP.x + 896 / 2, -this->strP.y + 700 / 2,
						   this->strP.x + 896 / 2, -this->strP.y + 700 / 2,
						   this->strP.x + 896 / 2, this->strP.y + 700 / 2,
						   -this->strP.x + 896 / 2, this->strP.y + 700 / 2, strAnm[0], true);
		}
	}
}
