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
	LoadDivGraph("Elec_power.png", 4, 4, 1, 64, 64, this->epower);
	LoadDivGraph("elec.png", 3, 3, 1, 64, 64, this->elec);
	LoadDivGraph("check.png", 6, 6, 1, 64, 64, this->check);
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

	if (scene == 0) {//ステージ0(チュートリアル)
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
	else if (scene == 5) {//ステージ1
		int mapInit[6][14] = {
		 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		 { 1,0,0,0,0,0,4,4,0,0,0,0,0,1 },
		 { 1,5,0,0,0,0,0,0,0,0,0,0,0,1 },
		 { 1,1,0,0,1,0,0,3,0,0,0,0,0,1 },
		 { 1,1,1,0,0,0,5,1,4,0,0,0,0,1 },
		 { 1,1,1,1,4,4,4,1,1,1,1,1,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
	else if (scene == 6) {//ステージ2
		int mapInit[6][14] = {
		 { 1,1,1,1,1,1,1,1,4,4,1,1,1,1 },
	 	 { 1,1,4,0,5,0,0,6,0,0,0,0,1,1 },
		 { 1,1,1,1,1,1,1,1,3,0,0,0,1,1 },
		 { 1,1,1,1,0,0,0,0,0,0,0,4,1,1 },
		 { 1,1,1,1,0,0,0,0,0,0,0,0,4,1 },
		 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
	else if (scene == 7) {//ステージ3
		int mapInit[6][14] = {
		 { 4,4,4,4,4,4,4,4,4,4,1,4,4,4 },
		 { 4,0,0,0,6,0,0,0,0,7,0,0,0,4 },
		 { 4,0,4,0,4,4,4,4,4,4,0,4,0,4 },
		 { 4,0,4,0,4,4,4,4,4,4,5,4,0,4 },
		 { 4,0,0,0,7,0,0,0,0,6,0,3,0,4 },
		 { 4,4,4,1,4,4,4,4,4,4,4,4,4,4 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
	else if (scene == 8) {//ステージ4
		int mapInit[6][14] = {
		 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		 { 1,0,0,0,0,0,4,4,0,0,6,0,0,1 },
	 	 { 10,0,0,0,0,0,0,0,0,0,0,6,0,1 },
		 { 1,5,0,0,1,0,0,3,0,0,0,0,6,1 },
		 { 1,0,1,0,0,0,5,1,4,0,0,0,0,1 },
		 { 1,1,1,1,4,4,4,1,1,1,1,8,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
	else if (scene == 9) {//ステージ5
		int mapInit[6][14] = {
		 { 1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		 { 1,6,0,1,0,1,0,1,6,0,6,0,6,1 },
		 { 4,0,0,0,0,0,0,5,0,0,0,0,0,1 },
		 { 10,0,0,0,0,0,0,0,0,0,5,0,0,1 },
		 { 4,0,0,5,0,11,0,3,0,0,0,0,6,1 },
		 { 1,1,1,4,4,1,1,1,4,4,4,1,1,1 },
		};

		for (int i = 0; i < mapCount.y; i++) {
			for (int j = 0; j < mapCount.x; j++) {
				map[i][j] = mapInit[i][j];
			}
		}
	}
}

void Map::sparkReset(int map[6][14]) {
	for (int y = 0; y < mapCount.y; y++) {
		for (int x = 0; x < mapCount.x; x++) {
			if (map[y][x] == ELEC1) {
				map[y][x] = NONE;
			}
			if (map[y][x] == ELEC2) {
				map[y][x] = NONE;
			}
			if (map[y][x] == ELEC3) {
				map[y][x] = NONE;
			}
		}
	}
}

void Map::spark(int map[6][14]) {
	for (int y = 0; y < mapCount.y; y++) {
		for (int x = 0; x < mapCount.x; x++) {
			if (map[y][x] == EPOWERU) {
				for (int k = 1; k < 5; k++) {
					if (map[y - k][x] == ELEC2) {
						map[y + k][x] = ELEC3;
					}
					else if (map[y - k][x] == NONE) {
						map[y - k][x] = ELEC1;
					}
					else {
						break;
					}
				}
			}
			if (map[y][x] == EPOWERD) {
				for (int k = 1; k < 5; k++) {
					if (map[y + k][x] == ELEC2) {
						map[y + k][x] = ELEC3;
					}
					else if (map[y + k][x] == NONE) {
						map[y + k][x] = ELEC1;
					}
					else {
						break;
					}
				}
			}
			if (map[y][x] == EPOWERL) {
				for (int k = 1; k < 13; k++) {
					if (map[y][x + k] == ELEC1) {
						map[y][x + k] = ELEC3;
					}
					if (map[y][x + k] == NONE) {
						map[y][x + k] = ELEC2;
					}
					else {
						break;
					}
				}
			}
			if (map[y][x] == EPOWERR) {
				for (int k = 1; k < 13; k++) {
					if (map[y][x - k] == ELEC1) {
						map[y][x - k] = ELEC3;
					}
					if (map[y][x - k] == NONE) {
						map[y][x - k] = ELEC2;
					}
					else {
						break;
					}
				}
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
			else if (map[y][x] == BLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->block, true);
			}
			else if (map[y][x] == ONOFFBLOCK) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->floor, true);
			}
			else if (map[y][x] == GOAL) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->goal, true);
			}
			else if (map[y][x] == NEEDLE) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->needle, true);
			}
			else if (map[y][x] == KEY) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->kagi, true);
			}
			else if (map[y][x] == TRAP) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->trap, true);
			}
			else if (map[y][x] == TRAPDOWN) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->kagi, true);
			}
			else if (map[y][x] == EPOWERU) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->epower[0], true);
			}
			else if (map[y][x] == EPOWERD) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->epower[1], true);
			}
			else if (map[y][x] == EPOWERL) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->epower[2], true);
			}
			else if (map[y][x] == EPOWERR) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->epower[3], true);
			}
			else if (map[y][x] == ELEC1) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->elec[0], true);
			}
			else if (map[y][x] == ELEC2) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->elec[1], true);
			}
			else if (map[y][x] == ELEC3) {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->elec[2], true);
			}
			else {
				DrawGraph(x * BLOCK_SIZE, y * BLOCK_SIZE, this->floor, true);
			}
		}
	}
}