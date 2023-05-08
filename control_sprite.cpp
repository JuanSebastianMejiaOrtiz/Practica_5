
#include "control_sprite.h"

control_sprite::control_sprite()
{
    full = new QPixmap;
    actual = new QPixmap;
}

control_sprite::~control_sprite()
{
    delete full;
    delete actual;
}

void control_sprite::Select_sprite(int x, int y, int width_sprite = 16, int height_sprite = 16)
{
    *actual = full->copy(width_sprite*x, height_sprite*y, width_sprite, height_sprite);
}

void control_sprite::Scale_sprite(float scale)
{
    *actual = actual->scaled(actual->width()*scale, actual->height()*scale);
}

void control_sprite::Show_Sprite(bool appear)
{
    if(appear) setPixmap(*actual);
}

