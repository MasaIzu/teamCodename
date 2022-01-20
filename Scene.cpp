#include "DxLib.h"
#include "key.h"
#include"MapPlayer.h"
#include "Map.h"
#include"Easing.h"
#include"Scene.h"

//ここは作った関数をまとめる所

Key* key = new Key;
Player* player = new Player(550, 103, 5, 64);
Map* MAP = new Map;
Easing* easing = new Easing;

void Scene::PushMove(char* keys, char* oldkeys, int map[][14], int mpx, int mpy, int PTX, int PTY) {
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
		if (player->isKeyAlive == 2) {
			if (player->isGoal == 1) {
				scene = 2;
			}
		}
	}
	else if (scene == 2) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player->x = 550; player->y = 103;
			player->isGoal = 0; player->isKeyAlive = 0;
			if (map[key->mapY][key->mapX] == 2) {
				map[key->mapY][key->mapX] = 0;
			}
		}
	}
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player->x = 550; player->y = 103;
			player->isGoal = 0; player->isKeyAlive = 0;
			if (map[key->mapY][key->mapX] == 2) {
				map[key->mapY][key->mapX] = 0;
			}
		}
	}
	if (player->isPlayerAlive == 0) {
		scene = 3;
		player->isPlayerAlive = 1; player->isKeyAlive = 0;
		if (map[key->mapY][key->mapX] == 2) {
			map[key->mapY][key->mapX] = 0;
		}
	}
}

void Scene::PushDraw(int map[][14]) {
	// 描画処理
	if (scene == 0) {
		DrawGraph(0,0,setumei,false);
		DrawFormatString(180, 400, GetColor(255, 255, 255), "ブロック配置");
		DrawFormatString(710, 450, GetColor(255, 255, 255), "自機操作");
		DrawFormatString(350, 200, GetColor(255, 255, 255), "スタート_スペース");
	}
	else if (scene == 1) {
		DrawGraph(0, 0, setumei, false);
		player->Draw(map, block, goal, needle, kagi);

		easing->EasingDraw();
		DrawFormatString(350, 400, GetColor(255, 255, 255), "ヒント:鍵");
		//DrawFormatString(450, 400, GetColor(255, 255, 255), "完全クリア歩数12:%d",key->pushCount);

		

	}
	else if (scene == 2) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "ゴール！やったね！");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "戻るにはスペース");
	}
	else if (scene == 3) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "ゆ〜だーい");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "戻るにはスペース");
	}
}