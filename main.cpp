#include "DxLib.h"
#include "key.h"
#include"Player.h"
#include "Map.h"
#include"Easing.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LC1B_22_ニシザワユウガ: タイトルunnnnch";

// ウィンドウ横幅
const int WIN_WIDTH = 896;

// ウィンドウ縦幅
const int WIN_HEIGHT = 384;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	

	// ゲームループで使う変数の宣言

	Key* key = new Key;
	Player* player = new Player(230, 230, 5, 64, 0);
	Map* MAP = new Map;
	Easing* easing = new Easing;

	int x, y;
	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i) {
			oldkeys[i] = keys[i];
		}
		//配列なのでoldkey = keys;のようにできない。要素を一つずつコピー
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);
		GetMousePoint(&x, &y);
		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

		player->Move(keys, oldkeys,MAP->map);
		key->Inputkey(keys, oldkeys, MAP->map, player->leftTopX, player->leftTopY);
		easing->EasingMove(x, y);
		easing->EasingLong(keys,oldkeys);
		
		// 描画処理
		for (int y = 0; y < MAP->mapCountY; y++) {
			for (int x = 0; x < MAP->mapCountX; x++) {
				if (MAP->map[y][x] == MAP->BLOCK) {
					DrawGraph(x * MAP->blockSize, y * MAP->blockSize, player->block, true);
				}
				if (MAP->map[y][x] == MAP->ONOFFBLOCK) {
					DrawGraph(x * MAP->blockSize, y * MAP->blockSize, player->block, true);
				}
			}
		}

		player->Draw();//関数の呼び出し
		easing->EasingDraw();

		DrawFormatString(200, 180, GetColor(255, 255, 255), "%d", easing->isSelect);
		

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}