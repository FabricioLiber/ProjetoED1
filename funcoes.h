//#include "fila.h"

/*typedef struct scliente {
  int id;
  int entrada;
  int atendimento;
} scliente;*/


void criaCliente (scliente *C, int minutos);
void entraFila (tfila *F, scliente *C, int minutos);
void entraCaixa (tfila *F, scliente *C);
void maiorFila(tfila F, int *tamanhoMaximo);
void tempoMaximoEspera (scliente clienteAtendimento, scliente *clienteMaximoEspera, int *esperaMaximo, int minutos);
void atualizaHora (int minutos);
