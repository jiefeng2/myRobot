/********************************************************************************
** Form generated from reading UI file 'frmPrepareDrug.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPREPAREDRUG_H
#define UI_FRMPREPAREDRUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPrepareDrug
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelInjector;
    QPushButton *btnInjector;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMoliquorbag;
    QPushButton *btnMoliquorbag;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *btnBottle;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnGoNext;
    QPushButton *btnGoBack;

    void setupUi(QWidget *frmPrepareDrug)
    {
        if (frmPrepareDrug->objectName().isEmpty())
            frmPrepareDrug->setObjectName(QString::fromUtf8("frmPrepareDrug"));
        frmPrepareDrug->resize(492, 300);
        verticalLayout = new QVBoxLayout(frmPrepareDrug);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelInjector = new QLabel(frmPrepareDrug);
        labelInjector->setObjectName(QString::fromUtf8("labelInjector"));
        labelInjector->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(labelInjector);

        btnInjector = new QPushButton(frmPrepareDrug);
        btnInjector->setObjectName(QString::fromUtf8("btnInjector"));

        horizontalLayout_3->addWidget(btnInjector);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelMoliquorbag = new QLabel(frmPrepareDrug);
        labelMoliquorbag->setObjectName(QString::fromUtf8("labelMoliquorbag"));
        labelMoliquorbag->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(labelMoliquorbag);

        btnMoliquorbag = new QPushButton(frmPrepareDrug);
        btnMoliquorbag->setObjectName(QString::fromUtf8("btnMoliquorbag"));

        horizontalLayout_2->addWidget(btnMoliquorbag);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(frmPrepareDrug);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(label_3);

        btnBottle = new QPushButton(frmPrepareDrug);
        btnBottle->setObjectName(QString::fromUtf8("btnBottle"));

        horizontalLayout->addWidget(btnBottle);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btnGoNext = new QPushButton(frmPrepareDrug);
        btnGoNext->setObjectName(QString::fromUtf8("btnGoNext"));

        horizontalLayout_4->addWidget(btnGoNext);

        btnGoBack = new QPushButton(frmPrepareDrug);
        btnGoBack->setObjectName(QString::fromUtf8("btnGoBack"));

        horizontalLayout_4->addWidget(btnGoBack);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(frmPrepareDrug);

        QMetaObject::connectSlotsByName(frmPrepareDrug);
    } // setupUi

    void retranslateUi(QWidget *frmPrepareDrug)
    {
        frmPrepareDrug->setWindowTitle(QApplication::translate("frmPrepareDrug", "frmPrepareDrug", nullptr));
        labelInjector->setText(QApplication::translate("frmPrepareDrug", "\346\263\250\345\260\204\345\231\250", nullptr));
        btnInjector->setText(QApplication::translate("frmPrepareDrug", "\345\256\211\350\243\205", nullptr));
        labelMoliquorbag->setText(QApplication::translate("frmPrepareDrug", "\346\257\215\346\266\262\345\270\246", nullptr));
        btnMoliquorbag->setText(QApplication::translate("frmPrepareDrug", "\345\256\211\350\243\205", nullptr));
        label_3->setText(QApplication::translate("frmPrepareDrug", "\344\270\200\345\205\2610\344\270\252\350\215\257\347\223\266", nullptr));
        btnBottle->setText(QApplication::translate("frmPrepareDrug", "\345\256\211\350\243\205", nullptr));
        btnGoNext->setText(QApplication::translate("frmPrepareDrug", "\344\270\213\344\270\200\346\255\245", nullptr));
        btnGoBack->setText(QApplication::translate("frmPrepareDrug", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPrepareDrug: public Ui_frmPrepareDrug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPREPAREDRUG_H
