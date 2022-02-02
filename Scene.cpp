#include "DxLib.h"
#include"Scene.h"

//�����͍�����֐����܂Ƃ߂鏊_���łɃV�[���Ǘ�

Scene::Scene() {
	scene = 0;
	isShiftPush = 0; sceneChange = 0;
	shiftGh = LoadGraph("taiou.png");
};

void Scene::PushMove(char* keys, char* oldkeys, int map[6][14], int mpx, int mpy) {
	if (scene == 0) {
		MAP.SelectMap(scene, map);
		MAP.MapKeep(map);
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
		}
	}
	else if (scene == 1) {
		charaTalk.CharContents(keys, oldkeys);
		if (charaTalk.goGame == 1) {
			scene = 2;
			charaTalk.goGame = 0;
			sceneChange = 1;/////Scene�̐؂�ւ��̎��ɂ�����������////////////////////////////
		}
	}
	//�X�e�[�W1
	else if (scene == 2) {
		if (sceneChange == 0) {
			if (charaTalk.goGame == 0) {
				player.Move(keys, oldkeys, map);
				key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
				MAP.sparkReset(map);
				MAP.spark(map);
				easing.EasingMove(mpx, mpy);
				easing.EasingLong(keys, oldkeys);
			}
			if (player.keyTake == 1) {
				charaTalk.goGame = 1;
				charaTalk.CharContents(keys, oldkeys);
				if (charaTalk.goGame == 0) {
					player.keyTake = 0;
				}
			}
			if (player.isGoal == 1) {
				scene = 3;
			}
		}
		else if (sceneChange == 1) {
			changeSc.Update(scene);
		}
	}
	//�X�e�[�W1�������ȃK�n�n
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 5;
			player.x = 550; player.y = 103;
			player.playerPosX = 550; player.playerPosY = 103;
			player.isGoal = 0; player.isKeyAlive = 1;

			MAP.SelectMap(scene, map);
			MAP.MapKeep(map);
		}
	}
	//���񂾂炱���ɍs������
	else if (scene == 4) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 0;
			player.x = 550; player.y = 103;
			player.playerPosX = 550; player.playerPosY = 103;
			player.isGoal = 0; player.isKeyAlive = 1;


		}
	}
	//�X�e�[�W2
	else if (scene == 5) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
		easing.EasingMove(mpx, mpy);
		easing.EasingLong(keys, oldkeys);

		if (player.isGoal == 1) {
			scene = 2;
		}
	}


	if (player.isPlayerAlive == 0) {
		scene = 4;
		player.isPlayerAlive = 1; player.isKeyAlive = 1;
		for (int y = 0; y < MAP.mapCount.y; y++) {
			for (int x = 0; x < MAP.mapCount.x; x++) {
				map[y][x] = MAP.map[y][x];
			}
		}
	}
	if (keys[KEY_INPUT_LSHIFT] == 1 && oldkeys[KEY_INPUT_LSHIFT] == 1) {
		isShiftPush = 1;
	}
	else {
		isShiftPush = 0;
	}
}

void Scene::PushDraw(int map[][14]) {
	// �`�揈��

	if (scene == 0) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�X�^�[�g_�X�y�[�X");
	}
	else if (scene == 1) {
		charaTalk.CharDraw();
	}
	else if (scene == 2) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		DrawFormatString(100, 400, GetColor(255, 255, 255), "���Ȃ����ł����L�[:");
		MAP.MapDraw(map);
		easing.EasingDraw();
		player.Draw(map);
		key.KeyDraw();
		if (player.keyTake == 1) {
			charaTalk.CharDraw();
		}
		changeSc.Draw();
	}
	else if (scene == 3) {
		DrawFormatString(100, 400, GetColor(255, 255, 255), "���Ȃ����ł����L�[:");
		key.KeyDraw();
		DrawFormatString(350, 200, GetColor(255, 255, 255), "�S�[���I������ˁI");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
	else if (scene == 4) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "��`���[��");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "�߂�ɂ̓X�y�[�X");
	}
	else if (scene == 5) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		easing.EasingDraw();
		player.Draw(map);

	}
}



