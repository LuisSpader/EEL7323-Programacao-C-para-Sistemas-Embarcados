/*
   File List_temp_fixa.cpp

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

// #include "List.h"
#include "Node_temp_fixa.cpp"

class List
{

  Node *head; // ponteiro com tamanho de endereço de um 'Node'
  int ID;

public:
  List(); // construtor -> ao construir cria objeto 'Node': head = 0;
  ~List();

  void create_first_Node(int new_ID, int new_temp, bool new_automatico_ou_botao);

  void insertBeforeFirst(int new_ID, int new_temp, bool new_automatico_ou_botao);
  void insertAfterLast(int new_ID, int new_temp, bool new_automatico_ou_botao);

  int readFirst();
  int removeFirst();

  void insertionSort(int new_ID, int new_temp, bool new_automatico_ou_botao);
  int removeNode(int temp);
  void listAll();

  void List::setID(int newID);
};

List::List()
{
  head = 0; // a classe Node possui 2 argumentos, aqui estamos igualando ambos a 0?
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
  // aqui criamos um novo nó: new Node(...)
  // e
  // salvamos o endereço deste novo 'Node' criado na variável de ponteiro 'head'
  // a próxima vez que for criado um novo Node, este apontará para o endereço armazenado anteriormente na variável head
}

void List::insertBeforeFirst(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  if (new_ID == ID){

  create_first_Node(new_ID, new_temp, new_automatico_ou_botao); // ?? pq o 'new' aloca espaço de forma dinâmica??
  // criando um novo Nodo com ponteiro 'next' =  'head', que foi inicializado no construtor da classe 'List': head = 0 || (lembrando que 'head' é um ponteiro de 'Node', ou seja, seu tamanho de endereço de memória é igual ao de um 'Node')
  // e com valor 'temp' passado como argumento do método
  // após criar o novo Nodo, a variável 'head' que é do tipo 'Node' receberá o endereço deste novo Nodo criado, assim na próxima vez qu for criado um novo 'Node', o mesmo apontará para o 'Node' criado anteriormente
  }
  else {cout << "Este não eh o ID cadastrado (ID unico)";}

}

void List::insertAfterLast(int new_ID, int new_temp, bool new_automatico_ou_botao)
{
  // declara 2 ponteiros do tipo 'Node' e os mesmos serão iguais a outra 'Node' chamado 'head', caso já exista algum 'nodo': head não apontará para o endereço 0
  Node *A = head;
  Node *B = head;
if (new_ID == ID){
  if (head == 0)                                                  // verifica se lista está vazia
    create_first_Node(new_ID, new_temp, new_automatico_ou_botao); // se lista está vazia, cria um novo Nodo
  else                                                            // se lista não está vazia
  {
    while (B != 0) // se B for o 'último' da lista, apontará para '0'
    // caso contrário ainda estamos no meio da lista
    {
      A = B;            // A recebe o valor de 'B'. Mas B é um ponteiro logo esse valor é um endereço
      B = A->getNext(); // B recebe o endereço contido no objeto para o qual A aponta no momento
      // exemplo:
      // B = &nó_1 (aponta para nó_1)
      // A = B (também aponta para nó_1)
      // B = A->getNext(); (B apomta para quem nó_1 apontava, logo: nó_2)
    } // quando chegar no último nó (nó_N), B = 0

        A->setNext(new Node(new_ID, new_temp, new_automatico_ou_botao, 0));
    // criamos um novo nó que apontará para '0' (final da lista)
    // porém precisamos alterar o 'antigo último nó da lista' aponte para o 'novo último nó'
    // e quem é o 'antigo último nó'? é o nó_N que tanto A quanto B finalizarm o loop apontando, então podemos usar os ponteiros para alterar o conteúdo deste último nó
    // A-> setNext(novo nó) = nó_N::setNext(novo nó) = B-> setNext(novo nó)
  }
    }
  else {cout << "Este não eh o ID cadastrado (ID unico)";}
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
  Node *A = head;
  Node *B = head;

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
    pint = B->get_ID(); // pint = 0 || aqui pegamos o valor de 'temp' do Nodo 'head'
    auxint = pint;      // auxint = 0

    // LOOP ENQUANTO EXISTIR NODO VÁLIDO COM VALOR MAIOR DO QUE 'value'
    while ((B != 0) && (auxint < new_temp))
    // (B != 0): verifica se existe 'nodo' já criado, ou seja, não aponta para '0' = existe endereço de memória para o nodo 'head'
    // (auxint < value): verifica se o campo 'temp' do primeiro nodo 'head' é menor do que o 'value' passado como argumento da funcao (que é o campo 'temp' do novo Nodo )

    {
      A = B;
      B = A->getNext(); // aqui o ponteiro 'B' aponta não mais para 'head', mas sim para onde o campo 'next' do nodo 'head' aponta, que é o próximo nodo da lista
      if (B != 0)
      {
        // 1:15:00 https://www.youtube.com/watch?v=3F8q6RLikfE&list=PL35tBJQqzeIv7PIItr-Xt2Wkk9E-W_-YS&index=19&t=93s
        pint = B->get_ID(); // pint agora recebe o valor do próximo nodo e não mais do nodo 'head'. Ele receberá o valor '5'
        auxint = pint;
      }
    }
    // --------------------------------------------------------------------------------------------------------------

    if (A == B)                                                           // verifica se os ponteiros apontam para o mesmo lugar (lista vazia: campo 'next' do nodo 'head' apontaria para '0')
      create_first_Node(new_ID, new_temp, new_automatico_ou_botao);       // inclui novo nodo
    else                                                                  // caso lista não esteja vazia
      A->setNext(new Node(new_ID, new_temp, new_automatico_ou_botao, B)); // inclui novo nodo
  }
}

int List::removeNode(int temp)
{
  Node *A = head;
  Node *B = head;
  int result;

  if (head == 0)
    result = 0;
  else
  {
    while ((B != 0) && (B->get_ID() != temp))
    { // Error!! the addresses will always be different!
      A = B;
      B = A->getNext();
    }
    if (B != 0)
    {
      if (B == head)
      { // it is the first node
        result = B->get_ID();
        head = B->getNext();
        delete B;
      }
      else
      { // the node is in the middle
        result = B->get_ID();
        A->setNext(B->getNext());
        delete B;
      }
    }
    else
      result = 0; // node not found!
  }

  return result;
}

void List::listAll()
{
  cout << "========== Lista Completa ==========" << endl;
  Node *aux = head;
  while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  {
    cout << aux->get_ID() << endl; // imprime o valor do nodo
    aux = aux->getNext();          // o ponteiro do tipo 'Node' que a 1ª iteração apontava para 'head', agora aponta para o endereço que o campo 'next' já apontava .
    // Resumindo, antes: aux apontava para &head
    // Agora: aux aponta para o valor do campo 'next' do nodo 'head' -> head(temp = valor1, next = &nodo2) QUE É O ENDEREÇO DO PRÓXIMO NODO
  }
  cout << "====================================" << endl;
}

void List::setID(int newID)
{
  // Node *aux = head; // ponteiro para o nodo 'head'

  if (newID <= 0) // NewID > 0
  {
    cout << "---------------------------------------------------------------\n";
    cout << "     Valor deve ser um inteiro maior que zero!" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  } else{
    ID = newID;
  }


}