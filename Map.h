#pragma once

class Map
{
public:

	int map[6][14] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,4,4,0,0,0,0,0,1},
		{1,5,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,0,0,3,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,4,0,0,0,0,1},
		{1,1,1,1,4,4,4,1,1,1,1,1,1,1},
	};

	const int blockSize = 64;

	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);

	enum MapInfo
	{
		NONE,
		BLOCK,
		ONOFFBLOCK,
		GOAL,
		NEEDLE,
		KEY,
	};

	void InitMap();
};