void criaCliente (scliente *C, int minutos);
int entraFila (tfila *F, scliente *C, int minutos);
int entraCaixa (tfila *F, scliente *C, int *flagCaixa);
void maiorFila(tfila F, int *tamanhoMaximo);
void tempoMaximoEspera (scliente clienteAtendimento, scliente *clienteMaximoEspera, int *esperaMaximo, int minutos);
void atualizaHora (int minutos);
