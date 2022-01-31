#pragma once
#include"Player.h"
#include"Map.h"
#include"key.h"
#include"Easing.h"

class Scene
{
public:
	int scene;
	Player player;
	Map MAP;
	Easing easing;
	Key key;

	void PushMove(char* keys, char* oldkeys, int map[6][14],int mpx,int mpy, int PTX, int PTY);
	void PushDraw(int map[][14]);

	// constructor & destructor
	Scene();
	~Scene();

};