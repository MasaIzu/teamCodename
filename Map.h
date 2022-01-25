#pragma once
#include "struct.h"
#include"Enum.h"

class Map
{
public:

	int block;
	int goal;
	int needle;
	int kagi;

	int map[6][14];
	MapCount mapCount;
	
public:
	// accesser
	int* getMap();
	void setMap(int map[6][14]);

	// constructor & distructor
	Map(int map[6][14]);

	//ŠÖ”
	void MapDraw(int map[6][14]);
};