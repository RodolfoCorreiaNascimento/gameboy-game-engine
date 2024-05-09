/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definições das funções relacionadas à manipulação de objetos no jogo.
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "object.h"

void CreateObject(struct Object *obj, u8 _x, u8 _y, u8 _vel_x, u8 _vel_y);
void ObjectMovement(struct Object *obj);
void ObjectScreenCollision(struct Object *obj);

#endif