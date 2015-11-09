//Ok

#include "Bird.h"

Bird::~Bird(){}

Bird::Bird(){
    setX(20);
    setY(20);
    setAceleration(0);
}
Bird::Bird(int x,int y,int size){
    this->x=x;
    this->y=y;
    this->size=size;
}
void Bird::setX(int x){
    this->x = x;
}
void Bird::setY(int y){
    this->y = y;
}
void Bird::setSize(int size){
    this->size=size;
}
void Bird::setAceleration(int aceleration){
    this->aceleration = aceleration;
}
int Bird::getX(){
    return this->x;
}
int Bird::getY(){
    return this->y;
}
int Bird::getSize(){
    return this->size;
}
int Bird::getAceleration(){
    return this->aceleration;
}
/*
void Bird::jumpBird(){
    setAceleration(-1);
    this->setY(this->getY() - 60);
}
*/
void Bird::jumpBird(){
    setAceleration(-1);
this->setY(this->getY() - 60);
    /*int aceleration_2 = 10;

    int fixed = this->getY() - 60;
    int i = this->getY();


    while(i > fixed){
        i += 10 - aceleration- 2;
        this->setY(this->getY() - 10 - aceleration_2);
        if(aceleration_2 !=0){
            aceleration_2-=2;
        }
    }*/
}

void Bird::gravity(){
    this->setY(this->getY() + 5 + aceleration);
    if(aceleration < 60){
        setAceleration(getAceleration()+10);
    }
}
bool Bird::groundColider(){
    if(getY()>= 400){
        setY(380);
        setGround(true);
        return true;
    }
    return false;
}

bool Bird::getGround(){
    return this->_ground;
}
void Bird::setGround(int _ground){
    this->_ground = _ground;
}
void Bird::draw(QPainter& painter){

    QImage imagem;

    if(count_fps <= 10){
        imagem.load(":/img/bird_1.png");
    }
    if(count_fps > 10 && count_fps <= 20){
        imagem.load(":/img/bird_2.png");
    }
    if(count_fps > 20 && count_fps <= 30){
        imagem.load(":/img/bird_3.png");
    }
    if(count_fps >=30){
        count_fps = 0;
    }
    if(getAceleration() < 0){
       imagem.load(":/img/bird_up_45.png");
    }
    if(getAceleration() >=30){
        imagem.load(":/img/bird_down_45.png");
    }
    if(getAceleration() >=60){
        imagem.load(":/img/bird_down.png");
    }

    painter.drawImage(getX(), getY(),imagem,0,0);
    count_fps++;

}
