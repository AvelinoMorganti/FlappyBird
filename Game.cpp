#include "Animation.h"
#include "Game.h"
#include "QMessageBox"
#include "QInputDialog"

using namespace std;


Game::Game(): QFrame(NULL, Qt::FramelessWindowHint){

    bird = new Bird(200,200,30);
    player = new Player();
    wall = new Wall();
    ground = new Ground();

    this->setFixedHeight(500);
    this->setFixedWidth(800);
    show();

    //bird->setGround(false);
    this->setEndGame(false);
    //this->setStart(false);
    this->setGodMode(false);
    partida=0;
};

void Game::draw(){
    repaint();
}
bool Game::reset(){
    QMessageBox::information(this, tr("Help - Flappy Bird"),trUtf8("Instruções\n\nP = Pause\nR = Reiniciar\nEspaço/Clique = Pular\nESC = Sair\nG = ???\nL = LineChart"));
    while(player->getPlayerName() == "Player 1"){
        player->setPlayerName(QInputDialog::getText(this, "Player 1",tr("Digite seu Nome: "), QLineEdit::Normal,"Player 1"));
    }
    bird->setX(200);
    bird->setY(200);
    bird->setSize(30);
    bird->setAceleration(0);
    bird->setGround(false);
    player->setScore(0);
    wall->clearWall();
    ground->setMeters(0);
    this->setEndGame(false);
    this->setStart(false);
    this->setGodMode(false);

    setPartida(getPartida() +1);
    return true;
}

void Game::paintEvent(QPaintEvent *event){
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    p.setPen(pen);
    p.drawRect(0, 0, width()-1, height()-1);

    QImage background;
    background.load(":/img/background.png");
    p.drawImage(5, 5,background);


    wall->draw(p);
    ground->draw(p);


    p.setFont(QFont("Arial",18,true));
    p.drawText(20,height()-20,player->getPlayerName());

    p.setFont(QFont("Arial",90,true));

    p.setBrush(QColor("#FFF"));

    if(_start){
        if(!_endgame){
            p.drawText(width() * 0.45,height()/2,QString::number(player->getScore()));
        }

        p.setFont(QFont("Arial",18,true));
        QString meters = QString("%1m").arg(QString::number(ground->getMeters()));
        p.drawText(750-(meters.size() * 12),height()-20,meters);
    }
    if(_endgame){
        if(count >=30){
            QImage gameover;
            gameover.load(":/img/gameOver.png");
            p.drawImage(300,100,gameover);
        }
        QImage scoreboard;
        scoreboard.load(":/img/scoreboard.png");
        p.drawImage(300,160,scoreboard);
        QImage replay;
        replay.load(":/img/replay.png");
        p.drawImage(300,275,replay);
        QImage rank;
        rank.load(":/img/rank.png");
        p.drawImage(410,275,rank);

        QImage medal;
        if(player->getScore() >= 10 && player->getScore() < 20){
            medal.load(":/img/medal_3.png");
        }
        if(player->getScore() >= 20 && player->getScore() <50){
            medal.load(":/img/medal_2.png");
        }
        if(player->getScore() >=50){
            medal.load(":/img/medal_1.png");
        }
        p.drawImage(325,200,medal);


        p.setFont(QFont("Arial",14,true));
        QString score = QString::number(player->getScore());
        p.drawText(470 - (score.size() * 5), 205,score);

    }
    if(!_start && !_endgame){
        QImage flappyBird;
        flappyBird.load(":/img/flappyBird.png");
        //p.drawImage(300,47, flappyBird);
        //p.drawImage(300,40+count/5, flappyBird);
        if(count >=30){
            p.drawImage(300,40+count/5, flappyBird);
        }
        if(count <30){
            p.drawImage(300,40-count/5, flappyBird);
        }

        if(count >=30){
            QImage getReady;
            getReady.load(":/img/getReady.png");
            p.drawImage(300,100, getReady);
        }
        QImage tap;
        tap.load(":/img/tap.png");
        p.drawImage(340,150,tap);
    }
    if(_godmode){
        if(count >=30){
            QImage star;
            star.load(":/img/star.png");
            p.drawImage((50 + (player->getPlayerName().size() *12)), height()-70,star);
        }
    }


    if(player->getScore() >= 10){
        QImage medal3;
        medal3.load(":/img/medal_3.png");
        p.drawImage((120 + (player->getPlayerName().size() *12)),height()-60,medal3);
    }
    if(player->getScore() >= 20 ){
        QImage medal2;
        medal2.load(":/img/medal_2.png");
        p.drawImage((170 + (player->getPlayerName().size() *12)),height()-60,medal2);
    }
    if(player->getScore() >=50){
        QImage medal1;
        medal1.load(":/img/medal_1.png");
        p.drawImage((220 + (player->getPlayerName().size() *12)),height()-60,medal1);
    }



    count++;
    if(count == 60){
        count =0;
    }
    bird->draw(p);
}

bool Game::getStart(){
    return this->_start;
}
void Game::setStart(bool _start){
    this->_start = _start;
}
bool Game::getEndGame(){
    return this->_endgame;
}
void Game::setEndGame(bool _endgame){
    this->_endgame = _endgame;
}

bool Game::getGodMode(){
    return this->_godmode;
}
void Game::setGodMode(bool _godmode){
    this->_godmode = _godmode;
}

void Game::setPartida(int partida){
    this->partida = partida;
}
int Game::getPartida(){
    return this->partida;
}


Game::~Game(){};
