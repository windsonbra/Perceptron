#include "Perceptron.h"

Perceptron::Perceptron()
{
    inicializarVariaveisInternas();
};

void Perceptron::inicializarVariaveisInternas()
{

    epoca=0;
    maximoDeEpocasPermitido=1000;

    numeroDePesos=2;

    vetorDePesos=new double[numeroDePesos];

    taxaDeAprendizagem=1;

    srand (time(NULL));

    bias=((rand() % 1000000 + 1)/1000000.000000);

    //inicializa vetor de pesos aleatoriamente
    for(int i=0; i<numeroDePesos; i++)
    {
        vetorDePesos[i]=((rand() % 1000000 + 1)/1000000.000000);
    }

    numeroDeParesDeEntradas=4;

    inicializarMatrizDeEntradas();
    inicializarVetorDeSaidasEsperadas();
};



void Perceptron::inicializarMatrizDeEntradas()
{
    matrizDeEntradas=new double*[numeroDeParesDeEntradas];

    for(int i=0; i<numeroDeParesDeEntradas; i++)
    {
        matrizDeEntradas[i]=new double[2];
    }

    matrizDeEntradas[0][0]=0; // entrada 1
    matrizDeEntradas[0][1]=0; // entrada 2

    matrizDeEntradas[1][0]=0; // entrada 1
    matrizDeEntradas[1][1]=1; // entrada 2

    matrizDeEntradas[2][0]=1; // entrada 1
    matrizDeEntradas[2][1]=0; // entrada 2

    matrizDeEntradas[3][0]=1; // entrada 1
    matrizDeEntradas[3][1]=1; // entrada 2

}

void Perceptron::inicializarVetorDeSaidasEsperadas()
{
    vetorDeSaidasEsperadas=new double[numeroDeParesDeEntradas];

    vetorDeSaidasEsperadas[0]=0; //Saída para entrada (0,0)
    vetorDeSaidasEsperadas[1]=0; //Saída para entrada (1,0)
    vetorDeSaidasEsperadas[2]=0; //Saída para entrada (0,1)
    vetorDeSaidasEsperadas[3]=1; //Saída para entrada (1,1)
    //Todas as saída formam uma porta AND
}

void Perceptron::treinar()
{
    //flag para saber se treinou
    bool treinou=true;
    //variavel que recebe o valor da saida do limiar
    double saidaDoLimiar;

    for(int i=0;i<numeroDeParesDeEntradas;i++) {
        //A saída recebe o resultado
        saidaDoLimiar = atingiuLimiar(matrizDeEntradas[i][0],matrizDeEntradas[i][1]);

        if(saidaDoLimiar !=vetorDeSaidasEsperadas[i]) {
            corrigirPeso(i,saidaDoLimiar);
            treinou=false;
        }
    }
    print();
    epoca++;

    if((treinou == false) && (epoca < maximoDeEpocasPermitido)) {
            // chamada recursiva do método
            treinar();

    }
}


double Perceptron::atingiuLimiar(double x1,double x2)
{
    double somatorio = x1*vetorDePesos[0] + x2*vetorDePesos[1] + bias;

    if(somatorio>0)
        return somatorio;
    else
        return 0;
}

void Perceptron::corrigirPeso(int i, double somatorio) {
    vetorDePesos[0] = vetorDePesos[0] + (taxaDeAprendizagem * (vetorDeSaidasEsperadas[i] - somatorio) * matrizDeEntradas[i][0]);
    vetorDePesos[1] = vetorDePesos[1] + (taxaDeAprendizagem * (vetorDeSaidasEsperadas[i] - somatorio) * matrizDeEntradas[i][1]);
    bias = bias + (taxaDeAprendizagem * (vetorDeSaidasEsperadas[i] - somatorio));
}

void Perceptron::testar()
{
    cout << "\n\nTeste:\n";
    cout << "Entrada (0,0): " << atingiuLimiar(0,0) << endl;
    cout << "Entrada (0,1): " << atingiuLimiar(0,1) << endl;
    cout << "Entrada (1,0): " << atingiuLimiar(1,0) << endl;
    cout << "Entrada (1,1): " << atingiuLimiar(1,1) << endl;

    cout << "Numero de epocas: " << epoca << endl;

}

void Perceptron::print() {
    cout << "-----------------\n";
    cout << "Epoca: " << epoca << endl;
    cout << "Bias: " << bias << endl;
    cout << "Peso w1: " << vetorDePesos[0] << endl;
    cout << "Peso w2: " << vetorDePesos[1] << endl;
    cout << "-----------------\n";

}
