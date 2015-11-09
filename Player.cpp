//Ok

#include "Player.h"

Player::~Player(){}

Player::Player(){
    setScore(0);
    setPlayerName("Player 1");
}
void Player::setScore(int score){
    this->score=score;
}
void Player::setPlayerName(QString playerName){
    this->playerName=playerName;
}
int Player::getScore(){
    return this->score;
}
QString Player::getPlayerName(){
    return this->playerName;
}
