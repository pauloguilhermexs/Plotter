#include "grafico.h"
#include <QPen>
#include <QPainter>


using namespace std;

 Grafico::Grafico(QWidget *parent): QLabel(parent), eval(), cor(), img(), largura(0), altura(0), minX(0.0), maxX(0.0), minY(0.0), maxY(0.0), nMarcX(0), nMarcY(0)
{

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // modificar politica de redimensionamento para QSizePolicy::Expanding
    setMinimumSize(540,540); // tamanho minimo
    setFrameShape(QFrame::Box); // forma da moldura
    setFrameShadow( QFrame::Plain); // sombra da moldura
    setAlignment(Qt::AlignCenter); // Alinhamento(tanto horizontal quanto vertical)

}

const Evaluator &Grafico::getEval(int i)
{
    return eval.at(i); // gera excecao em caso de indice invalido
}

const QColor &Grafico::getCor(int i)
{
    return cor.at(i); // gera excecao em caso de indice invalido
}

void Grafico::pushFuncao(QString Funcao, QColor Cor)
{
    try
    {
        Evaluator new_eval;
        new_eval.set(Funcao.toStdString());
        eval.push_back(new_eval);
        cor.push_back(Cor);
    }
    catch (const std::exception& e)
    {
        throw;
    }
}

void Grafico::clearFuncoes()
{
    eval.clear(); // chama clear
    cor.clear(); // chama clear
}

void Grafico::setLimites(int MinX, int MaxX, int ExpX, int MinY, int MaxY, int ExpY)
{
    // calcular limite do grafico de acordo com os parametros
    minX = MinX * pow(10.0, ExpX);
    maxX = MaxX * pow(10.0, ExpX);
    minY = MinY * pow(10.0, ExpY);
    maxY = MaxY * pow(10.0, ExpY);
    // Calcular o numero de marcadores do grafico de acordo com os parametros
    nMarcX = 1+MaxX-MinX;
    nMarcY = 1+MaxY-MinY;

}

void Grafico::desenharGrafico()
{
    QPen pen; //Criar uma caneta
    QPainter painter; // Criar um desenhador
    largura = width(); // Fazer dado membro largura ser igual a width
    altura =height(); // Fazer dado membro altura ser igual a height
    QPixmap img(largura, altura); // Criar uma imagem de dimensoes largura e altura

    img.fill(Qt::white); // Preencher img com cor branca
    painter.begin(&img); // Inciar desenho

    // Configurar a caneta para os eixos(preto,3px de largura)
    pen.setColor(Qt::black);
    pen.setWidth(3);
    //painter.setPen(Qt::black, 3);
    painter.setPen(pen);

    double Izero = convYtoI(0.0);

    if(Izero >=0.0 && Izero <=altura-1.0)
    {
        // Desenhar o eixo X
        QLineF lineX(0.0, Izero, largura - 1.0, Izero);
        painter.drawLine(lineX);

        for(int i = 0; i<nMarcX-1; ++i)
        {
            double Jmarc = convXtoJ(minX + (maxX-minX)*i/(nMarcX-1.0)); // Calcular coordenada Jmarc
            QLineF marcador(Jmarc, Izero-3.0, Jmarc, Izero+3.0); // Tracar linha
            painter.drawLine(marcador);
        }
    }

    double Jzero= convXtoJ(0.0);

    if(Jzero >=0.0 && Jzero <= largura-1.0)
    {
        // Desenhar o eixo Y
        QLineF lineY(Jzero, 0.0, Jzero, altura - 1.0);
        painter.drawLine(lineY);

        for(int i = 0; i<nMarcY; ++i)
        {
            double Imarc = convYtoI(minY + (maxY - minY) * i / (nMarcY - 1.0)); // Calcular coordenada Imarc
            QLineF marcador(Jzero - 3.0, Imarc, Jzero + 3.0, Imarc); // Tracar linha
            painter.drawLine(marcador);
        }
    }

    if(eval.empty())
    {
        // Nao ha funcoes, finalizar e exibir apenas os eixos
        painter.end();
        setPixmap(img);
        return;
    }

    double X, Y, I, Iant; // Variaveis para desenhar curvas

    pen.setWidth(1); // // Configurar caneta

    for(int k = 0; k < static_cast<int>(eval.size()); ++k)
    {
        // Fixar caneta
        pen.setColor(cor.at(k));
        painter.setPen(pen);

        Iant = -1.0; //Atribuir -1.0

        for(int j = 0; j < largura-1; ++j)
        {
            X = convJtoX(j); // Calcular valor de X
            Y = eval.at(k)(X); //Calcular valor de Y
            I = convYtoI(Y); // Calcular coordenada linha I

            if(Iant >= 0.0 && Iant <= altura - 1.0 && I >= 0.0 && I <= altura - 1.0 && j > 0) // Verificar se I e Iant estao dentro dos limites
            {
                // Desenhar uma linha
                QLineF line(j - 1, Iant, j, I);
                painter.drawLine(line);
            }

            Iant = I;

        }
    }

    painter.end(); // concluir o desenhador
    setPixmap(img); // exibir o objeto
}

void Grafico::resizeEvent(QResizeEvent *event)
{

    if(event->oldSize() != event->size())
    desenharGrafico();

}

void Grafico::mouseReleaseEvent(QMouseEvent *event)
{
    QPointF posicao = event->position();
    emit signGraficoClicked(convJtoX(posicao.x()),convItoY(posicao.y()));
}
