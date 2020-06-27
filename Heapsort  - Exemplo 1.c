
#include "stdio.h"
#include "stdlib.h"

void lerVet( int *p, int t ){

	int i;

	for ( i=0; i 0 ) {

          i--;
          t = a[i];

      }
      else {

          n--;
          if (n == 0)
             return;

          t = a[n];
          a[n] = a[0];

      }

      pai = i;
      filho = i*2 + 1;

      while (filho < n) {

          if (( filho + 1 < n )  &&  ( a[filho + 1] > a[filho] ))
              filho++;

          if (a[filho] > t) {

             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;

          }
          else
             break;

      }
      a[pai] = t;

   }
}


int main(){

	int *p, tam;

	printf("Quantidade de elementos do vetor? ");
	scanf("%d",&tam);

	p = (int*) malloc(tam * sizeof(int));

	printf("\nDigite o conteudo do vetor:\n");
	lerVet(p, tam);

	printf("\nConteudo digitado para o vetor:\n");
	mostrarVet(p, tam);

	printf("\nOrdenando o vetor...\n");
	heapSort(p, tam);

	printf("\nConteudo do vetor ja ordenado:\n");
	mostrarVet(p, tam);

	free(p);

	return 0;

}
