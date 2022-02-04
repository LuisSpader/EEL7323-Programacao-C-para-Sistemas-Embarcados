/*
   Arquivo ABP.h

   Header para a classe ABP

   Essa classe pode ser utilizada na criacao e manipulacao
   de arvores binarias de pesquisa. Possui as seguintes operacoes:

   1. Criacao de arvore binaria de pesquisa (ABP) vazia
   2. Remocao
   3. Inserir elemento na ABP
   4. Remover elemento da ABP
   5. Remover o menor elemento da ABP
   6. Procurar elemento na ABP
   7. Verificar se a ABP esta' vazia
   8. Imprimir a arvore

   Eduardo Augusto Bezerra <eduardob@acm.org>
   Faculdade de Informatica, PUC-RS
   Laboratorio de Programacao II

   Setember 2002.

*/

#include "Nodo_arvoreb.cpp"

class ABP
{
  NodoAB *raiz;
  void auxApagaABP(NodoAB *);
  void auxInserir(NodoAB *&, int);
  void auxRemoverNodo(NodoAB *&, int);
  NodoAB *auxProcurar(NodoAB *, int);
  void auxImprimirABP(NodoAB *, int);

public:
  ABP();
  ~ABP();
  void apagaABP();
  void inserirNodo(int elemento);
  void removerNodo(int elemento);
  NodoAB *removerMenorValor(NodoAB *&);
  NodoAB *procurarNodo(int elemento);
  bool estaVazia();
  void imprimirABP();
};
