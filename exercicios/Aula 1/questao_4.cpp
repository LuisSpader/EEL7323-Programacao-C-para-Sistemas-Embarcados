// Escreva um programa que declare uma matriz 100x100 de inteiros. Você deve inicializar a matriz com zeros usando ponteiros. Preencha depois a matriz com os números de 1 a 10.000 usando ponteiros.

#include <stdio.h>

int main()
{
  int n = 100;
  int matriz[100][100];
  int *p;
  p = &(matriz[0][0]); // ponteiro para o loop -> aponta para o início da matriz

  for (int i = 0; i < (n * n); i++)
  {
    *p = 0;
    p++;
    // printf("\n%d\n", i);
  }

  for (int i = 0; i < (n * n); i++)
  {
    *p = i;
    p++;
    // printf("\n%d\n", *p);
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     printf("\n", matriz[i][j]);
  //   }
  // }

  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j < n; j++)
  //     matriz[i][j] = p[i];
  //     p++;
  //  return total;

  printf("\n %d \n", matriz[n][n]);
}