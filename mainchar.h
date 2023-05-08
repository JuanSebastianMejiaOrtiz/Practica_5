
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#define alto_mainchar 16
#define ancho_mainchar 16
#define pos_x_initial 0
#define pos_y_initial 0

class mainchar : public QGraphicsPixmapItem
{
public:
    mainchar();
    ~mainchar();

    //Inputs
    void keyPressEvent(QKeyEvent *event);
        //Movement
    void Movement();
    void Move_UpOrDown();
    void Move_LeftorRight();
        //Bomba
    //Bomba

    //Collision
    //Funciones que digan si toca o no un limite o un muro

    //Attack


private:
    char* movement_input; //u:up ; d:down ; l:left ; r:right ; n:none

};

#endif // MAINCHAR_H
