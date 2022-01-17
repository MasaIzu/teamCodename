#include "DxLib.h"
#include "key.h"
#include"MapPlayer.h"
#include "Map.h"
#include"Easing.h"
#include"Scene.h"

//ここは作った関数をまとめる所

Key* key = new Key;
Player* player = new Player(230, 230, 5, 64);
Map* MAP = new Map;
Easing* easing = new Easing;

void Scene::PushMove(char* keys, char* oldkeys, int map[][14],int mpx,int mpy, int PTX, int PTY) {
	if (scene == 0) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
		}
	}
	else if (scene == 1) {
		// 更新処理
		player->Move(keys, oldkeys, map);
		key->Inputkey(keys, oldkeys, map, PTX, PTY);
		easing->EasingMove(mpx, mpy);
		easing->EasingLong(keys, oldkeys);

	}
}

void Scene::PushDraw(int map[][14]) {
	// 描画処理
	if (scene == 1) {
		player->Draw(map,block,goal);
		easing->EasingDraw();
	}
}