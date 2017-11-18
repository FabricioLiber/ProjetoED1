#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "fila.h"
#include "funcoes.h"
#define TEMPO 65

void main () {
	tfila F;
  tcliente clienteEntrada, clienteAtendimento;
  telem dado, idCli=0, tEntrada, tAtend;
  int i,minutos=0, flagCaixa=0, aux;
  printf("\e[H\e[2J");
  criarFila (&F);
  srand(time(NULL));


    for (i = 0; i < TEMPO; i++,minutos++) {
        atualizaHora(minutos);
        printf("\e[H\e[2J");
        printf("TEMPO DO PROGRAMA: %d MINUTO%s\n",minutos, minutos == 1 ? "" : "S");
        ///cria o Cliente
        criaCliente (&clienteEntrada,minutos,&idCli);

        printf("CLIENTE: PARA CHEGAR NA FILA:%d(%d,%d)\n", clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);
        ///chegada na fila
        if (clienteEntrada.entrada == minutos ) {
            //printf("\n\n\n%d\n\n\n", clienteEntrada.entrada);
            inserirFila(&F, clienteEntrada.id, clienteEntrada.entrada, clienteEntrada.atendimento);
        }
       ///atendimento no caixa
        if (flagCaixa == 0) {
            if (!removerFila(&F,&idCli,&tAtend)) {
                clienteAtendimento.id = clienteEntrada.id;
                clienteAtendimento.atendimento = clienteEntrada.atendimento;
                printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n", clienteAtendimento.id, clienteAtendimento.atendimento);
                flagCaixa = 1;
            }else {
                printf("CAIXA LIVRE!\n");
            }
        } else {
            printf ("CAIXA EM ATENDIMENTO: Cliente %d (tempo previsto atendimento %d)\n", clienteAtendimento.id, clienteAtendimento.atendimento);
            clienteAtendimento.atendimento--;
            if (clienteAtendimento.atendimento == 0) {
                printf("FIM DO ATENDIMENTO! PROXIMO CLIENTE!\n");
                flagCaixa = 0;
            }
        }
    imprimirFila (F);

    fflush(stdin);
    printf("Pressione ENTER \n");
    getchar();
    }
}
