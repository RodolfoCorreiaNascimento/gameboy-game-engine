#include "rigidbody.h"

void AddGravity(Object *obj, u8 _velY, u8 gravity)
{
    u8 strength_weight = obj->mass * gravity;
    obj->y += _velY;
    obj->vel_y += strength_weight;
}

void AddForce(Object *obj, u8 forca) {
    // Adicionando a força à velocidade
    obj->vel_y -= forca;
}