/*
   Arquivo Nodo_arvoreb.h

   Header para a classe NodoAB

   Essa classe pode ser utilizada na criacao e manipulacao
   de arvores binarias de inteiros. Possui as seguintes operacoes:

   1. Criacao de nodo (com e sem parametros).
   2. Retorna o filho a direita de um nodo.
   3. Retorna o filho a esquerda de um nodo.
   4. Retorna o valor (inteiro) armazenado no nodo.
   5. Armazena um valor (inteiro) em um nodo.
   6. Verifica se um nodo e' uma folha.

   Eduardo Augusto Bezerra <eduardob@acm.org>
   Faculdade de Informatica, PUC-RS
   Laboratorio de Programacao II

   Setember 2002.

*/

class NodoAB
{

  int dado; // valor armazenado no nodo

public:
  NodoAB *esquerda; // ponteiro para o elemento a esquerda do nodo
  NodoAB *direita;  // ponteiro para o elemento a direita do nodo

  // construtor sem parametros
  NodoAB();
  // construtor com parametros
  NodoAB(int val, NodoAB *esq, NodoAB *dir);
  // retorna o valor armazenado no nodo
  int getDado();
  // altera o valor armazenado no nodo
  void setDado(int novoDado);
  // retorna ponteiro para o filho esquerdo do nodo atual
  NodoAB *nodoEsquerda();
  // retorna ponteiro para o filho direito do nodo atual
  NodoAB *nodoDireita();
  // retorna verdadeiro se o nodo e' uma folha
  bool ehFolha();
};
