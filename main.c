#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"
#define TEMPO 20

void main () {
	tfila F;
  tcliente clientes[2];
  telem dado, idCli=0, tEntrada, tAtend;
  int i,minutos=0, flagCaixa=0, aux;

  printf("\e[H\e[2J");
  criarFila (&F);
  srand(time(NULL));
  //inserirFila(&F, 1, 3, 2);
  //inserirFila(&F, 2, 1, 3);
  //inserirFila(&F, 3, 2, 4);
  //inserirFila(&F, 4, 5, 3);
  //removerFila (&F, &idCli);
  //primeiroFila(F,&idCli);
  //printf ("%d\n",idCli);
  //printf("%d\n",tamanhoFila(F));
  //imprimirFila(F);

  for (i = 0; i < TEMPO; i++,minutos++) {
		printf("\e[H\e[2J");

    //cria o Cliente
    if (minutos == 0 || tEntrada == minutos) {
			clientes[0].id = ++idCli;
			clientes[0].entrada = minutos + (1+(rand() % 4));
      clientes[0].atendimento = (1+(rand() % 4));
    }
    //chegada na fila
    if (clientes[0].entrada == minutos ) {
      inserirFila(&F, clientes[0].id, clientes[0].entrada, clientes[0].atendimento);
    }
    imprimirFila (F);

		/*

   //atendimento no caixa
    if (flagCaixa=0) {
      removerFila(&F,&idCli,&tAtend);
      clientes[1].id = idCli;
      clientes[1].atendimento = tAtend;
      flagCaixa = 1;

    //sair do atendimento e caixa vazio
    } else {
      clientes[1].atendimento--;
      if (clientes[1].atendimento==0) {
        printf("CAIXA VAZIO! PROXIMO CLIENTE!\n");
        flagCaixa = 0;
      }
    }
		*/


    //pausa automatica do programa
    sleep(1);
  }
}
