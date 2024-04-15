//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_your_game_here_H
#define METASPRITE_your_game_here_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define your_game_here_TILE_ORIGIN 0
#define your_game_here_TILE_W 8
#define your_game_here_TILE_H 8
#define your_game_here_WIDTH 160
#define your_game_here_HEIGHT 144
#define your_game_here_TILE_COUNT 100
#define your_game_here_PALETTE_COUNT 1
#define your_game_here_COLORS_PER_PALETTE 4
#define your_game_here_TOTAL_COLORS 4
#define your_game_here_MAP_ATTRIBUTES 0

BANKREF_EXTERN(your_game_here)

extern const palette_color_t your_game_here_palettes[4];
extern const uint8_t your_game_here_tiles[1600];

extern const unsigned char your_game_here_map[360];
#define your_game_here_map_attributes your_game_here_map

void ShowYourGameHere() BANKED;

#endif
