#include "lehfuncao.h"
#include "ui_lehfuncao.h"

using namespace std;

 LehFuncao::LehFuncao(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LehFuncao), Cor(0,0,255)
{
    ui->setupUi(this);
}

LehFuncao::~LehFuncao()
{
    delete ui;
}

void LehFuncao::clear()
{
    ui->lineEdit->clear();
}

void LehFuncao::on_radioAzul_clicked()
{
    Cor = QColor(0,0,255);
}


void LehFuncao::on_radioVermelho_clicked()
{
    Cor = QColor(255,0,0);
}


void LehFuncao::on_radioVerde_clicked()
{
    Cor = QColor(0,255,0);
}


void LehFuncao::on_radioPreto_clicked()
{
    Cor = QColor(0,0,0);
}


void LehFuncao::on_buttonBox_accepted()
{
    emit signIncluirFuncao(ui->lineEdit->text(), Cor);
}

