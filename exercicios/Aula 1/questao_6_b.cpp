// O que está errado com os programas abaixos? Descubra e indique a solução para consertá-los. Execute-o no computador para ver se o erro foi resolvido.

/* esse programa esta errado */
// void main() // funções 'void' não podem retornar nada, e 'printf' é um retorno
// {
//   int x, *p;
//   x = 10;
//   p = x; //aqui não pega o endereço
//   printf("%d", *p);
// }

// ================================================
#include <stdio.h>

/* esse programa esta CORRETO */
int main()
{
  int x, *p;
  x = 10;
  p = &x;
  printf("%d", *p);
}