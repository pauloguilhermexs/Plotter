/********************************************************************************
** Form generated from reading UI file 'mainplotador.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPLOTADOR_H
#define UI_MAINPLOTADOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPlotador
{
public:
    QAction *actionFun_o;
    QAction *actionApagar;
    QAction *actionSair;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableFuncoes;
    QFrame *line1;
    QGridLayout *gridLimites;
    QSpinBox *spinExpY;
    QLabel *labelMax;
    QSpinBox *spinMaxY;
    QLabel *labelEixo;
    QLabel *labelExp;
    QSpinBox *spinMaxX;
    QLabel *labelX;
    QLabel *labelMin;
    QSpinBox *spinMinY;
    QSpinBox *spinExpX;
    QSpinBox *spinMinX;
    QLabel *labelY;
    QFrame *line2;
    QPushButton *pushApagar;
    QMenuBar *menubar;
    QMenu *menuPlotagem;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainPlotador)
    {
        if (MainPlotador->objectName().isEmpty())
            MainPlotador->setObjectName("MainPlotador");
        MainPlotador->resize(800, 601);
        actionFun_o = new QAction(MainPlotador);
        actionFun_o->setObjectName("actionFun_o");
        actionApagar = new QAction(MainPlotador);
        actionApagar->setObjectName("actionApagar");
        actionSair = new QAction(MainPlotador);
        actionSair->setObjectName("actionSair");
        centralwidget = new QWidget(MainPlotador);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(190, 540));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        tableFuncoes = new QTableWidget(frame);
        if (tableFuncoes->columnCount() < 2)
            tableFuncoes->setColumnCount(2);
        tableFuncoes->setObjectName("tableFuncoes");
        tableFuncoes->setTabKeyNavigation(false);
        tableFuncoes->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        tableFuncoes->setColumnCount(2);
        tableFuncoes->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableFuncoes);

        line1 = new QFrame(frame);
        line1->setObjectName("line1");
        line1->setFrameShape(QFrame::Shape::HLine);
        line1->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line1);

        gridLimites = new QGridLayout();
        gridLimites->setObjectName("gridLimites");
        spinExpY = new QSpinBox(frame);
        spinExpY->setObjectName("spinExpY");
        spinExpY->setMinimum(-9);
        spinExpY->setMaximum(9);

        gridLimites->addWidget(spinExpY, 2, 3, 1, 1);

        labelMax = new QLabel(frame);
        labelMax->setObjectName("labelMax");
        labelMax->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelMax, 0, 2, 1, 1);

        spinMaxY = new QSpinBox(frame);
        spinMaxY->setObjectName("spinMaxY");
        spinMaxY->setMinimum(-8);
        spinMaxY->setMaximum(9);
        spinMaxY->setValue(9);

        gridLimites->addWidget(spinMaxY, 2, 2, 1, 1);

        labelEixo = new QLabel(frame);
        labelEixo->setObjectName("labelEixo");
        labelEixo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelEixo, 0, 0, 1, 1);

        labelExp = new QLabel(frame);
        labelExp->setObjectName("labelExp");
        labelExp->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelExp, 0, 3, 1, 1);

        spinMaxX = new QSpinBox(frame);
        spinMaxX->setObjectName("spinMaxX");
        spinMaxX->setMinimum(-8);
        spinMaxX->setMaximum(9);
        spinMaxX->setValue(9);

        gridLimites->addWidget(spinMaxX, 1, 2, 1, 1);

        labelX = new QLabel(frame);
        labelX->setObjectName("labelX");
        labelX->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelX, 1, 0, 1, 1);

        labelMin = new QLabel(frame);
        labelMin->setObjectName("labelMin");
        labelMin->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelMin, 0, 1, 1, 1);

        spinMinY = new QSpinBox(frame);
        spinMinY->setObjectName("spinMinY");
        spinMinY->setMinimum(-9);
        spinMinY->setMaximum(8);
        spinMinY->setValue(-9);

        gridLimites->addWidget(spinMinY, 2, 1, 1, 1);

        spinExpX = new QSpinBox(frame);
        spinExpX->setObjectName("spinExpX");
        spinExpX->setMinimum(-9);
        spinExpX->setMaximum(9);

        gridLimites->addWidget(spinExpX, 1, 3, 1, 1);

        spinMinX = new QSpinBox(frame);
        spinMinX->setObjectName("spinMinX");
        spinMinX->setMinimum(-9);
        spinMinX->setMaximum(8);
        spinMinX->setValue(-9);

        gridLimites->addWidget(spinMinX, 1, 1, 1, 1);

        labelY = new QLabel(frame);
        labelY->setObjectName("labelY");
        labelY->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLimites->addWidget(labelY, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLimites);

        line2 = new QFrame(frame);
        line2->setObjectName("line2");
        line2->setFrameShape(QFrame::Shape::HLine);
        line2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line2);

        pushApagar = new QPushButton(frame);
        pushApagar->setObjectName("pushApagar");

        verticalLayout->addWidget(pushApagar);


        horizontalLayout->addWidget(frame);

        MainPlotador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainPlotador);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuPlotagem = new QMenu(menubar);
        menuPlotagem->setObjectName("menuPlotagem");
        MainPlotador->setMenuBar(menubar);
        statusbar = new QStatusBar(MainPlotador);
        statusbar->setObjectName("statusbar");
        MainPlotador->setStatusBar(statusbar);

        menubar->addAction(menuPlotagem->menuAction());
        menuPlotagem->addAction(actionFun_o);
        menuPlotagem->addAction(actionApagar);
        menuPlotagem->addSeparator();
        menuPlotagem->addAction(actionSair);

        retranslateUi(MainPlotador);

        QMetaObject::connectSlotsByName(MainPlotador);
    } // setupUi

    void retranslateUi(QMainWindow *MainPlotador)
    {
        MainPlotador->setWindowTitle(QCoreApplication::translate("MainPlotador", "Plotador de fun\303\247\303\265es", nullptr));
        actionFun_o->setText(QCoreApplication::translate("MainPlotador", "Fun\303\247\303\243o...", nullptr));
        actionApagar->setText(QCoreApplication::translate("MainPlotador", "Apagar", nullptr));
        actionSair->setText(QCoreApplication::translate("MainPlotador", "Sair", nullptr));
        labelMax->setText(QCoreApplication::translate("MainPlotador", "Max", nullptr));
        labelEixo->setText(QCoreApplication::translate("MainPlotador", "EIXO", nullptr));
        labelExp->setText(QCoreApplication::translate("MainPlotador", "Exp", nullptr));
        labelX->setText(QCoreApplication::translate("MainPlotador", "X", nullptr));
        labelMin->setText(QCoreApplication::translate("MainPlotador", "Min", nullptr));
        labelY->setText(QCoreApplication::translate("MainPlotador", "Y", nullptr));
        pushApagar->setText(QCoreApplication::translate("MainPlotador", "APAGAR", nullptr));
        menuPlotagem->setTitle(QCoreApplication::translate("MainPlotador", "Plotagem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPlotador: public Ui_MainPlotador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPLOTADOR_H
