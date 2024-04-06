#
# Simple Makefile that compiles all .c and .s files in the same folder
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../../
endif

LCC = $(GBDK_HOME)bin/lcc 

# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif


# You can set the name of the .gb ROM file here
PROJECTNAME    = BankingTutorial-AutoBanking

BINS	    = $(PROJECTNAME).gb
CSOURCES   := $(wildcard *.c)
ASMSOURCES := $(wildcard *.s)

all:	$(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ \-p/mkdir/ | grep -v make >> compile.bat

gbdk-splash-screen.o: gbdk-splash-screen.c
	$(LCC) $(LCCFLAGS)  -Wf-bo3 -c -o  gbdk-splash-screen.o gbdk-splash-screen.c

big-data-file1.o: big-data-file1.c
	$(LCC) $(LCCFLAGS)  -Wf-bo2 -c -o  big-data-file1.o big-data-file1.c

big-data-file2.o: big-data-file2.c
	$(LCC) $(LCCFLAGS)  -Wf-bo4 -c -o  big-data-file2.o big-data-file2.c

# Compile and link all source files in a single call to LCC
# MBC5+ROM+RAM : -Wl-yt0x19
#  4 ROM banks  : -Wl-yo4
$(BINS): gbdk-splash-screen.o big-data-file1.o big-data-file2.o
	$(LCC) $(LCCFLAGS) -Wl-yt0x1A -Wl-yo8  -o $@ main.c gbdk-splash-screen.o big-data-file1.o big-data-file2.o

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst

