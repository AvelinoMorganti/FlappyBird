#ifndef GROUND_H
#define GROUND_H

#include "Includes.h"

class Ground{
public:
    Ground();
    void draw(QPainter& painter);
    void setMeters(int meters);
    int getMeters();
private:
    int x,y;
    int count_fps;
    int meters;
};

#endif // GROUND_H
