// O que está errado com os programas abaixos? Descubra e indique a solução para consertá-los. Execute-o no computador para ver se o erro foi resolvido.

void main() /* esse programa esta errado */
{
  int x, *p;
  x = 10;
  *p = x; //assim o VALOR_APONTADO pelo endereço do ponteiro será o endereço de 'x'
  // se o ponteiro estivesse apontado para uma outra variável A por exemplo e ela valesse 15 (A = 15)
  // agora o valor para onde o ponteiro aponta (15 seria trocado pelo valor do ENDEREÇO de x)
  // no caso A_value = x_address
  // caso dê printf("%d", *p); -> irá mostrar o ENDEREÇO de x
}

// ========== PROGRAMA CORRIGIDO ==================
void main()
{
  int x, *p;
  x = 10;
  p = &x; //assim o VALOR_APONTADO será o VALOR de 'x'
  // se o ponteiro estivesse apontado para uma outra variável A por exemplo e ela valesse 10 (A = 15)
  // agora o valor para onde o ponteiro aponta (15 seria trocado pelo valor do VALOR de x = 10)
  // no caso p -> x (10)
  // caso dê printf("%d", *p); -> irá mostrar o (VALOR = 10) x
}