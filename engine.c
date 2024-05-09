/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definições das funções relacionadas à engine.
*/

#include "engine.h"
#include <gb/gb.h>

// Definições das funções relacionadas à engine

// Definições globais da engine, se necessário

// ------------------------- INITIALIZE ENGINE ------------------------------ //
void InitializeEngine() 
{
    // Inicializa a engine do jogo

    // --------- SET DISPLAY ON AND SHOW SPRITE ------------ //
    DISPLAY_ON;
    SHOW_SPRITES;
}

// ------------------------- LOAD ENGINE REOURCES ------------------------------ //
void LoadEngineResources()
{
    // Carrega recursos da engine
}

// ------------------------- UPDATE ENGINE ------------------------------ //
void UpdateEngine()
{
    // Atualiza a engine do jogo
}

// --------- COPY TILES TO VRAM ------------------- //
void LoadSprites(u8 tile, u8 nb, u8 sprn, u8 select_tile, const u8 *data)
{
    u8 _tile        = tile;
    u8 _nb          = nb;
    const u8 *_data = data;

    u8 _sprn              = sprn;
    u8 _select_tile       = select_tile;

    set_sprite_data(_tile, _nb, _data);
    set_sprite_tile(sprn, select_tile);
}

// ------------------------- SET CAMERA POSITION ------------------------------ //
/*void SetCameraPosition(u8 x, u8 y) 
{

}

// ------------------------- PLAY SOUND ------------------------------ //
void PlaySound(const u8 *sound)
{

}

// ------------------------- STOP SOUND ------------------------------ //
void StopSound()
{

}

// ------------------------- PLAY MUSIC ------------------------------ //
void PlayMusic(const u8 *music)
{

}

// ------------------------- STOP MUSIC ------------------------------ //
void StopMusic()
{

} */


