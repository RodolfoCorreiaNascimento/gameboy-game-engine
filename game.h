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

#include "object.h"
#include "apple.h"
#include <gb/gb.h>

// ------------- GAME INIT ------------------- //

// Initializes the game
/*!
 * \brief Essa implementação inicia a o jogo do game boy.
 */
void StartGame();

// Load the sprites
/*!
 * \brief Essa implementação carrega os tiles e backgrounds da game.
 */
void SetupSprites();

// Main game loop
/*!
 * \brief Essa implementação atualiza o jogo.
 */
void UpdateGame();

#endif
