/*
   File List_temp_fixa.cpp

   Class List_temp_fixa stores Nodes (class Node_temp_fixa) in a linked list.

   This file has the implementation for class List_temp_fixa

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

#include <stdlib.h>
using namespace std;
#include <iomanip>
#include "centered.cpp"
#include <cassert>

// #include "List_temp_fixa.h"
#include "Node_temp_fixa.cpp"

class List_temp_fixa : public ClockCalendar
{

  Node_temp_fixa *head; // ponteiro com tamanho de endereço de um 'Node_temp_fixa'
  int ID;

public:
  List_temp_fixa(int newID); // construtor -> ao construir cria objeto 'Node_temp_fixa': head = 0;
  ~List_temp_fixa();
  void Ligar();
  void Desligar();

  void create_first_Node(int new_temp, bool new_automatico_ou_botao);

  void insertBeforeFirst(int new_temp, bool new_automatico_ou_botao);
  void insertAfterLast(int new_temp, bool new_automatico_ou_botao);

  int readFirst();
  int removeFirst();

  void insertionSort(int new_temp, bool new_automatico_ou_botao);
  int removeNode(int temp);

  void listAll();
  void listInterval(string limit_inf, string limit_sup, string hr_init, string hr_end);
  void setID(int newID);
  string TempoLigado();
  void printNode(Node_temp_fixa *aux);
};

List_temp_fixa::List_temp_fixa(int newID)
{
  setID(newID);
  head = 0; // a classe Node_temp_fixa possui 2 argumentos, aqui estamos igualando ambos a 0?
  Ligar();
}

List_temp_fixa::~List_temp_fixa()
{
  Node_temp_fixa *cursor = head;
  while (head)
  {
    delete head;
    cursor = cursor->getNext();
    head = cursor;
    // cursor = cursor->getNext();
    // delete head;
    // head = cursor;
  }
  head = 0; // Officially empty
}

void List_temp_fixa::create_first_Node(int new_temp, bool new_automatico_ou_botao)
{
  head = new Node_temp_fixa(ID, new_temp, new_automatico_ou_botao, head);
  // aqui criamos um novo nó: new Node_temp_fixa(...)
  // e
  // salvamos o endereço deste novo 'Node_temp_fixa' criado na variável de ponteiro 'head'
  // a próxima vez que for criado um novo Node_temp_fixa, este apontará para o endereço armazenado anteriormente na variável head
}

void List_temp_fixa::insertBeforeFirst(int new_temp, bool new_automatico_ou_botao)
{
  create_first_Node(new_temp, new_automatico_ou_botao); // ?? pq o 'new' aloca espaço de forma dinâmica??

  // criando um novo Nodo com ponteiro 'next' =  'head', que foi inicializado no construtor da classe 'List_temp_fixa': head = 0 || (lembrando que 'head' é um ponteiro de 'Node_temp_fixa', ou seja, seu tamanho de endereço de memória é igual ao de um 'Node_temp_fixa')
  // e com valor 'temp' passado como argumento do método
  // após criar o novo Nodo, a variável 'head' que é do tipo 'Node_temp_fixa' receberá o endereço deste novo Nodo criado, assim na próxima vez qu for criado um novo 'Node_temp_fixa', o mesmo apontará para o 'Node_temp_fixa' criado anteriormente
}

void List_temp_fixa::insertAfterLast(int new_temp, bool new_automatico_ou_botao)
{
  // declara 2 ponteiros do tipo 'Node_temp_fixa' e os mesmos serão iguais a outra 'Node_temp_fixa' chamado 'head', caso já exista algum 'nodo': head não apontará para o endereço 0
  Node_temp_fixa *A = head;
  Node_temp_fixa *B = head;

  if (head == 0)                                          // verifica se lista está vazia
    create_first_Node(new_temp, new_automatico_ou_botao); // se lista está vazia, cria um novo Nodo
  else                                                    // se lista não está vazia
  {
    while (B != 0) // se B for o 'último' da lista, apontará para '0'
    // caso contrário ainda estamos no meio da lista
    {
      A = B;            // A recebe o valor de 'B'. Mas B é um ponteiro logo esse valor é um endereço
      B = A->getNext(); // B recebe o endereço contido no objeto para o qual A aponta no momento
      // exemplo:
      // B = &nó_1 (aponta para nó_1)
      // A = B (também aponta para nó_1)
      // B = A->getNext(); (B aponta para quem nó_1 apontava, logo: nó_2)
    } // quando chegar no último nó (nó_N), B = 0

    A->setNext(new Node_temp_fixa(ID, new_temp, new_automatico_ou_botao, 0));
    // criamos um novo nó que apontará para '0' (final da lista)
    // porém precisamos alterar o 'antigo último nó da lista' aponte para o 'novo último nó'
    // e quem é o 'antigo último nó'? é o nó_N que tanto A quanto B finalizarm o loop apontando, então podemos usar os ponteiros para alterar o conteúdo deste último nó
    // A-> setNext(novo nó) = nó_N::setNext(novo nó) = B-> setNext(novo nó)
  }
}

int List_temp_fixa::readFirst()
{
  return head->get_ID();
  // return head->get_All_Data();
}

int List_temp_fixa::removeFirst()
{
  int retval = 0;
  if (head != 0)
  {
    cout << "Nodo no endereço " << head << endl;
    cout << "Contendo o valor " << head->get_ID();
    cout << "Vai ser removido da lista." << endl;
    cout << "A nova lista possui os seguintes valores: " << endl;

    retval = head->get_ID();
    Node_temp_fixa *oldHead = head;
    head = head->getNext();
    delete oldHead;
  }
  return retval;
}

void List_temp_fixa::insertionSort(int new_temp, bool new_automatico_ou_botao)
{
  // função para inserir 'Nodo' em ordem crescente de seu valor 'value'
  Node_temp_fixa *A = head;
  Node_temp_fixa *B = head;

  if (head == 0)
  {
    // head = new Node_temp_fixa(value, head);
    create_first_Node(new_temp, new_automatico_ou_botao);
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

    if (A == B)                                                                 // verifica se os ponteiros apontam para o mesmo lugar (lista vazia: campo 'next' do nodo 'head' apontaria para '0')
      create_first_Node(new_temp, new_automatico_ou_botao);                     // inclui novo nodo
    else                                                                        // caso lista não esteja vazia
      A->setNext(new Node_temp_fixa(ID, new_temp, new_automatico_ou_botao, B)); // inclui novo nodo
  }
}

int List_temp_fixa::removeNode(int temp)
{
  Node_temp_fixa *A = head;
  Node_temp_fixa *B = head;
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

void List_temp_fixa::listAll()
{
  Node_temp_fixa *aux = head;
  cout << "---------------------------------------------------------------\n";
  cout << "========== Lista Completa ==========" << endl;
  cout << "|" << setw(12) << centered("Data")
       << "|" << setw(10) << centered("Hora")
       << "|" << setw(10) << centered("ID")
       << "|" << setw(13) << centered("Temp. Externa")
       << "|" << setw(18) << centered("Temp. Dispositivo")
       << "|" << setw(22) << centered("Acionamento (1 = aut.)")
       << "|" << endl;
  while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  {

    // cout << "|" << setw(21) << aux->get_DataHora()
    cout << "|" << setw(12) << centered(aux->getCalendarString())
         << "|" << setw(10) << centered(aux->getClockString())
         << "|" << setw(10) << centered(to_string(aux->get_ID()))
         << "|" << setw(13) << centered(to_string(aux->get_temp_ext()))
         << "|" << setw(18) << centered(to_string(aux->get_new_temp_int()))
         << "|" << setw(22) << centered(to_string(aux->get_automatico_ou_botao()))
         << "|" << endl;
    aux = aux->getNext(); // o ponteiro do tipo 'Node_temp_fixa' que a 1ª iteração apontava para 'head', agora aponta para o endereço que o campo 'next' já apontava .
    // Resumindo, antes: aux apontava para &head
    // Agora: aux aponta para o valor do campo 'next' do nodo 'head' -> head(temp = valor1, next = &nodo2) QUE É O ENDEREÇO DO PRÓXIMO NODO
  }
  cout << "---------------------------------------------------------------\n";
}

// void List_temp_fixa::listInterval(string limit_inf, string limit_sup, string hr_init = "00:00:00", string hr_end = "23:59:59")
// {
//   Node_temp_fixa *aux = head;

//   cout << "---------------------------------------------------------------\n";
//   cout << "========== Lista Intervalo: " << limit_inf << " - " << limit_sup << " | " << hr_init << " - " << hr_end << "; ==========" << endl;
//   cout << "|" << setw(11) << centered("Data")
//        << "|" << setw(10) << centered("Hora")
//        << "|" << setw(10) << centered("ID")
//        << "|" << setw(13) << centered("Temp. Externa")
//        << "|" << setw(18) << centered("Temp. Dispositivo")
//        << "|" << setw(22) << centered("Acionamento (1 = aut.)")
//        << "|" << endl;

//   while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
//   {
//     if (aux->ClockCalendar::Data1EhMAIORqueData2(aux->data, limit_inf) == true && aux->ClockCalendar::Data1EhMENORqueData2(aux->data, limit_sup) == true)
//     {

//       if (aux->ClockCalendar::Hora1EhMAIORqueHora2(aux->hora, hr_init) == true && aux->ClockCalendar::Hora1EhMENORqueHora2(aux->hora, hr_end) == true)
//       {
//         cout << "|" << setw(11) << (aux->getCalendarString())
//              << "|" << setw(10) << (aux->getClockString())
//              << "|" << setw(10) << centered(to_string(aux->get_ID()))
//              << "|" << setw(13) << centered(to_string(aux->get_temp_ext()))
//              << "|" << setw(18) << centered(to_string(aux->get_new_temp_int()))
//              << "|" << setw(22) << centered(to_string(aux->get_automatico_ou_botao()))
//              << "|" << endl;
//       }
//     }
//     aux = aux->getNext(); // o ponteiro do tipo 'Node_temp_fixa' que a 1ª iteração apontava para 'head', agora aponta para o endereço que o campo 'next' já apontava .
//                           // Resumindo, antes: aux apontava para &head
//                           // Agora: aux aponta para o valor do campo 'next' do nodo 'head' -> head(temp = valor1, next = &nodo2) QUE É O ENDEREÇO DO PRÓXIMO NODO
//   }
//   cout << "---------------------------------------------------------------\n";
// }
void List_temp_fixa::listInterval(string limit_inf, string limit_sup, string hr_init = "00:00:00", string hr_end = "23:59:59")
{
  Node_temp_fixa *aux = head;

  cout << "---------------------------------------------------------------\n";
  cout << "========== Lista Intervalo: " << limit_inf << " - " << limit_sup << " | " << hr_init << " - " << hr_end << "; ==========" << endl;
  cout << "|" << setw(11) << centered("Data")
       << "|" << setw(10) << centered("Hora")
       << "|" << setw(10) << centered("ID")
       << "|" << setw(13) << centered("Temp. Externa")
       << "|" << setw(18) << centered("Temp. Dispositivo")
       << "|" << setw(22) << centered("Acionamento (1 = aut.)")
       << "|" << endl;

  while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  {
    if ((aux->data > limit_inf) && (aux->data < limit_sup))
    // if (aux->ClockCalendar::Data1EhMAIORqueData2(aux->data, limit_inf) == true && aux->ClockCalendar::Data1EhMENORqueData2(aux->data, limit_sup) == true)
    {
      // if ((aux->hora >= hr_init) && (aux->hora <= hr_end))
      printNode(aux);
    }
    else if (aux->data == limit_inf)
    {
      if (aux->data >= hr_init)
      {
        printNode(aux);
      }
    }
    else if (aux->data == limit_sup)
    {
      if (aux->hora <= hr_end)
      {
        printNode(aux);
      }
    }
    aux = aux->getNext(); // o ponteiro do tipo 'Node_temp_fixa' que a 1ª iteração apontava para 'head', agora aponta para o endereço que o campo 'next' já apontava .
                          // Resumindo, antes: aux apontava para &head
                          // Agora: aux aponta para o valor do campo 'next' do nodo 'head' -> head(temp = valor1, next = &nodo2) QUE É O ENDEREÇO DO PRÓXIMO NODO
  }
  cout << "---------------------------------------------------------------\n";
}
void List_temp_fixa::setID(int newID)
{
  // Node_temp_fixa *aux = head; // ponteiro para o nodo 'head'

  if (newID <= 0) // NewID > 0
  {
    cout << "---------------------------------------------------------------\n";
    cout << "     Valor deve ser um inteiro maior que zero!" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  }
  else
  {
    ID = newID;
  }
};

void List_temp_fixa::Ligar()
{
  create_first_Node(9999, true);
}

void List_temp_fixa::Desligar()
{
  insertAfterLast(1111, true);

  // insertAfterLast(7777, true);

  // Node_temp_fixa *aux = head;
  // aux->changeNode_manual("Tempo ligado", TempoLigado(), ID, 0, true, aux->getNext()); // string new_hr, int new_ID, int new_temp_int, bool new_automatico_ou_botao, Node_temp_fixa *nxt
}

string List_temp_fixa::TempoLigado()
{
  Node_temp_fixa *aux = head;
  string h1, h2;

  // cout << aux->get_temp_int();
  while (aux != 0) // enquanto não chega no último nodo (que aponta para '0')
  {
    // cout << aux->get_temp_int() << endl;
    if (aux->get_temp_int() == 9999) // List_temp_fixa::Ligar()
    {
      h1 = aux->hora;
    }
    else
    {
      if (aux->get_temp_int() == 1111) // List_temp_fixa::Desligar()
      {
        h2 = aux->hora;
        break;
      }
    }
    aux = aux->getNext();
  }
  // cout << "h1 " << h1 << endl;
  // cout << "h2 " << h2 << endl;
  // cout << "intervalo " << aux->ClockInterval(h1, h2);
  // ClockCalendar::ClockInterval(h1,h2);
  // return ("aux->ClockInterval(h1, h2)");
  stringstream str;
  str << get<0>(aux->ClockInterval(h1, h2)) << ":" << get<1>(aux->ClockInterval(h1, h2)) << ":" << get<2>(aux->ClockInterval(h1, h2));
  return (str.str());
}

// Data1 = 01/01/2020; Hora1 = 10:00:00 -> Início
// Data2 = 02/01/2020; Hora2 = 08:00:00 -> Fim

void List_temp_fixa::printNode(Node_temp_fixa *aux)
{
  cout << "|" << setw(11) << (aux->getCalendarString())
       << "|" << setw(10) << (aux->getClockString())
       << "|" << setw(10) << centered(to_string(aux->get_ID()))
       << "|" << setw(13) << centered(to_string(aux->get_temp_ext()))
       << "|" << setw(18) << centered(to_string(aux->get_new_temp_int()))
       << "|" << setw(22) << centered(to_string(aux->get_automatico_ou_botao()))
       << "|" << endl;
}
