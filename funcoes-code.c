#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"
#include "funcoes.h"

void criaCliente (tcliente *clientes, int minutos, telem *idCli) {
  if (minutos == 0 || (clientes[0].entrada) < minutos) {
    srand( (unsigned)time(NULL) );
    (clientes[0].id) = ++*idCli;
    (clientes[0].entrada) = minutos + (1+(rand() % 4));
    (clientes[0].atendimento) = (1+(rand() % 4));
  }
}
