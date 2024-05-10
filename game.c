
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
// ---------------- DEFINIÇÕES GLOBAIS -------------------- //
struct Object player;

// --------- SET INITIAL SETUP ------------------ //
void StartGame() 
{
    // Create Player
    //CreateObject(&player, 70, 80, 0, 0);
    CreateSprite(&player, 70, 80, 16, 16, 8);
    set_sprite_data(0, 8, marioTile);
}

void SetupSprites()
{
    
}

void UpdateGame()
{
    MoveSprite(&player, player.x, player.y);
    ObjectMovement(&player, player.x, player.y, 1, 1);
    ObjectScreenCollision(&player, 160, 144, player.spritesize, player.spritesize);
}
