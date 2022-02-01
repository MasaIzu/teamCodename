#include"Player.h"
#include "DxLib.h"
#include"Global.h"
#include"Enum.h"
#include"Map.h"

Player::Player() {//次のタスク＿マップチップの当たり判定をplayerにする
	this->x = 550;this->playerPosX = 550;
	this->y = 103;this->playerPosY = 103;
	this->r = 5;this->speed = 64;

	this->easing = new Easing;

	//警告が鬱陶しいので対象変数全部初期化
	rightTopX = 0; rightTopY = 0; rightBottomX = 0; rightBottomY = 0;
	leftTopX = 0; leftTopY = 0; leftBottomX = 0; leftBottomY = 0;
	rightTopOldX = 0; rightTopOldY = 0; rightBottomOldX = 0; rightBottomOldY = 0;
	leftTopOldX = 0; leftTopOldY = 0; leftBottomOldX = 0; leftBottomOldY = 0;
	oldX = 0; oldY = 0;
	this->isPlayerStop = 0;
	isHitKey = 0; isGoal = 0; isPlayerAlive = 1; isKeyAlive = 1;
	Start = 0; Final = 0; oldFinal = 0; maxTime = 20; time = 0;
	playerPosOldX = 0; playerPosOldY = 0; isPush = 0;
	playerLeftTopX = 0; playerLeftTopY = 0; oldPlayerLeftTopX = 0; oldPlayerLeftTopY = 0;
	keyCount = 0; onaCount = 0; playerCount = 0; trapTimer = 4.5;
	playerMapPosX = 0; playerMapPosY = 0;
}


