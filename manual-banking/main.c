#include <gb/gb.h>
#include <stdint.h>

// Miccealenous data
#include "big-data-file1.h"
#include "big-data-file2.h"

// Extra Functions
#include "show-splash-screen1.h"
#include "show-splash-screen2.h"

// Our assets
#include "tutorial.h"
#include "banking.h"
#include "gbdk-splash-screen.h"

void WaitForAButtonPress(){
    
    while((joypad() & J_A))vsync();
    while(!(joypad() & J_A))vsync();
    while((joypad() & J_A))vsync();
}

void main(void)
{

    DISPLAY_ON;
    SHOW_BKG;


    // We want to show our banking text
    // It is in bank 1
    // Switch to bank 1 so we can access it's data
    SWITCH_ROM(1);

    set_bkg_data(0,banking_TILE_COUNT,banking_tiles);
    VBK_REG=0;
    set_bkg_tiles(0,0,20,18,banking_map);
    VBK_REG=1;
    set_bkg_tiles(0,0,20,18,banking_map_attributes);


    // Wait for A button press
    WaitForAButtonPress();

    // This function is non banked
    ShowGBDKSplashScreeen1();

    // Wait for A button press
    WaitForAButtonPress();

    // We want to show our tutorial screen
    // Our tutorial text is in the same bank as the "banking" text
    // We previously set the bank to 1, if the 'ShowGBDKSplashScreen' properly restores the active bank
    // then this will work fine.
    set_bkg_data(0,tutorial_TILE_COUNT,tutorial_tiles);
    VBK_REG=0;
    set_bkg_tiles(0,0,20,18,tutorial_map);
    VBK_REG=1;
    set_bkg_tiles(0,0,20,18,tutorial_map_attributes);

    // Wait for A button press
    WaitForAButtonPress();

    // This function lies in bank 2
    ShowYourGameHere();

    // Loop forever
    while(bigData1[1] && bigData2[1]) {


		// Game main loop processing goes here


		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
