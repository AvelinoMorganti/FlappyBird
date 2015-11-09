#ifndef FLAPPYSOUND_H
#define FLAPPYSOUND_H

#include "Includes.h"

class FlappySound{

public:
    FlappySound();
    void soundDie();
    void soundHit();
    void soundPoint();
    void soundSwooshing();
    void soundWing();
    void soundInvincibility(bool status);
    void soundStarRoad(bool status);
public:
    Phonon::MediaObject *invincibility;
    Phonon::MediaObject *starRoad;
    /*QSound bell(":/sounds/point.wav");
    bell.play();*/

};

#endif // FLAPPYSOUND_H
