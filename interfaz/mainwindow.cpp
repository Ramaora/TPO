#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QByteArray>
#include <QtSerialPort>
QSerialPort* puerto;
int m_datos_recibidos=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    puerto=new QSerialPort("COM3");

    puerto->setBaudRate(QSerialPort::Baud9600);
    puerto->setDataBits(QSerialPort::DataBits::Data8);
    puerto->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    puerto->setStopBits(QSerialPort::StopBits::OneStop);
    puerto->setParity(QSerialPort::Parity::NoParity);

    if (puerto->open(QIODevice::ReadWrite)){
        ui->LABELCANCION->setText("RICHARD");}else
        {ui->LABELCANCION->setText ("ERROR");}


    EnumerarPuertos();
    connect(puerto, SIGNAL(readyRead()),this,SLOT(onDatosRecibidos()));

    QPixmap pix("C:/Users/Rama/Documents/interfaz/sprites/Logo.jpg");
    ui->logo->setPixmap(pix);

    QPixmap pixmap("C:/Users/Rama/Documents/interfaz/sprites/play.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::EnumerarPuertos()
{
    ui->comboBox_puertos->clear();

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (int i = 0; i < ports.size(); i++)
        ui->comboBox_puertos->addItem(ports.at(i).portName(), ports.at(i).portName());
}

void MainWindow::on_pushButton_clicked()
{
    static bool i=true;
    if (i){
        QPixmap pixmap("C:/Users/Rama/Documents/interfaz/sprites/pause.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }else {
        QPixmap pixmap("C:/Users/Rama/Documents/interfaz/sprites/play.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }
        i=(!i);
}

void MainWindow::onDatosRecibidos(){
    QByteArray bytes;
    int cant =puerto->bytesAvailable();
    bytes.resize(cant);
    puerto->read(bytes.data(),bytes.size());
    m_datos_recibidos+=bytes.size();
    maqestado(bytes);


}

void MainWindow::maqestado(QByteArray data){
    if (data.contains("%ARRANCAR$")){
       ui->LABELCANCION->setText("ARRANCAR");
       return;
    }
    if (data.contains("%SIGUIENTE$")){
       ui->LABELCANCION->setText("SIGUIENTE");
       return;
    }
    if (data.contains("%ANTERIOR$")){
       ui->LABELCANCION->setText("ANTERIOR");
       return;
    }
    if (data.contains("%PAUSE")){
       ui->LABELCANCION->setText("ANTERIOR");
       return;
    }


    }



