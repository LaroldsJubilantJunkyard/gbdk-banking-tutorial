#include <gb/gb.h>
#include <stdint.h>
#include "gbdk-splash-screen.h"
#include "big-data-file1.h"
#include "big-data-file2.h"

void main(void)
{

    DISPLAY_ON;
    SHOW_BKG;

    // We want to show our splash screen
    set_bkg_data(0,gbdk_splash_screen_TILE_COUNT,gbdk_splash_screen_tiles);
    set_bkg_tiles(0,0,20,18,gbdk_splash_screen_map);

    // Loop forever
    while(bigData1[1] && bigData2[1]) {


		// Game main loop processing goes here


		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
