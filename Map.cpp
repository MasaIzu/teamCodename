#include"Map.h"

Map::Map(int map[6][14]) {
	for (int i = 0; i < mapCount.y; i++) {
		for (int j = 0; j < mapCount.x; j++) {
			this->map[i][j] = map[i][j];
		}
	}
}


int* Map::getMap() {
	return *map;
}

void Map::setMap(int map[6][14]) {

}
