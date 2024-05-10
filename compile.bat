					REM delete previous files
DEL *.gb

REM compile .c files into .o files
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o game.o game.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o engine.o engine.c


REM Compile a .gb file from the compiled .o files
C:\GBDK\bin\lcc -DUSE_SFR_FOR_REG -o GameBoy_GameEngine.gb main.o game.o engine.o
REM delete intermediate files created for the conmpilation process
DEL *.asm
DEL *.lst
DEL *.ihx
DEL *.sym
DEL *.o
