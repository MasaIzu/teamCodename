#pragma once

class Key
{
public:

	char keys[256] = { 0 };
	
	int mapX = 1;
	int mapY = 1;
	bool push = false;

	void Inputkey(char* keys, char* oldkeys, int map[][14],int PTX,int PTY);

};