#include <gb/gb.h>
#include <stdint.h>

// Miccealenous data
// For teaching purposes, we've added a bunch of extra data to fill up the ROM file
#include "big-data-file1.h"
#include "big-data-file2.h"

// Extra Functions
#include "nonbanked-function.h"
#include "banked-function.h"

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
    set_bkg_tiles(0,0,20,18,banking_map);


    // Wait for A button press
    WaitForAButtonPress();

    // This function is non banked
    // It will switch banks (to bank 2) before showing the gbdk splash screen
    // It should restore the initial bank (bank 1) after it's done
    // if it dosn't, our 'tutorial' screen afterwards will fail.
    ShowGBDKSplashScreeen1();

    // Wait for A button press
    WaitForAButtonPress();

    // We want to show our tutorial screen
    // Our tutorial text is in the same bank as the "banking" text
    // We previously set the bank to 1, if the 'ShowGBDKSplashScreen' properly restores the active bank
    // then this will work fine.
    set_bkg_data(0,tutorial_TILE_COUNT,tutorial_tiles);
    set_bkg_tiles(0,0,20,18,tutorial_map);

    // Wait for A button press
    WaitForAButtonPress();

    // This function lies in bank 2
    // GBDK will automatically switch to bank 2 when calling this function
    ShowYourGameHere();

    // Loop forever
    while(bigData1[1] && bigData2[1]) {


		// Game main loop processing goes here
        SCX_REG= SCX_REG+1;


		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}