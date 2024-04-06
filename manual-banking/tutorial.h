//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_tutorial_H
#define METASPRITE_tutorial_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define tutorial_TILE_ORIGIN 0
#define tutorial_TILE_W 8
#define tutorial_TILE_H 8
#define tutorial_WIDTH 160
#define tutorial_HEIGHT 144
#define tutorial_TILE_COUNT 53
#define tutorial_PALETTE_COUNT 1
#define tutorial_COLORS_PER_PALETTE 4
#define tutorial_TOTAL_COLORS 4
#define tutorial_MAP_ATTRIBUTES 0

BANKREF_EXTERN(tutorial)

extern const palette_color_t tutorial_palettes[4];
extern const uint8_t tutorial_tiles[848];

extern const unsigned char tutorial_map[360];
#define tutorial_map_attributes tutorial_map

#endif
