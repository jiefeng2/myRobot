/********************************************************************************
** Form generated from reading UI file 'frmRecipeSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMRECIPESETTING_H
#define UI_FRMRECIPESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmRecipeSetting
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRead;
    QPushButton *btnSave;
    QPushButton *btnExit;

    void setupUi(QWidget *frmRecipeSetting)
    {
        if (frmRecipeSetting->objectName().isEmpty())
            frmRecipeSetting->setObjectName(QString::fromUtf8("frmRecipeSetting"));
        frmRecipeSetting->resize(487, 326);
        label = new QLabel(frmRecipeSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(23, 40, 71, 20));
        lineEdit = new QLineEdit(frmRecipeSetting);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 40, 71, 20));
        label_2 = new QLabel(frmRecipeSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 40, 21, 20));
        label_3 = new QLabel(frmRecipeSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(197, 70, 21, 20));
        lineEdit_2 = new QLineEdit(frmRecipeSetting);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 70, 71, 20));
        label_4 = new QLabel(frmRecipeSetting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 70, 71, 20));
        widget = new QWidget(frmRecipeSetting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 290, 285, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRead = new QPushButton(widget);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));

        horizontalLayout->addWidget(btnRead);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnExit = new QPushButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout->addWidget(btnExit);


        retranslateUi(frmRecipeSetting);

        QMetaObject::connectSlotsByName(frmRecipeSetting);
    } // setupUi

    void retranslateUi(QWidget *frmRecipeSetting)
    {
        frmRecipeSetting->setWindowTitle(QApplication::translate("frmRecipeSetting", "frmRecipeSetting", nullptr));
        label->setText(QApplication::translate("frmRecipeSetting", "\350\245\277\346\236\227\347\223\266\346\225\260\351\207\217", nullptr));
        label_2->setText(QApplication::translate("frmRecipeSetting", "\344\270\252", nullptr));
        label_3->setText(QApplication::translate("frmRecipeSetting", "ml", nullptr));
        label_4->setText(QApplication::translate("frmRecipeSetting", "\346\257\215\346\266\262\350\242\213\345\255\220\345\217\226\346\266\262\351\207\217", nullptr));
        btnRead->setText(QApplication::translate("frmRecipeSetting", "\350\257\273\345\217\226", nullptr));
        btnSave->setText(QApplication::translate("frmRecipeSetting", "\344\277\235\345\255\230", nullptr));
        btnExit->setText(QApplication::translate("frmRecipeSetting", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmRecipeSetting: public Ui_frmRecipeSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMRECIPESETTING_H
