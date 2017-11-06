#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QByteArray>
#include <QtSerialPort>
#include <QByteArrayList>
QSerialPort* puerto;

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

    QPixmap pix("sprites/Logo.jpg");
    ui->logo->setPixmap(pix);

    QPixmap pixmap("sprites/play.png");
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
        QPixmap pixmap("sprites/pause.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }else {
        QPixmap pixmap("sprites/play.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }
        i=(!i);
}

void MainWindow::onDatosRecibidos(){
    QByteArray bytes;
    QByteArray static word;
    int cant =puerto->bytesAvailable();
    bytes.resize(cant);
    puerto->read(bytes.data(),bytes.size());
    word.append(bytes);
    if(word.startsWith("%")&&word.endsWith("$")){
        maqestado(word);
        word.clear();
        word.resize(0);
    }
}
void MainWindow::llenarComboboxTemas(QByteArray nombres){
    nombres.remove(0,1);
    nombres.chop(1);
    QByteArrayList lista;
    lista = nombres.split(SEP_VALUE);
    while(!lista.isEmpty()){
        ui->listacanciones->addItem(lista.first());
        lista.removeFirst();
    }return;

}
void MainWindow::maqestado(const QByteArray data){
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
    if (data.contains("%PAUSAR$")){
       ui->LABELCANCION->setText("PAUSA");
       return;
    }else{
       llenarComboboxTemas(data);
       return;
    }
}



