/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Funções para manipulação de objetos no jogo, incluindo criação, movimentação e detecção de colisões com a tela.
*/

#include "gameobject.h"
#include <gb/gb.h>

void CreateObject(struct Object *obj, u8 _x, u8 _y, u8 _vel_x, u8 _vel_y)
{
    obj->x =         _x;
    obj->y =         _y;
    obj->vel_x =     _vel_x;
    obj->vel_y =     _vel_y;
}

// -------------- IMPLEMENTAÇÃO DE MOVIMENTAÇÃO -------------------- //

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

// ---------------- IMPLEMENTAÇÃO DA COLISÃO DA TELA -------------------- //

void ObjectScreenCollision(struct Object *obj)
{
    // ------- RIGHT SCREEN CHECK --------- //
    if (obj->x >= 160)
    {
        obj->x = 160;
    }

    // -------- LEFT SCREEN CHECK --------- //
    if (obj->x <= 8)
    {
        obj->x = 8;
    }

    // -------- TOP SCREEN CHECK --------- //
    if (obj->y <= 16)
    {
        obj->y = 16;
    }

    // -------- BOTTOM SCREEN CHECK ----- //
    if (obj->y >= 144 + 8)
    {
        obj->y = 144 + 8;
    }
}

