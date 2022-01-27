#include "DxLib.h"
#include"Scene.h"

//�����͍�����֐����܂Ƃ߂鏊_���łɃV�[���Ǘ�

void Scene::PushMove(char* keys, char* oldkeys, int map[][14],int mpx,int mpy, int PTX, int PTY) {
	if (scene == 0) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
		}
	}
	else if (scene == 1) {
		// �X�V����
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, PTX, PTY);
		easing.EasingMove(mpx, mpy);
		easing.EasingLong(keys, oldkeys);
		if (this->player.isPlayerAlive == 1) {
			if (player.isGoal == 1) {
				scene = 2;
			}
		}
	}
	else if (scene == 2) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player.x = 550; player.y = 103;
			player.isGoal = 0; player.isKeyAlive = 1;
			if (map[key.mapY][key.mapX] == 2) {
				map[key.mapY][key.mapX] = 0;
			}
		}
	}
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player.x = 550; player.y = 103;
			player.isGoal = 0; player.isKeyAlive = 1;
			if (map[key.mapY][key.mapX] == 2) {
				map[key.mapY][key.mapX] = 0;
			}
		}
	}
	if (player.isPlayerAlive == 0) {
		scene = 3;
		player.isPlayerAlive = 1; player.isKeyAlive = 1;
		if (map[key.mapY][key.mapX] == 2) {
			map[key.mapY][key.mapX] = 0;
		}
	}
}

void Scene::PushDraw(int map[][14]) {
	// �`�揈��
	if (scene == 0) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�X�^�[�g_�X�y�[�X");
	}
	else if (scene == 1) {
		player.Draw();
		MAP.MapDraw(map);
		easing.EasingDraw();
	}
	else if (scene == 2) {
		key.KeyDraw();
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�S�[���I������ˁI");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
	else if (scene == 3) {
		key.KeyDraw();
		DrawFormatString(350, 200, GetColor(255, 255, 255), "��`���[��");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
}

Scene::Scene():MAP(MAP.map) {
	scene = 0;
};

