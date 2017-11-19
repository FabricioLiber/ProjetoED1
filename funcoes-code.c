#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"
#include "funcoes.h"

void criaCliente (tcliente *cliente, int minutos, telem *idCli) {
  if (minutos == 0 || cliente->entrada < minutos) {
    srand( (unsigned)time(NULL) );
    cliente->id = ++*idCli;
    cliente->entrada = minutos + (1+(rand() % 4));
    cliente->atendimento = (1+(rand() % 10));
  }
}

void entraFila (tfila *F, tcliente *cliente, int minutos) {
  if (cliente->entrada == minutos ) {
    inserirFila(F, cliente->id, cliente->entrada, cliente->atendimento);
  }
}

void entraCaixa (tfila *F, tcliente *cAtendimento) {
  int id, tAtend, tEntrada;

  removerFila(F,&id,&tAtend, &tEntrada);
  cAtendimento->id = id;
  cAtendimento->atendimento = tAtend;
  cAtendimento->entrada = tEntrada;
}

void maiorFila(tfila F, int *tamanhoMaximo){
    if (*tamanhoMaximo < tamanhoFila(F))
        *tamanhoMaximo = tamanhoFila(F);
}

int tempoMaximoEspera (int clienteAtendimento, int clienteMaximoEspera) {
    if (clienteAtendimento > clienteMaximoEspera)
        return 1;
    return 0;
}

void atualizaHora (int minutos) {
    printf("TEMPO DO PROGRAMA - %s%d:%s%d h\n\n", abs(minutos / 60) < 10 ? "0" : "",
            abs(minutos / 60), (minutos % 60) < 10 ? "0" : "", minutos % 60);
}
