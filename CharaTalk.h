#pragma once
class CharaTalk
{
public:
	char talk[50];

	int numberOfTimes;
	int goGame;
	int filtaGh;
	int playerGh;
	//��x���񂳂Ȃ��Ƃ����ł��ӎu
	int isOnly;
	CharaTalk();

	void CharContents(char* keys, char* oldkeys);
	void CharDraw();
};

