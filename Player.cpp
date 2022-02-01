#include"Player.h"
#include "DxLib.h"
#include"Global.h"
#include"Enum.h"
#include"Map.h"

Player::Player() {//���̃^�X�N�Q�}�b�v�`�b�v�̓����蔻���player�ɂ���
	this->x = 550;this->playerPosX = 550;
	this->y = 103;this->playerPosY = 103;
	this->r = 5;this->speed = 64;

	this->easing = new Easing;

	//�x�����T�������̂őΏەϐ��S��������
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

	//����̍��W�擾
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

		//�v���C���[
		//����̍��W�擾
		leftTopX = (x - r) / BLOCK_SIZE;
		leftTopY = (y - r) / BLOCK_SIZE;

		//�E��̍��W�擾
		rightTopX = (x + r - 1) / BLOCK_SIZE;
		rightTopY = (y - r) / BLOCK_SIZE;

		//�E���̍��W�擾
		rightBottomX = (x + r - 1) / BLOCK_SIZE;
		rightBottomY = (y + r - 1) / BLOCK_SIZE;

		//�����̍��W�擾
		leftBottomX = (x - r) / BLOCK_SIZE;
		leftBottomY = (y + r - 1) / BLOCK_SIZE;


		//�v���C���[��old
		//����̍��W�擾
		leftTopOldX = (oldX - r) / BLOCK_SIZE;
		leftTopOldY = (oldY - r) / BLOCK_SIZE;

		//�E��̍��W�擾
		rightTopOldX = (oldX + r - 1) / BLOCK_SIZE;
		rightTopOldY = (oldY - r) / BLOCK_SIZE;

		//�E���̍��W�擾
		rightBottomOldX = (oldX + r - 1) / BLOCK_SIZE;
		rightBottomOldY = (oldY + r - 1) / BLOCK_SIZE;

		//�����̍��W�擾
		leftBottomOldX = (oldX - r) / BLOCK_SIZE;
		leftBottomOldY = (oldY + r - 1) / BLOCK_SIZE;


		//�����������Ă���Ȃ���Ƃɖ߂�
		if (map[leftTopY][leftTopX] == BLOCK) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == BLOCK && map[leftTopY][leftTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == BLOCK && map[leftTopY][leftTopOldX] == BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == BLOCK) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == BLOCK && map[rightTopY][rightTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == BLOCK && map[rightTopY][rightTopOldX] == BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == BLOCK) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == BLOCK && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == BLOCK && map[rightBottomY][rightBottomOldX] == BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == BLOCK) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == BLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == BLOCK && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}

			else if (map[leftBottomOldY][leftBottomX] == BLOCK && map[leftBottomY][leftBottomOldX] == BLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		//�����������Ă���Ȃ���Ƃɖ߂�ONOFFBLOCK��
		if (map[leftTopY][leftTopX] == ONOFFBLOCK) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == ONOFFBLOCK && map[leftTopY][leftTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == ONOFFBLOCK && map[leftTopY][leftTopOldX] == ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == ONOFFBLOCK) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == ONOFFBLOCK && map[rightTopY][rightTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == ONOFFBLOCK && map[rightTopY][rightTopOldX] == ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == ONOFFBLOCK) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == ONOFFBLOCK && map[rightBottomY][rightBottomOldX] == ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == ONOFFBLOCK) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == ONOFFBLOCK) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				y = oldY;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				x = oldX;
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == ONOFFBLOCK && map[leftBottomY][leftBottomOldX] == ONOFFBLOCK) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				x = oldX;
				y = oldY;
				isHitKey = 0;
				break;
			}
		}

		//�����������Ă���Ȃ���Ƃɖ߂�GOAL��
		if (map[leftTopY][leftTopX] == GOAL) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == GOAL) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == GOAL && map[leftTopY][leftTopOldX] == GOAL) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == GOAL) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == GOAL) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == GOAL && map[rightTopY][rightTopOldX] == GOAL) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == GOAL) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == GOAL) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == GOAL && map[rightBottomY][rightBottomOldX] == GOAL) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == GOAL) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == GOAL) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == NONE) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == GOAL && map[leftBottomY][leftBottomOldX] == GOAL) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		//�����������Ă���Ȃ���Ƃɖ߂�NEEDLE��
		if (map[leftTopY][leftTopX] == NEEDLE) {
			if (map[leftTopOldY][leftTopX] == NONE && map[leftTopY][leftTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftTopOldY][leftTopX] == NONE || KEY && map[leftTopY][leftTopOldX] == NEEDLE) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == NEEDLE && map[leftTopY][leftTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftTopOldY][leftTopX] == NEEDLE && map[leftTopY][leftTopOldX] == NEEDLE) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[rightTopY][rightTopX] == NEEDLE) {
			if (map[rightTopOldY][rightTopX] == NONE && map[rightTopY][rightTopOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightTopOldY][rightTopX] == NONE || KEY && map[rightTopY][rightTopOldX] == NEEDLE) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == NEEDLE && map[rightTopY][rightTopOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightTopOldY][rightTopX] == NEEDLE && map[rightTopY][rightTopOldX] == NEEDLE) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[rightBottomY][rightBottomX] == NEEDLE) {
			if (map[rightBottomOldY][rightBottomX] == NONE && map[rightBottomY][rightBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[rightBottomOldY][rightBottomX] == NONE || KEY && map[rightBottomY][rightBottomOldX] == NEEDLE) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == NEEDLE && map[rightBottomY][rightBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[rightBottomOldY][rightBottomX] == NEEDLE && map[rightBottomY][rightBottomOldX] == NEEDLE) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
		}

		if (map[leftBottomY][leftBottomX] == NEEDLE) {
			if (map[leftBottomOldY][leftBottomX] == NONE && map[leftBottomY][leftBottomOldX] == NONE) {//���������ɂȂ��̂ł���Ή������Ȃ�

			}
			else if (map[leftBottomOldY][leftBottomX] == NONE || KEY && map[leftBottomY][leftBottomOldX] == NEEDLE) {//������Y���������Ă���Ȃ�Y�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NONE || KEY) {//������X���������Ă���Ȃ�X�����̈ʒu�ɖ߂�
				isHitKey = 0;
				break;
			}
			else if (map[leftBottomOldY][leftBottomX] == NEEDLE && map[leftBottomY][leftBottomOldX] == NEEDLE) {//�ǂ������������Ă�̂Ȃ�Η��������̈ʒu�ɖ߂�
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

	//�����������Ă���Ȃ�KEY������
	if (map[playerLeftTopY][playerLeftTopX] == KEY) {
		map[playerLeftTopY][playerLeftTopX] = NONE;
	}

	//�����������Ă���Ȃ�player�͎���NEEDLE��
	if (map[playerLeftTopY][playerLeftTopX] == NEEDLE) {
		isPlayerAlive = 0;
	}
	//�����������Ă���Ȃ�player�͎���TRAP��
	if (map[playerLeftTopY][playerLeftTopX] == TRAPDOWN) {

	}
	if (map[playerLeftTopY][playerLeftTopX] == TRAP) {
		isPlayerAlive = 0;
	}

	//�����������Ă���Ȃ�player�̓S�[������
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

