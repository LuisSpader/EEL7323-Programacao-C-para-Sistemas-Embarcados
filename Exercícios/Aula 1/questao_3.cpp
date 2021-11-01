#include <stdio.h>
int main()
{
  int x, *p, *q; // x = inteiro, p = ponteiro de inteiro, q = ponteiro de ponteiro de inteiro
  x = 10;
  *p = x;  // p recebe VALOR da variável 'x'
  *q = *p; // q recebe VALOR da variável para onde o ponteiro 'p' aponta

  printf("\n%d\n", *p);
  return (0);
}