
#include "mainchar.h"

mainchar::mainchar()
{
    QPixmap imagen;
    imagen.load(":/Recursos/Practica5_sprites.png");
    setPos(0,0);
    setPixmap(imagen);

}

