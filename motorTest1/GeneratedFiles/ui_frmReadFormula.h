/********************************************************************************
** Form generated from reading UI file 'frmReadFormula.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMREADFORMULA_H
#define UI_FRMREADFORMULA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmReadFormula
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnReadFormula;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tbvwFormula;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGoNext;
    QPushButton *btnGoBack;

    void setupUi(QWidget *frmReadFormula)
    {
        if (frmReadFormula->objectName().isEmpty())
            frmReadFormula->setObjectName(QString::fromUtf8("frmReadFormula"));
        frmReadFormula->resize(459, 338);
        verticalLayout = new QVBoxLayout(frmReadFormula);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnReadFormula = new QPushButton(frmReadFormula);
        btnReadFormula->setObjectName(QString::fromUtf8("btnReadFormula"));

        horizontalLayout_2->addWidget(btnReadFormula);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        tbvwFormula = new QTableView(frmReadFormula);
        tbvwFormula->setObjectName(QString::fromUtf8("tbvwFormula"));

        verticalLayout->addWidget(tbvwFormula);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnGoNext = new QPushButton(frmReadFormula);
        btnGoNext->setObjectName(QString::fromUtf8("btnGoNext"));

        horizontalLayout->addWidget(btnGoNext);

        btnGoBack = new QPushButton(frmReadFormula);
        btnGoBack->setObjectName(QString::fromUtf8("btnGoBack"));

        horizontalLayout->addWidget(btnGoBack);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(frmReadFormula);

        QMetaObject::connectSlotsByName(frmReadFormula);
    } // setupUi

    void retranslateUi(QWidget *frmReadFormula)
    {
        frmReadFormula->setWindowTitle(QApplication::translate("frmReadFormula", "frmReadFormula", nullptr));
        btnReadFormula->setText(QApplication::translate("frmReadFormula", "\350\257\273\345\217\226\351\205\215\346\226\271", nullptr));
        btnGoNext->setText(QApplication::translate("frmReadFormula", "\344\270\213\344\270\200\346\255\245", nullptr));
        btnGoBack->setText(QApplication::translate("frmReadFormula", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmReadFormula: public Ui_frmReadFormula {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMREADFORMULA_H
