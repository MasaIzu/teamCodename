#include"Player.h"
#include "DxLib.h"
#include"Global.h"
#include"Enum.h"

Player::Player() {//次のタスク＿マップチップの当たり判定をplayerにする
	this->x = 550;
	this->playerPosX = 550;
	this->y = 103;
	this->playerPosY = 103;
	this->r = 5;
	this->speed = 64;

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
}


void Player::Move(char* keys, char* oldkeys, int map[6][14]) {

	if (isPush == 0) {
		if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0) {
			isHitKey = 1;
			isPush = 1;
			Start = y;
		}
		if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0) {
			isHitKey = 2;
			isPush = 1;
			Start = y;
		}
		if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0) {
			isHitKey = 3;
			isPush = 2;
			Start = x;
		}
		if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0) {
			isHitKey = 4;
			isPush = 2;
			Start = x;
		}
	}

	//左上の座標取得
	leftTopX = (x - r) / BLOCK_SIZE;
	leftTopY = (y - r) / BLOCK_SIZE;

	playerLeftTopX = (playerPosX) / BLOCK_SIZE;
	playerLeftTopY = (playerPosY) / BLOCK_SIZE;

	oldPlayerLeftTopX = (playerPosOldX) / BLOCK_SIZE;
	oldPlayerLeftTopY = (playerPosOldY) / BLOCK_SIZE;

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
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == BLOCK && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == BLOCK && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == BLOCK && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == BLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == BLOCK && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == ONOFFBLOCK && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == ONOFFBLOCK && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == ONOFFBLOCK) {//もしもYが当たっているならYを元の位置に戻す
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
		}

		if (map[rightTopY][rightTopX] == GOAL) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
		}

		if (map[rightBottomY][rightBottomX] == GOAL) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
		}

		if (map[leftBottomY][leftBottomX] == GOAL) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == GOAL) {//もしもYが当たっているならYを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == GOAL) {//どっちも当たってるのならば両方を元の位置に戻す
				if (isKeyAlive == 0) {
					isGoal = 1;
				}
			}
		}

		//もし当たっているならもとに戻すNEEDLE版
		if (map[leftTopY][leftTopX] == NEEDLE) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0; 
				break;
			}
			else if (map[leftTopOldY][leftTopX] == NEEDLE && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0; 
				break;
			}
			else if (map[rightTopOldY][rightTopX] == NEEDLE && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0; 
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == NEEDLE && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
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
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NEEDLE) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0; 
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NEEDLE) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0; 
				break;
			}
		}

		//もし当たっているならもとに戻すKEY版
		if (map[leftTopY][leftTopX] == KEY) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == KEY) {//もしもYが当たっているならYを元の位置に戻す
				
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == KEY && map[leftTopY][leftTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == KEY && map[leftTopY][leftTopOldX] == KEY) {//どっちも当たってるのならば両方を元の位置に戻す
				
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == KEY) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == KEY) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == KEY && map[rightTopY][rightTopOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == KEY && map[rightTopY][rightTopOldX] == KEY) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == KEY) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == KEY) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == KEY && map[rightBottomY][rightBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == KEY && map[rightBottomY][rightBottomOldX] == KEY) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == KEY) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//もしも特にないのであれば何もしない

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == KEY) {//もしもYが当たっているならYを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == KEY && map[leftBottomY][leftBottomOldX] == NONE) {//もしもXが当たっているならXを元の位置に戻す
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == KEY && map[leftBottomY][leftBottomOldX] == KEY) {//どっちも当たってるのならば両方を元の位置に戻す
				isHitKey = 0;
				break;
			}
		}
	}

	//もし当たっているならKEYを消す
	if (map[playerLeftTopY][playerLeftTopX] == KEY) {
		map[playerLeftTopY][playerLeftTopX] = NONE;
	}

	//もし当たっているならplayerは死ぬ
	if (map[playerLeftTopY][playerLeftTopX] == NEEDLE) {
		isPlayerAlive = 0;
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

	DrawFormatString(300, 500, GetColor(255, 255, 255), "%d", playerLeftTopX);
	DrawFormatString(300, 520, GetColor(255, 255, 255), "%d", playerLeftTopY);
}

