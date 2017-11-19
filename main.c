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
  tcliente clienteEntrada, clienteAtendimento, clienteMaiorEspera;
  telem dado, idCli=0, tEntrada, tAtend;
  int i,minutos=0, flagCaixa=0, aux, tamanhoMaximo = 0, esperaMaximo = 0;

  printf("\e[H\e[2J");
  criarFila (&F);
  srand(time(NULL));

  for (i = 0; i < TEMPO; i++,minutos++) {
    printf("\e[H\e[2J");
    atualizaHora (minutos);

    ///cria o Cliente
    criaCliente (&clienteEntrada,minutos,&idCli);
    printf("CLIENTE: PARA CHEGAR NA FILA:%d(%d,%d)\n", clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);

    ///entrada na fila
		entraFila (&F,&clienteEntrada,minutos);

   //atendimento no caixa
		if (flagCaixa==0 ) {
			if (!vaziaFila(F)) {
				entraCaixa (&F,&clienteAtendimento);
				if (tempoMaximoEspera(minutos - clienteAtendimento.entrada, esperaMaximo)) {
                    clienteMaiorEspera = clienteAtendimento;
                    esperaMaximo = minutos - clienteAtendimento.entrada;
				}
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
        printf("FILA: ");
		imprimirFila (F);
		///calcular maior tamanho que a fila teve
		maiorFila(F, &tamanhoMaximo);

    //pausa automatica do programa
    //sleep(2);
		//Pausa manual do programa;
		fflush(stdin);
		printf("\nPressione ENTER \n");
		getchar();

  }
    printf("Tamanho maximo da fila: %d clientes\n", tamanhoMaximo);
    printf("Cliente %d (%d, %d), Maior espera %d minutos", clienteMaiorEspera.id,
            clienteMaiorEspera.entrada, clienteMaiorEspera.atendimento, esperaMaximo);
}
