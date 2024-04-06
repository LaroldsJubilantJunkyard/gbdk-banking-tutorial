#pragma bank 2

#include <gb/gb.h>
#include <stdint.h>
#include "your-game-here.h"


void ShowYourGameHere() BANKED{

    // We want to show our splash screen
    set_bkg_data(0,your_game_here_TILE_COUNT,your_game_here_tiles);
    VBK_REG=0;
    set_bkg_tiles(0,0,20,18,your_game_here_map);
    VBK_REG=1;
    set_bkg_tiles(0,0,20,18,your_game_here_map_attributes);

}