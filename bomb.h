
#ifndef BOMB_H
#define BOMB_H

#include "control_sprite.h"
#include "global_macros.h"

class bomb : public control_sprite
{
    Q_OBJECT
public:
    bomb();
    ~bomb();

    //Set and Get Methods
        //kaboom
    void Set_kaboom(bool boom);
    bool Get_kaboom();
        //Already_Exist
    void Set_Already_Exist(bool exist);
    bool Get_Already_Exist();

private:
    //Animation Atributes
    bool kaboom; //0:no explosion, 1:explosion
    QTimer *bomb_timer;
    int Bomb_Animation_Speed; //1000: 1 second
    int Bomb_Animation_Actual_Frame;
    short Bomb_Animation_Moving_Repeat;

    //Other
    bool *Already_Exist;

    //Animation Methods
    void Bomb_Moving();
    void Boom();
    void After_Boom();

private slots:
    //Animation Explosion
    void Kaboom();
};

#endif // BOMB_H
