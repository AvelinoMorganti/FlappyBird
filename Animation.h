/*

http://gamedev.stackexchange.com/questions/70268/can-someone-explain-flappy-birds-physics-to-me
http://fnoschese.wordpress.com/2014/01/30/flappy-bird-when-reality-seems-unrealistic/


*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Includes.h"
#include "Game.h"
#include "Wall.h"
#include "Bird.h"
#include "Player.h"
#include "FlappySound.h"
#include "LineChart.h"

class Animation: public  QMainWindow{
    Q_OBJECT
public:
    Animation();
    void pause();
    void godmode();
    void grafic();


    void end();


    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);



    void jumpBird();
    void gravity();
    void passWall();

public slots:
    void reset();

private slots:
    void _update();
    void _gravity();

private:
    QFrame *frame;
    QVBoxLayout *layout;
    Player *player;
    Game *game;
    Bird *bird;
    Wall *wall;
    qint64 _last_time_60fps;
    qint64 _accumulator60;
    int _max_fps;
    int _counter;
    float _constant_dt;
    QTimer *tanimation, *tgravity;
    bool _pause, _grafic,_jump;

    FlappySound *sound;
    LineChart* line_chart, *real_time;

    QVector<QString> x_values;
    QVector<QString> y_values;
    QVector<QString> legendValues;
    QVector<QPoint> graficWalls;
    QVector<QPoint> graficScore;

    int salto=0;
    int valorSubida=0;

};

#endif // ANIMATION_H



