#pragma once

class Scene
{//for���ŉ񂹂΃L�[�̕ۑ�������
public:
	int block = LoadGraph("test.png");
	int goal = LoadGraph("goal.png");
	int needle = LoadGraph("toge_kari.png");
	int kagi = LoadGraph("keykari.png");

	int scene = 0; 

	void PushMove(char* keys, char* oldkeys, int map[][14],int mpx,int mpy, int PTX, int PTY);
	void PushDraw(int map[][14]);

};