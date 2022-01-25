#pragma once
#include"Scene.h"


class Key
{
public:

	char keys[256] = { 0 };
	
	int mapX = 1;
	int mapY = 1;
	bool push = false;
	char str;
	int Scene;
	char codeName[256];
	
	char keepCode[256];

	void Inputkey(char* keys, char* oldkeys, int map[][14],int PTX,int PTY);
	void KeyDraw();
	Key();
};