/********************************************************************************
** Form generated from reading UI file 'frmLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOGIN_H
#define UI_FRMLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLogin
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *txtUsr;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *txtPassWord;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExit;

    void setupUi(QWidget *frmLogin)
    {
        if (frmLogin->objectName().isEmpty())
            frmLogin->setObjectName(QString::fromUtf8("frmLogin"));
        frmLogin->resize(438, 270);
        label = new QLabel(frmLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 261, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(26);
        label->setFont(font);
        layoutWidget = new QWidget(frmLogin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 130, 195, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        txtUsr = new QLineEdit(layoutWidget);
        txtUsr->setObjectName(QString::fromUtf8("txtUsr"));

        horizontalLayout->addWidget(txtUsr);

        layoutWidget1 = new QWidget(frmLogin);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 150, 195, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        txtPassWord = new QLineEdit(layoutWidget1);
        txtPassWord->setObjectName(QString::fromUtf8("txtPassWord"));
        txtPassWord->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtPassWord);

        layoutWidget2 = new QWidget(frmLogin);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 200, 202, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnLogin = new QPushButton(layoutWidget2);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        horizontalLayout_3->addWidget(btnLogin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnExit = new QPushButton(layoutWidget2);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_3->addWidget(btnExit);


        retranslateUi(frmLogin);

        QMetaObject::connectSlotsByName(frmLogin);
    } // setupUi

    void retranslateUi(QWidget *frmLogin)
    {
        frmLogin->setWindowTitle(QApplication::translate("frmLogin", "frmLogin", nullptr));
        label->setText(QApplication::translate("frmLogin", "\350\207\252\345\212\250\351\205\215\350\215\257\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("frmLogin", "\350\264\246\345\217\267", nullptr));
        txtUsr->setText(QApplication::translate("frmLogin", "admin", nullptr));
        label_3->setText(QApplication::translate("frmLogin", "\345\257\206\347\240\201", nullptr));
        txtPassWord->setText(QApplication::translate("frmLogin", "111111", nullptr));
        btnLogin->setText(QApplication::translate("frmLogin", "\347\231\273\345\275\225", nullptr));
        btnExit->setText(QApplication::translate("frmLogin", "\345\205\263\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLogin: public Ui_frmLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOGIN_H
