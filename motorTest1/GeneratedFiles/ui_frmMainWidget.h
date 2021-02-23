/********************************************************************************
** Form generated from reading UI file 'frmMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAINWIDGET_H
#define UI_FRMMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMainWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDispense;
    QPushButton *btnRecipeSet;
    QPushButton *btnSystemSet;
    QPushButton *btnExit;

    void setupUi(QWidget *frmMainWidget)
    {
        if (frmMainWidget->objectName().isEmpty())
            frmMainWidget->setObjectName(QString::fromUtf8("frmMainWidget"));
        frmMainWidget->resize(507, 420);
        horizontalLayout = new QHBoxLayout(frmMainWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnDispense = new QPushButton(frmMainWidget);
        btnDispense->setObjectName(QString::fromUtf8("btnDispense"));
        btnDispense->setMinimumSize(QSize(0, 60));

        horizontalLayout->addWidget(btnDispense);

        btnRecipeSet = new QPushButton(frmMainWidget);
        btnRecipeSet->setObjectName(QString::fromUtf8("btnRecipeSet"));
        btnRecipeSet->setMinimumSize(QSize(0, 60));

        horizontalLayout->addWidget(btnRecipeSet);

        btnSystemSet = new QPushButton(frmMainWidget);
        btnSystemSet->setObjectName(QString::fromUtf8("btnSystemSet"));
        btnSystemSet->setMinimumSize(QSize(0, 60));

        horizontalLayout->addWidget(btnSystemSet);

        btnExit = new QPushButton(frmMainWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(0, 60));

        horizontalLayout->addWidget(btnExit);


        retranslateUi(frmMainWidget);

        QMetaObject::connectSlotsByName(frmMainWidget);
    } // setupUi

    void retranslateUi(QWidget *frmMainWidget)
    {
        frmMainWidget->setWindowTitle(QApplication::translate("frmMainWidget", "frmMainWidget", nullptr));
        btnDispense->setText(QApplication::translate("frmMainWidget", "\351\205\215\350\215\257", nullptr));
        btnRecipeSet->setText(QApplication::translate("frmMainWidget", "\351\205\215\350\215\257\350\256\276\347\275\256", nullptr));
        btnSystemSet->setText(QApplication::translate("frmMainWidget", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnExit->setText(QApplication::translate("frmMainWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMainWidget: public Ui_frmMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAINWIDGET_H
