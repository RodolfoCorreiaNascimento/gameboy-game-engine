
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

// ---------------- DEFINIÇÕES GLOBAIS -------------------- //
struct Object player;

// --------- SET INITIAL SETUP ------------------ //
void StartGame() 
{
    // Create Player
    CreateObject(&player, 70, 80, 0, 0);
}

void SetupSprites()
{
    LoadSprites(0, 1, 0, 0, TileLabel);
}

void UpdateGame()
{
    ObjectMovement(&player, 1, 1);
    ObjectScreenCollision(&player, 160, 144, 8, 16);
}