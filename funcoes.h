void criaCliente (tcliente *cliente, int minutos, telem *idCli);
void entraFila (tfila *F, tcliente *cliente, int minutos);
void entraCaixa (tfila *F, tcliente *cAtendimento);
void maiorFila(tfila F, int *tamanhoMaximo);
int tempoMaximoEspera (int clienteAtendimento, int clienteMaximoEspera);
void atualizaHora (int minutos);
