
/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Esta é a implementação do jogo onde é aplicada a lógica do mesmo, como movimento de objetos, mecânica e colisões, etc.
*/

#include "game.h"
#include "engine.h"
#include "mario.c"
#include "worldTile.c"
#include "tileMapSheet.c"
#include "windowmap.c"
#include <gbdk/font.h>
// ---------------- DEFINIÇÕES GLOBAIS -------------------- //
Object player;

// --------- SET INITIAL SETUP ------------------ //
void StartGame() 
{
    // create font variable that holds a font
    font_t min_font;

    // init font
    font_init();

    // load font into our variable
    min_font = font_load(font_min); // 36 tiles

    // set font to our vram
    font_set(min_font);

    set_win_tiles(0, 0, windowTileWidth, windowTileHeight, windowTile);
    move_win(8, 136);

    // Create Player
    CreateSprite(&player, 160/2 + 16, 144/2 + 16, 16, 16, 8, 150, 0, marioTileCount, marioTile);

    // Create Background
    CreateBackground(37, mapTileCount, tileMapSheet, 0, 0, worldTileWidth, worldTileHeight, worldTile);
    
}

void SetupSprites()
{

}

void UpdateGame()
{
    AddGravity(&player, 5, 9);
    MoveSprite(&player, player.x, player.y);
    ObjectMovement(&player, player.x, player.y, 1, 1);
    ObjectScreenCollision(&player, 160, 144, player.spritesize, player.spritesize);
}
