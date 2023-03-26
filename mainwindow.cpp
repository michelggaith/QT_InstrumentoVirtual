#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <string>
#include <QMessageBox>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

int aux;

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    //serialBuffer="";

    QObject::connect(serial, SIGNAL(readyRead()),this, SLOT(serialReceived()));


}

MainWindow::~MainWindow()
{

    delete ui;
    serial->close();
}

//FUNCION PRINCIPAL
void MainWindow::serialReceived(){



datoleido = serial->readAll();
//qDebug()<<datoleido;

QStringList lst=datoleido.split(",");

if((lst.size())>=10){
    value =lst[0].toInt();
    value2=lst[1].toInt();
    value3=lst[2].toInt();
    value4=lst[3].toInt();
    value5=lst[4].toInt();
    value6=lst[5].toInt();
    value7=lst[6].toInt();
    value8=lst[7].toInt();
    value9=lst[8].toInt();
    value10=lst[9].toInt();
    value11=lst[10].toInt();
    aux=value;

}else{
              qDebug()<<lst.size();
}

//ENCENDER ADC
if(ADC1==1){
    ui->lcdNumber->display(value*3300/4096);
} else{ ui->lcdNumber->display("0");}

if(ADC2==1){
    ui->lcdNumber_2->display(value2*3300/4096);
} else{ ui->lcdNumber_2->display("0");}
if(ADC3==1){
    ui->lcdNumber_3->display(value3*3300/4096);
} else{ ui->lcdNumber_3->display("0");}

QObject().thread()->usleep(1000*1000*1);

}

//REALIZAR CONEXION SERIAL//
void MainWindow::on_pushButton_clicked()
{
    if(serial->open(QIODevice::ReadWrite))
    {
        ui ->label ->clear();
        ui ->label ->setText("Conexión exitosa");
    }
    else
    {
        ui ->label ->clear();
        ui ->label ->setText("Conexión fallida");
    }
    serial ->setPortName("com3");
    serial -> setBaudRate(QSerialPort::Baud115200);
    serial -> setDataBits(QSerialPort::Data8);
    serial -> setParity(QSerialPort::NoParity);
    serial -> setStopBits(QSerialPort::OneStop);
    serial -> setFlowControl(QSerialPort::NoFlowControl);

}



//LEER ESTADO DE LAS ENTRADAS (FUNCIONA CORRECTAMENTE)
void MainWindow::on_pushButton_5_clicked()
{
    lectura=1;
    ui->lcdNumber_13->display(value4);
    ui->lcdNumber_14->display(value5);
    ui->lcdNumber_16->display(value6);
    ui->lcdNumber_12->display(value7);
    ui->lcdNumber_18->display(value8);
    ui->lcdNumber_15->display(value9);
    ui->lcdNumber_17->display(value10);
    ui->lcdNumber_19->display(value11);
}



//FUNCIONES PARA ENVIAR ESTADO A LAS ENTRADAS


void MainWindow::on_Send1_clicked()
{   if(ui->LcdOut1->value()==0.0){
        ui->LcdOut1->display(1);
        Out[0]=1;
    }
    else{Out[0]=0;
    ui->LcdOut1->display(0);
    }
}


void MainWindow::on_Send2_clicked()
{  if(ui->LcdOut2->value()==0.0){
        ui->LcdOut2->display(1);
        Out[1]=1;
    }
    else{Out[1]=0;
    ui->LcdOut2->display(0);
    }
}


void MainWindow::on_Send3_clicked()
{  if(ui->LcdOut3->value()==0.0){
        ui->LcdOut3->display(1);
        Out[2]=1;
    }
    else{Out[2]=0;
    ui->LcdOut3->display(0);
    }

}


void MainWindow::on_Send4_clicked()
{  if(ui->LcdOut4->value()==0.0){
        ui->LcdOut4->display(1);
        Out[3]=1;
    }
    else{Out[3]=0;
    ui->LcdOut4->display(0);
    }
}


void MainWindow::on_Send5_clicked()
{  if(ui->LcdOut5->value()==0.0){
        ui->LcdOut5->display(1);
        Out[4]=1;
    }
    else{Out[4]=0;
    ui->LcdOut5->display(0);
    }
}


void MainWindow::on_Send6_clicked()
{  if(ui->LcdOut6->value()==0.0){
        ui->LcdOut6->display(1);
        Out[5]=1;
    }
    else{Out[5]=0;
    ui->LcdOut6->display(0);
    }
}


void MainWindow::on_Send7_clicked()
{  if(ui->LcdOut7->value()==0.0){
        ui->LcdOut7->display(1);
        Out[6]=1;
    }
    else{Out[6]=0;
    ui->LcdOut7->display(0);
    }
}


void MainWindow::on_Send8_clicked()
{  if(ui->LcdOut8->value()==0.0){
        ui->LcdOut8->display(1);
        Out[7]=1;
    }
    else{Out[7]=0;
    ui->LcdOut8->display(0);
    }

}



//FUNCIONES DE DISPLAY DE ADC ( FUNCIONA CORRECTAMENTE )//


void MainWindow::on_Boton1_clicked()
{
    ADC1=1;
}


void MainWindow::on_Boton2_clicked()
{
    ADC1=0;
}


void MainWindow::on_Boton3_clicked()
{
    ADC2=1;
}


void MainWindow::on_Boton4_clicked()
{
    ADC2=0;
}


void MainWindow::on_Boton5_clicked()
{
    ADC3=1;
}


void MainWindow::on_Boton6_clicked()
{
    ADC3=0;
}

//FUNCION PARA ENVIAR

void MainWindow::on_pushButton_2_clicked()
{
    serial->clear();
    sprintf(Salida, "%lu%lu%lu%lu%lu%lu%lu%lu", Out[0],Out[1],Out[2],Out[3],Out[4],Out[5],Out[6],Out[7]);
    serial->write(Salida, 8);
    serial->waitForBytesWritten(1000);
    qDebug()<<Salida;
    memset(Salida, 0, 9);

}
