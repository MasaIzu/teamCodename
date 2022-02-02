#include "DxLib.h"
#include"Scene.h"

//ここは作った関数をまとめる所_ついでにシーン管理

Scene::Scene() {
	scene = 0;
	isShiftPush = 0; sceneChange = 0; stageSelect = 0;
	shiftGh = LoadGraph("taiou.png");
	goalGh = LoadGraph("thanksGh.png");
};

void Scene::PushMove(char* keys, char* oldkeys, int map[6][14], int mpx, int mpy) {

	if (scene == 0) {
		MAP.SelectMap(scene, map);
		MAP.MapKeep(map);
		easing.selectScene = 0;
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			scene = 1;
			changeSc.titleFaze += 1;
		}
	}
	else if (scene == 1) {
		charaTalk.CharContents(keys, oldkeys);
		if (changeSc.isChangeScene == 1) {
			scene = 2;
			changeSc.isChangeScene = 0;
		}
		if (charaTalk.goGame == 1) {
			charaTalk.goGame = 0;
			sceneChange = 1;
		}
	}

	//ステージ0(チュートリアル)
	else if (scene == 2) {
		if (sceneChange == 0) {
			if (charaTalk.goGame == 0) {
				player.Move(keys, oldkeys, map);
				key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
				easing.EasingMove(mpx, mpy);
				easing.EasingLong(keys, oldkeys);
			}
			if (player.keyTake == 1) {
				charaTalk.goGame = 1;
				if (charaTalk.numberOfTimes == 2) {
					charaTalk.numberOfTimes = 3;
				}
				charaTalk.CharContents(keys, oldkeys);
				if (charaTalk.goGame == 0) {
					player.keyTake = 0;
				}
			}
			if (player.isGoal == 1) {
				scene = 3;
			}
		}

		stageSelect = 0;
	}
	//ステージたち勝ったなガハハ
	else if (scene == 3) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			if (stageSelect == 0) {//ステージ0(チュートリアル)
				scene = 5;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 1) {//ステージ1
				scene = 6;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 2) {//ステージ2
				scene = 7;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 3) {//ステージ3
				scene = 8;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 4) {//ステージ4
				scene = 9;
				player.x = 416; player.y = 96;
				player.playerPosX = 416; player.playerPosY = 96;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 5) {//ステージ5
				scene = 10;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			MAP.SelectMap(scene, map);
			MAP.MapKeep(map);
		}
	}
	//死んだらここに行き着く
	else if (scene == 4) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			if (stageSelect == 0) {//ステージ0(チュートリアル)
				scene = 2;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 1) {//ステージ1
				scene = 5;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 2) {//ステージ2
				scene = 6;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 3) {//ステージ3
				scene = 7;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 4) {//ステージ4
				scene = 8;
				player.x = 550; player.y = 103;
				player.playerPosX = 550; player.playerPosY = 103;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			else if (stageSelect == 5) {//ステージ5
				scene = 9;
				player.x = 416; player.y = 96;
				player.playerPosX = 416; player.playerPosY = 96;
				player.isGoal = 0; player.isKeyAlive = 1;
				player.onaCount = 0; player.time = 0;  player.isPush = 0;
				for (int i = 0; i < 100; i++) {
					key.codeName[i] = 0;
				}
			}
			MAP.SelectMap(scene, map);
			MAP.MapKeep(map);

		}
	}
	//ステージ1
	else if (scene == 5) {
		easing.selectScene = 0;
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);

		if (player.isGoal == 1) {
			scene = 3;
		}
		stageSelect = 1;
	}
	//ステージ2
	else if (scene == 6) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);

		if (player.isGoal == 1) {
			scene = 3;
		}
		stageSelect = 2;
	}
	//ステージ3
	else if (scene == 7) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);

		if (player.isGoal == 1) {
			scene = 3;
		}
		stageSelect = 3;
	}
	//ステージ4
	else if (scene == 8) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
		MAP.sparkReset(map);
		MAP.spark(map);

		if (player.isGoal == 1) {
			scene = 3;
		}
		stageSelect = 4;
	}
	//ステージ5
	else if (scene == 9) {
		player.Move(keys, oldkeys, map);
		key.Inputkey(keys, oldkeys, map, player.playerLeftTopX, player.playerLeftTopY);
		MAP.sparkReset(map);
		MAP.spark(map);

		if (player.isGoal == 1) {
			scene = 3;
		}
		stageSelect = 5;
	}
	//CLEARシーン
	else if (scene == 10) {
		easing.isThx = 1;
	
		if (easing.selectScene == 1) {
			scene = 0;
			changeSc.faze = 0;
			changeSc.isChangeSc = 0;	//チェンジスクリーンのフラグ
			changeSc.topP.x = 0;
			changeSc.topP.y = -300;
			changeSc.botP.x = 0;
			changeSc.botP.y = 300;
			changeSc.leftP.x = -250;
			changeSc.leftP.y = 0;
			changeSc.rightP.x = 250;
			changeSc.rightP.y = 0;
			changeSc.time = 0;
			changeSc.time2 = -10;
			changeSc.maxTime = 20;
			changeSc.maxtime2 = 30;
			changeSc.randomX = 0;
			changeSc.randomY = 0;
			changeSc.strP.x = 0;
			changeSc.strP.y = 0;
			changeSc.waitTime = 0;
			changeSc.isChangeScene = 0;
			changeSc.titleFaze = 1;
		}
		if (easing.selectScene == 2) {
			scene = 5;
		}
		if (easing.selectScene == 3) {

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
	if (keys[KEY_INPUT_LSHIFT] == 1 && oldkeys[KEY_INPUT_LSHIFT] == 0) {
		if (isShiftPush == 0) {
			isShiftPush = 1;
		}
		else {
			isShiftPush = 0;
		}
	}


	if (sceneChange == 1) {
		changeSc.isChangeSc = 1;
		sceneChange = 0;
	}
	changeSc.Update();

}

void Scene::PushDraw(int map[][14]) {
	// 描画処理

	if (scene == 0) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "スタート_スペース");
	}
	else if (scene == 1) {
		charaTalk.CharDraw();
	}
	//ステージ0
	else if (scene == 2) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		DrawFormatString(100, 400, GetColor(255, 255, 255), "あなたが打ったキー:");
		MAP.MapDraw(map);
		player.Draw(map);
		key.KeyDraw();
		if (player.keyTake == 1) {
			charaTalk.CharDraw();
		}

	}
	else if (scene == 3) {
		DrawFormatString(100, 400, GetColor(255, 255, 255), "あなたが打ったキー:");
		key.KeyDraw();
		DrawFormatString(350, 200, GetColor(255, 255, 255), "ゴール！やったね！");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "戻るにはスペース");
	}
	else if (scene == 4) {
		DrawFormatString(350, 200, GetColor(255, 255, 255), "ゆ～だーい");
		DrawFormatString(350, 240, GetColor(255, 255, 255), "戻るにはスペース");
	}
	//ステージ1
	else if (scene == 5) {
		DrawFormatString(100, 400, GetColor(255, 255, 255), "あなたが打ったキー:");
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		player.Draw(map);
		key.KeyDraw();
	}
	//ステージ2
	else if (scene == 6) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		player.Draw(map);
	}
	//ステージ3
	else if (scene == 7) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		player.Draw(map);
	}
	//ステージ4
	else if (scene == 8) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		player.Draw(map);
	}
	//ステージ5
	else if (scene == 9) {
		if (isShiftPush == 1) {
			DrawGraph(0, 0, shiftGh, true);
		}
		MAP.MapDraw(map);
		player.Draw(map);
	}
	//goal
	else if (scene == 10) {
		DrawGraph(0, 0, goalGh, true);
		easing.EasingDraw();
	}

	changeSc.Draw();
}



