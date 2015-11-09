//Ok

#include "Util.h"

Util::~Util(){}
Util::Util(){}

/*
        Baseado em:
        http://developer.nokia.com/community/wiki/Generating_random-value_integers_in_Qt
*/
int Util::randInt(int low, int high){
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    return qrand() % ((high + 1) - low) + low;
}



