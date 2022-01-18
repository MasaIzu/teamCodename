#pragma once
#include "struct.h"

class Map
{
private:
	int map[6][14];
	MapCount mapCount;

public:
	// accesser
	int* getMap();
	void setMap(int map[6][14]);

	// constructor & distructor
	Map(int map[6][14]);
};