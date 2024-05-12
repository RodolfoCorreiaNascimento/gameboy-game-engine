/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definição da estrutura de dados para objetos no jogo.
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "my_types.h"

/*!
 * \brief Essa estrutura representa um objeto,
 *          que possui coordenadas x e y, velocidade. i.e: struct Object player;
 */
typedef struct 
{
    u8 x;
    u8 y;
    u8 vel_x;
    u8 vel_y;
    u8 width, height;
    u8 spriteids[4];
    u8 spritesize;

    // physics
    u8 mass;
   
}Object;

void Translate(Object *obj, u8 x, u8 y);

void MoveTo(Object *obj, u8 x_orig, u8 y_orig, u8 x_dest, u8 y_dest);

#endif