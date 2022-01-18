#include "DxLib.h"
#include "key.h"
#include"Player.h"
#include "Map.h"
#include"Easing.h"
#include "Enum.h"
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
	Player* player = new Player(550, 80, 5, 64);
	Map* MAP = new Map;
	Scene* SCENE = new Scene;

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
		
		//包含の処理ができていません
		SCENE->PushMove(keys, oldkeys, MAP->map, x, y, player->leftTopX, player->leftTopY);

		
		// 描画処理
		SCENE->PushDraw(MAP->map);


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