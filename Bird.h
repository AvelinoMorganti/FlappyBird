//Ok

#ifndef BIRD_H
#define BIRD_H

#include "Includes.h"

class Bird{

public:
    ~Bird();
    Bird();
    Bird(int x,int y,int size);
    void setX(int x);
    void setY(int y);
    void setSize(int size);
    void setAceleration(int aceleration);
    int getX();
    int getY();
    int getSize();
    int getAceleration();
    void jumpBird();
    void gravity();
    bool groundColider();
    void draw(QPainter& painter);
    bool getGround();
    void setGround(int _ground);
private:
    int x,y,size;
    int aceleration=0;
    int bird_aceleration=0;
    int count_fps;
    bool _ground;
};

#endif // BIRD_H
