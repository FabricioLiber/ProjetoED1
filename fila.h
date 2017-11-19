typedef int telem;

typedef struct no {
  telem id;
  telem entrada;
  telem atendimento;
  struct no* prox;
} tcliente;

typedef struct tfila {
  tcliente* inicio;
  tcliente* fim;
} tfila;

void criarFila (tfila *F);
int vaziaFila (tfila F);
int primeiroFila (tfila F, telem *idCli);
int inserirFila (tfila *F, telem idCli, telem entrada, telem atendimento);
int removerFila (tfila *F, telem *idCli, telem *atendimento, telem *tEntrada);
int tamanhoFila (tfila F);
void imprimirFila (tfila F);
