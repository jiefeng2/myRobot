/********************************************************************************
** Form generated from reading UI file 'frmDispenseProcess.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDISPENSEPROCESS_H
#define UI_FRMDISPENSEPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmDispenseProcess
{
public:
    QLabel *lblForceSensorVal;
    QPushButton *btnGoNext;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *btnprocess;
    QPushButton *pushButton;

    void setupUi(QWidget *frmDispenseProcess)
    {
        if (frmDispenseProcess->objectName().isEmpty())
            frmDispenseProcess->setObjectName(QString::fromUtf8("frmDispenseProcess"));
        frmDispenseProcess->resize(890, 606);
        lblForceSensorVal = new QLabel(frmDispenseProcess);
        lblForceSensorVal->setObjectName(QString::fromUtf8("lblForceSensorVal"));
        lblForceSensorVal->setGeometry(QRect(180, 60, 171, 16));
        btnGoNext = new QPushButton(frmDispenseProcess);
        btnGoNext->setObjectName(QString::fromUtf8("btnGoNext"));
        btnGoNext->setGeometry(QRect(720, 540, 75, 23));
        layoutWidget = new QWidget(frmDispenseProcess);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 160, 151, 198));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_7);

        btnprocess = new QPushButton(frmDispenseProcess);
        btnprocess->setObjectName(QString::fromUtf8("btnprocess"));
        btnprocess->setGeometry(QRect(710, 390, 93, 28));
        pushButton = new QPushButton(frmDispenseProcess);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(700, 250, 93, 28));

        retranslateUi(frmDispenseProcess);

        QMetaObject::connectSlotsByName(frmDispenseProcess);
    } // setupUi

    void retranslateUi(QWidget *frmDispenseProcess)
    {
        frmDispenseProcess->setWindowTitle(QApplication::translate("frmDispenseProcess", "frmDispenseProcess", nullptr));
        lblForceSensorVal->setText(QApplication::translate("frmDispenseProcess", "\346\266\262\344\275\223\350\264\250\351\207\217\357\274\2320 g", nullptr));
        btnGoNext->setText(QApplication::translate("frmDispenseProcess", "\344\270\213\344\270\200\346\255\245", nullptr));
        pushButton_2->setText(QApplication::translate("frmDispenseProcess", "\345\220\221\347\254\254N\344\270\252\350\245\277\346\236\227\347\223\266\346\263\250\345\260\204", nullptr));
        pushButton_3->setText(QApplication::translate("frmDispenseProcess", "\346\216\222\346\260\224", nullptr));
        pushButton_4->setText(QApplication::translate("frmDispenseProcess", "\346\272\266\350\247\243", nullptr));
        pushButton_5->setText(QApplication::translate("frmDispenseProcess", "\345\220\270\346\260\224", nullptr));
        pushButton_6->setText(QApplication::translate("frmDispenseProcess", "\344\273\216\347\254\254N\344\270\252\350\245\277\346\236\227\347\223\266\345\217\226\346\266\262", nullptr));
        pushButton_7->setText(QApplication::translate("frmDispenseProcess", "\345\220\221\346\257\215\346\266\262\350\242\213\346\263\250\345\260\204", nullptr));
        btnprocess->setText(QApplication::translate("frmDispenseProcess", "\345\274\200\345\247\213\351\205\215\350\215\257", nullptr));
        pushButton->setText(QApplication::translate("frmDispenseProcess", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmDispenseProcess: public Ui_frmDispenseProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDISPENSEPROCESS_H
