#include"Map.h"
#include"DxLib.h"
#include"Global.h"


Map::Map(int map[6][14]) {

	this->block = LoadGraph("test.png");
	this->goal = LoadGraph("goal.png");
	this->needle = LoadGraph("toge_kari.png");
	this->kagi = LoadGraph("keykari.png");
	LoadDivGraph("check.png", 6, 6, 1, 64, 64, this->check);

	mapCount = { 14,6 };
	
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

void Map::MapDraw(int map[6][14]) {

	for (int y = 0; y < mapCount.y; y++) {
		for (int x = 0; x < mapCount.x; x++) {
			if (map[y][x] == BLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->block, true);
			}
			if (map[y][x] == ONOFFBLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->block, true);
			}
			if (map[y][x] == GOAL) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->goal, true);
			}
			if (map[y][x] == NEEDLE) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->needle, true);
			}
			if (map[y][x] == KEY) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->kagi, true);
			}
		}
	}
}