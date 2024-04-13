//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_tutorial_screen_H
#define METASPRITE_tutorial_screen_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define tutorial_screen_TILE_ORIGIN 0
#define tutorial_screen_TILE_W 8
#define tutorial_screen_TILE_H 8
#define tutorial_screen_WIDTH 160
#define tutorial_screen_HEIGHT 144
#define tutorial_screen_TILE_COUNT 53
#define tutorial_screen_PALETTE_COUNT 1
#define tutorial_screen_COLORS_PER_PALETTE 4
#define tutorial_screen_TOTAL_COLORS 4
#define tutorial_screen_MAP_ATTRIBUTES 0

BANKREF_EXTERN(tutorial)

extern const palette_color_t tutorial_screen_palettes[4];
extern const uint8_t tutorial_screen_tiles[848];

extern const unsigned char tutorial_screen_map[360];
#define tutorial_screen_map_attributes tutorial_screen_map

#endif
