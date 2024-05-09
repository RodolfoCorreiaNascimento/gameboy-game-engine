/*
09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Este arquivo contém as definições do jogo, incluindo a inicialização, carregamento de sprites e o loop principal do jogo.
*/

#ifndef GAME_H
#define GAME_H

#include "gameobject.h"
#include "object.h"
#include "apple.h"
#include <gb/gb.h>

// ------------- GAME INIT ------------------- //

// Initializes the game
void StartGame();

// Load the sprites
void SetupSprites();

// Main game loop
void UpdateGame();

#endif
