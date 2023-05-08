
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

void control_sprite::Select_sprite()
{

}

void control_sprite::Scale_sprite()
{

}

void control_sprite::Show_Sprite(bool appear)
{
    if(appear){
        setPixmap(actual);
    }
}

