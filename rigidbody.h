#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "my_types.h"
#include "object.h"
/*P = m . g, em que m é a massa do objeto e g é a aceleração gravitacional*/
// m vai esta no Object, p é o resultado, g é a aceleração gravitacional 

// Fazer função que recebe tal parametros
void AddGravity(Object *obj, u8 _vel_y, u8 gravity);

void AddForce(Object *obj, u8 force);

#endif