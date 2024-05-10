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
struct Object
{
    u8 x;
    u8 y;
    u8 vel_x;
    u8 vel_y;
    u8 width, height;
    u8 spriteids[4];
    u8 spritesize;
};

#endif