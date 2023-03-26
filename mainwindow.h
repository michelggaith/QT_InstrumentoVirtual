#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QDialog>
#include <QDebug>
#include <vector>
#include <string>
#include <iostream>

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

namespace Ui {
    class MainWindow;
}



class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


private slots:
    void serialReceived();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();


//ONOFF


    void on_Boton1_clicked();

    void on_Boton2_clicked();

    void on_Boton3_clicked();

    void on_Boton4_clicked();

    void on_Boton5_clicked();

    void on_Boton6_clicked();

    void on_Send1_clicked();

    void on_Send2_clicked();

    void on_Send3_clicked();

    void on_Send4_clicked();

    void on_Send5_clicked();

    void on_Send6_clicked();

    void on_Send7_clicked();

    void on_Send8_clicked();

    void on_pushButton_2_clicked();

private:


        QString datoleido;
        QString serialBuffer;
        int value ;
        int value2;
        int value3;
        int value4;
        int value5;
        int value6;
        int value7;
        int value8;
        int value9;
        int value10;
        int value11;
        int ADC1;
        int ADC2;
        int ADC3;
        int lectura;
        int Out[8]={0,0,0,0,0,0,0,0};
        char Salida[9];

        Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