void Player::Move(char* keys, char* oldkeys, int map[6][14]) {

	if (isPush == 0) {
		if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0) {
			isHitKey = 1;
			isPush = 1;
			Start = y;
			playerCount = 1;
		}
		else if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0) {
			isHitKey = 2;
			isPush = 1;
			Start = y;
			playerCount = 1;
		}
		else if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0) {
			isHitKey = 3;
			isPush = 2;
			Start = x;
			playerCount = 1;
		}
		else if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0) {
			isHitKey = 4;
			isPush = 2;
			Start = x;
			playerCount = 1;
		}
	}

	//左上の座標取得
	leftTopX = (x - r) / BLOCK_SIZE;
	leftTopY = (y - r) / BLOCK_SIZE;

	playerLeftTopX = (playerPosX - r) / BLOCK_SIZE;
	playerLeftTopY = (playerPosY - r) / BLOCK_SIZE;

	oldPlayerLeftTopX = (playerPosOldX - r) / BLOCK_SIZE;
	oldPlayerLeftTopY = (playerPosOldY - r) / BLOCK_SIZE;

	if (playerCount == 1) {
		playerMapPosX = playerLeftTopX;
		playerMapPosY = playerLeftTopY;
	}

	while (isHitKey == 1 || isHitKey == 2 || isHitKey == 3 || isHitKey == 4) {

		oldX = x;
		oldY = y;

		playerPosOldX = playerPosX;
		playerPosOldY = playerPosY;

		if (isHitKey == 1) {
			y -= speed;
		}
		if (isHitKey == 2) {
			y += speed;
		}
		if (isHitKey == 3) {
			x -= speed;
		}
		if (isHitKey == 4) {
			x += speed;
		}

		//プレイヤー
		//左上の座標取得
		leftTopX = (x - r) / BLOCK_SIZE;
		leftTopY = (y - r) / BLOCK_SIZE;

		//右上の座標取得
		rightTopX = (x + r - 1) / BLOCK_SIZE;
		rightTopY = (y - r) / BLOCK_SIZE;

		//右下の座標取得
		rightBottomX = (x + r - 1) / BLOCK_SIZE;
		rightBottomY = (y + r - 1) / BLOCK_SIZE;

		//左下の座標取得
		leftBottomX = (x - r) / BLOCK_SIZE;
		leftBottomY = (y + r - 1) / BLOCK_SIZE;


		//プレイヤーのold
		//左上の座標取得
		leftTopOldX = (oldX - r) / BLOCK_SIZE;
		leftTopOldY = (oldY - r) / BLOCK_SIZE;

		//右上の座標取得
		rightTopOldX = (oldX + r - 1) / BLOCK_SIZE;
		rightTopOldY = (oldY - r) / BLOCK_SIZE;

		//右下の座標取得
		rightBottomOldX = (oldX + r - 1) / BLOCK_SIZE;
		rightBottomOldY = (oldY + r - 1) / BLOCK_SIZE;

		//左下の座標取得
		leftBottomOldX = (oldX - r) / BLOCK_SIZE;
		leftBottomOldY = (oldY + r - 1) / BLOCK_SIZE;


		//もし当たっているならもとに戻す
		if (map[leftTopY][leftTopX] == BLOCK) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == BLOCK && map[leftTopY][leftTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == BLOCK && map[leftTopY][leftTopOldX] == BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == BLOCK) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == BLOCK && map[rightTopY][rightTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == BLOCK && map[rightTopY][rightTopOldX] == BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == BLOCK) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == BLOCK && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == BLOCK && map[rightBottomY][rightBottomOldX] == BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == BLOCK) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == BLOCK && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}

			else if (map[leftBottomOldY][leftBottomX] == BLOCK && map[leftBottomY][leftBottomOldX] == BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		//もし当たっているならもとに戻すONOFFBLOCK版
		if (map[leftTopY][leftTopX] == ONOFFBLOCK) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == ONOFFBLOCK && map[leftTopY][leftTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == ONOFFBLOCK && map[leftTopY][leftTopOldX] == ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == ONOFFBLOCK) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == ONOFFBLOCK && map[rightTopY][rightTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == ONOFFBLOCK && map[rightTopY][rightTopOldX] == ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == ONOFFBLOCK) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == ONOFFBLOCK) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		//もし当たっているならもとに戻すGOAL版
		if (map[leftTopY][leftTopX] == GOAL) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == GOAL) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == GOAL) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == GOAL) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		//もし当たっているならもとに戻すNEEDLE版
		if (map[leftTopY][leftTopX] == NEEDLE) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == NEEDLE && map[leftTopY][leftTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == NEEDLE && map[leftTopY][leftTopOldX] == NEEDLE) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == NEEDLE) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == NEEDLE && map[rightTopY][rightTopOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == NEEDLE && map[rightTopY][rightTopOldX] == NEEDLE) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == NEEDLE) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == NEEDLE && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == NEEDLE && map[rightBottomY][rightBottomOldX] == NEEDLE) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == NEEDLE) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NEEDLE) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}


	}


	if (playerCount == 1) {
		if (x != playerPosX) {
			onaCount++;
			playerCount = 0;
		}
		else if (y != playerPosY) {
			onaCount++;
			playerCount = 0;
		}
	}
	if (onaCount % 2 == 0) {
		for (int y = 0; y < MAP.mapCount.y; y++) {
			for (int x = 0; x < MAP.mapCount.x; x++) {
				if (map[y][x] == TRAPDOWN) {
					if (playerLeftTopX == x && playerLeftTopY == y) {

					}
					else {
						map[y][x] = TRAP;
					}
				}
			}
		}
	}
	else {
		for (int y = 0; y < MAP.mapCount.y; y++) {
			for (int x = 0; x < MAP.mapCount.x; x++) {
				if (map[y][x] == TRAP) {
					map[y][x] = TRAPDOWN;
				}
			}
		}
	}

	//もし当たっているならKEYを消す
	if (map[playerLeftTopY][playerLeftTopX] == KEY) {
		map[playerLeftTopY][playerLeftTopX] = NONE;
	}

	//もし当たっているならplayerは死ぬNEEDLE版
	if (map[playerLeftTopY][playerLeftTopX] == NEEDLE) {
		isPlayerAlive = 0;
	}
	//もし当たっているならplayerは死ぬTRAP版
	if (map[playerLeftTopY][playerLeftTopX] == TRAPDOWN) {

	}
	if (map[playerLeftTopY][playerLeftTopX] == TRAP) {
		isPlayerAlive = 0;
	}

	//もし当たっているならplayerはゴールする
	if (map[playerLeftTopY][playerLeftTopX] == GOAL) {
		for (int y = 0; y < MAP.mapCount.y; y++) {
			for (int x = 0; x < MAP.mapCount.x; x++) {
				if (map[y][x] == KEY) {
					keyCount++;
				}
			}
		}
		if (keyCount == 0) {
			isGoal = 1;
		}
	}
	else {
		keyCount = 0;
	}

	if (isPush == 1) {
		if (time < maxTime) {
			time++;
			playerPosY = Start + (y - Start) * easing->easeOutQuart(time / maxTime);
		}
		else {
			time = 0;
			isPush = 0;
		}
	}
	else if (isPush == 2) {
		if (time < maxTime) {
			time++;
			playerPosX = Start + (x - Start) * easing->easeOutQuart(time / maxTime);
		}
		else {
			time = 0;
			isPush = 0;
		}
	}
}

void Player::Draw() {
	DrawCircle(this->playerPosX - r, this->playerPosY - r, r, GetColor(255, 255, 255), true);

	DrawFormatString(300, 500, GetColor(255, 255, 255), "%d", onaCount);
	DrawFormatString(300, 540, GetColor(255, 255, 255), "%d", x);
	DrawFormatString(300, 560, GetColor(255, 255, 255), "%d", playerPosX);
	DrawFormatString(300, 580, GetColor(255, 255, 255), "%d", playerCount);
}

