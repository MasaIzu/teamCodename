#include "DxLib.h"
#include "key.h"
#include"MapPlayer.h"
#include "Map.h"
#include"Easing.h"
#include"Scene.h"

//�����͍�����֐����܂Ƃ߂鏊

Key* key = new Key;
Player* player = new Player(550, 103, 5, 64);
Map* MAP = new Map;
Easing* easing = new Easing;

void Scene::PushMove(char* keys, char* oldkeys, int map[][14],int mpx,int mpy, int PTX, int PTY) {
	if (scene == 0) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
		}
	}
	else if (scene == 1) {
		// �X�V����
		player->Move(keys, oldkeys, map);
		key->Inputkey(keys, oldkeys, map, PTX, PTY);
		easing->EasingMove(mpx, mpy);
		easing->EasingLong(keys, oldkeys);
		if (player->isGoal == 1) {
			scene = 2;
		}
	}
	else if (scene == 2) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player->x = 550; player->y =103;
			player->isGoal = 0;
		}
	}
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player->x = 550; player->y = 103;
			player->isGoal = 0;
		}
	}
	if (player->isPlayerAlive == 0) {
		scene = 3;
		player->isPlayerAlive = 1;
	}
}

void Scene::PushDraw(int map[][14]) {
	// �`�揈��
	if (scene == 0) {
		DrawFormatString(350, 200, GetColor(255, 255, 255),"�X�^�[�g_�X�y�[�X");
	}
	else if (scene == 1) {
		player->Draw(map,block,goal, needle, kagi);
		easing->EasingDraw();
	}
	else if (scene == 2) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�S�[���I������ˁI");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
	else if (scene == 3) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "��`���[��");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
}