
/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Função principal que inicia o jogo, inicializa a engine, carrega recursos, inicia o jogo e executa o loop principal do jogo.
*/

#include <gb/gb.h>
#include "apple.h"
#include "engine.h"
#include "game.h"

void main(void)
{
    // -------- ------- INIT ENGINE -------------------- //
    InitializeEngine();
    LoadEngineResources();

    // --------- INIT GAME AND LOAD SPRITES ------------ //
    StartGame();
    SetupSprites();

    while(1)
    {
        // --------------- UPDATE ENGINE AND THE GAME ------------ //
        UpdateEngine();
        UpdateGame();

        // ---------------- FRAMERATE DELAY ---------------------- //
        delay(10);

        // VSYNC - Sincronização Vertical ------------------------ //
        wait_vbl_done();
    }
}
