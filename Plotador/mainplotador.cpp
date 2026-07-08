#include "mainplotador.h"
#include "ui_mainplotador.h"
#include <QMessageBox>

using namespace std;

 MainPlotador::MainPlotador(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPlotador), grafico(new Grafico(this)), lehFuncao(new LehFuncao(this))
{

    ui->setupUi(this);
    grafico->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->horizontalLayout->insertWidget(0, grafico);  // inserir objeto para o qual grafico aponta

   // conecoes de sinais
    connect(lehFuncao, &LehFuncao::signIncluirFuncao, this, &MainPlotador::slotIncluirFuncao);
    connect(grafico, &Grafico::signGraficoClicked, this, &MainPlotador::slotGraficoClicked);

    //mudanca da politica de redimensionamento

    ui->tableFuncoes->setStyleSheet("QHeaderView::section {background-color:lightgray}");
    ui->tableFuncoes->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableFuncoes->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);

   // fixar o texto do cabeçalho das 2 colunas como sendo “COR” E “FUNCAO”:
    ui->tableFuncoes->setHorizontalHeaderLabels(QStringList() << "COR" << "FUNCAO");

    grafico->setLimites(ui->spinMinX->value(), ui->spinMaxX->value(), ui->spinExpX->value(), ui->spinMinY->value(), ui->spinMaxY->value(), ui->spinExpY->value()); // Substituicao de atribuicao do valores iniciais dos limites

    MainPlotador::desenharGrafico(); // chamar desenharGrafico de mainPlotador

}

MainPlotador::~MainPlotador()
{
    delete ui;

}

void MainPlotador::on_actionFun_o_triggered()
{
    lehFuncao->clear(); //limpa eventual conteudo anterior da janela de digitacao de funcao
    lehFuncao->show(); // exibe diálogo para digitar nova funcao
}


void MainPlotador::on_actionApagar_triggered()
{
    on_pushApagar_clicked(); // executa a mesma acao do botao apagar
}


void MainPlotador::on_actionSair_triggered()
{
    QCoreApplication::quit(); // fecha aplicativo
}


void MainPlotador::on_spinMinX_valueChanged(int arg1)
{
    grafico->setLimites(arg1, ui->spinMaxX->value(), ui->spinExpX->value(), ui->spinMinY->value(), ui->spinMaxY->value(), ui->spinExpY->value()); // Usando setLimites do grafico
    ui->spinMaxX->setMinimum(arg1 + 1);  // O valor maximo do eixo X tem que ser maior que o valor minimo
    desenharGrafico(); // Redesenha a imagem do grafico
}


void MainPlotador::on_spinMaxX_valueChanged(int arg1)
{
    grafico->setLimites(ui->spinMinX->value(), arg1, ui->spinExpX->value(), ui->spinMinY->value(), ui->spinMaxY->value(), ui->spinExpY->value()); // Usando setLimites do grafico

    ui->spinMinX->setMaximum(arg1 - 1); // O valor maximo do eixo X tem que ser maior que o valor minimo
    desenharGrafico(); //Redesenha a imagem do grafico
}

void MainPlotador::on_spinMinY_valueChanged(int arg1)
{
    grafico->setLimites( ui->spinMinX->value(), ui->spinMaxX->value(), ui->spinExpX->value(), arg1, ui->spinMaxY->value(), ui->spinExpY->value()); // Usando setLimites do grafico
    ui->spinMaxY->setMinimum(arg1 + 1); // O valor maximo do eixo Y tem que ser maior que o valor minimo
    desenharGrafico(); // Redesenha a imagem do grafico
}


void MainPlotador::on_spinMaxY_valueChanged(int arg1)
{
    grafico->setLimites( ui->spinMinX->value(), ui->spinMaxX->value(), ui->spinExpX->value(), ui->spinMinY->value(), arg1, ui->spinExpY->value()); // Usando setLimites do grafico
    ui->spinMinY->setMaximum(arg1 - 1);  // O valor maximo do eixo Y tem que ser maior que o valor minimo
    desenharGrafico(); // Redesenha a imagem do grafico
}

void MainPlotador::on_spinExpX_valueChanged(int arg1)
{
    grafico->setLimites(ui->spinMinX->value(),  ui->spinMaxX->value(), arg1, ui->spinMinY->value(), ui->spinMaxY->value(), ui->spinExpY->value()); // Usando setLimites do grafico
    desenharGrafico(); // Redesenha a imagem do grafico
}

void MainPlotador::on_spinExpY_valueChanged(int arg1)
{ 
    grafico->setLimites(ui->spinMinX->value(), ui->spinMaxX->value(), ui->spinExpX->value(), ui->spinMinY->value(), ui->spinMaxY->value(), arg1); // Usando setLimites do grafico
    desenharGrafico(); // Redesenha a imagem do grafico
}

void MainPlotador::on_pushApagar_clicked()
{
    grafico->clearFuncoes();
    exibirFuncoes(); // Reexibir a lista de funcoes
    desenharGrafico(); // Redenhar o grafico
}

void MainPlotador::slotIncluirFuncao(const QString &Funcao, const QColor &Cor)
{
    try
    {
        grafico->pushFuncao(Funcao, Cor);
        exibirFuncoes(); // Chamando a funcao exibirFuncoes

        desenharGrafico(); // Chamando a funcao desenharGrafico
    }
    catch(const invalid_argument &e)  // em caso de erro
    {
        QMessageBox::critical(this, "Funcao invalida", "Erro na funcao: " + QString::fromStdString(e.what()));
    }
}

void MainPlotador::slotGraficoClicked(const double &X, const double &Y)
{
    QString coordenadas = QString("X=%1 Y=%2").arg(X, 0, 'f', 4).arg(Y, 0, 'f', 4);
    statusBar()->showMessage(coordenadas, 2000);
}


void MainPlotador::exibirFuncoes()
{

    ui->tableFuncoes->clearContents(); // Apagar conteudo anterior da tabela de funcoes
    ui->tableFuncoes->setRowCount(grafico->size()); // Fixar o numero de linhas da tabela de funcoes


    QLabel * prov; // ponteiro para rotulo
    QPixmap img(20,20); // imagem pixmap de tamanho 20x20

    for(int k = 0; k < static_cast<int>(grafico->size()); ++k)
    {

       img.fill(grafico->getCor(k)); // Preencher a imagem com a k-esima cor
       prov = new QLabel(); // Alocar dinamicamente um novo Qlabel
       prov->setAlignment(Qt::AlignCenter); // Alterar o alinhamento
       prov->setPixmap(img); // Alterar a imagem
       ui->tableFuncoes->setCellWidget(k, 0, prov); // Fixar widget
       prov = new QLabel(); //Alocar dinamicamente mais uma vez
       prov->setAlignment(Qt::AlignCenter | Qt::AlignLeft); //Alterar alinhamento
       prov->setWordWrap(true); // Alterar QLabel
       prov->setText(QString::fromStdString(grafico->getEval(k).getText())); // Alterar o texto
       ui->tableFuncoes->setCellWidget(k ,1,prov); // Fixar widget
    }
}

