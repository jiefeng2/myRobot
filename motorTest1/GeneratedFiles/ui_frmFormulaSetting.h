/********************************************************************************
** Form generated from reading UI file 'frmFormulaSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMFORMULASETTING_H
#define UI_FRMFORMULASETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmFormulaSetting
{
public:
    QTableView *tbvwFormula;
    QGroupBox *groupBox;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_30;
    QSpinBox *sboxF1;
    QLabel *label_31;
    QSpinBox *sboxG1;
    QWidget *layoutWidget_13;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_40;
    QSpinBox *sboxVf;
    QLabel *label_41;
    QSpinBox *sboxVg;
    QSpinBox *sboxF2;
    QLabel *label_32;
    QLabel *label_33;
    QSpinBox *sboxG2;
    QSpinBox *sboxF3;
    QLabel *label_34;
    QLabel *label_35;
    QSpinBox *sboxG3;
    QLabel *label_36;
    QSpinBox *sboxF4;
    QLabel *label_37;
    QSpinBox *sboxG4;
    QLabel *label_38;
    QSpinBox *sboxF5;
    QLabel *label_39;
    QLineEdit *sboxG5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLineEdit *txtNum;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_22;
    QLineEdit *txtPharName;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_23;
    QLineEdit *txtLiquorName;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_24;
    QLineEdit *txtPillName;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QSpinBox *sboxVialNum;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_26;
    QSpinBox *sboxLiquorVol;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_27;
    QSpinBox *sboxSingleLiquorVol;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_28;
    QSpinBox *sboxTargetWeight;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_42;
    QSpinBox *sboxShakeAngle;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_43;
    QSpinBox *sboxShakeTimes;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_44;
    QSpinBox *sboxWeighingError;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_45;
    QSpinBox *sboxPumpCapacity;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_29;
    QSpinBox *sboxExchangeTime;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *btnNew;
    QPushButton *btnModify;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_33;
    QPushButton *btnDel;
    QPushButton *btnExit;

    void setupUi(QDialog *frmFormulaSetting)
    {
        if (frmFormulaSetting->objectName().isEmpty())
            frmFormulaSetting->setObjectName(QString::fromUtf8("frmFormulaSetting"));
        frmFormulaSetting->resize(773, 637);
        tbvwFormula = new QTableView(frmFormulaSetting);
        tbvwFormula->setObjectName(QString::fromUtf8("tbvwFormula"));
        tbvwFormula->setGeometry(QRect(210, 10, 551, 261));
        groupBox = new QGroupBox(frmFormulaSetting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(310, 280, 421, 231));
        groupBox->setMinimumSize(QSize(0, 200));
        layoutWidget_8 = new QWidget(groupBox);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 50, 163, 26));
        horizontalLayout_26 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(layoutWidget_8);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_26->addWidget(label_30);

        sboxF1 = new QSpinBox(layoutWidget_8);
        sboxF1->setObjectName(QString::fromUtf8("sboxF1"));

        horizontalLayout_26->addWidget(sboxF1);

        label_31 = new QLabel(layoutWidget_8);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_26->addWidget(label_31);

        sboxG1 = new QSpinBox(layoutWidget_8);
        sboxG1->setObjectName(QString::fromUtf8("sboxG1"));

        horizontalLayout_26->addWidget(sboxG1);

        layoutWidget_13 = new QWidget(groupBox);
        layoutWidget_13->setObjectName(QString::fromUtf8("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(10, 20, 163, 26));
        horizontalLayout_31 = new QHBoxLayout(layoutWidget_13);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        label_40 = new QLabel(layoutWidget_13);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_31->addWidget(label_40);

        sboxVf = new QSpinBox(layoutWidget_13);
        sboxVf->setObjectName(QString::fromUtf8("sboxVf"));

        horizontalLayout_31->addWidget(sboxVf);

        label_41 = new QLabel(layoutWidget_13);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_31->addWidget(label_41);

        sboxVg = new QSpinBox(layoutWidget_13);
        sboxVg->setObjectName(QString::fromUtf8("sboxVg"));

        horizontalLayout_31->addWidget(sboxVg);

        sboxF2 = new QSpinBox(groupBox);
        sboxF2->setObjectName(QString::fromUtf8("sboxF2"));
        sboxF2->setGeometry(QRect(42, 81, 46, 24));
        label_32 = new QLabel(groupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(11, 81, 24, 16));
        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(95, 81, 24, 16));
        sboxG2 = new QSpinBox(groupBox);
        sboxG2->setObjectName(QString::fromUtf8("sboxG2"));
        sboxG2->setGeometry(QRect(126, 81, 46, 24));
        sboxF3 = new QSpinBox(groupBox);
        sboxF3->setObjectName(QString::fromUtf8("sboxF3"));
        sboxF3->setGeometry(QRect(100, 110, 46, 24));
        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(53, 110, 41, 20));
        label_35 = new QLabel(groupBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(183, 110, 41, 20));
        sboxG3 = new QSpinBox(groupBox);
        sboxG3->setObjectName(QString::fromUtf8("sboxG3"));
        sboxG3->setGeometry(QRect(240, 110, 46, 24));
        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(53, 140, 41, 20));
        sboxF4 = new QSpinBox(groupBox);
        sboxF4->setObjectName(QString::fromUtf8("sboxF4"));
        sboxF4->setGeometry(QRect(100, 140, 46, 24));
        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(183, 140, 41, 20));
        sboxG4 = new QSpinBox(groupBox);
        sboxG4->setObjectName(QString::fromUtf8("sboxG4"));
        sboxG4->setGeometry(QRect(240, 140, 46, 24));
        label_38 = new QLabel(groupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(53, 170, 41, 20));
        sboxF5 = new QSpinBox(groupBox);
        sboxF5->setObjectName(QString::fromUtf8("sboxF5"));
        sboxF5->setGeometry(QRect(100, 170, 46, 24));
        label_39 = new QLabel(groupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(183, 170, 41, 20));
        sboxG5 = new QLineEdit(groupBox);
        sboxG5->setObjectName(QString::fromUtf8("sboxG5"));
        sboxG5->setGeometry(QRect(240, 170, 71, 21));
        layoutWidget = new QWidget(frmFormulaSetting);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 197, 414));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(label);

        txtNum = new QLineEdit(layoutWidget);
        txtNum->setObjectName(QString::fromUtf8("txtNum"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtNum->sizePolicy().hasHeightForWidth());
        txtNum->setSizePolicy(sizePolicy);
        txtNum->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(txtNum);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_18->addWidget(label_22);

        txtPharName = new QLineEdit(layoutWidget);
        txtPharName->setObjectName(QString::fromUtf8("txtPharName"));
        sizePolicy.setHeightForWidth(txtPharName->sizePolicy().hasHeightForWidth());
        txtPharName->setSizePolicy(sizePolicy);
        txtPharName->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_18->addWidget(txtPharName);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_19->addWidget(label_23);

        txtLiquorName = new QLineEdit(layoutWidget);
        txtLiquorName->setObjectName(QString::fromUtf8("txtLiquorName"));
        sizePolicy.setHeightForWidth(txtLiquorName->sizePolicy().hasHeightForWidth());
        txtLiquorName->setSizePolicy(sizePolicy);
        txtLiquorName->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_19->addWidget(txtLiquorName);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_20->addWidget(label_24);

        txtPillName = new QLineEdit(layoutWidget);
        txtPillName->setObjectName(QString::fromUtf8("txtPillName"));
        sizePolicy.setHeightForWidth(txtPillName->sizePolicy().hasHeightForWidth());
        txtPillName->setSizePolicy(sizePolicy);
        txtPillName->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_20->addWidget(txtPillName);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_21->addWidget(label_25);

        sboxVialNum = new QSpinBox(layoutWidget);
        sboxVialNum->setObjectName(QString::fromUtf8("sboxVialNum"));

        horizontalLayout_21->addWidget(sboxVialNum);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_22->addWidget(label_26);

        sboxLiquorVol = new QSpinBox(layoutWidget);
        sboxLiquorVol->setObjectName(QString::fromUtf8("sboxLiquorVol"));

        horizontalLayout_22->addWidget(sboxLiquorVol);


        verticalLayout->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_23->addWidget(label_27);

        sboxSingleLiquorVol = new QSpinBox(layoutWidget);
        sboxSingleLiquorVol->setObjectName(QString::fromUtf8("sboxSingleLiquorVol"));

        horizontalLayout_23->addWidget(sboxSingleLiquorVol);


        verticalLayout->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_24->addWidget(label_28);

        sboxTargetWeight = new QSpinBox(layoutWidget);
        sboxTargetWeight->setObjectName(QString::fromUtf8("sboxTargetWeight"));

        horizontalLayout_24->addWidget(sboxTargetWeight);


        verticalLayout->addLayout(horizontalLayout_24);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        label_42 = new QLabel(layoutWidget);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_34->addWidget(label_42);

        sboxShakeAngle = new QSpinBox(layoutWidget);
        sboxShakeAngle->setObjectName(QString::fromUtf8("sboxShakeAngle"));

        horizontalLayout_34->addWidget(sboxShakeAngle);


        verticalLayout->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_43 = new QLabel(layoutWidget);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_35->addWidget(label_43);

        sboxShakeTimes = new QSpinBox(layoutWidget);
        sboxShakeTimes->setObjectName(QString::fromUtf8("sboxShakeTimes"));

        horizontalLayout_35->addWidget(sboxShakeTimes);


        verticalLayout->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        label_44 = new QLabel(layoutWidget);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_36->addWidget(label_44);

        sboxWeighingError = new QSpinBox(layoutWidget);
        sboxWeighingError->setObjectName(QString::fromUtf8("sboxWeighingError"));

        horizontalLayout_36->addWidget(sboxWeighingError);


        verticalLayout->addLayout(horizontalLayout_36);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        label_45 = new QLabel(layoutWidget);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_37->addWidget(label_45);

        sboxPumpCapacity = new QSpinBox(layoutWidget);
        sboxPumpCapacity->setObjectName(QString::fromUtf8("sboxPumpCapacity"));

        horizontalLayout_37->addWidget(sboxPumpCapacity);


        verticalLayout->addLayout(horizontalLayout_37);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_25->addWidget(label_29);

        sboxExchangeTime = new QSpinBox(layoutWidget);
        sboxExchangeTime->setObjectName(QString::fromUtf8("sboxExchangeTime"));

        horizontalLayout_25->addWidget(sboxExchangeTime);


        verticalLayout->addLayout(horizontalLayout_25);

        layoutWidget1 = new QWidget(frmFormulaSetting);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 500, 195, 30));
        horizontalLayout_32 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        horizontalLayout_32->setContentsMargins(0, 0, 0, 0);
        btnNew = new QPushButton(layoutWidget1);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout_32->addWidget(btnNew);

        btnModify = new QPushButton(layoutWidget1);
        btnModify->setObjectName(QString::fromUtf8("btnModify"));

        horizontalLayout_32->addWidget(btnModify);

        layoutWidget2 = new QWidget(frmFormulaSetting);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 570, 195, 30));
        horizontalLayout_33 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(0, 0, 0, 0);
        btnDel = new QPushButton(layoutWidget2);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));

        horizontalLayout_33->addWidget(btnDel);

        btnExit = new QPushButton(layoutWidget2);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_33->addWidget(btnExit);


        retranslateUi(frmFormulaSetting);

        QMetaObject::connectSlotsByName(frmFormulaSetting);
    } // setupUi

    void retranslateUi(QDialog *frmFormulaSetting)
    {
        frmFormulaSetting->setWindowTitle(QApplication::translate("frmFormulaSetting", "frmFormulaSetting", nullptr));
        groupBox->setTitle(QApplication::translate("frmFormulaSetting", "\346\260\224\346\266\262\344\272\244\346\215\242\345\217\202\346\225\260", nullptr));
        label_30->setText(QApplication::translate("frmFormulaSetting", "F1:", nullptr));
        label_31->setText(QApplication::translate("frmFormulaSetting", "G1:", nullptr));
        label_40->setText(QApplication::translate("frmFormulaSetting", "Vf:", nullptr));
        label_41->setText(QApplication::translate("frmFormulaSetting", "Vg:", nullptr));
        label_32->setText(QApplication::translate("frmFormulaSetting", "F2:", nullptr));
        label_33->setText(QApplication::translate("frmFormulaSetting", "G2:", nullptr));
        label_34->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2431", nullptr));
        label_35->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2432", nullptr));
        label_36->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2433", nullptr));
        label_37->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2434", nullptr));
        label_38->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2435", nullptr));
        label_39->setText(QApplication::translate("frmFormulaSetting", "\344\270\262\345\217\2436", nullptr));
        label->setText(QApplication::translate("frmFormulaSetting", "\347\274\226\345\217\267:", nullptr));
        label_22->setText(QApplication::translate("frmFormulaSetting", "\350\215\257\345\211\202\345\220\215\347\247\260:", nullptr));
        label_23->setText(QApplication::translate("frmFormulaSetting", "\346\257\215\346\266\262\345\220\215\347\247\260:", nullptr));
        label_24->setText(QApplication::translate("frmFormulaSetting", "\350\215\257\347\223\266\345\220\215\347\247\260:", nullptr));
        label_25->setText(QApplication::translate("frmFormulaSetting", "\350\245\277\346\236\227\347\223\266\346\225\260\351\207\217:", nullptr));
        label_26->setText(QApplication::translate("frmFormulaSetting", "\346\257\215\346\266\262\351\207\217(ml):", nullptr));
        label_27->setText(QApplication::translate("frmFormulaSetting", "\345\215\225\347\223\266\346\257\215\346\266\262\351\207\217(ml):", nullptr));
        label_28->setText(QApplication::translate("frmFormulaSetting", "\347\233\256\346\240\207\351\207\215\351\207\217(g):", nullptr));
        label_42->setText(QApplication::translate("frmFormulaSetting", "\346\221\207\346\231\203\350\247\222\345\272\246(\345\272\246):", nullptr));
        label_43->setText(QApplication::translate("frmFormulaSetting", "\346\221\207\346\231\203\346\254\241\346\225\260\357\274\210\346\254\241\357\274\211:", nullptr));
        label_44->setText(QApplication::translate("frmFormulaSetting", "\347\247\260\351\207\215\350\257\257\345\267\256(g):", nullptr));
        label_45->setText(QApplication::translate("frmFormulaSetting", "\346\212\275\346\260\224\351\207\217(ml):", nullptr));
        label_29->setText(QApplication::translate("frmFormulaSetting", "\346\260\224\346\266\262\344\272\244\346\215\242\346\254\241\346\225\260:", nullptr));
        btnNew->setText(QApplication::translate("frmFormulaSetting", "\346\226\260\345\273\272", nullptr));
        btnModify->setText(QApplication::translate("frmFormulaSetting", "\344\277\256\346\224\271", nullptr));
        btnDel->setText(QApplication::translate("frmFormulaSetting", "\345\210\240\351\231\244", nullptr));
        btnExit->setText(QApplication::translate("frmFormulaSetting", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmFormulaSetting: public Ui_frmFormulaSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMFORMULASETTING_H
