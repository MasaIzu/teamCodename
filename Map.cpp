#include"Map.h"
#include"DxLib.h"
#include"Global.h"


Map::Map() {

	this->block = LoadGraph("block1.png");
	this->block2 = LoadGraph("NONE.png");
	this->goal = LoadGraph("goal.png");
	this->needle = LoadGraph("toge_kari.png");
	this->kagi = LoadGraph("keykari.png");
	this->trap = LoadGraph("needle1.png");
	this->floor = LoadGraph("floor.png");
	mapCount = { 14,6 };
	isOnly = 0;
}


void Map::MapKeep(int map[6][14]) {
	for (int i = 0; i < mapCount.y; i++) {
		for (int j = 0; j < mapCount.x; j++) {
			this->map[i][j] = map[i][j];
		}
	}
}

void Map::SelectMap(int scene, int map[6][14]) {

	if (scene == 0) {
		int mapInit[6][14] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,5,0,0,0,3,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
	else if (scene == 5) {
		int mapInit[6][14] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,4,0,0,0,0,0,0,1 },
		{ 1,5,5,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,1,0,0,3,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,1,4,0,0,0,0,1 },
		{ 1,1,1,1,4,4,4,1,1,1,1,1,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
}


void Map::MapDraw(int map[6][14]) {

	for (int y = 0; y < mapCount.y; y++) {
		for (int x = 0; x < mapCount.x; x++) {
			if (map[y][x] == NONE) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->block2, true);
			}
			if (map[y][x] == BLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->block, true);
			}
			if (map[y][x] == ONOFFBLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->floor, true);
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
			if (map[y][x] == TRAP) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->trap, true);
			}
			if (map[y][x] == TRAPDOWN) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->kagi, true);
			}
		}
	}
}