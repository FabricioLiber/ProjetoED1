#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"
#include "funcoes.h"
#define ENTRADA 5
#define ATENDIMENTO 5

void criaCliente (scliente *C, int minutos) {
  //srand( (unsigned)time(NULL) );
  if (minutos == 0) {
    C->id = 1;
    C->entrada = minutos + (1+(rand() % ENTRADA));
    C->atendimento = (1+(rand() % ATENDIMENTO));
  }
  if (C->entrada < minutos) {
    C->id ++;
    C->entrada = minutos + (1+(rand() % ENTRADA));
    C->atendimento = (1+(rand() % ATENDIMENTO));
  }
}

void entraFila (tfila *F, scliente *C, int minutos) {
  if (C->entrada == minutos ) {
    inserirFila(F,*C);
  }
}

void entraCaixa (tfila *F, scliente *C) {

  removerFila(F,C);
}

void maiorFila(tfila F, int *tamanhoMaximo){
    if (*tamanhoMaximo < tamanhoFila(F))
        *tamanhoMaximo = tamanhoFila(F);
}

void tempoMaximoEspera (scliente clienteAtendimento, scliente *clienteMaximoEspera, int *esperaMaximo, int minutos) {
  if (minutos-clienteAtendimento.entrada > *esperaMaximo) {
      *clienteMaximoEspera = clienteAtendimento;
      *esperaMaximo = (minutos-clienteAtendimento.entrada);
  }
}

void atualizaHora (int minutos) {
    printf("TEMPO DO PROGRAMA - %s%d:%s%d h\n\n", abs(minutos / 60) < 10 ? "0" : "",
            abs(minutos / 60), (minutos % 60) < 10 ? "0" : "", minutos % 60);
}
