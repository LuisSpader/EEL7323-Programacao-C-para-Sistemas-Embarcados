/*
   Arquivo Nodo_arvoreb.cpp

   Implementacao para a classe NodoAB

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

#include "Nodo_arvoreb.h"

NodoAB::NodoAB()
{
  esquerda = direita = 0;
}
NodoAB::NodoAB(int val, NodoAB *esq, NodoAB *dir)
{
  dado = val;
  esquerda = esq;
  direita = dir;
}
// retorna o valor armazenado no nodo
int NodoAB::getDado()
{
  return dado;
}
// altera o valor armazenado no nodo
void NodoAB::setDado(int novoDado)
{
  dado = novoDado;
}
// retorna ponteiro para o filho esquerdo do nodo atual
NodoAB *NodoAB::nodoEsquerda()
{
  return esquerda;
}
// retorna ponteiro para o filho direito do nodo atual
NodoAB *NodoAB::nodoDireita()
{
  return direita;
}
// retorna verdadeiro se o nodo e' uma folha
bool NodoAB::ehFolha()
{
  return (esquerda == 0) && (direita == 0);
}
