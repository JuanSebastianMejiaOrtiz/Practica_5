
#include "mainchar.h"

mainchar::mainchar() : Character(pos_x_initial_mc, pos_y_initial_mc)
{
    //Assign Memory for Attributes
    bomba = new bomb;

    //Set Default Values
    Dead_Actual_Frame = 0;

    //Obtain QPixmap full
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(0, 0, ancho_mainchar*number_cols_mc, alto_mainchar*number_lines_mc);

    //Connect for all signals
        //Connect Start Explosion
    connect(bomba, SIGNAL(start_explosion(QTimer*)), this, SLOT(Quit_Bomb(QGraphicsItem*,QTimer*)));
        //Connect and Start Dead_Timer
    connect(&Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));
    Dead_Timer.start(Dead_Animation_Speed_mc);
}

mainchar::~mainchar()
{

}

void mainchar::keyPressEvent(QKeyEvent *event)
{
    if (Get_isAlive()){
        //Movement
        if (event->key() == Qt::Key_W){
            Set_Direction('u');
            Move();
        }
        else if (event->key() == Qt::Key_S){
            Set_Direction('d');
            Move();
        }
        else if (event->key() == Qt::Key_A){
            Set_Direction('l');
            Move();
        }
        else if (event->key() == Qt::Key_D){
            Set_Direction('r');
            Move();
        }

        //Bomba (para bailar esto es una)
        if(event->key() == Qt::Key_B && !bomba->is_activated()){
            //Pos Bomba
            bomba->Pos_Bomb = Position_Bomb();

            bomba->activate_bomb(true);
            bomba->setPos(bomba->Pos_Bomb);
            bomba->bomb_timer->start(bomb_Animation_Speed);
            emit colocar_bomba(bomba);
        }
    }
}

QPointF mainchar::Position_Bomb()
{
    int PositioninX = static_cast<int>(pos().x()) / wall_ancho;
    int PositioninY = static_cast<int>(pos().y()) / wall_alto;
    int residuo;

    PositioninX *= wall_ancho;
    PositioninY *= wall_alto;

    residuo = PositioninX % (wall_ancho * Scale);
    PositioninX -= residuo;

    residuo = PositioninY % (wall_alto * Scale);
    PositioninY -= residuo;

    return QPointF(PositioninX, PositioninY);
}

void mainchar::Dead_Animation()
{
    if (!Get_isAlive()){
        if (Dead_Actual_Frame < Dead_Animation_Frame_Ammount_mc){
            Select_sprite(Dead_Actual_Frame, 2);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Dead_Actual_Frame++;
        }
        else if (Dead_Actual_Frame == Dead_Animation_Frame_Ammount_mc){
            //Dead_Timer->stop();
            Dead_Timer.stop();
            Dead_Actual_Frame = 0;
            Show_Sprite(0);
        }
    }
}

void mainchar::Quit_Bomb(QGraphicsItem *item, QTimer *timer)
{
    emit quita_bomba(item, timer);
}

