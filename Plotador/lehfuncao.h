#ifndef LEHFUNCAO_H
#define LEHFUNCAO_H

#include <QDialog>
#include <QString>
#include <QColor>


namespace Ui {
class LehFuncao;
}

class LehFuncao : public QDialog
{
    Q_OBJECT

public:
    explicit LehFuncao(QWidget *parent = nullptr);
    ~LehFuncao();

    // Funcao membro publica clear
    void clear();

signals:

    // Declaracao do SignIncluirFuncao
    void signIncluirFuncao(const QString &Funcao, const QColor &Cor);

private slots:
    void on_radioAzul_clicked();

    void on_radioVermelho_clicked();

    void on_radioVerde_clicked();

    void on_radioPreto_clicked();

    void on_buttonBox_accepted();

private:
    Ui::LehFuncao *ui;

    // Dado membro privado cor
    QColor Cor;

};

#endif // LEHFUNCAO_H
