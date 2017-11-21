/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QLabel *LABELCANCION;
    QSplitter *splitter;
    QComboBox *comboBox_puertos;
    QComboBox *listacanciones;
    QSplitter *splitter_5;
    QLabel *label;
    QPushButton *pushButton_conectar;
    QPushButton *pushButton_refrescar;
    QLCDNumber *lcdNumber;
    QSplitter *splitter_4;
    QSplitter *splitter_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(347, 361);
        MainWindow->setMinimumSize(QSize(300, 100));
        MainWindow->setStyleSheet(QLatin1String("\n"
"background-color: rgb(79, 79, 79);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        LABELCANCION = new QLabel(splitter_3);
        LABELCANCION->setObjectName(QStringLiteral("LABELCANCION"));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LABELCANCION->setFont(font);
        LABELCANCION->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_3->addWidget(LABELCANCION);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        comboBox_puertos = new QComboBox(splitter);
        comboBox_puertos->setObjectName(QStringLiteral("comboBox_puertos"));
        comboBox_puertos->setMaximumSize(QSize(69, 20));
        splitter->addWidget(comboBox_puertos);
        splitter_3->addWidget(splitter);

        verticalLayout->addWidget(splitter_3);

        listacanciones = new QComboBox(centralWidget);
        listacanciones->setObjectName(QStringLiteral("listacanciones"));
        listacanciones->setMinimumSize(QSize(301, 21));
        QPalette palette;
        QBrush brush(QColor(79, 79, 79, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        listacanciones->setPalette(palette);

        verticalLayout->addWidget(listacanciones);

        splitter_5 = new QSplitter(centralWidget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter_5);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(241, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("sprites/Logo.jpg")));
        label->setScaledContents(true);
        splitter_5->addWidget(label);

        verticalLayout->addWidget(splitter_5);

        pushButton_conectar = new QPushButton(centralWidget);
        pushButton_conectar->setObjectName(QStringLiteral("pushButton_conectar"));

        verticalLayout->addWidget(pushButton_conectar);

        pushButton_refrescar = new QPushButton(centralWidget);
        pushButton_refrescar->setObjectName(QStringLiteral("pushButton_refrescar"));

        verticalLayout->addWidget(pushButton_refrescar);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(281, 51));

        verticalLayout->addWidget(lcdNumber);

        splitter_4 = new QSplitter(centralWidget);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(61, 51));
        pushButton_2->setMaximumSize(QSize(97, 71));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton_2->setIconSize(QSize(40, 40));
        splitter_2->addWidget(pushButton_2);
        pushButton = new QPushButton(splitter_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(61, 51));
        pushButton->setMaximumSize(QSize(97, 71));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton->setIconSize(QSize(50, 50));
        splitter_2->addWidget(pushButton);
        pushButton_3 = new QPushButton(splitter_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(61, 51));
        pushButton_3->setMaximumSize(QSize(97, 71));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton_3->setIconSize(QSize(40, 40));
        splitter_2->addWidget(pushButton_3);
        splitter_4->addWidget(splitter_2);

        verticalLayout->addWidget(splitter_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "REPRODUCTOR WAV", Q_NULLPTR));
        LABELCANCION->setText(QApplication::translate("MainWindow", "<html><head/><body><p>SIN CONEXION</p></body></html>", Q_NULLPTR));
        label->setText(QString());
        pushButton_conectar->setText(QApplication::translate("MainWindow", "CONECTAR SERIE", Q_NULLPTR));
        pushButton_refrescar->setText(QApplication::translate("MainWindow", "REFRESCAR", Q_NULLPTR));
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
