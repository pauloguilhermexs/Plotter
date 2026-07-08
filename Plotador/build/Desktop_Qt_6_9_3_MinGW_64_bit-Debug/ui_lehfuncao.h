/********************************************************************************
** Form generated from reading UI file 'lehfuncao.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEHFUNCAO_H
#define UI_LEHFUNCAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LehFuncao
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QRadioButton *radioPreto;
    QRadioButton *radioAzul;
    QRadioButton *radioVerde;
    QRadioButton *radioVermelho;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *LehFuncao)
    {
        if (LehFuncao->objectName().isEmpty())
            LehFuncao->setObjectName("LehFuncao");
        LehFuncao->resize(400, 200);
        buttonBox = new QDialogButtonBox(LehFuncao);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 150, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(true);
        gridLayoutWidget = new QWidget(LehFuncao);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(80, 60, 251, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioPreto = new QRadioButton(gridLayoutWidget);
        radioPreto->setObjectName("radioPreto");
        radioPreto->setStyleSheet(QString::fromUtf8("color: rgb(0,0,0);"));

        gridLayout_2->addWidget(radioPreto, 0, 4, 1, 1);

        radioAzul = new QRadioButton(gridLayoutWidget);
        radioAzul->setObjectName("radioAzul");
        radioAzul->setStyleSheet(QString::fromUtf8("color: rgb(0,0,255);"));
        radioAzul->setChecked(true);

        gridLayout_2->addWidget(radioAzul, 0, 0, 1, 1);

        radioVerde = new QRadioButton(gridLayoutWidget);
        radioVerde->setObjectName("radioVerde");
        radioVerde->setStyleSheet(QString::fromUtf8("color: rgb(0,255,0);"));

        gridLayout_2->addWidget(radioVerde, 0, 3, 1, 1);

        radioVermelho = new QRadioButton(gridLayoutWidget);
        radioVermelho->setObjectName("radioVermelho");
        radioVermelho->setStyleSheet(QString::fromUtf8("color: rgb(255,0,0);"));

        gridLayout_2->addWidget(radioVermelho, 0, 2, 1, 1);

        layoutWidget = new QWidget(LehFuncao);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 361, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(LehFuncao);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, LehFuncao, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, LehFuncao, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LehFuncao);
    } // setupUi

    void retranslateUi(QDialog *LehFuncao)
    {
        LehFuncao->setWindowTitle(QCoreApplication::translate("LehFuncao", "Nova fun\303\247\303\243o", nullptr));
        radioPreto->setText(QCoreApplication::translate("LehFuncao", "Preto", nullptr));
        radioAzul->setText(QCoreApplication::translate("LehFuncao", "Azul", nullptr));
        radioVerde->setText(QCoreApplication::translate("LehFuncao", "Verd", nullptr));
        radioVermelho->setText(QCoreApplication::translate("LehFuncao", "Verm", nullptr));
        label->setText(QCoreApplication::translate("LehFuncao", "Nova fun\303\247\303\243o:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LehFuncao: public Ui_LehFuncao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEHFUNCAO_H
