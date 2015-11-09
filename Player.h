#ifndef PLAYER_H
#define PLAYER_H

#include "Includes.h"

class Player{
public:
    Player();
    ~Player();
    void setScore(int score);
    int getScore();
    void setPlayerName(QString playerName);
    QString getPlayerName();
private:
    int score;
    QString playerName;
};

#endif // PLAYER_H
