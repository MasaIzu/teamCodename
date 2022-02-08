#pragma once
class CharaTalk
{
public:
	char talk[50];

	int numberOfTimes;
	int goGame;
	int filtaGh;
	int playerGh[6];
	int playerAnmC;
	int waitTimer;
	//“ñ“x‚à‰ñ‚³‚È‚¢‚Æ‚¢‚¤ŒÅ‚¢ˆÓŽu
	int isOnly;
	CharaTalk();

	void CharContents(char* keys, char* oldkeys);
	void CharDraw();
};

