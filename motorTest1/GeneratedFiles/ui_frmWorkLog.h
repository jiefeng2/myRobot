/********************************************************************************
** Form generated from reading UI file 'frmWorkLog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMWORKLOG_H
#define UI_FRMWORKLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_frmWorkLog
{
public:
    QPushButton *btnClear;
    QPushButton *btnExit;

    void setupUi(QDialog *frmWorkLog)
    {
        if (frmWorkLog->objectName().isEmpty())
            frmWorkLog->setObjectName(QString::fromUtf8("frmWorkLog"));
        frmWorkLog->resize(400, 300);
        btnClear = new QPushButton(frmWorkLog);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(160, 260, 93, 28));
        btnExit = new QPushButton(frmWorkLog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(280, 260, 93, 28));

        retranslateUi(frmWorkLog);

        QMetaObject::connectSlotsByName(frmWorkLog);
    } // setupUi

    void retranslateUi(QDialog *frmWorkLog)
    {
        frmWorkLog->setWindowTitle(QApplication::translate("frmWorkLog", "frmWorkLog", nullptr));
        btnClear->setText(QApplication::translate("frmWorkLog", "\346\270\205\347\251\272", nullptr));
        btnExit->setText(QApplication::translate("frmWorkLog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmWorkLog: public Ui_frmWorkLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMWORKLOG_H
