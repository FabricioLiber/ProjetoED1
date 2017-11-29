#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "funcoes.h"
#define TEMPO 720

int main () {
    /// Criação da fila
    tfila F;

    /// Criação de variáveis (clientes) para controle
    scliente clienteEntrada, clienteAtendimento, clienteMaximoEspera;

    /// Variáveis auxiliares
    int i,minutos = 0, flagCaixa = 0, tamanhoMaximo = 0, esperaMaximo = 0;

    /// Limpa a tela
    system("cls");

    criarFila (&F);
    srand(time(NULL));

    for (i = 0; i < TEMPO; i ++, minutos ++) {
        system("cls");
        atualizaHora(minutos);

        ///cria o Cliente
        criaCliente(&clienteEntrada, minutos);
        ///entrada na fila
        entraFila(&F, &clienteEntrada, minutos);

        ///atendimento no caixa
        if (flagCaixa == 0) {
            if (!vaziaFila(F)) {
                entraCaixa (&F, &clienteAtendimento);
                flagCaixa = 1;
                tempoMaximoEspera(clienteAtendimento, &clienteMaximoEspera, &esperaMaximo, minutos);
                printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n",
                        clienteAtendimento.id, clienteAtendimento.atendimento);
            }else {
                printf("CAIXA LIVRE!\n");
            }
        ///sair do atendimento e caixa vazio
        } else {
            clienteAtendimento.atendimento--;
            if (clienteAtendimento.atendimento == 0) {
                printf("FIM DO ATENDIMENTO AO CLIENTE %d! PROXIMO CLIENTE!\n", clienteAtendimento.id);
                flagCaixa = 0;
            } else {
                printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n",
                    clienteAtendimento.id, clienteAtendimento.atendimento);
            }
        }
        ///Imprime  a fila com os clientes na espera
        imprimirFila (F);
        ///Calcula maior tamanho que a fila teve
        maiorFila(F, &tamanhoMaximo);
        ///pausa automatica do programa
        ///sleep(1);
        ///Pausa manual do programa
        fflush(stdin);
        printf("\nPressione ENTER \n");
        getchar();
    }
    /// Apresentação do maior tamanho da fila
    printf("Tamanho maximo da fila: %d clientes\n", tamanhoMaximo);

    /// Apresentação do cliente com a maior espera
    if (esperaMaximo) {
        printf("Cliente %d (%d, %d), Maior espera %d minutos\n", clienteMaximoEspera.id,
               clienteMaximoEspera.entrada, clienteMaximoEspera.atendimento, esperaMaximo);
    } else {
        printf("Nao houve espera por parte dos clientes!!\n");
    }
    return 0;
}
