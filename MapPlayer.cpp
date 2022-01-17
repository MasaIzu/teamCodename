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

	//����̍��W�擾
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

		//�v���C���[
		//����̍��W�擾
		leftTopX = (x - r) / MAP.blockSize;
		leftTopY = (y - r) / MAP.blockSize;

		//�E��̍��W�擾
		rightTopX = (x + r - 1) / MAP.blockSize;
		rightTopY = (y - r) / MAP.blockSize;

		//�E���̍��W�擾
		rightBottomX = (x + r - 1) / MAP.blockSize;
		rightBottomY = (y + r - 1) / MAP.blockSize;

		//�����̍��W�擾
		leftBottomX = (x - r) / MAP.blockSize;
		leftBottomY = (y + r - 1) / MAP.blockSize;


		//�v���C���[��old
		//����̍��W�擾
		leftTopOldX = (playerPosOldX - r) / MAP.blockSize;
		leftTopOldY = (playerPosOldY - r) / MAP.blockSize;

		//�E��̍��W�擾
		rightTopOldX = (playerPosOldX + r - 1) / MAP.blockSize;
		rightTopOldY = (playerPosOldY - r) / MAP.blockSize;

		//�E���̍��W�擾
		rightBottomOldX = (playerPosOldX + r - 1) / MAP.blockSize;
		rightBottomOldY = (playerPosOldY + r - 1) / MAP.blockSize;

		//�����̍��W�擾
		leftBottomOldX = (playerPosOldX - r) / MAP.blockSize;
		leftBottomOldY = (playerPosOldY + r - 1) / MAP.blockSize;


		//�����������Ă���Ȃ���Ƃɖ߂�
		if (map[leftTopY][leftTopX] == MAP.BLOCK) {
			if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�
				
			}
			else if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.BLOCK && map[leftTopY][leftTopOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.BLOCK && map[leftTopY][leftTopOldX] == MAP.BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == MAP.BLOCK) {
			if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.BLOCK && map[rightTopY][rightTopOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.BLOCK && map[rightTopY][rightTopOldX] == MAP.BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == MAP.BLOCK) {
			if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.BLOCK && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.BLOCK && map[rightBottomY][rightBottomOldX] == MAP.BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == MAP.BLOCK) {
			if (map[leftBottomOldY][leftBottomX] == MAP.NONE &&map[leftBottomY][leftBottomOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.BLOCK && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.BLOCK && map[leftBottomY][leftBottomOldX] == MAP.BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		//�����������Ă���Ȃ���Ƃɖ߂�ONOFFBLOCK��
		if (map[leftTopY][leftTopX] == MAP.ONOFFBLOCK) {
			if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftTopOldY][leftTopX] == MAP.NONE && map[leftTopY][leftTopOldX] == MAP.ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.ONOFFBLOCK && map[leftTopY][leftTopOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == MAP.ONOFFBLOCK && map[leftTopY][leftTopOldX] == MAP.ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == MAP.ONOFFBLOCK) {
			if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == MAP.NONE && map[rightTopY][rightTopOldX] == MAP.ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.ONOFFBLOCK && map[rightTopY][rightTopOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == MAP.ONOFFBLOCK && map[rightTopY][rightTopOldX] == MAP.ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == MAP.ONOFFBLOCK) {
			if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.NONE && map[rightBottomY][rightBottomOldX] == MAP.ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == MAP.ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == MAP.ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == MAP.ONOFFBLOCK) {
			if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.NONE && map[leftBottomY][leftBottomOldX] == MAP.ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == MAP.NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = playerPosOldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == MAP.ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == MAP.ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = playerPosOldX;
				y = playerPosOldY;
				isHitKey = 0;
				break;
			}
		}
	}
}

void Player::Draw(int map[][14]) {
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
}
