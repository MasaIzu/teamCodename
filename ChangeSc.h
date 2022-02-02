#pragma once
#include"struct.h"
#include"easing.h"

class ChangeSc
{
public:
	int changeScAnm[7];	//画像格納
	int strAnm[6];

	int isChangeSc;	//イージング関数と動きのフェーズ
	int faze;
	int time;
	int time2;
	int waitTime;
	int maxTime;
	int maxtime2;
	int isChangeScene;

	float randomX;	//シェイクで使います。ごめんなさいごめんなさいごめんなさい
	float randomY;

	Pos rightP;	//位置
	Pos leftP;
	Pos topP;
	Pos botP;
	Pos strP;

	Easing easing;	//包含

	void Update ();	//毎フレームの更新
	void Draw ();	//描画

	ChangeSc ();	//コンストラクタ

};

