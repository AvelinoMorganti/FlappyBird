/*
#include <QApplication>
#include <QMainWindow>
#include "LineChart.h"

void teste1()
{

    // Joaçaba: Temp. Máxima
    QVector<QPoint> points;
    points.push_back(QPoint(1, 29));
    points.push_back(QPoint(2, 28));
    points.push_back(QPoint(3, 28));
    points.push_back(QPoint(4, 23));
    points.push_back(QPoint(5, 22));
    points.push_back(QPoint(6, 21));
    points.push_back(QPoint(7, 19));
    points.push_back(QPoint(8, 20));
    points.push_back(QPoint(9, 22));
    points.push_back(QPoint(10, 23));
    points.push_back(QPoint(11, 27));
    points.push_back(QPoint(12, 25));

    // Joaçaba: Temp. Mínima
    QVector<QPoint> points2;
    points2.push_back(QPoint(1, 16));
    points2.push_back(QPoint(2, 16));
    points2.push_back(QPoint(3, 16));
    points2.push_back(QPoint(4, 13));
    points2.push_back(QPoint(5, 10));
    points2.push_back(QPoint(6, 10));
    points2.push_back(QPoint(7, 9));
    points2.push_back(QPoint(8, 9));
    points2.push_back(QPoint(9, 11));
    points2.push_back(QPoint(10, 13));
    points2.push_back(QPoint(11, 15));
    points2.push_back(QPoint(12, 16));

    QVector<QString> x_values;
    x_values.push_back("1");
    x_values.push_back("2");
    x_values.push_back("3");
    x_values.push_back("4");
    x_values.push_back("5");
    x_values.push_back("6");
    x_values.push_back("7");
    x_values.push_back("8");
    x_values.push_back("9");
    x_values.push_back("10");
    x_values.push_back("11");
    x_values.push_back("12");

    QVector<QString> y_values;
    y_values.push_back("5");
    y_values.push_back("9");
    y_values.push_back("13");
    y_values.push_back("17");
    y_values.push_back("21");
    y_values.push_back("25");
    y_values.push_back("29");

    LineChart* line_chart = new LineChart();
    line_chart->addSeries(points, QColor(0xCC3333));
    line_chart->addSeries(points2, QColor(0x3366CC));

    line_chart->setAxisX(x_values);
    line_chart->setAxisY(y_values);
    line_chart->setLabelX("Meses do Ano");
    line_chart->setLabelY("Temperatura (C)");
    line_chart->setTitle("Histórico da Temperatura: Joaçaba (Min/Max)");

    QMainWindow* window = new QMainWindow();
    window->setWindowTitle("LineChart Demo");
    window->setCentralWidget(line_chart);
    window->resize(600, 450);
    window->show();
}

void teste2()
{
    // Internet Explorer
    QVector<QPoint> points;
    points.push_back(QPoint(2006, 82));
    points.push_back(QPoint(2007, 80));
    points.push_back(QPoint(2008, 75));
    points.push_back(QPoint(2009, 67));
    points.push_back(QPoint(2010, 56));
    points.push_back(QPoint(2011, 44));

    // Taxa de Assassinato
    QVector<QPoint> points2;
    points2.push_back(QPoint(2006, 75));
    points2.push_back(QPoint(2007, 73));
    points2.push_back(QPoint(2008, 68));
    points2.push_back(QPoint(2009, 51));
    points2.push_back(QPoint(2010, 43));
    points2.push_back(QPoint(2011, 39));

    QVector<QString> x_values;
    x_values.push_back("2006");
    x_values.push_back("2007");
    x_values.push_back("2008");
    x_values.push_back("2009");
    x_values.push_back("2010");
    x_values.push_back("2011");

    QVector<QString> y_values;
    y_values.push_back("30");
    y_values.push_back("45");
    y_values.push_back("60");
    y_values.push_back("75");
    y_values.push_back("90");

    LineChart* line_chart = new LineChart();
    line_chart->addSeries(points, QColor(0x3300CC));
    line_chart->addSeries(points2, QColor(0x00CC33));

    line_chart->setAxisX(x_values);
    line_chart->setAxisY(y_values);
    line_chart->setLabelY("Fatia de Mercado (%)");
    line_chart->setTitle("Internet Explorer vs Taxa de Assassinato nos EUA");


    QMainWindow* window = new QMainWindow();
    window->setWindowTitle("LineChart Demo");
    window->setCentralWidget(line_chart);
    window->resize(600, 450);
    window->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    teste1();
    teste2();

    return a.exec();
}
*/
