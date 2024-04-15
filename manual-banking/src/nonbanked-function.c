#pragma bank 1

#include <gb/gb.h>
#include <stdint.h>
#include "tutorial-screen.h"
#include "banking-screen.h"
#include "gbdk-splash-screen.h"

void RandomFunctionInBank1() BANKED{

    // This function is in bank 1 
}

void ShowGBDKSplashScreeen1() NONBANKED{

    // This function is non banked (a.k.a. in bank 0)
    // because it's nonbanked, we can switch the active bank in it

    uint8_t _previous_bank = CURRENT_BANK;


    SWITCH_ROM(2);

    // We want to show our splash screen
    set_bkg_data(0,gbdk_splash_screen_TILE_COUNT,gbdk_splash_screen_tiles);
    set_bkg_tiles(0,0,20,18,gbdk_splash_screen_map);

    SWITCH_ROM(_previous_bank);

}