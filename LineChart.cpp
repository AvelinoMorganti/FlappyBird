#include "LineChart.h"
using namespace std;

LineChart::~LineChart(){

    QRect ct = geometry();
    ct.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(ct);
};

LineChart::LineChart(){
    // setLabelX("Label X");
    //setLabelY("Label Y");
    setTitle("Title");
    setMinimumSize(500,400);
    //Enables
    setAjust(false);
    enableLabelX(true);
    enableLabelY(true);
    enableTitle(true);
    enableNumbersX(true);
    enableNumbersY(true);
    enableGrafic(true);
    enableGridX(true);
    enableGridY(true);
    enableLegend(true);
    //setAjust(true);
    //Fonts
    setFontNumbers("Verdana",12,true);
    setFontLabels("Arial",18,true);
    setFontLegend("Arial",10,true);
    //Colors
    setLabelXColor(QColor("#000"));
    setLabelYColor(QColor("#000"));
    setTitleColor(QColor("#000"));
    setNumbersXColor(QColor("#0F0"));
    setNumbersYColor(QColor("#0F0"));
    setGridXColor(QColor("#00F"));
    setGridYColor(QColor("#00F"));
};
void LineChart::addSeries(QVector<QPoint>points, QColor color){
    this->grafics.append(points);
    this->colors.append(color);
}
void LineChart::setAxisX(QVector<QString> x_values){
    this->xValues=x_values;
}
void LineChart::setAxisY(QVector<QString> y_values){
    this->yValues=y_values;
}
void LineChart::setLabelX(QString label_x){
    this->labelX = label_x;
}
void LineChart::setLabelY(QString label_y){
    this->labelY= label_y;
}
void LineChart::setTitle(const char * Title){
    this->Title = QString::fromUtf8(Title);
}
void LineChart::setLegend(const char * Legend){
    this->Legend = QString::fromUtf8(Legend);
}
void LineChart::setLegendValues(QVector<QString> legendValues){
    this->legendValues = legendValues;
}
void LineChart::addLegendColor(QColor color){
    this->legendColor.append(color);
}
QVector<QString> LineChart::getAxisX(){
    return this->xValues;
}
QVector<QString> LineChart::getAxisY(){
    return this->yValues;
}
QString LineChart::getLabelX(){
    return this->labelX;
}
QString LineChart::getLabelY(){
    return this->labelY;
}
QString LineChart::getTitle(){
    return this->Title;
}
QVector<QString> LineChart::getLegend(){
    return this->legendValues;
}
void LineChart::setAjust(bool bAjust){
    this->bAjust = bAjust;
}
void LineChart::enableLabelX(bool b_label_x){
    this->bLabelX = b_label_x;
}
void LineChart::enableLabelY(bool b_label_y){
    this->bLabelY = b_label_y;
}
void LineChart::enableTitle(bool b_label_title){
    this->bTitle = b_label_title;
}
void LineChart::enableNumbersX(bool b_numbers_x){
    this->bNumbersX = b_numbers_x;
}
void LineChart::enableNumbersY(bool b_numbers_y){
    this->bNumbersY = b_numbers_y;
}
void LineChart::enableGrafic(bool b_grafic){
    this->bGrafic = b_grafic;
}
void LineChart::enableGridX(bool b_grid_x){
    this->bGridX = b_grid_x;
}
void LineChart::enableGridY(bool b_grid_y){
    this->bGridY = b_grid_y;
}
void LineChart::enableLegend(bool bLegend){
    this->bLegend = bLegend;
}
void LineChart::setFontNumbers(QString fonte, int tamanho, bool negrito){
    this->fNumbers = QFont(fonte,tamanho,negrito);
}
void LineChart::setFontNumbers(QFont fNumbers){
    this->fNumbers = fNumbers;
}
void LineChart::setFontLabels(QString fonte, int tamanho, bool negrito){
    this->fLabels = QFont(fonte,tamanho,negrito);
}
void LineChart::setFontLabels(QFont fLabels){
    this->fLabels = fLabels;
}
void LineChart::setFontLegend(QString fonte, int tamanho, bool negrito){
    this->fLegend = QFont(fonte,tamanho,negrito);
}
void LineChart::setFontLegend(QFont fLegend){
    this->fLegend = fLegend;
}
void LineChart::setLabelXColor(QColor labelXColor){
    this->labelXColor = labelXColor;
}
void LineChart::setLabelYColor(QColor labelYColor){
    this->labelYColor = labelYColor;
}
void LineChart::setTitleColor(QColor titleColor){
    this->titleColor = titleColor;
}
void LineChart::setNumbersXColor(QColor numbersXColor){
    this->numbersXColor = numbersXColor;
}
void LineChart::setNumbersYColor(QColor numbersYColor){
    this->numbersYColor = numbersYColor;
}
void LineChart::setGraficColor(QColor graficColor){
    this->graficColor = graficColor;
}
void LineChart::setGridXColor(QColor gridXColor){
    this->gridXColor = gridXColor;
}
void LineChart::setGridYColor(QColor gridYColor){
    this->gridYColor = gridYColor;
}
void LineChart::drawRotatedText(QPainter *painter, float degrees, int x, int y, const QString &text){
    painter->save();
    painter->translate(x, y);
    painter->rotate(degrees);
    painter->drawText(0, 0, text);
    painter->restore();
}
void LineChart::paintEvent(QPaintEvent *event){
    QPainter p(this);
    QPen caneta;


    p.fillRect(0,0,width(),height(),Qt::white);
    p.setFont(fLabels);
    if(bTitle){
        p.setPen(titleColor);

        p.drawText((width()/2 - (getTitle().size() * 5)),40, getTitle());
    }
    if(bLabelX){
        p.setPen(labelXColor);
        p.drawText((width()/2 - (getLabelX().size() * 5)),height()-20,getLabelX());
    }
    if(bLabelY){
        p.setPen(labelYColor);
        drawRotatedText(&p, 270, 50, height() / 2, getLabelY());
    }

    if(bLegend){
        p.setFont(fLegend);
        for(int i=0; i<legendValues.size();i++){
            p.fillRect(width()-200,(i+1)*20,5,5, legendColor.at(i));
            p.drawText(width()-190,((i+1)*20+5), legendValues.at(i));
        }
    }

    p.setFont(fNumbers);
    for(int i=yValues.size();i>=0;i--){
        caneta.setWidth(1);
        caneta.setColor(numbersYColor);
        p.setPen(caneta);

        QString a = yValues.value(i);
        int espacamento_y = (height()-150) / (yValues.size()-1);
        int posicao = (-i * espacamento_y) + height()-100;
        if(bNumbersY){
            p.drawText(60,posicao,a);
        }
        if(i>0 && bGridY){
            caneta.setColor(gridYColor);
            caneta.setStyle(Qt::DashLine);
            p.setPen(caneta);
            p.drawLine(100,posicao + espacamento_y,width()-50, posicao+espacamento_y);
        }
    }
    for(int i=xValues.size();i>=0;i--){
        caneta.setWidth(1);
        caneta.setColor(numbersXColor);
        p.setPen(caneta);

        QString a = xValues.value(i);
        int espacamento_x = (width()-150) / (xValues.size()-1);
        int posicao = (i * espacamento_x) +100;
        if(bNumbersX){
            p.drawText(posicao,height()-50,a);
        }
        if(i>0 && bGridX){
            caneta.setColor(gridXColor);
            caneta.setStyle(Qt::DashLine);
            p.setPen(caneta);
            p.drawLine(posicao-espacamento_x,50,posicao-espacamento_x,height()-100);
        }
    }

    QVector<QVector<QPoint> > graficTemp = this->grafics;
    QVector<QPoint> grafic;

    for(int i=0;i<graficTemp.size();i++){
        grafic = resize(graficTemp.value(i));
        p.save();
        p.translate(100,height()-100);
        if(bGrafic){
            caneta.setColor(this->colors.at(i));
            caneta.setWidth(2.5);
            caneta.setStyle(Qt::SolidLine);
            p.setPen(caneta);
            p.drawPolyline(grafic);
        }
        for(int i=0;i<grafic.size();i++){
            QPoint ponto = grafic.at(i);
            caneta.setColor(QColor("#000"));
            p.setPen(caneta);
            p.drawPoint(ponto.x(),ponto.y());
            p.drawEllipse(ponto.x(),ponto.y(),3,3);
        }
        p.restore();
    }
}
QVector<QPoint> LineChart::resize(QVector<QPoint> vector){
    for(int i=0;i<vector.size();i++){
        QVector<QPoint> temp = vector;
        int tamanhoFrameY = (height()-150);
        int tamanhoFrameX = (width()-150);
        int taxaAjusteY;
        int taxaAjusteX;
        if(bAjust){
            taxaAjusteY = tamanhoFrameY/(yValues.size()-1);
            if(this->yValues.at(0).toInt() != 0){
                vector[i].setY(((temp[i].y()) * - (taxaAjusteY/(yValues.size()+1))) + (taxaAjusteY));
            }else{
                vector[i].setY(((temp[i].y()) * - (taxaAjusteY/(yValues.size()+1))));
            }
            taxaAjusteX = tamanhoFrameX/(this->xValues.at(xValues.size()-1).toInt() - this->xValues.at(0).toInt());
            vector[i].setX(((temp[i].x()) * (taxaAjusteX)) - (this->xValues.at(0).toInt() * taxaAjusteX));

          }else{
            taxaAjusteY = tamanhoFrameY/(yValues.size()-1);
            if(this->yValues.at(0).toInt() != 0){
                vector[i].setY(((temp[i].y()) * - taxaAjusteY/yValues.at(0).toInt()) - taxaAjusteY/yValues.size()-1);
            }
            taxaAjusteX = tamanhoFrameX/(this->xValues.at(xValues.size()-1).toInt() - this->xValues.at(0).toInt());
            vector[i].setX(((temp[i].x()) * (taxaAjusteX)) - (this->xValues.at(0).toInt() * taxaAjusteX));



        }
    }
    return vector;
}
