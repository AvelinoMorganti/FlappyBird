//Ok

//
//Adicionar legendas.
//
#ifndef LINECHART_H
#define LINECHART_H

#include "Includes.h"

class LineChart: public QMainWindow{
    Q_OBJECT
public:
    ~LineChart();
    LineChart();
    //Sets
    void addSeries(QVector<QPoint> points, QColor color);
    void addLegendColor(QColor color);
    //void setGraficos(QVector<LineChart> graficos);
    void setLegendValues(QVector<QString> legendValues);
    void setPoints(QVector<QPoint> points);
    void setColor(QColor color);
    void setAxisX(QVector<QString> xValues);
    void setAxisY(QVector<QString> yValues);
    void setLabelX(QString labelX);
    void setLabelY(QString labelY);
    //void setTitle(QString Title);
    void setTitle(const char *Title);
    void setLegend(const char *Legend);
    //Gets
    QVector<LineChart> getGraficos();
    QVector<QPoint> getPoints();
    QColor getColor();
    QVector<QString> getAxisX();
    QVector<QString> getAxisY();
    QVector<QString> getLegend();
    QString getLabelX();
    QString getLabelY();
    QString getTitle();
    //Enables
    void setAjust(bool bAjust);
    void enableLabelX(bool bLabelX);
    void enableLabelY(bool bLabelY);
    void enableTitle(bool bTitle);
    void enableNumbersX(bool bNumbersX);
    void enableNumbersY(bool bNumbersY);
    void enableGrafic(bool bGrafic);
    void enableGridX(bool bGridX);
    void enableGridY(bool bGridY);
    void enableLegend(bool bLegend);
    //Fonts
    void setFontNumbers(QString fonte, int tamanho, bool negrito);
    void setFontNumbers(QFont fNumbers);
    void setFontLabels(QString fonte, int tamanho, bool negrito);
    void setFontLabels(QFont fLabels);
    void setFontLegend(QString fonte, int tamanho, bool negrito);
    void setFontLegend(QFont fLegend);
    //Colors
    void setLabelXColor(QColor labelXColor);
    void setLabelYColor(QColor labelYColor);
    void setTitleColor(QColor titleColor);
    void setNumbersXColor(QColor numbersXColor);
    void setNumbersYColor(QColor numbersYColor);
    void setGraficColor(QColor graficColor);
    void setGridXColor(QColor gridXColor);
    void setGridYColor(QColor gridYColor);
    //Funções
    void drawRotatedText(QPainter *painter, float degrees, int x, int y, const QString &text);
    QVector<QPoint> resize(QVector<QPoint> vector);
    void paintEvent(QPaintEvent * event);

private:
    QVector<QVector<QPoint> > grafics;
    QVector<QColor> colors;
    QVector<QColor> legendColor;
    QColor labelXColor, labelYColor, titleColor, numbersXColor, numbersYColor, graficColor, gridXColor, gridYColor;
    bool bAjust, bLabelX, bLabelY, bTitle, bNumbersX, bNumbersY, bGrafic, bGridX, bGridY, bLegend;
    QVector<QString> xValues;
    QVector<QString> yValues;
    QVector<QString> legendValues;
    QString labelX,labelY, Title,Legend;
    QFont fNumbers,fLabels, fLegend;
};

#endif // LINECHART_H
