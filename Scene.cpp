#include "DxLib.h"
#include"Scene.h"

//�����͍�����֐����܂Ƃ߂鏊_���łɃV�[���Ǘ�

void Scene::PushMove(char* keys, char* oldkeys, int map[6][14], int mpx, int mpy) {
	if (scene == 0) {
		MAP.MapKeep(map);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
		}
	}
	//�X�e�[�W1
	else if (scene == 1) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
		easing.EasingMove(mpx, mpy);
		easing.EasingLong(keys, oldkeys);

		if (player.isGoal == 1) {
			scene = 2;
		}

	}
	//�X�e�[�W1�������ȃK�n�n
	else if (scene == 2) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 4;
			player.x = 550; player.y = 103;
			player.playerPosX = 550; player.playerPosY = 103;
			player.isGoal = 0; player.isKeyAlive = 1;

			MAP.SelectMap(scene, map);
			MAP.MapKeep(map);
		}
	}
	//���񂾂炱���ɍs������
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player.x = 550; player.y = 103;
			player.playerPosX = 550; player.playerPosY = 103;
			player.isGoal = 0; player.isKeyAlive = 1;
			for (int y = 0; y < MAP.mapCount.y; y++) {
				for (int x = 0; x < MAP.mapCount.x; x++) {
					map[y][x] = MAP.map[y][x];
				}
			}
		}
	}
	//�X�e�[�W2
	else if (scene == 4) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
		easing.EasingMove(mpx, mpy);
		easing.EasingLong(keys, oldkeys);

		if (player.isGoal == 1) {
			scene = 2;
		}
	}


	if (player.isPlayerAlive == 0) {
		scene = 3;
		player.isPlayerAlive = 1; player.isKeyAlive = 1;
		for (int y = 0; y < MAP.mapCount.y; y++) {
			for (int x = 0; x < MAP.mapCount.x; x++) {
				map[y][x] = MAP.map[y][x];
			}
		}
	}
}

void Scene::PushDraw(int map[][14]) {
	// �`�揈��
	if (scene == 0) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�X�^�[�g_�X�y�[�X");
	}
	else if (scene == 1) {
		MAP.MapDraw(map);
		easing.EasingDraw();
		player.Draw();
		key.KeyDraw();
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
	else if (scene == 4) {
		MAP.MapDraw(map);
		easing.EasingDraw();
		player.Draw();
	}
}

Scene::Scene() {
	scene = 0;
};

