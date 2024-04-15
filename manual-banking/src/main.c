#include <gb/gb.h>
#include <stdint.h>

// Extra Function
#include "nonbanked-function.h"

// Our assets
#include "your-game-here.h"
#include "tutorial-screen.h"
#include "banking-screen.h"
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

    set_bkg_data(0,banking_screen_TILE_COUNT,banking_screen_tiles);
    set_bkg_tiles(0,0,20,18,banking_screen_map);


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
    set_bkg_data(0,tutorial_screen_TILE_COUNT,tutorial_screen_tiles);
    set_bkg_tiles(0,0,20,18,tutorial_screen_map);

    // Wait for A button press
    WaitForAButtonPress();

    // This function lies in bank 2
    // GBDK will automatically switch to bank 2 when calling this function
    ShowYourGameHere();

    // Loop forever
    while(TRUE) {

		// Game main loop processing goes here
        SCX_REG= SCX_REG+1;

		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
