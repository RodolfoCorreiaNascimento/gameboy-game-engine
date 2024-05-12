
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
// ---------------- DEFINIÇÕES GLOBAIS -------------------- //
Object player;

// --------- SET INITIAL SETUP ------------------ //
void StartGame() 
{
    
    // Create Player
    CreateSprite(&player, 160/2 + 16, 144/2 + 16, 16, 16, 8, 150, 0, marioTileCount, marioTile);

    // Create Background
    CreateBackground(0, mapTileCount, tileMapSheet, 0, 0, worldTileWidth, worldTileHeight, worldTile);
    
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
