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

    QPixmap pixmap("sprites/play.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    QPixmap pixmap3("sprites/anterior.png");
    QIcon ButtonIcon3(pixmap3);
    ui->pushButton_2->setIcon(ButtonIcon3);
    QPixmap pixmap4("sprites/siguiente.png");
    QIcon ButtonIcon4(pixmap4);
    ui->pushButton_3->setIcon(ButtonIcon4);
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
        QPixmap pixmap("sprites/play.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }else {
        QPixmap pixmap("sprites/pause.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
    }
        i=(!i);
        puerto->write("apj");
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
    QPixmap pixmap1("sprites/pause.png");
    QIcon ButtonIcon1(pixmap1);
    QPixmap pixmap2("sprites/play.png");
    QIcon ButtonIcon2(pixmap2);

    if (data.contains("%ARRANCAR$")){
       ui->LABELCANCION->setText("ARRANCAR");
       ui->pushButton->setIcon(ButtonIcon1);

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
       ui->pushButton->setIcon(ButtonIcon2);
       return;
    }if (data.contains("%ack$")){
        if(!this->tengoCanciones){
            puerto->write("aNj");
        }else{
            puerto->write("aYj");
        }
        return;
     }else{
       llenarComboboxTemas(data);
       tengoCanciones=true;
       return;
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    puerto->write("aAj");
}

void MainWindow::on_pushButton_3_clicked()
{
    puerto->write("aSj");
}




void MainWindow::on_listacanciones_currentIndexChanged(int index)
{
    QByteArray aux;
    aux.setNum(index);
    puerto->write("a"+aux+"j");
}
