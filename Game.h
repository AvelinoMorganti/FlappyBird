#ifndef GAME_H
#define GAME_H

#include "Includes.h"
#include <Bird.h>
#include <Player.h>
#include "Wall.h"
#include "Ground.h"

class Game: public QFrame{
    Q_OBJECT
public:
    Game();
    ~Game();
    void draw();
    bool reset();
    void paintEvent(QPaintEvent * event);
    bool getStart();
    void setStart(bool _start);
    bool getEndGame();
    void setEndGame(bool _endgame);
    bool getGodMode();
    void setGodMode(bool _godmode);
    void setPartida(int partida);
    int getPartida();


public:
    QFrame *frame;
    QLabel *lb;
    QVBoxLayout *layout;
    Bird *bird;
    Player *player;
    Wall *wall;
    Ground * ground;
    //bool _bird, _wall, _stop, _endgame;
    bool _wall, _stop, _endgame, _start, _godmode;
    int count;
    int partida;

};

#endif // GAME_H
