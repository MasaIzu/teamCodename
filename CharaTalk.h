#pragma once
class CharaTalk
{
public:
	char talk[50];

	int numberOfTimes;
	int goGame;
	int filtaGh;
	int playerGh;
	//二度も回さないという固い意志
	int isOnly;
	CharaTalk();

	void CharContents(char* keys, char* oldkeys);
	void CharDraw();
};

