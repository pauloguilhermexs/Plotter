#ifndef MAINPLOTADOR_H
#define MAINPLOTADOR_H

#include <QMainWindow>
#include "evaluator.h"
#include "lehfuncao.h"
#include "grafico.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainPlotador;
}
QT_END_NAMESPACE

class MainPlotador : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPlotador(QWidget *parent = nullptr);
    ~MainPlotador();

private slots:
    void on_actionFun_o_triggered();

    void on_actionApagar_triggered();

    void on_actionSair_triggered();

    void on_spinMinX_valueChanged(int arg1);

    void on_spinMaxX_valueChanged(int arg1);

    void on_spinMinY_valueChanged(int arg1);

    void on_spinMaxY_valueChanged(int arg1);

    void on_spinExpX_valueChanged(int arg1);

    void on_spinExpY_valueChanged(int arg1);

    void on_pushApagar_clicked();

    void slotIncluirFuncao(const QString &Funcao, const QColor &Cor); // Novo slot privado

    void slotGraficoClicked(const double& X, const double& Y);

private:
    Ui::MainPlotador *ui;

    Grafico* grafico; // ponteiro para um objeto da classe de exibicao de graficos
    void exibirFuncoes(); //exibe a lista de funçoes a serem plotadas.
    inline void desenharGrafico(){grafico->desenharGrafico();} // desenha o grafico com as funçoes.

    LehFuncao* lehFuncao; //um ponteiro para um objeto da classe de leitura de funçoes.



};
#endif // MAINPLOTADOR_H
