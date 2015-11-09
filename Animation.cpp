#include "Animation.h"
#include "QLabel"
#include "QMessageBox"

Animation::Animation(): QMainWindow(NULL, Qt::FramelessWindowHint){
    layout = new QVBoxLayout();
    frame = new QFrame();
    frame->setLayout(layout);

    this->setFixedHeight(520);
    this->setFixedWidth(820);

    setCentralWidget(frame);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowTitle(QString::fromUtf8("Flappy Bird"));

    QRect ct = geometry();
    ct.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(ct);

    game = new Game();
    layout->addWidget(game);
    frame->setFocus();
    game->setStart(false);
    show();

    //sound = new FlappySound();
    reset();
    game->reset();

    tanimation = new QTimer(this);
    tanimation->start(1000/_max_fps);
    QObject::connect(tanimation, SIGNAL(timeout()),this, SLOT(_update()));

    line_chart = new LineChart();
    line_chart->setWindowTitle("Grafic - FlappyBird");
    line_chart->setLabelX("Partidas");
    line_chart->setLabelY("Valores");
    line_chart->setTitle("Gráfico");
    line_chart->setLegend("Legenda");
    line_chart->setMinimumSize(600,400);
    \
    real_time = new LineChart();
    real_time->setWindowTitle("RealTime - FlappyBird");
    real_time->setLabelX("Posição X");
    real_time->setLabelY("Valores");
    real_time->setTitle("Gráfico");
    real_time->setLegend("Legenda");
    real_time->setMinimumSize(600,400);
    \


    legendValues.push_back("Scores");
    legendValues.push_back(QString::fromUtf8("Altura canos - Média"));
    line_chart->setLegendValues(legendValues);
    line_chart->addLegendColor(QColor(0xCC6633));
    line_chart->addLegendColor(QColor(0x3366CC));

    y_values.push_back("0");
    y_values.push_back("10");
    y_values.push_back("20");
    y_values.push_back("30");
    y_values.push_back("40");
    y_values.push_back("50");
    y_values.push_back("60");
    y_values.push_back("70");
    y_values.push_back("80");
    y_values.push_back("90");
    y_values.push_back("100");

    x_values.push_back("1");
    x_values.push_back("2");
}
void Animation::_gravity(){
    if(game->getStart()){

    }
}
void Animation::_update(){
    qint64 now = QDateTime::currentMSecsSinceEpoch();


    {

        qint64 passed = now - _last_time_60fps;
        _accumulator60 += passed;
        while (_accumulator60 >= _constant_dt)
        {
            _accumulator60 -= _constant_dt;
        }


        if(!game->getGodMode()){
            if(this->game->bird->groundColider()){
                //sound->soundWing();
                //sound->soundDie();
                //this->pause(false);
                _pause = false;
                // this->pause();
                game->setEndGame(true);

            }
            if(this->game->wall->wallColider(this->game->bird->getY())){
                if(!game->getEndGame()){
                   // sound->soundHit();
                }
                //_pause = true;
                //this->pause();
                game->setEndGame(true);
            }
        }
        if(this->game->wall->point(this->game->bird->getY())){
            this->game->player->setScore(this->game->player->getScore()+1);
            //sound->soundPoint();
        }
        this->game->draw();

        _last_time_60fps = now;
    }

    if(game->getStart() && (!game->bird->getGround())){
        this->game->wall->passWall();
        if(_counter%12 == 1){  //60x/5 = 12  1000/5 = 200ms
            this->game->bird->gravity();
        }
        if(_counter == 59){
            game->ground->setMeters(game->ground->getMeters()+1);
        }
    }
    if(!game->getEndGame()){
    }

    //if(_counter%2 == 0){
    if(_jump){
        //salto += (10 + aceleration);
        //aceleration--;
        salto +=1;
        valorSubida += salto;

        this->game->bird->setY(this->game->bird->getY() - salto);
        this->game->bird->setAceleration(-1);

        if(valorSubida >= 60){
            this->game->bird->setAceleration(0);
            salto = 0;
            valorSubida = 0;
            _jump= false;
        }
    }
    //}

    _counter++;
    _counter = _counter % 60; // Ranges from 0 to 59

    // Reset the timer
    //QTimer::singleShot(1000/_max_fps, this, SLOT(_update()));
}

