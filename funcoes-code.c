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
    cliente->atendimento = (1+(rand() % 4));
  }
}
