#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "fila.h"
#include "funcoes.h"
#define TEMPO 20

void main () {
	tfila F;
  tcliente clienteEntrada, clienteAtendimento;
  telem dado, idCli=0, tEntrada, tAtend;
  int i,minutos=0, flagCaixa=0, aux, tamanhoMaximo=0;

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
    printf("TEMPO DO PROGRAMA: %d MINUTO%s\n",minutos, minutos == 1 ? "" : "S");
    ///cria o Cliente
    criaCliente (&clienteEntrada,minutos,&idCli);
    /*if (minutos == 0 || clientes[0].entrada < minutos) {
			clientes[0].id = ++idCli;
			clientes[0].entrada = minutos + (1+(rand() % 4));
      clientes[0].atendimento = (1+(rand() % 4));
    }*/
    printf("CLIENTE: PARA CHEGAR NA FILA:%d(%d,%d)\n", clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);
    ///chegada na fila
    if (clienteEntrada.entrada == minutos ) {
      inserirFila(&F, clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);
    }
   //atendimento no caixa
		if (flagCaixa==0 ) {
			if (!vaziaFila(F)) {
				removerFila(&F,&idCli,&tAtend);
      	clienteAtendimento.id = clienteEntrada.id;
      	clienteAtendimento.atendimento = clienteEntrada.atendimento;
				printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n", clienteAtendimento.id, clienteAtendimento.atendimento);
      	flagCaixa = 1;
			}else {
				printf("CAIXA LIVRE!\n");
			}


    //sair do atendimento e caixa vazio
    } else {
			printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n", clienteAtendimento.id, clienteAtendimento.atendimento);
      clienteAtendimento.atendimento--;
      if (clienteAtendimento.atendimento==0) {
        printf("FIM DO ATENDIMENTO! PROXIMO CLIENTE!\n");
        flagCaixa = 0;
      }
    }
		imprimirFila (F);
		maiorFila(F, &tamanhoMaximo);

    //pausa automatica do programa
    //sleep(2);
		//Pausa manual do programa;
		fflush(stdin);
		printf("Pressione ENTER \n");
		getchar();

  }
    printf("Tamanho maximo da fila: %d clientes", tamanhoMaximo);
}
