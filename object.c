#include "object.h"

void Translate(struct Object *obj, u8 _x, u8 _y)
{
    obj->x += _x;
    obj->y += _y;
}

void MoveTo(struct Object *obj, u8 x_orig, u8 y_orig, u8 x_dest, u8 y_dest)
{
    obj->x = x_dest;
    obj->y = y_dest;
}