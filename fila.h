typedef struct {
  int id;
  int entrada;
  int atendimento;
} scliente;

typedef scliente telem;

typedef struct no {
  scliente cliente;
  struct no* prox;
} tno;

typedef struct tfila {
  tno* inicio;
  tno* fim;
} tfila;

void criarFila (tfila *F);
int vaziaFila (tfila F);
int primeiroFila (tfila F, scliente *C);
int inserirFila (tfila *F, scliente C);
int removerFila (tfila *F, scliente *C);
int tamanhoFila (tfila F);
void imprimirFila (tfila F);
