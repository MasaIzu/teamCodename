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
	int trap;
	int trapdown;
	int check[6] = { 0 };
	int floor;
	int epower[4] = { 0 };
	int elec[3] = { 3 };

	int map[6][14];
	MapCount mapCount;
	
public:

	// accesser
	int* getMap();
	void setMap(int map[6][14]);

	void sparkReset(int map[6][14]);
	void spark(int map[6][14]);

	// constructor & distructor
	Map(int map[6][14]);

	//ŠÖ”
	void MapDraw(int map[6][14]);
};