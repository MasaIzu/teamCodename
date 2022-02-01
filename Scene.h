#pragma once
#include"Player.h"
#include"Map.h"
#include"key.h"
#include"Easing.h"

class Scene
{
private:
	int scene;
	
public:
	Player player;
	Map MAP;
	Easing easing;
	Key key;

	void PushMove(char* keys, char* oldkeys, int map[6][14],int mpx,int mpy);
	void PushDraw(int map[][14]);


	// constructor & destructor
	Scene();
	~Scene();

};