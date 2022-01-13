#include "DxLib.h"
#include "key.h"
#include"Player.h"
#include "Map.h"
#include"Easing.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LC1B_22_�j�V�U�����E�K: �^�C�g��unnnnch";

// �E�B���h�E����
const int WIN_WIDTH = 896;

// �E�B���h�E�c��
const int WIN_HEIGHT = 384;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	Key* key = new Key;
	Player* player = new Player(230, 230, 5, 64, 0);
	Map* MAP = new Map;
	Easing* easing = new Easing;

	int x, y;
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i) {
			oldkeys[i] = keys[i];
		}
		//�z��Ȃ̂�oldkey = keys;�̂悤�ɂł��Ȃ��B�v�f������R�s�[
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);
		GetMousePoint(&x, &y);
		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		player->Move(keys, oldkeys,MAP->map);
		key->Inputkey(keys, oldkeys, MAP->map, player->leftTopX, player->leftTopY);
		easing->EasingMove(x, y);
		easing->EasingLong(keys,oldkeys);
		
		// �`�揈��
		for (int y = 0; y < MAP->mapCountY; y++) {
			for (int x = 0; x < MAP->mapCountX; x++) {
				if (MAP->map[y][x] == MAP->BLOCK) {
					DrawGraph(x * MAP->blockSize, y * MAP->blockSize, player->block, true);
				}
				if (MAP->map[y][x] == MAP->ONOFFBLOCK) {
					DrawGraph(x * MAP->blockSize, y * MAP->blockSize, player->block, true);
				}
			}
		}

		player->Draw();//�֐��̌Ăяo��
		easing->EasingDraw();

		DrawFormatString(200, 180, GetColor(255, 255, 255), "%d", easing->isSelect);
		

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}