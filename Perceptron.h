#include <iostream>
#include <cstdlib>

using namespace std;

class Perceptron
{
public:

    int epoca;
    int maximoDeEpocasPermitido;
    int numeroDePesos;
    double *vetorDePesos;
    double taxaDeAprendizagem;
    double bias;
    int numeroDeParesDeEntradas;
    double **matrizDeEntradas;
    double *vetorDeSaidasEsperadas;

    Perceptron();
    void inicializarVariaveisInternas();
    void inicializarVetorDeSaidasEsperadas();
    void inicializarMatrizDeEntradas();
    void treinar();
    double atingiuLimiar(double,double);
    void corrigirPeso(int, double);
    void testar();
    void print();
};
