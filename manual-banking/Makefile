#
# Simple Makefile that compiles all .c and .s files in the same folder
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
	GBDK_HOME = ../../../
endif

LCC = $(GBDK_HOME)bin/lcc 
LCCFLAGS = -Iheaders


# You can set the name of the .gb ROM file here
PROJECTNAME    = BankingTutorial-ManualBanking

BINS	    = $(PROJECTNAME).gb
CSOURCES   := $(wildcard src/*.c)

all: prepare $(BINS)

prepare:
	mkdir -p bin

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ \-p/mkdir/ | grep -v make >> compile.bat

romusage:  $(CSOURCES)
	$(LCC) $(LCCFLAGS) -Wl-yt0x1A -Wl-yo8 Iheaders  -Wa-l -Wl-m -Wl-j -debug -v -o $(BINS) $(CSOURCES)
	../romusage.exe $(PROJECTNAME).cdb -a -nB -R

# Compile and link all source files in a single call to LCC
# MBC5+ROM+RAM : -Wl-yt0x19
#  8 ROM banks  : -Wl-yo8
$(BINS): $(CSOURCES)
	$(LCC) $(LCCFLAGS) -Wl-yt0x1A -Wl-yo8  -o $@ $(CSOURCES)

romusage:  $(CSOURCES)
	$(LCC) $(LCCFLAGS) -Wl-yt0x1A -Wl-yo8 Iheaders  -Wa-l -Wl-m -Wl-j -debug -v -o $(BINS) $(CSOURCES)
	../romusage.exe $(PROJECTNAME).cdb -a -nB -R

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.noi *.rst
	rm -f  bin/*.*

