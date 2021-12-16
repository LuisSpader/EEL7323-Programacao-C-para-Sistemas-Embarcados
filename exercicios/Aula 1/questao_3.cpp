// Verifique o programa abaixo. Encontre o seu erro e corrija-o para que escreva o número 10 na tela.

// #include <stdio.h>
// int main()
// {
// int x, *p, **q;
// p = &x;
// q = &p;
// x = 10;
// printf("\n%d\n", &q);
// return(0);
// }

#include <stdio.h>
int main()
{
  // x inteiro, p ponteiro de inteiro, q ponteiro de ponteiro de inteiro
  int x, *p, **q;

  // p aponta para o endereço de x
  p = &x;

  // q aponta para o endereço do ponteiro p (que armazena o endereço de 'x')
  q = &p;

  x = 10;

  // &q: pega apenas o endereço do ponteiro 'q'
  // *q: pega o valor do ponteiro 'q' (que é o endereço do ponteiro 'p')
  // **q: pega o valor do ponteiro o qual o 'q' já aponta (valor do ponteiro 'p')
  printf("\n%d\n", **q);
  return (0);
}