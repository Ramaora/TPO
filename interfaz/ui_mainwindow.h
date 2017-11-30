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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LABELCANCION;
    QComboBox *comboBox_puertos;
    QComboBox *listacanciones;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_conectar;
    QPushButton *pushButton_refrescar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdNumberM;
    QLCDNumber *lcdNumberS;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(300, 400);
        MainWindow->setMinimumSize(QSize(300, 400));
        MainWindow->setStyleSheet(QLatin1String("\n"
"background-color: rgb(79, 79, 79);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        LABELCANCION = new QLabel(centralWidget);
        LABELCANCION->setObjectName(QStringLiteral("LABELCANCION"));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LABELCANCION->setFont(font);
        LABELCANCION->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(LABELCANCION);

        comboBox_puertos = new QComboBox(centralWidget);
        comboBox_puertos->setObjectName(QStringLiteral("comboBox_puertos"));
        comboBox_puertos->setMaximumSize(QSize(69, 20));

        horizontalLayout_3->addWidget(comboBox_puertos);


        verticalLayout_2->addLayout(horizontalLayout_3);

        listacanciones = new QComboBox(centralWidget);
        listacanciones->setObjectName(QStringLiteral("listacanciones"));
        listacanciones->setMinimumSize(QSize(280, 21));
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

        verticalLayout_2->addWidget(listacanciones);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(241, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("sprites/Logo.jpg")));
        label->setScaledContents(true);

        verticalLayout_3->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_conectar = new QPushButton(centralWidget);
        pushButton_conectar->setObjectName(QStringLiteral("pushButton_conectar"));

        verticalLayout->addWidget(pushButton_conectar);

        pushButton_refrescar = new QPushButton(centralWidget);
        pushButton_refrescar->setObjectName(QStringLiteral("pushButton_refrescar"));

        verticalLayout->addWidget(pushButton_refrescar);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdNumberM = new QLCDNumber(centralWidget);
        lcdNumberM->setObjectName(QStringLiteral("lcdNumberM"));
        lcdNumberM->setMinimumSize(QSize(40, 51));

        horizontalLayout->addWidget(lcdNumberM);

        lcdNumberS = new QLCDNumber(centralWidget);
        lcdNumberS->setObjectName(QStringLiteral("lcdNumberS"));
        lcdNumberS->setMinimumSize(QSize(40, 51));

        horizontalLayout->addWidget(lcdNumberS);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(61, 51));
        pushButton_2->setMaximumSize(QSize(97, 71));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton_2->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(61, 51));
        pushButton->setMaximumSize(QSize(97, 71));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(61, 51));
        pushButton_3->setMaximumSize(QSize(97, 71));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(79, 79, 79);"));
        pushButton_3->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

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
