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
  int id, tempo;

  removerFila(F,&id,&tempo);
  cAtendimento->id = id;
  cAtendimento->atendimento = tempo;
}
