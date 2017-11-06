#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void EnumerarPuertos(void);
    void separarNombres(const QByteArray);




private slots:
    void on_pushButton_clicked();
    void onDatosRecibidos();
    void maqestado(const QByteArray);

private:  
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
