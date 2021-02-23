/********************************************************************************
** Form generated from reading UI file 'frmSelfTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSELFTEST_H
#define UI_FRMSELFTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmSelfTest
{
public:
    QPushButton *btnStartSelfTest;
    QPushButton *btnGoNext;
    QPushButton *btnGoBack;
    QPushButton *btnOpenPort;
    QTextEdit *textEdit;

    void setupUi(QWidget *frmSelfTest)
    {
        if (frmSelfTest->objectName().isEmpty())
            frmSelfTest->setObjectName(QString::fromUtf8("frmSelfTest"));
        frmSelfTest->resize(460, 315);
        btnStartSelfTest = new QPushButton(frmSelfTest);
        btnStartSelfTest->setObjectName(QString::fromUtf8("btnStartSelfTest"));
        btnStartSelfTest->setGeometry(QRect(330, 100, 75, 23));
        btnGoNext = new QPushButton(frmSelfTest);
        btnGoNext->setObjectName(QString::fromUtf8("btnGoNext"));
        btnGoNext->setGeometry(QRect(214, 260, 71, 23));
        btnGoBack = new QPushButton(frmSelfTest);
        btnGoBack->setObjectName(QString::fromUtf8("btnGoBack"));
        btnGoBack->setGeometry(QRect(304, 260, 71, 23));
        btnOpenPort = new QPushButton(frmSelfTest);
        btnOpenPort->setObjectName(QString::fromUtf8("btnOpenPort"));
        btnOpenPort->setGeometry(QRect(330, 50, 75, 23));
        textEdit = new QTextEdit(frmSelfTest);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 100, 181, 101));

        retranslateUi(frmSelfTest);

        QMetaObject::connectSlotsByName(frmSelfTest);
    } // setupUi

    void retranslateUi(QWidget *frmSelfTest)
    {
        frmSelfTest->setWindowTitle(QApplication::translate("frmSelfTest", "frmSelfTest", nullptr));
        btnStartSelfTest->setText(QApplication::translate("frmSelfTest", "\350\207\252\346\243\200", nullptr));
        btnGoNext->setText(QApplication::translate("frmSelfTest", "\344\270\213\344\270\200\346\255\245", nullptr));
        btnGoBack->setText(QApplication::translate("frmSelfTest", "\350\277\224\345\233\236", nullptr));
        btnOpenPort->setText(QApplication::translate("frmSelfTest", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSelfTest: public Ui_frmSelfTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSELFTEST_H
