#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define SEP_VALUE ','


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
    void llenarComboboxTemas(QByteArray);




private slots:
    void on_pushButton_clicked();
    void onDatosRecibidos();
    void maqestado(const QByteArray);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_listacanciones_currentIndexChanged(int index);

    void on_pushButton_refrescar_clicked();

    void on_pushButton_conectar_clicked();
    void bajarflag();

private:
    Ui::MainWindow *ui;
    bool tengoCanciones=false;
};

#endif // MAINWINDOW_H
