					REM delete previous files
DEL *.gb

REM compile .c files into .o files
C:\gbdk\bin\lcc -c -o main.o main.c
C:\gbdk\bin\lcc -c -o apple.o apple.c
C:\gbdk\bin\lcc -c -o gameobject.o gameobject.c
C:\gbdk\bin\lcc -c -o game.o game.c
C:\gbdk\bin\lcc -c -o engine.o engine.c

REM Compile a .gb file from the compiled .o files
C:\GBDK\bin\lcc  -o HandlingSpritesInGBDK.gb main.o apple.o gameobject.o game.o engine.o

REM delete intermediate files created for the conmpilation process
DEL *.asm
DEL *.lst
DEL *.ihx
DEL *.sym
DEL *.o
