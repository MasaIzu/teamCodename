﻿#include <DxLib.h>
#include "key.h"

Key::Key () {
	for ( int i = 0; i < 256; i++ ) {
		codeName[i] = 0;
	}
}


void Key::Inputkey (char* keys, char* oldkeys, int map[][14], int PTX, int PTY) {

	for ( int i = 0; i < 256; i++ ) {
		if ( keys[KEY_INPUT_1] == true && oldkeys[KEY_INPUT_1] == false ) {
			mapX = 1;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '1';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_2] == true && oldkeys[KEY_INPUT_2] == false ) {
			mapX = 2;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '2';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_3] == true && oldkeys[KEY_INPUT_3] == false ) {
			mapX = 3;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '3';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_4] == true && oldkeys[KEY_INPUT_4] == false ) {
			mapX = 4;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '4';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_5] == true && oldkeys[KEY_INPUT_5] == false ) {
			mapX = 5;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '5';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_6] == true && oldkeys[KEY_INPUT_6] == false ) {
			mapX = 6;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '6';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_7] == true && oldkeys[KEY_INPUT_7] == false ) {
			mapX = 7;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '7';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_8] == true && oldkeys[KEY_INPUT_8] == false ) {
			mapX = 8;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '8';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_9] == true && oldkeys[KEY_INPUT_9] == false ) {
			mapX = 9;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '9';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_0] == true && oldkeys[KEY_INPUT_0] == false ) {
			mapX = 10;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '0';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_MINUS] == true && oldkeys[KEY_INPUT_MINUS] == false ) {
			mapX = 11;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '-';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_PREVTRACK] == true && oldkeys[KEY_INPUT_PREVTRACK] == false ) {
			mapX = 12;
			mapY = 1;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '^';
						break;
					}
				}
			}
		}

		if ( keys[KEY_INPUT_Q] == true && oldkeys[KEY_INPUT_Q] == false ) {
			mapX = 1;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'Q';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_W] == true && oldkeys[KEY_INPUT_W] == false ) {
			mapX = 2;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'W';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_E] == true && oldkeys[KEY_INPUT_E] == false ) {
			mapX = 3;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'E';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_R] == true && oldkeys[KEY_INPUT_R] == false ) {
			mapX = 4;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'R';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_T] == true && oldkeys[KEY_INPUT_T] == false ) {
			mapX = 5;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'T';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_Y] == true && oldkeys[KEY_INPUT_Y] == false ) {
			mapX = 6;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'Y';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_U] == true && oldkeys[KEY_INPUT_U] == false ) {
			mapX = 7;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'U';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_I] == true && oldkeys[KEY_INPUT_I] == false ) {
			mapX = 8;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'I';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_O] == true && oldkeys[KEY_INPUT_O] == false ) {
			mapX = 9;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'O';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_P] == true && oldkeys[KEY_INPUT_P] == false ) {
			mapX = 10;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'P';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_AT] == true && oldkeys[KEY_INPUT_AT] == false ) {
			mapX = 11;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '@';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_LBRACKET] == true && oldkeys[KEY_INPUT_LBRACKET] == false ) {
			mapX = 12;
			mapY = 2;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '[';
						break;
					}
				}
			}
		}

		if ( keys[KEY_INPUT_A] == true && oldkeys[KEY_INPUT_A] == false ) {
			mapX = 1;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'A';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_S] == true && oldkeys[KEY_INPUT_S] == false ) {
			mapX = 2;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'S';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_D] == true && oldkeys[KEY_INPUT_D] == false ) {
			mapX = 3;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'D';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_F] == true && oldkeys[KEY_INPUT_F] == false ) {
			mapX = 4;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'F';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_G] == true && oldkeys[KEY_INPUT_G] == false ) {
			mapX = 5;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'G';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_H] == true && oldkeys[KEY_INPUT_H] == false ) {
			mapX = 6;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'H';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_J] == true && oldkeys[KEY_INPUT_J] == false ) {
			mapX = 7;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'J';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_K] == true && oldkeys[KEY_INPUT_K] == false ) {
			mapX = 8;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'K';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_L] == true && oldkeys[KEY_INPUT_L] == false ) {
			mapX = 9;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'L';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_SEMICOLON] == true && oldkeys[KEY_INPUT_SEMICOLON] == false ) {
			mapX = 10;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = ';';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_COLON] == true && oldkeys[KEY_INPUT_COLON] == false ) {
			mapX = 11;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = ':';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_RBRACKET] == true && oldkeys[KEY_INPUT_RBRACKET] == false ) {
			mapX = 12;
			mapY = 3;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = ']';
						break;
					}
				}
			}
		}

		if ( keys[KEY_INPUT_Z] == true && oldkeys[KEY_INPUT_Z] == false ) {
			mapX = 1;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'Z';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_X] == true && oldkeys[KEY_INPUT_X] == false ) {
			mapX = 2;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'X';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_C] == true && oldkeys[KEY_INPUT_C] == false ) {
			mapX = 3;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'C';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_V] == true && oldkeys[KEY_INPUT_V] == false ) {
			mapX = 4;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'V';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_B] == true && oldkeys[KEY_INPUT_B] == false ) {
			mapX = 5;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'B';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_N] == true && oldkeys[KEY_INPUT_N] == false ) {
			mapX = 6;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'N';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_M] == true && oldkeys[KEY_INPUT_M] == false ) {
			mapX = 7;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'M';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_COMMA] == true && oldkeys[KEY_INPUT_COMMA] == false ) {
			mapX = 8;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = ',';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_PERIOD] == true && oldkeys[KEY_INPUT_PERIOD] == false ) {
			mapX = 9;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '.';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_SLASH] == true && oldkeys[KEY_INPUT_SLASH] == false ) {
			mapX = 10;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '/';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_BACKSLASH] == true && oldkeys[KEY_INPUT_BACKSLASH] == false ) {
			mapX = 11;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = '_';
						break;
					}
				}
			}
		}
		if ( keys[KEY_INPUT_RSHIFT] == true && oldkeys[KEY_INPUT_RSHIFT] == false ) {
			mapX = 12;
			mapY = 4;
			push = true;
			if ( mapX == PTX && mapY == PTY ) {

			}
			else {
				if ( map[mapY][mapX] == 0 || map[mapY][mapX] == 2 ) {
					if ( codeName[i] == 0 ) {
						codeName[i] = 'S';
						codeName[i + 1] = 'H';
						codeName[i + 2] = 'I';
						codeName[i + 3] = 'F';
						codeName[i + 4] = 'T';
						break;
					}
				}
			}
		}
	}

	if ( push == true ) {
		if ( mapX == PTX && mapY == PTY ) {
			push = false;
		}
		else if ( map[mapY][mapX] == 0 || map[mapY][mapX] >= 12 ) {
			map[mapY][mapX] = 2;
		}
		else if ( map[mapY][mapX] == 2 ) {
			map[mapY][mapX] = 0;
		}
		push = false;

	}

}

void Key::KeyDraw () {
	SetFontSize (23);
	for ( int i = 0; i < 256; i++ ) {
		if ( codeName[i] != 0 ) {
			DrawFormatString (350 + 15 * i, 400, GetColor (255, 255, 255), "%c", codeName[i]);
		}
	}
}