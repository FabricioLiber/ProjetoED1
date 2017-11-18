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
  int i,minutos=0, flagCaixa=0, aux;

  printf("\e[H\e[2J");
  criarFila (&F);
  srand(time(NULL));

  for (i = 0; i < TEMPO; i++,minutos++) {
    printf("\e[H\e[2J");
    printf("TEMPO DO PROGRAMA: %d MINUTO%s\n",minutos, minutos == 1 ? "" : "S");

    ///cria o Cliente
    criaCliente (&clienteEntrada,minutos,&idCli);
    printf("CLIENTE: PARA CHEGAR NA FILA:%d(%d,%d)\n", clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);

    ///entrada na fila
		entraFila (&F,&clienteEntrada,minutos);

   //atendimento no caixa
		if (flagCaixa==0 ) {
			if (!vaziaFila(F)) {
				entraCaixa (&F,&clienteAtendimento);
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

    //pausa automatica do programa
    //sleep(2);
		//Pausa manual do programa;
		fflush(stdin);
		printf("\nPressione ENTER \n");
		getchar();

  }
}
