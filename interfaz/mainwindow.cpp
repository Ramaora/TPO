#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
