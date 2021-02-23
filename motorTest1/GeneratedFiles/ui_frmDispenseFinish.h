/********************************************************************************
** Form generated from reading UI file 'frmDispenseFinish.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDISPENSEFINISH_H
#define UI_FRMDISPENSEFINISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmDispenseFinish
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *btndBottle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *btndMoLiquorbag;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *btndInjector;
    QSpacerItem *verticalSpacer;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *frmDispenseFinish)
    {
        if (frmDispenseFinish->objectName().isEmpty())
            frmDispenseFinish->setObjectName(QString::fromUtf8("frmDispenseFinish"));
        frmDispenseFinish->resize(482, 263);
        gridLayout = new QGridLayout(frmDispenseFinish);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(frmDispenseFinish);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 0));

        horizontalLayout->addWidget(label_3);

        btndBottle = new QPushButton(frmDispenseFinish);
        btndBottle->setObjectName(QString::fromUtf8("btndBottle"));

        horizontalLayout->addWidget(btndBottle);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frmDispenseFinish);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 0));

        horizontalLayout_2->addWidget(label_2);

        btndMoLiquorbag = new QPushButton(frmDispenseFinish);
        btndMoLiquorbag->setObjectName(QString::fromUtf8("btndMoLiquorbag"));

        horizontalLayout_2->addWidget(btndMoLiquorbag);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(frmDispenseFinish);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 0));

        horizontalLayout_3->addWidget(label);

        btndInjector = new QPushButton(frmDispenseFinish);
        btndInjector->setObjectName(QString::fromUtf8("btndInjector"));

        horizontalLayout_3->addWidget(btndInjector);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        btnExit = new QPushButton(frmDispenseFinish);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        gridLayout->addWidget(btnExit, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(143, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);


        retranslateUi(frmDispenseFinish);

        QMetaObject::connectSlotsByName(frmDispenseFinish);
    } // setupUi

    void retranslateUi(QWidget *frmDispenseFinish)
    {
        frmDispenseFinish->setWindowTitle(QApplication::translate("frmDispenseFinish", "frmDispenseFinish", nullptr));
        label_3->setText(QApplication::translate("frmDispenseFinish", "\345\216\273\351\231\244\350\215\257\347\223\266\345\217\212\345\244\271\345\205\267", nullptr));
        btndBottle->setText(QApplication::translate("frmDispenseFinish", "\345\215\270\350\275\275", nullptr));
        label_2->setText(QApplication::translate("frmDispenseFinish", "\346\257\215\346\266\262\350\242\213", nullptr));
        btndMoLiquorbag->setText(QApplication::translate("frmDispenseFinish", "\345\215\270\350\275\275", nullptr));
        label->setText(QApplication::translate("frmDispenseFinish", "\346\263\250\345\260\204\345\231\250", nullptr));
        btndInjector->setText(QApplication::translate("frmDispenseFinish", "\345\215\270\350\275\275", nullptr));
        btnExit->setText(QApplication::translate("frmDispenseFinish", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmDispenseFinish: public Ui_frmDispenseFinish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDISPENSEFINISH_H
