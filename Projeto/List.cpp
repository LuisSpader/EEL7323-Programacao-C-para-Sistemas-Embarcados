/*
   File List.cpp

   Class List stores Nodes (class Node) in a linked list.

   This file has the implementation for class List

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/
// Fila: 2 eventos:
// •O ar-condicionado foi ajustado devido à variações na temperatura externa.
// •Um dos botões de ajuste foi pressionado, quando o usuário informou que não estava satisfeito com a temperatura atual.
// Na ocorrência de cada um desses eventos, deverá ser incluído um novo nodo na fila contendo:
// ID do controlador (cada equipamento possui um ID único);
// data/hora do evento (usar o clock/calendar desenvolvido anteriormente).

#include "List.h"

List::List()
{
  head = 0; // a classe Node possui 2 argumentos, aqui estamos igualando ambos a 0?
  // 'head' é um ponteiro do tipo 'Node', logo faz o ponteiro apontar para o endereço '0...'
  //   Node::Node(int 0, Node *0)
  // {
  //   val = 0;
  //   next = 0;
  // }
}

List::~List()
{
  Node *cursor = head;
  while (head)
  {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

void List::create_first_Node(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  head = new Node(new_ID, new_temp, new_automatico_ou_botao, head);
}

void List::insertBeforeFirst(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  create_first_Node(new_ID, new_temp, new_automatico_ou_botao); // ?? pq o 'new' aloca espaço de forma dinâmica??

  // criando um novo Nodo com ponteiro 'next' =  'head', que foi inicializado no construtor da classe 'List': head = 0 || (lembrando que 'head' é um ponteiro de 'Node', ou seja, seu tamanho de endereço de memória é igual ao de um 'Node')
  // e com valor 'temp' passado como argumento do método
  // após criar o novo Nodo, a variável 'head' que é do tipo 'Node' receberá o endereço deste novo Nodo criado, assim na próxima vez qu for criado um novo 'Node', o mesmo apontará para o 'Node' criado anteriormente
}

void List::insertAfterLast(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  // declara 2 ponteiros do tipo 'Node' e os mesmos serão iguais a outra 'Node' chamado 'head', caso já exista algum 'nodo': head não apontará para o endereço 0
  Node *p = head;
  Node *q = head;

  if (head == 0)                                                  // verifica se lista está vazia
    create_first_Node(new_ID, new_temp, new_automatico_ou_botao); // se lista está vazia, cria um novo Nodo
  else                                                            // se lista não está vazia
  {
    while (q != 0)
    {
      p = q;
      q = p->getNext();
    }
    p->setNext(new Node(new_ID, new_temp, new_automatico_ou_botao, 0)); // o CONTEÚDO para onde o ponteiro aponta, será modificado com o valor deste novo 'Node'
  }
}

int List::readFirst()
{
  return head->get_ID();
}

int List::removeFirst()
{
  int retval = 0;
  if (head != 0)
  {
    cout << "Nodo no endereço " << head << endl;
    cout << "Contendo o valor " << head->get_ID();
    cout << "Vai ser removido da lista." << endl;
    cout << "A nova lista possui os seguintes valores: " << endl;

    retval = head->get_ID();
    Node *oldHead = head;
    head = head->getNext();
    delete oldHead;
  }
  return retval;
}

void List::insertionSort(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  // função para inserir 'Nodo' em ordem crescente de seu valor 'value'
  Node *p = head;
  Node *q = head;

  if (head == 0)
  {
    // head = new Node(value, head);
    create_first_Node(new_ID, new_temp, new_automatico_ou_botao);
    int i;
    i = head->get_ID();
  }
  else
  {
    int pint;
    int auxint;
    pint = q->get_ID(); // pint = 0 || aqui pegamos o valor de 'temp' do Nodo 'head'
    auxint = pint;      // auxint = 0

    // LOOP ENQUANTO EXISTIR NODO VÁLIDO COM VALOR MAIOR DO QUE 'value'
    while ((q != 0) && (auxint < new_temp))
    // (q != 0): verifica se existe 'nodo' já criado, ou seja, não aponta para '0' = existe endereço de memória para o nodo 'head'
    // (auxint < value): verifica se o campo 'temp' do primeiro nodo 'head' é menor do que o 'value' passado como argumento da funcao (que é o campo 'temp' do novo Nodo )

    {
      p = q;
      q = p->getNext(); // aqui o ponteiro 'q' aponta não mais para 'head', mas sim para onde o campo 'next' do nodo 'head' aponta, que é o próximo nodo da lista
      if (q != 0)
      {
        // 1:15:00 https://www.youtube.com/watch?v=3F8q6RLikfE&list=PL35tBJQqzeIv7PIItr-Xt2Wkk9E-W_-YS&index=19&t=93s
        pint = q->get_ID(); // pint agora recebe o valor do próximo nodo e não mais do nodo 'head'. Ele receberá o valor '5'
        auxint = pint;
      }
    }
    // --------------------------------------------------------------------------------------------------------------

    if (p == q)                                                           // verifica se os ponteiros apontam para o mesmo lugar (lista vazia: campo 'next' do nodo 'head' apontaria para '0')
      create_first_Node(new_ID, new_temp, new_automatico_ou_botao);       // inclui novo nodo
    else                                                                  // caso lista não esteja vazia
      p->setNext(new Node(new_ID, new_temp, new_automatico_ou_botao, q)); // inclui novo nodo
  }
}

int List::removeNode(int temp)
{
  Node *p = head;
  Node *q = head;
  int result;

  if (head == 0)
    result = 0;
  else
  {
    while ((q != 0) && (q->get_ID() != temp))
    { // Error!! the addresses will always be different!
      p = q;
      q = p->getNext();
    }
    if (q != 0)
    {
      if (q == head)
      { // it is the first node
        result = q->get_ID();
        head = q->getNext();
        delete q;
      }
      else
      { // the node is in the middle
        result = q->get_ID();
        p->setNext(q->getNext());
        delete q;
      }
    }
    else
      result = 0; // node not found!
  }

  return result;
}

void List::listAll()
{
  Node *aux = head;
  while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  {
    cout << aux->get_ID() << endl; // imprime o valor do nodo
    aux = aux->getNext();          // o ponteiro do tipo 'Node' que a 1ª iteração apontava para 'head', agora aponta para o endereço que o campo 'next' já apontava .
    // Resumindo, antes: aux apontava para &head
    // Agora: aux aponta para o valor do campo 'next' do nodo 'head' -> head(temp = valor1, next = &nodo2) QUE É O ENDEREÇO DO PRÓXIMO NODO
  }
}

void List::setID(int newID)
{
  // Node *aux = head; // ponteiro para o nodo 'head'

  // if (newID <= 0) // NewID > 0
  // {
  //   cout << "---------------------------------------------------------------\n";
  //   cout << "     Valor deve ser um inteiro maior que zero!" << endl;
  //   cout << "---------------------------------------------------------------\n";
  //   return;
  // }

  // // PERCORRENDO TODOS OS NODOS PARA VERIFICAR ID REPETIDO
  // while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  // {
  //   if(newID == aux->get_ID() ){
  //     cout << "---------------------------------------------------------------\n";
  //     cout << "                   Este ID ja existe!" << endl;
  //     cout << "---------------------------------------------------------------\n";
  //     return;
  //   }
  //   aux = aux->getNext();
  // }
}