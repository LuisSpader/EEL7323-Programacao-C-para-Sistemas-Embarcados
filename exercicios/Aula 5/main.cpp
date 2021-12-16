/*
    Exemplo de agregacao - exercicio 6 descrito em:
  http://gse.ufsc.br/bezerra/disciplinas/cpp/aulas/dia1_9_4.html
*/
/*

 Universidade Federal de Santa Catarina (UFSC)
 Centro Tecnologico (CTC)
 Departamento de Engenharia Eletrica e Eletronica (EEL)
 Programacao de Sistemas Embarcados / Programacao C++ para Sistemas Embarcados
 Prof. Eduardo Augusto Bezerra
 Apr. 2012

 Files:
    Aluno.h - Header file for Aluno class
    Aluno.cpp - Source file (implementation) for Aluno
    Vetor.h - Header file for Vetor class
    Vetor.cpp - Source file (implementation) for Vetor

 - Class "Aluno" can be used to instantiate objects of type Aluno.
   Each Aluno object will have a "Matricula", two grades ("Notas"),
   and also the final grade.

 - Class "Vetor" has two arrays. An array of "Aluno", and an array of bool.
   The array of bool will have true in the positions where there is
   a valid Aluno. The "empty" positions of the bool vector will have false.

 The two classes can be arranged in a class hierarchy as shown
 below. It is an "aggregation", where Class Vetor "has" Class Aluno.
 In this relationship, the child can exist independently of the parent.

          +----------------+
          |     Vetor      |
          +----------------+
                 / \
                 \ /  has
                  |
                  |
          +----------------+
          |      Aluno     |
          +----------------+

 In the main program, a menu is used for the user to select which action will
 be performed in the vector.

 */

#include "Vetor.cpp"

int main()
{
  bool sair = false;
  int opcao, matr;
  float n1, n2;
  VetAluno CadAlunos;
  cout << "Programa de cadastro de alunos - EEL 510232 - UFSC 2015";
  do
  {
    // Mostra todas as opções
    cout << "\n1. Cadastrar aluno" << endl;
    cout << "2. Consultar aluno" << endl;
    cout << "3. Listar turma" << endl;
    cout << "4. Excluir aluno" << endl;
    cout << "5. Alterar aluno" << endl;
    cout << "6. Sair" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    // Switch para direcionar a escolha aos metodos da classe CadAlunos
    switch (opcao)
    {
    case 1:
      cout << "\nDigite a matricula: ";
      cin >> matr;
      cout << "Digite a nota 1: ";
      cin >> n1;
      cout << "Digite a nota 2: ";
      cin >> n2;
      CadAlunos.inclui(matr, n1, n2);
      break;
    case 2:
      cout << "\nDigite a matricula do aluno a consultar: ";
      cin >> matr;
      CadAlunos.consulta(matr);
      break;
    case 3:
      cout << "\nOpcao listar turma, listando:\n";
      CadAlunos.listaVet();
      break;
    case 4:
      cout << "\nDigite a matricula do aluno a excluir: ";
      cin >> matr;
      CadAlunos.exclui(matr);
      break;
    case 5:
      cout << "\nDigite a matricula do aluno a consultar: ";
      cin >> matr;
      CadAlunos.altera(matr);
      break;
    case 6:
      sair = true;
      break;
    default:
      cout << "\nA opcao digitada nao existe! Tente novamente. \n\n";
    }
  } while (!sair);
  return 0;
}