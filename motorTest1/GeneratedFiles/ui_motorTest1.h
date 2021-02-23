/********************************************************************************
** Form generated from reading UI file 'motorTest1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORTEST1_H
#define UI_MOTORTEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_motorTest1Class
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *btnOpenSerialPort;
    QComboBox *comBoxMotor1;
    QComboBox *comBoxMotor2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *cboxIsLink;
    QLabel *lblProtState;
    QComboBox *comBoxForce;
    QLabel *label_13;
    QGroupBox *groupBox_2;
    QSpinBox *spboxMotor1Position;
    QLabel *label_3;
    QPushButton *btnStartMotor1;
    QLabel *label_4;
    QSpinBox *spboxMotor1Vel;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btnGoZeroMotor1;
    QGroupBox *groupBox_3;
    QSpinBox *spboxMotor2Position;
    QLabel *label_7;
    QPushButton *btnStartMotor2;
    QLabel *label_8;
    QSpinBox *spboxMotor2Vel;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *btnGoZeroMotor2;
    QGroupBox *groupBox_4;
    QLabel *label_11;
    QPushButton *btnStartReadForce;
    QLabel *label_12;
    QLabel *lblForceVal;
    QPushButton *btnClearForce;
    QLabel *lblReadForceState;
    QGroupBox *groupBox_5;
    QPushButton *btnSetFilter;
    QSpinBox *spboxFilterStrength;
    QComboBox *comBoxFilterType;
    QLabel *label_16;
    QLabel *label_14;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *motorTest1Class)
    {
        if (motorTest1Class->objectName().isEmpty())
            motorTest1Class->setObjectName(QString::fromUtf8("motorTest1Class"));
        motorTest1Class->resize(838, 407);
        centralWidget = new QWidget(motorTest1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 391, 121));
        btnOpenSerialPort = new QPushButton(groupBox);
        btnOpenSerialPort->setObjectName(QString::fromUtf8("btnOpenSerialPort"));
        btnOpenSerialPort->setGeometry(QRect(290, 80, 75, 23));
        comBoxMotor1 = new QComboBox(groupBox);
        comBoxMotor1->setObjectName(QString::fromUtf8("comBoxMotor1"));
        comBoxMotor1->setGeometry(QRect(30, 20, 69, 22));
        comBoxMotor2 = new QComboBox(groupBox);
        comBoxMotor2->setObjectName(QString::fromUtf8("comBoxMotor2"));
        comBoxMotor2->setGeometry(QRect(30, 50, 69, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 60, 54, 12));
        cboxIsLink = new QCheckBox(groupBox);
        cboxIsLink->setObjectName(QString::fromUtf8("cboxIsLink"));
        cboxIsLink->setGeometry(QRect(300, 20, 71, 16));
        lblProtState = new QLabel(groupBox);
        lblProtState->setObjectName(QString::fromUtf8("lblProtState"));
        lblProtState->setGeometry(QRect(250, 82, 20, 20));
        lblProtState->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        comBoxForce = new QComboBox(groupBox);
        comBoxForce->setObjectName(QString::fromUtf8("comBoxForce"));
        comBoxForce->setGeometry(QRect(30, 80, 69, 22));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 90, 54, 12));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 150, 391, 81));
        spboxMotor1Position = new QSpinBox(groupBox_2);
        spboxMotor1Position->setObjectName(QString::fromUtf8("spboxMotor1Position"));
        spboxMotor1Position->setGeometry(QRect(50, 20, 71, 22));
        spboxMotor1Position->setMinimum(-9999);
        spboxMotor1Position->setMaximum(9999);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 20, 21, 16));
        btnStartMotor1 = new QPushButton(groupBox_2);
        btnStartMotor1->setObjectName(QString::fromUtf8("btnStartMotor1"));
        btnStartMotor1->setGeometry(QRect(300, 50, 75, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 31, 20));
        spboxMotor1Vel = new QSpinBox(groupBox_2);
        spboxMotor1Vel->setObjectName(QString::fromUtf8("spboxMotor1Vel"));
        spboxMotor1Vel->setGeometry(QRect(50, 50, 71, 22));
        spboxMotor1Vel->setMaximum(99);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 50, 21, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 31, 20));
        btnGoZeroMotor1 = new QPushButton(groupBox_2);
        btnGoZeroMotor1->setObjectName(QString::fromUtf8("btnGoZeroMotor1"));
        btnGoZeroMotor1->setGeometry(QRect(300, 20, 75, 23));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 150, 391, 81));
        spboxMotor2Position = new QSpinBox(groupBox_3);
        spboxMotor2Position->setObjectName(QString::fromUtf8("spboxMotor2Position"));
        spboxMotor2Position->setGeometry(QRect(50, 20, 71, 22));
        spboxMotor2Position->setMinimum(-9999);
        spboxMotor2Position->setMaximum(9999);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(140, 20, 21, 16));
        btnStartMotor2 = new QPushButton(groupBox_3);
        btnStartMotor2->setObjectName(QString::fromUtf8("btnStartMotor2"));
        btnStartMotor2->setGeometry(QRect(300, 50, 75, 23));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 31, 20));
        spboxMotor2Vel = new QSpinBox(groupBox_3);
        spboxMotor2Vel->setObjectName(QString::fromUtf8("spboxMotor2Vel"));
        spboxMotor2Vel->setGeometry(QRect(50, 50, 71, 22));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(140, 50, 21, 16));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 50, 31, 20));
        btnGoZeroMotor2 = new QPushButton(groupBox_3);
        btnGoZeroMotor2->setObjectName(QString::fromUtf8("btnGoZeroMotor2"));
        btnGoZeroMotor2->setGeometry(QRect(300, 20, 75, 23));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 240, 391, 91));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(190, 30, 21, 16));
        btnStartReadForce = new QPushButton(groupBox_4);
        btnStartReadForce->setObjectName(QString::fromUtf8("btnStartReadForce"));
        btnStartReadForce->setGeometry(QRect(300, 20, 75, 23));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 30, 51, 20));
        lblForceVal = new QLabel(groupBox_4);
        lblForceVal->setObjectName(QString::fromUtf8("lblForceVal"));
        lblForceVal->setGeometry(QRect(90, 30, 71, 20));
        btnClearForce = new QPushButton(groupBox_4);
        btnClearForce->setObjectName(QString::fromUtf8("btnClearForce"));
        btnClearForce->setGeometry(QRect(300, 50, 75, 23));
        lblReadForceState = new QLabel(groupBox_4);
        lblReadForceState->setObjectName(QString::fromUtf8("lblReadForceState"));
        lblReadForceState->setGeometry(QRect(270, 20, 20, 20));
        lblReadForceState->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(430, 240, 391, 91));
        btnSetFilter = new QPushButton(groupBox_5);
        btnSetFilter->setObjectName(QString::fromUtf8("btnSetFilter"));
        btnSetFilter->setGeometry(QRect(300, 50, 75, 23));
        spboxFilterStrength = new QSpinBox(groupBox_5);
        spboxFilterStrength->setObjectName(QString::fromUtf8("spboxFilterStrength"));
        spboxFilterStrength->setGeometry(QRect(100, 50, 71, 22));
        spboxFilterStrength->setMaximum(50);
        comBoxFilterType = new QComboBox(groupBox_5);
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->addItem(QString());
        comBoxFilterType->setObjectName(QString::fromUtf8("comBoxFilterType"));
        comBoxFilterType->setGeometry(QRect(100, 20, 151, 22));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 50, 71, 20));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 71, 20));
        motorTest1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(motorTest1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 23));
        motorTest1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(motorTest1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        motorTest1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(motorTest1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        motorTest1Class->setStatusBar(statusBar);

        retranslateUi(motorTest1Class);

        QMetaObject::connectSlotsByName(motorTest1Class);
    } // setupUi

    void retranslateUi(QMainWindow *motorTest1Class)
    {
        motorTest1Class->setWindowTitle(QApplication::translate("motorTest1Class", "motorTest1", nullptr));
        groupBox->setTitle(QApplication::translate("motorTest1Class", "\347\253\257\345\217\243\350\256\276\347\275\256", nullptr));
        btnOpenSerialPort->setText(QApplication::translate("motorTest1Class", "\346\211\223\345\274\200\347\253\257\345\217\243", nullptr));
        label->setText(QApplication::translate("motorTest1Class", "\347\224\265\346\234\2721", nullptr));
        label_2->setText(QApplication::translate("motorTest1Class", "\347\224\265\346\234\2722", nullptr));
        cboxIsLink->setText(QApplication::translate("motorTest1Class", "\346\230\257\345\220\246\350\201\224\345\212\250", nullptr));
        lblProtState->setText(QString());
        label_13->setText(QApplication::translate("motorTest1Class", "\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        groupBox_2->setTitle(QApplication::translate("motorTest1Class", "\347\224\265\346\234\2721\350\277\220\345\212\250\345\217\202\346\225\260", nullptr));
        label_3->setText(QApplication::translate("motorTest1Class", "mm", nullptr));
        btnStartMotor1->setText(QApplication::translate("motorTest1Class", "\350\277\220\350\241\214", nullptr));
        label_4->setText(QApplication::translate("motorTest1Class", "\350\241\214\347\250\213", nullptr));
        label_5->setText(QApplication::translate("motorTest1Class", "mm", nullptr));
        label_6->setText(QApplication::translate("motorTest1Class", "\351\200\237\345\272\246", nullptr));
        btnGoZeroMotor1->setText(QApplication::translate("motorTest1Class", "\345\233\236\351\233\266", nullptr));
        groupBox_3->setTitle(QApplication::translate("motorTest1Class", "\347\224\265\346\234\2722\350\277\220\345\212\250\345\217\202\346\225\260", nullptr));
        label_7->setText(QApplication::translate("motorTest1Class", "mm", nullptr));
        btnStartMotor2->setText(QApplication::translate("motorTest1Class", "\350\277\220\350\241\214", nullptr));
        label_8->setText(QApplication::translate("motorTest1Class", "\350\241\214\347\250\213", nullptr));
        label_9->setText(QApplication::translate("motorTest1Class", "mm", nullptr));
        label_10->setText(QApplication::translate("motorTest1Class", "\351\200\237\345\272\246", nullptr));
        btnGoZeroMotor2->setText(QApplication::translate("motorTest1Class", "\345\233\236\351\233\266", nullptr));
        groupBox_4->setTitle(QApplication::translate("motorTest1Class", "\345\212\233\344\274\240\346\204\237\345\231\250\350\256\276\347\275\256", nullptr));
        label_11->setText(QApplication::translate("motorTest1Class", "g", nullptr));
        btnStartReadForce->setText(QApplication::translate("motorTest1Class", "\345\274\200\345\247\213\350\257\273\346\225\260", nullptr));
        label_12->setText(QApplication::translate("motorTest1Class", "\346\265\213\351\207\217\345\200\274", nullptr));
        lblForceVal->setText(QApplication::translate("motorTest1Class", "\346\265\213\351\207\217\345\200\274", nullptr));
        btnClearForce->setText(QApplication::translate("motorTest1Class", "\346\270\205    \351\233\266", nullptr));
        lblReadForceState->setText(QString());
        groupBox_5->setTitle(QApplication::translate("motorTest1Class", "\346\273\244\346\263\242\345\231\250\350\256\276\347\275\256", nullptr));
        btnSetFilter->setText(QApplication::translate("motorTest1Class", "\350\256\276\347\275\256\346\273\244\346\263\242\345\231\250", nullptr));
        comBoxFilterType->setItemText(0, QApplication::translate("motorTest1Class", "\346\227\240\346\273\244\346\263\242\345\231\250", nullptr));
        comBoxFilterType->setItemText(1, QApplication::translate("motorTest1Class", "\345\271\263\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(2, QApplication::translate("motorTest1Class", "\344\270\255\344\275\215\345\200\274\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(3, QApplication::translate("motorTest1Class", "\344\270\200\351\230\266\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(4, QApplication::translate("motorTest1Class", "\346\273\221\345\212\250\345\271\263\345\235\207\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(5, QApplication::translate("motorTest1Class", "\344\270\255\344\275\215\345\200\274\345\271\263\345\235\207\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(6, QApplication::translate("motorTest1Class", "\346\273\221\345\212\250\344\270\255\344\275\215\345\200\274\345\271\263\345\235\207\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(7, QApplication::translate("motorTest1Class", "\345\271\263\345\235\207\345\200\274\346\273\244\346\263\242+\344\270\200\351\230\266\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(8, QApplication::translate("motorTest1Class", "\344\270\255\344\275\215\345\200\274\346\273\244\346\263\242+\344\270\200\351\230\266\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(9, QApplication::translate("motorTest1Class", "\346\273\221\345\212\250\345\271\263\345\235\207\346\273\244\346\263\242+\344\270\200\351\230\266\346\273\244\346\263\242", nullptr));
        comBoxFilterType->setItemText(10, QApplication::translate("motorTest1Class", "\344\270\255\344\275\215\345\200\274\345\271\263\345\235\207\346\273\244\346\263\242+\344\270\200\351\230\266\346\273\244\346\263\242", nullptr));

        label_16->setText(QApplication::translate("motorTest1Class", "\346\273\244\346\263\242\345\274\272\345\272\246", nullptr));
        label_14->setText(QApplication::translate("motorTest1Class", "\346\273\244\346\263\242\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class motorTest1Class: public Ui_motorTest1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORTEST1_H
