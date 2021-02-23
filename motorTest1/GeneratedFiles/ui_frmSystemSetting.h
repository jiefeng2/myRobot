/********************************************************************************
** Form generated from reading UI file 'frmSystemSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSYSTEMSETTING_H
#define UI_FRMSYSTEMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmSystemSetting
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnParamSetting;
    QPushButton *btnAccountManagement;
    QPushButton *btnFormulaSetting;
    QPushButton *btnWorkLog;
    QPushButton *btnExit;

    void setupUi(QWidget *frmSystemSetting)
    {
        if (frmSystemSetting->objectName().isEmpty())
            frmSystemSetting->setObjectName(QString::fromUtf8("frmSystemSetting"));
        frmSystemSetting->resize(400, 300);
        layoutWidget = new QWidget(frmSystemSetting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 121, 191));
        layoutWidget->setMinimumSize(QSize(0, 30));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnParamSetting = new QPushButton(layoutWidget);
        btnParamSetting->setObjectName(QString::fromUtf8("btnParamSetting"));
        btnParamSetting->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btnParamSetting);

        btnAccountManagement = new QPushButton(layoutWidget);
        btnAccountManagement->setObjectName(QString::fromUtf8("btnAccountManagement"));
        btnAccountManagement->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btnAccountManagement);

        btnFormulaSetting = new QPushButton(layoutWidget);
        btnFormulaSetting->setObjectName(QString::fromUtf8("btnFormulaSetting"));
        btnFormulaSetting->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btnFormulaSetting);

        btnWorkLog = new QPushButton(layoutWidget);
        btnWorkLog->setObjectName(QString::fromUtf8("btnWorkLog"));
        btnWorkLog->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btnWorkLog);

        btnExit = new QPushButton(layoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(btnExit);


        retranslateUi(frmSystemSetting);

        QMetaObject::connectSlotsByName(frmSystemSetting);
    } // setupUi

    void retranslateUi(QWidget *frmSystemSetting)
    {
        frmSystemSetting->setWindowTitle(QApplication::translate("frmSystemSetting", "frmSystemSetting", nullptr));
        btnParamSetting->setText(QApplication::translate("frmSystemSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        btnAccountManagement->setText(QApplication::translate("frmSystemSetting", "\350\264\246\346\210\267\347\256\241\347\220\206", nullptr));
        btnFormulaSetting->setText(QApplication::translate("frmSystemSetting", "\350\215\257\346\226\271\350\256\276\347\275\256", nullptr));
        btnWorkLog->setText(QApplication::translate("frmSystemSetting", "\345\267\245\344\275\234\346\227\245\345\277\227", nullptr));
        btnExit->setText(QApplication::translate("frmSystemSetting", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSystemSetting: public Ui_frmSystemSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSYSTEMSETTING_H
