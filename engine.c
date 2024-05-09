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

void CreateObject(struct Object *obj, u8 _x, u8 _y, u8 _vel_x, u8 _vel_y)
{
    obj->x =         _x;
    obj->y =         _y;
    obj->vel_x =     _vel_x;
    obj->vel_y =     _vel_y;
}

// --------------  MOVIMENTAÇÃO DE OBJETO -------------------- //

void ObjectMovement(struct Object *obj)
{
    obj->vel_x = 1;
    obj->vel_y = 1;

    if (joypad() & J_RIGHT)
    {
        obj->x+=obj->vel_x;
    }

    if (joypad() & J_LEFT)
    {
       obj->x-=obj->vel_x;
    }

    if (joypad() & J_UP)
    {
        obj->y-=obj->vel_y;
    }

    if (joypad() & J_DOWN)
    {
        obj->y+=obj->vel_y;
    }

    move_sprite(0, obj->x, obj->y);
}

// ---------------- COLISÃO DA TELA -------------------- //

void ObjectScreenCollision(struct Object *obj, u8 _screenwidth, u8 _screenheight, u8 _tileWidth, u8 _tileDimension)
{
    u8 screenwidth = _screenwidth;
    u8 screenheight = _screenheight;
    u8 tileWidth = _tileWidth;
    u8 tileDimension = _tileDimension;

    // ------- RIGHT SCREEN CHECK --------- //
    if (obj->x >= screenwidth)
    {
        obj->x = screenwidth;
    }

    // -------- LEFT SCREEN CHECK --------- //
    if (obj->x <= tileWidth)
    {
        obj->x = tileWidth;
    }

    // -------- TOP SCREEN CHECK --------- //
    if (obj->y <= tileDimension)
    {
        obj->y = tileDimension;
    }

    // -------- BOTTOM SCREEN CHECK ----- //
    if (obj->y >= screenheight + tileWidth)
    {
        obj->y = screenheight + tileWidth;
    }
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




