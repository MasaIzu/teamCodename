#include "DxLib.h"
#include "key.h"
#include"Player.h"
#include "Map.h"
#include"Easing.h"
#include "Enum.h"
#include"Global.h"
#include"Scene.h"

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
	Player* player = new Player();

	int mapInit[6][14] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,4,4,0,0,0,0,6,1 },
	{ 1,5,5,5,5,5,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,1,0,0,3,0,0,0,0,6,1 },
	{ 1,0,1,0,0,0,5,1,4,0,0,0,0,1 },
	{ 1,1,1,1,4,4,4,1,1,1,1,1,1,1 },
	};

	Map* MAP = new Map(mapInit);
	Scene* SCENE = new Scene;
	
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
		
	
		SCENE->PushMove(keys, oldkeys, mapInit, x, y, player->leftTopX, player->leftTopY);

		
		// �`�揈��
		SCENE->PushDraw(mapInit);


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