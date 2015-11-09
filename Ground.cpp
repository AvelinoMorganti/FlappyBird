#include "Ground.h"

Ground::Ground(){
    count_fps=0;
    meters= 0;
}

void Ground::setMeters(int meters){
    this->meters = meters;
}
int Ground::getMeters(){
    return this->meters;
}

void Ground::draw(QPainter& painter){

    QImage imagem;
    imagem.load(":/img/ground.png");


    if(count_fps <= 30){
        painter.drawImage(-7, 400,imagem,0,0);
    }
    if(count_fps > 30){
        painter.drawImage(-21, 400,imagem,0,0);
    }
    if(count_fps == 60){
        count_fps = 0;
        //meters++;
    }
    count_fps++;

}
