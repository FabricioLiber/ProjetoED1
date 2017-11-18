#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "fila.h"
#include "funcoes.h"

void criaCliente (tcliente *cliente, int minutos, telem *idCli) {
  if (minutos == 0 || cliente->entrada < minutos) {
    srand( (unsigned)time(NULL) );
    cliente->id = ++*idCli;
    cliente->entrada = minutos + (1+(rand() % 4));
    cliente->atendimento = (1+(rand() % 4));
  }
}

void atualizaHora (minutos) {
    printf("%s%d:%s%d\n\n", abs((minutos + 420) / 60) < 10 ? "0" : "",
            abs((minutos + 420) / 60), (minutos % 60) < 10 ? "0" : "", minutos % 60);
}

tcliente tempoMaximoEspera (tcliente clienteAtendimento, tcliente clienteMaximoEspera, int minutos) {
    minutos - clienteAtendimento.entrada > clienteMaximoEspera.atendimento
}
