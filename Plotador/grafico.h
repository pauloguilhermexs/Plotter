#ifndef GRAFICO_H
#define GRAFICO_H

#include <QLabel>
#include <QSize>
#include "evaluator.h"
#include <QColor>
#include <QResizeEvent>


class Grafico : public QLabel
{
    Q_OBJECT

public:
    explicit Grafico(QWidget *parent = nullptr); // Incluir como parametro o pai do widget
    inline bool empty() {return eval.empty();} //Retorna true se o vetor de funcoes esta vazio
    inline size_t size(){return eval.size();} // Retorna o numero de funcoes a serem plotadas
    const Evaluator& getEval(int i); // Retorna uma referencia constante ao i-esimo evaluador atualmente definido
    const QColor& getCor(int i);// Retorna uma referencia constante a i-esima cor de plotagem atualmente definida
    void pushFuncao(QString Funcao, QColor Cor); // Acrescenta uma nova funcao, com sua respectiva cor de plotagem
    void clearFuncoes(); // Limpa, os vetores evaluadores e de cores de plotagem
    void setLimites(int MinX, int MaxX, int ExpX, int MinY, int MaxY, int ExpY); // altera os limites e o numero de marcadores do grafico
    void desenharGrafico(); // Plota o grafico das funcoes atualmente definidas

signals:
    void signGraficoClicked(const double& X, const double& Y); // Novo sinal

private:

    // movidas da MainPlotador(mainplotador.h)
   inline double convXtoJ(double X) const{return ((largura-1)*(X-minX)/(maxX-minX));} //converte o valor X para coordenada J (coluna).
   inline double convYtoI(double Y) const{return ((altura-1)*(maxY-Y)/(maxY-minY));} //converte o valor Y para coordenada I (linha).
   inline double convJtoX(double J) const{return (minX+(maxX-minX)*J/(largura-1));} //converte coordenada J (coluna) para valor X.
   inline double convItoY(double I) const{return (maxY-(maxY-minY)*I/(altura-1));} //converte coordenada I (linha) para valor Y.
    std::vector<Evaluator> eval; //o vetor de evaluadores de funçoes.
    std::vector<QColor> cor; //o vetor de cores a serem usadas nas curvas do grafico.
    QPixmap img;  // ESSE DADO MEMRBO PRIVADO NAO TINHA ANTES EM MAINPLOTADOR, DE ACORDO COM A ESPECIFICACAO
    int largura,altura; //dimensoes da imagem onde serah desenhado o grafico.
    double minX,maxX,minY,maxY; //os limites dos eixos do grafico.
    int nMarcX,nMarcY; //o numero de marcadores nos eixos do grafico.

    void resizeEvent(QResizeEvent *event) override; // funcao resizeEvent
    void mouseReleaseEvent(QMouseEvent *event) override;  // Nova funcao privada



};

#endif // GRAFICO_H
