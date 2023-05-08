
#ifndef CONTROL_SPRITE_H
#define CONTROL_SPRITE_H

#include <QGraphicsPixmapItem>

class control_sprite : public QGraphicsPixmapItem
{
public:
    control_sprite();
    ~control_sprite();

    void Select_sprite(int x, int y, int width_sprite, int height_sprite);
    void Scale_sprite(float scale);
    void Show_Sprite(bool appear);
protected:
    QPixmap *full, *actual;
};

#endif // CONTROL_SPRITE_H
