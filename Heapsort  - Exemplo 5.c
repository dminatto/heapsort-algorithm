
#include "stdio.h"
#include "stdlib.h"

struct TipoItem {
  int Chave;
};

const n = 10;
typedef TipoItem TipoVetor[n + 1];

void Swap(TipoItem *x, TipoItem *y);
void Refaz(int Esq, int Dir, TipoVetor A);
void HeapSort(TipoVetor A);

void main() {
  TipoVetor A, Original;
  int x, i;

  randomize();
  for (i=1; i<=n; i++) {
    x = random(100);
    A[i].Chave = x;
    Original[i].Chave = x;
  }

  HeapSort(A);


  printf(" i- Vetor Original       Vetor Ordenado\n");
  for (i=1; i<=n; i++)
    printf("%2d- %8d %20d\n", i, Original[i], A[i]);
}


void Swap(TipoItem *x, TipoItem *y) {
  TipoItem aux;
  aux = *x;
  *x = *y;
  *y = aux;
}


void Refaz(int Esq, int Dir, TipoVetor A) {
  int i, j;
  TipoItem x;
  i = Esq;
  j = 2 * i;
  x = A[i];
  while (j <= Dir) {
    if ((j < Dir) && (A[j].Chave < A[j+1].Chave))
       j = j + 1;
    if (x.Chave >= A[j].Chave)
       break;
    A[i] = A[j];
    i = j;
    j = 2 * i;
  }
  A[i] = x;
}

void HeapSort(TipoVetor A) {
  int Esq, Dir;


  Esq = (n / 2) + 1;
  Dir = n;
  while (Esq > 1) {
    Esq = Esq - 1;
    Refaz(Esq, Dir, A);
  }

  while (Dir > 1) {
    Swap(&A[1], &A[Dir]);
    Dir = Dir - 1;
    Refaz(Esq, Dir, A);
  }
}
