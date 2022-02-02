#pragma once
#include"Player.h"
#include"Map.h"
#include"key.h"
#include"Easing.h"
#include"CharaTalk.h"
#include"ChangeSc.h"

class Scene
{
private:
	int scene;
	int isShiftPush;
	int shiftGh;
	int sceneChange;
public:
	Player player;
	Map MAP;
	Easing easing;
	Key key;
	CharaTalk charaTalk;
	ChangeSc changeSc;

	void PushMove(char* keys, char* oldkeys, int map[6][14],int mpx,int mpy);
	void PushDraw(int map[][14]);


	// constructor & destructor
	Scene();
	~Scene();

};