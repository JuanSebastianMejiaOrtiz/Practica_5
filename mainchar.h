
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>


class mainchar : public QGraphicsPixmapItem
{
public:
    mainchar(int x, int y, int ancho, int alto);
    ~mainchar();

    void Select_Sprite(int x, int y);
    void Scale_Sprite(int scale);

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
    QPixmap* ImgMainChar;
    char* movement_input; //u:up ; d:down ; l:left ; r:right ; n:none
    bool* Se_Mueve;

};

#endif // MAINCHAR_H
