#include <gb/gb.h>
#include <stdint.h>
#include "tutorial.h"
#include "banking.h"
#include "gbdk-splash-screen.h"
#include "big-data-file1.h"
#include "big-data-file2.h"

void ShowGBDKSplashScreeen1() NONBANKED{

    uint8_t _previous_bank = CURRENT_BANK;


    SWITCH_ROM(2);

    // We want to show our splash screen
    set_bkg_data(0,gbdk_splash_screen_TILE_COUNT,gbdk_splash_screen_tiles);
    set_bkg_tiles(0,0,20,18,gbdk_splash_screen_map);

    SWITCH_ROM(_previous_bank);

}