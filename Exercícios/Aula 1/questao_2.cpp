#include <stdio.h>
// #include <cstdio>

int main()
{
  int y, *p, x; /* declara inteiros, onde p é um ponteiro de inteiro */
  y = 0;
  p = &y;                /* p recebe o endereço da variavél y na memória */
  x = *p;                /* x recebe o valor apontado pelo ponteiro 'p' */
  x = 4;                 /* x recebe o valor 4 */
  (*p)++;                /* o VALOR o qual o ponteiro aponta é incrementado de +1 -> y = 1*/
  x--;                   /* o VALOR de x é decrementado: -1 -> x = 3*/
  (*p) += x;             /* o VALOR o qual o ponteiro aponta é incrementado pelo valor de 'x' -> y = 4 */
  printf("y = %d\n", y); /* y = 4 */
  return (0);
}
