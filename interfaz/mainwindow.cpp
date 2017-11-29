#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QByteArray>
#include <QtSerialPort>
#include <QByteArrayList>
QSerialPort* puerto;
bool flagcambiar=true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EnumerarPuertos();

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
        if(ui->LABELCANCION->text()=="CONECTADO"){
        puerto->write("apj");
}
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
    QByteArray aux;
    int aux2;

    if (data.contains("%ARRANCAR$")){
       ui->pushButton->setIcon(ButtonIcon1);

       return;
    }
    if (data.contains("%SIGUIENTE$")){
       return;
    }
    if (data.contains("%ANTERIOR$")){
       return;
    }
    if (data.contains("%PAUSAR$")){
       ui->pushButton->setIcon(ButtonIcon2);
       return;
    }
    if (data.contains("ack")){
        if(!this->tengoCanciones){
            puerto->write("aNj");
        }
        aux=data;
        aux.chop(1);
        aux.remove(0,4);
        char *p = aux.data();
        aux2=p[0];
        //ui->listacanciones->setDisabled(true);
        if((ui->listacanciones->currentIndex()!= aux2)){

            ui->listacanciones->setCurrentIndex(aux2);

         }
       // ui->listacanciones->setDisabled(false);
        return;
     }else{
       llenarComboboxTemas(data);
       tengoCanciones=true;
       return;
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(ui->LABELCANCION->text()=="CONECTADO"){
        puerto->write("aAj");
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->LABELCANCION->text()=="CONECTADO"){
        puerto->write("aSj");
    }

}




void MainWindow::on_listacanciones_currentIndexChanged(int index)
{
    QByteArray aux;
    if (flagcambiar){
        flagcambiar=false;
        QTimer::singleShot(200, this, SLOT(bajarflag()));
        aux.setNum(index);
        puerto->write("a"+aux+"j");
    }
}

void MainWindow::on_pushButton_refrescar_clicked()
{
    EnumerarPuertos();
}

void MainWindow::on_pushButton_conectar_clicked()
{
    static bool puertoabierto=false;
    if (!puertoabierto){
        puertoabierto=!puertoabierto;
        ui->pushButton_conectar->setText("DESCONECTAR");
    puerto=new QSerialPort(ui->comboBox_puertos->currentText());
    puerto->setBaudRate(QSerialPort::Baud9600);
    puerto->setDataBits(QSerialPort::DataBits::Data8);
    puerto->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    puerto->setStopBits(QSerialPort::StopBits::OneStop);
    puerto->setParity(QSerialPort::Parity::NoParity);


    if (puerto->open(QIODevice::ReadWrite)){
        ui->LABELCANCION->setText("CONECTADO");}else
        {ui->LABELCANCION->setText ("ERROR");}
    connect(puerto, SIGNAL(readyRead()),this,SLOT(onDatosRecibidos()));
    }else{
        puerto->close();
        ui->pushButton_conectar->setText("CONECTAR");
        ui->LABELCANCION->setText("DESCONECTADO");
        puertoabierto=false;
    }
}

void MainWindow::bajarflag(){
    flagcambiar=true;

}
