#pragma once
#include "struct.h"
#include"Enum.h"

class Map
{
public:
	int block;
	int block2;
	int goal;
	int needle;
	int kagi;
	int trap;
	int trapDown;
	int floor;
	int map[6][14];
	MapCount mapCount;
	int changeNextMap[6][14];
	int isOnly;
	int check[6] = { 0 };
	int epower[4] = { 0 };
	int elec[3] = { 3 };
public:

	void sparkReset(int map[6][14]);
	void spark(int map[6][14]);

	// constructor & distructor
	Map();

	//ä÷êî
	void MapKeep(int map[6][14]);
	void MapDraw(int map[6][14]);
	void SelectMap(int scene, int map[6][14]);
};