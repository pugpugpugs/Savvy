#pragma once
#include <string>

// Paths
const std::string START_TILE_FILEPATH = "assets\\start.png";
const std::string NORMAL_TILE_FILEPATH = "assets\\tilemap.png";
const std::string DW_TILE_FILEPATH = "assets\\tilemap.png";
const std::string TW_TILE_FILEPATH = "assets\\tilemap.png";
const std::string DL_TILE_FILEPATH = "assets\\green.png";
const std::string TL_TILE_FILEPATH = "assets\\darkgreen.png";

const std::string LETTER_TILE_FILEPATH = "assets\\tilemap.png";

// Texture
const int ORIG_BOARD_TILE_SPRITE_SIZE = 16;
const int BOARD_TILE_SPRITE_SIZE = 64;

// Tiles
const int BOARD_TILE_SCALE_SIZE = 128;

const int ORIG_BOARD_TILE_WIDTH = 14;
const int BOARD_TILE_WIDTH = 64;
const int ORIG_BOARD_TILE_HEIGHT = 14;
const int BOARD_TILE_HEIGHT = 64;

const int LETTER_TILE_START_POS_Y = 128;
const int LETTER_TILE_START_POS_X = 0;

const int NORMAL_TILE_MULTIPLIER = 1;
//const int NORMAL_TILE_START_POS_X = 145;
const int NORMAL_TILE_START_POS_X = 0;
//const int NORMAL_TILE_START_POS_Y = 1;
const int NORMAL_TILE_START_POS_Y = 0;

const int DW_TILE_MULTIPLIER = 2;
const int DW_TILE_START_POS_X = 64;
//const int DW_TILE_START_POS_X = 1;
const int DW_TILE_START_POS_Y = 0;
//const int DW_TILE_START_POS_Y = 1;

const int TW_TILE_MULTIPLIER = 3;
const int TW_TILE_START_POS_X = 128;
const int TW_TILE_START_POS_Y = 0;