void Animation::reset(){
    _counter = 0;
    _accumulator60 = 0;
    _max_fps = 60;
    _constant_dt = 1000 / _max_fps;
    _last_time_60fps = QDateTime::currentMSecsSinceEpoch();
    _pause = false;
    //sound->soundStarRoad(true);

    if(game->getPartida() >2){
        x_values.push_back(QString::number(game->getPartida()));
    }
    if(this->game->getPartida() >0){
        graficScore.push_back(QPoint(this->game->getPartida(),this->game->player->getScore()));
        graficWalls.push_back(QPoint(this->game->getPartida(),(this->game->wall->getMediaAltura()/this->game->wall->getQntWalls())/4));
    }
}

void Animation::godmode(){
    if(game->_godmode){
        game->setGodMode(false);
       // sound->soundInvincibility(false);
    }else{
        if(!game->_endgame){
            game->setGodMode(true);
          //  sound->soundInvincibility(true);
        }
    }
}

void Animation::grafic(){
    if(_grafic){
        line_chart->hide();
        _grafic = false;
    }else{
        //graficWalls.push_back(QPoint(this->game->getPartida(), this->game->wall->getMediaAltura()/this->game->wall->getQntWalls()));
        line_chart->addSeries(graficWalls, QColor(0x3366CC));
        line_chart->addSeries(graficScore, QColor(0xCC6633));
        line_chart->setAxisX(x_values);
        line_chart->setAxisY(y_values);
        line_chart->show();
        _grafic = true;
    }
}
void Animation::pause(){
    if(_pause){
        //this->tgravity->start();
        this->tanimation->start();
        _pause = false;
        //_start = true;
    }else{
        //this->tgravity->stop();
        this->tanimation->stop();
        _pause = true;
        //_start = false;
    }
}
void Animation::keyPressEvent(QKeyEvent * event){
    switch (event->key()) {
    case Qt::Key_Space:{

        if(!game->getStart()){
            /*tgravity = new QTimer(this);
                tgravity->start(200);
                QObject::connect(tgravity, SIGNAL(timeout()),this, SLOT(_gravity()));*/
            //sound->soundStarRoad(falcse);
            game->setStart(true);
        }
        if(!this->game->getEndGame()  && !_pause){

            //this->game->bird->jumpBird();
            jumpBird();
            //sound->soundSwooshing();

        }
        break;
    }
    case Qt::Key_P:{
        pause();
        break;
    }
    case Qt::Key_R:{
        reset();
        game->reset();
        break;
    }
    case Qt::Key_G:{
        godmode();
        break;
    }
    case Qt::Key_L:{
        grafic();
        break;
    }
    case Qt::Key_Escape:{
        game->~Game();
        std::cout << "Bye bye\n";
        exit(0);
        break;
    }
    case Qt::Key_F1:{
        QMessageBox::information(this, tr("Help - Flappy Bird"),trUtf8("Instruções\n\nP = Pause\nR = Reiniciar\nEspaço/Clique = Pular\nESC = Sair\nG = ???\nL = LineChart"));
        break;
    }
    default:{
        QWidget::keyPressEvent(event);
    }
    }
}
void Animation::jumpBird(){
    _jump = true;

}
void Animation::mousePressEvent(QMouseEvent * event){


    if(!game->getStart()){
        /*tgravity = new QTimer(this);
            tgravity->start(200);
            QObject::connect(tgravity, SIGNAL(timeout()),this, SLOT(_gravity()));*/
        //sound->soundStarRoad(false);
        game->setStart(true);
    }
    if(!this->game->getEndGame() && !_pause){
        //this->game->bird->jumpBird();
        jumpBird();
        //QSound bell(":/sounds/die.mp3");
        //sound->soundSwooshing();
    }
    //std::cout << "X: "<< event->pos().x() << "\n" <<endl;
    //std::cout << "Y: "<< event->pos().y() <<endl;


}
void Animation::mouseReleaseEvent(QMouseEvent * event){
}

void Animation::mouseMoveEvent(QMouseEvent * event){
    if(event->FocusOut){
        pause();
    }
    if(event->FocusIn){

    }
}
