#include"MapPlayer.h"
#include "DxLib.h"
#include "key.h"


void Player::Move(char* keys, char* oldkeys, int map[][14]) {
	
	if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0) {
		isHitKey = 1;
	}
	if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0) {
		isHitKey = 2;
	}
	if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0) {
		isHitKey = 3;
	}
	if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0) {
		isHitKey = 4;
	}

	//左上の座標取得
	leftTopX = (x - r) / MAP.blockSize;
	leftTopY = (y - r) / MAP.blockSize;

	while (isHitKey == 1|| isHitKey == 2|| isHitKey == 3|| isHitKey == 4) {

		playerPosOldX = x;
		playerPosOldY = y;

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
		leftTopX = (x - r) / MAP.blockSize;
		leftTopY = (y - r) / MAP.blockSize;

		//右上の座標取得
		rightTopX = (x + r - 1) / MAP.blockSize;
		rightTopY = (y - r) / MAP.blockSize;

		//右下の座標取得
		rightBottomX = (x + r - 1) / MAP.blockSize;
		rightBottomY = (y + r - 1) / MAP.blockSize;

		//左下の座標取得
		leftBottomX = (x - r) / MAP.blockSize;
		leftBottomY = (y + r - 1) / MAP.blockSize;


		//プレイヤーのold
		//左上の座標取得
		leftTopOldX = (playerPosOldX - r) / MAP.blockSize;
		leftTopOldY = (playerPosOldY - r) / MAP.blockSize;

		//右上の座標取得
		rightTopOldX = (playerPosOldX + r - 1) / MAP.blockSize;
		rightTopOldY = (playerPosOldY - r) / MAP.blockSize;

		//右下の座標取得
		rightBottomOldX = (playerPosOldX + r - 1) / MAP.blockSize;
		rightBottomOldY = (playerPosOldY + r - 1) / MAP.blockSize;

		//左下の座標取得
		leftBottomOldX = (playerPosOldX - r) / MAP.blockSize;
		leftBottomOldY = (playerPosOldY + r - 1) / MAP.blockSize;


		//もし当たっているならもとに戻す
		if (map[leftTopY][leftTopX] == MAP.BLOCK) {
			if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.NONE) {//もしも特にないのであれば何もしない
				
			}
			else if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.BLOCK && map[leftTopY][leftTopOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.BLOCK && map[leftTopY][leftTopOldX] == MAP.BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == MAP.BLOCK) {
			if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.BLOCK && map[rightTopY][rightTopOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.BLOCK && map[rightTopY][rightTopOldX] == MAP.BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == MAP.BLOCK) {
			if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.BLOCK && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.BLOCK && map[rightBottomY][rightBottomOldX] == MAP.BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == MAP.BLOCK) {
			if (map[leftBottomOldY][leftBottomX] == MAP.NONE &&map[leftBottomY][leftBottomOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.BLOCK && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.BLOCK && map[leftBottomY][leftBottomOldX] == MAP.BLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		//もし当たっているならもとに戻すONOFFBLOCK版
		if (map[leftTopY][leftTopX] == MAP.ONOFFBLOCK) {
			if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.ONOFFBLOCK && map[leftTopY][leftTopOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.ONOFFBLOCK && map[leftTopY][leftTopOldX] == MAP.ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == MAP.ONOFFBLOCK) {
			if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.ONOFFBLOCK && map[rightTopY][rightTopOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.ONOFFBLOCK && map[rightTopY][rightTopOldX] == MAP.ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == MAP.ONOFFBLOCK) {
			if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == MAP.ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == MAP.ONOFFBLOCK) {
			if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//もしもXが当たっているならXを元の位置に戻す
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == MAP.ONOFFBLOCK) {//どっちも当たってるのならば両方を元の位置に戻す
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}
	}
}

void Player::Draw(int map[][14],int block,int goal) {
	for (int y = 0; y < MAP.mapCountY; y++) {
		for (int x = 0; x < MAP.mapCountX; x++) {
			if (map[y][x] == MAP.BLOCK) {
				DrawGraph(x * MAP.blockSize, y * MAP.blockSize, block, true);
			}
			if (map[y][x] == MAP.ONOFFBLOCK) {
				DrawGraph(x * MAP.blockSize, y * MAP.blockSize, block, true);
			}
			if (map[y][x] == MAP.GOAL) {
				DrawGraph(x * MAP.blockSize, y * MAP.blockSize, goal, true);
			}
		}
	}
	DrawCircle(x - r, y - r, r, GetColor(255, 255, 255), true);
}

Player::Player(int px, int py, int r, int speed) {
	x = px;
	y = py;
	this->r = r;
	this->speed = speed;

	//警告が鬱陶しいので対象変数全部初期化
	rightTopX = 0;
	rightTopY = 0;;
	rightBottomX = 0;
	rightBottomY = 0;
	leftTopX = 0;
	leftTopY = 0;
	leftBottomX = 0;
	leftBottomY = 0;
	rightTopOldX = 0;
	rightTopOldY = 0;
	rightBottomOldX = 0;
	rightBottomOldY = 0;
	leftTopOldX = 0;
	leftTopOldY = 0;
	leftBottomOldX = 0;
	leftBottomOldY = 0;
	playerPosOldX = 0;
	playerPosOldY = 0;
	this->isPlayerStop = 0;
	isHitKey = 0;
}

