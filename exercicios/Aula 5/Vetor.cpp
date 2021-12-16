#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include "Vetor.h"

// Construtor
VetAluno::VetAluno()
{
  for (int i = 0; i < 20; i++)
  {
    valido[i] = 0;          // Liberar a escrita no vetor vAlunos
    vAlunos[i].setMatr(-1); // Para evitar problemas de matricula duplicada
  }
}
// Metodo para a listagem dos alunos da turma
void VetAluno::listaVet()
{
  for (int i = 0; i < 20; i++)
  {
    if (valido[i])
    {
      cout << "Aluno matricula: " << vAlunos[i].getMatr() << endl;
      cout << "Nota prova 1: " << vAlunos[i].getN1() << endl;
      cout << "Nota prova 2: " << vAlunos[i].getN2() << endl;
      cout << "Media final: " << vAlunos[i].calcMedia() << endl
           << endl;
    }
  }
}
// Metodo para a inclusao de alunos
void VetAluno::inclui(int matr, float n1, float n2)
{
  int i = 0;
  int guardaPosicao;
  bool sai = false;
  bool termina = false;
  do
  {
    for (int x = 0; x < 20; x++)
    {
      if (matr == vAlunos[x].getMatr())
      {
        cout << "Matricula duplicada! Erro" << endl;
        sai = true;
      }
    }
    if (!sai && !valido[i])
    {
      guardaPosicao = i;
      termina = true;
    }
    i++;
  } while (i < 20 && !sai && !termina);
  // Caso sai = true, o encerramento foi devido a um problema de matricula
  // duplicada, nao podendo ser gravado os dados no objeto
  // A flag 'termina' existe para direcionar o fluxo caso haja um espaco livre no vetor valido[i]
  if (!sai && termina)
  {
    vAlunos[guardaPosicao].setMatr(matr);
    vAlunos[guardaPosicao].setN1(n1);
    vAlunos[guardaPosicao].setN2(n2);
    valido[guardaPosicao] = 1; // Indica o preenchimeto de um objeto
  }
}
// Metodo para a exclusao de um aluno. Caso a matricula digitada for correta, libera-se a escrita atraves
// do vetor de controle 'valido'
void VetAluno::exclui(int matr)
{
  bool found = 0;
  int i = 0;
  while (!found && i < 20)
  {
    if (matr == vAlunos[i].getMatr())
    {
      found = 1;
      valido[i] = 0;
      vAlunos[i].setMatr(-1); // Numero invalido para liberar o repreenchimento
      cout << "Aluno excluido!\n\n";
    }
    i++;
  }
  if (!found)
    cout << "Aluno nao encontrado! Tente novamente.\n\n";
}
// Metodo para consulta de apenas uma matricula
void VetAluno::consulta(int matr)
{
  bool found = 0;
  int i = 0;
  while (!found && i < 20)
  {
    if (matr == vAlunos[i].getMatr())
    {
      found = 1;
      cout << "Nota 1: " << vAlunos[i].getN1() << endl;
      cout << "Nota 2: " << vAlunos[i].getN2() << endl;
      cout << "Media final: " << vAlunos[i].calcMedia() << endl
           << endl;
    }
    i++;
  }
  if (!found)
    cout << "Aluno nao encontrado! Tente novamente.\n\n";
}
// Alteracao das notas de um determinado aluno
void VetAluno::altera(int matr)
{
  bool found = 0;
  int i = 0;
  float nota1, nota2;
  while (!found && i < 20)
  {
    if (matr == vAlunos[i].getMatr())
    {
      found = 1;
      cout << "Digite a nova nota 1: ";
      cin >> nota1;
      cout << "\nDigite a nova nota 2: ";
      cin >> nota2;
      vAlunos[i].setN1(nota1);
      vAlunos[i].setN2(nota2);
    }
    i++;
  }
  if (!found)
    cout << "Aluno nao encontrado! Tente novamente.\n\n";
}