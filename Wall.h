//Ok

#ifndef WALL_H
#define WALL_H

#include "Includes.h"
#include "Util.h"

class Wall{

public:
    Wall();
    ~Wall();
    Wall(int x,int y);
    void setX(int x);
    void setY(int y);
    void setSizeX(int sizeX);
    void setSizeY(int sizeY);
    int getX();
    int getY();
    int getSizeX();
    int getSizeY();
    void clearWall();
    void makeWall();
    void passWall();
    void draw(QPainter& painter);
    bool wallColider(int pos_y_bird);
    bool point(int pos_y_bird);
    float getMediaAltura();
    void setMediaAltura(float mediaAltura);
    int getQntWalls();
    void setQntWalls(int qntWalls);

public:
//private:
    int x,y,sizeX, sizeY, count;

    //int grid[60][100];
    int grid[1000][1];
    float mediaAltura;
    int qntWalls;

};
#endif // GHOST_H
