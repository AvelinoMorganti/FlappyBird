//Ok

#include "Wall.h"

Wall::~Wall(){}

Wall::Wall(){
    setSizeX(60);
    clearWall();
    mediaAltura=0;
}
Wall::Wall(int x,int y){
    this->x=x;
    this->y=y;
}
void Wall::setX(int x){
    this->x = x;
}
void Wall::setY(int y){
    this->y = y;
}
void Wall::setSizeX(int sizeX){
    this->sizeX=sizeX;
}
void Wall::setSizeY(int sizeY){
    this->sizeY=sizeY;
}
int Wall::getX(){
    return this->x;
}
int Wall::getY(){
    return this->y;
}
int Wall::getSizeX(){
    return this->sizeX;
}
int Wall::getSizeY(){
    return this->sizeY;
}
void Wall::clearWall(){
    for(int i=0;i<999;i++){
        this->grid[i][0]=0;
    }
}
void Wall::makeWall(){
    Util *util = new Util();
    int linha = util->randInt(-250,-50);
    //int linha = -50;
    this->grid[998][0]=linha;
    mediaAltura += (linha + 420);
    qntWalls++;
}
void Wall::passWall(){
    if(count == 120){
        makeWall();
        count = 0;
    }

    for(int j=0;j<2;j++){
        for(int i=1;i<999;i++){
            this->grid[i][0] = this->grid[(i+1)][0];
            std::cout << grid[i][j];
        }
        std::cout << "" << std::endl;
    }

    count++;
}

bool Wall::wallColider(int pos_y_bird){
    //if(grid[198][0] < 0){
        for(int i = 198;i<250;i++){
            //if(pos_y_bird <= (grid[198][0]+320)){
            if((pos_y_bird <= (grid[i][0]+320 -1)) && grid[i][0] <0){
                return true;
            }
        //if(pos_y_bird >= (grid[198][0]+420 - 30)){
            if((pos_y_bird >= (grid[i][0]+420 -24)) && grid[i][0] <0){
                return true;
            }
        }
    //}
    return false;
}

bool Wall::point(int pos_y_bird){
    if(grid[198][0] < 0){
        if((pos_y_bird > (grid[198][0]+320)) && (pos_y_bird < (grid[198][0]+420))){
            return true;
        }
    }
    return false;
}

void Wall::draw(QPainter& painter){
    for(int i=0;i<1000;i++){
        if((this->grid[i][0])<0){
            QImage wall_down;
            wall_down.load(":/img/wall_down.png");
            painter.drawImage(i, this->grid[i][0],wall_down);
            QImage wall_up;
            wall_up.load(":/img/wall_up.png");
            painter.drawImage(i, (this->grid[i][0] + 420),wall_up);


        }
    }
}

float Wall::getMediaAltura(){
    return this->mediaAltura;
}
void Wall::setMediaAltura(float mediaAltura){
    this->mediaAltura = mediaAltura;
}

int Wall::getQntWalls(){
    return this->qntWalls;
}
void Wall::setQntWalls(int qntWalls){
    this->qntWalls = qntWalls;
}
