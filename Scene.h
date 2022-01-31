#pragma once
#include"Player.h"
#include"Map.h"
#include"key.h"
#include"Easing.h"

class Scene
{
private:
	int scene;
	Player player;
	Key key;
	Easing easing;
	Map MAP;
public:


	void PushMove(char* keys, char* oldkeys, int map[][14],int mpx,int mpy, int PTX, int PTY);
	void PushDraw(int map[][14]); 


	// constructor & destructor
	Scene();
	~Scene();

};