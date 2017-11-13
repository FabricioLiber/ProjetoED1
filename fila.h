typedef int telem;

typedef struct no {
  telem espera;
  telem atendimento;
  struct no prox;
} tno;

typdef struct tfila {
  tno* inicio;
  tno* fim;
}

void criarFila (tfila *F);
int vaziaFila (tfila F);
int primeiroFila (tfila F);
int inserirFila (tfila *F, telem atendimento, telem espera);
int removerFila (tfila *F, telem atendimento, telem espera);
