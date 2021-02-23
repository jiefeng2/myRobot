/********************************************************************************
** Form generated from reading UI file 'frmAccountManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMACCOUNTMANAGER_H
#define UI_FRMACCOUNTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmAccountManager
{
public:
    QHBoxLayout *horizontalLayout_7;
    QTableView *tbwUserManager;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtUserName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *txtUserNum;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *txtUserPassword;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *cmdUserType;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnNewUser;
    QPushButton *btnModifyUser;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnDelUser;
    QPushButton *btnExit;

    void setupUi(QWidget *frmAccountManager)
    {
        if (frmAccountManager->objectName().isEmpty())
            frmAccountManager->setObjectName(QString::fromUtf8("frmAccountManager"));
        frmAccountManager->resize(632, 411);
        horizontalLayout_7 = new QHBoxLayout(frmAccountManager);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        tbwUserManager = new QTableView(frmAccountManager);
        tbwUserManager->setObjectName(QString::fromUtf8("tbwUserManager"));

        horizontalLayout_7->addWidget(tbwUserManager);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(frmAccountManager);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtUserName = new QLineEdit(groupBox);
        txtUserName->setObjectName(QString::fromUtf8("txtUserName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtUserName->sizePolicy().hasHeightForWidth());
        txtUserName->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(txtUserName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        txtUserNum = new QLineEdit(groupBox);
        txtUserNum->setObjectName(QString::fromUtf8("txtUserNum"));
        sizePolicy.setHeightForWidth(txtUserNum->sizePolicy().hasHeightForWidth());
        txtUserNum->setSizePolicy(sizePolicy);
        txtUserNum->setReadOnly(false);

        horizontalLayout_2->addWidget(txtUserNum);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        txtUserPassword = new QLineEdit(groupBox);
        txtUserPassword->setObjectName(QString::fromUtf8("txtUserPassword"));
        sizePolicy.setHeightForWidth(txtUserPassword->sizePolicy().hasHeightForWidth());
        txtUserPassword->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(txtUserPassword);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        cmdUserType = new QComboBox(groupBox);
        cmdUserType->addItem(QString());
        cmdUserType->addItem(QString());
        cmdUserType->setObjectName(QString::fromUtf8("cmdUserType"));

        horizontalLayout_3->addWidget(cmdUserType);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnNewUser = new QPushButton(frmAccountManager);
        btnNewUser->setObjectName(QString::fromUtf8("btnNewUser"));

        horizontalLayout_4->addWidget(btnNewUser);

        btnModifyUser = new QPushButton(frmAccountManager);
        btnModifyUser->setObjectName(QString::fromUtf8("btnModifyUser"));

        horizontalLayout_4->addWidget(btnModifyUser);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnDelUser = new QPushButton(frmAccountManager);
        btnDelUser->setObjectName(QString::fromUtf8("btnDelUser"));

        horizontalLayout_5->addWidget(btnDelUser);

        btnExit = new QPushButton(frmAccountManager);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_5->addWidget(btnExit);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout_2);


        retranslateUi(frmAccountManager);

        QMetaObject::connectSlotsByName(frmAccountManager);
    } // setupUi

    void retranslateUi(QWidget *frmAccountManager)
    {
        frmAccountManager->setWindowTitle(QApplication::translate("frmAccountManager", "frmAccountManager", nullptr));
        groupBox->setTitle(QApplication::translate("frmAccountManager", "\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("frmAccountManager", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_2->setText(QApplication::translate("frmAccountManager", "\345\267\245\345\217\267:", nullptr));
        label_4->setText(QApplication::translate("frmAccountManager", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QApplication::translate("frmAccountManager", "\347\224\250\346\210\267\346\235\203\351\231\220:", nullptr));
        cmdUserType->setItemText(0, QApplication::translate("frmAccountManager", "\346\223\215\344\275\234\345\221\230", nullptr));
        cmdUserType->setItemText(1, QApplication::translate("frmAccountManager", "\347\256\241\347\220\206\345\221\230", nullptr));

        btnNewUser->setText(QApplication::translate("frmAccountManager", "\346\226\260\345\273\272", nullptr));
        btnModifyUser->setText(QApplication::translate("frmAccountManager", "\344\277\256\346\224\271", nullptr));
        btnDelUser->setText(QApplication::translate("frmAccountManager", "\345\210\240\351\231\244", nullptr));
        btnExit->setText(QApplication::translate("frmAccountManager", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmAccountManager: public Ui_frmAccountManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMACCOUNTMANAGER_H
