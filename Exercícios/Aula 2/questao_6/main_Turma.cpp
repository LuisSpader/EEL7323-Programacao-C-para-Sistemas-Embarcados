/* File main_Turma.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e numero de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o numero de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o numero de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_alunos] > aluno(nota[n_notas], media_final, matricula)
  * Numéro de matrícula deve ser único
  * Métodos: consulta_aluno, listagem_alunos(mostra todos os campos), exclusão_aluno, altera_dados_aluno(exceto matrícula)
*/
#include <iostream>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <string.h> // Para trabalhar com strings
#include "class_Turma.cpp"
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

int main()
{
  class_Turma turma;
  int b_matricula, b_switch;
  float b_n1, b_n2;
  bool continuar = true;

  while (continuar == true) // enquanto encerraPrograma = false;
  {
    // cout << "--------------------------------------- \n \n " << endl;
    cout << "=========== Programa Turma ===========" << endl;
    cout << "Capacidade: " << N_ALUNOS << " alunos; Vagas: " << turma.vagas << endl;
    cout << "Digite a operacao desejada:" << endl;
    cout << "1 - Cadastro Novo Aluno" << endl;
    cout << "2 - Consulta Aluno" << endl;
    cout << "3 - Listagem Alunos" << endl;
    cout << "4 - Alterar dados Aluno" << endl;
    cout << "5 - Excluir Aluno" << endl;
    cout << "6 - Encerra Programa" << endl;
    cin >> b_switch;

    switch (b_switch)
    {
    case 1: // 1 - Cadastro Novo Aluno
    {
      cout << "Digite o numero de matricula" << endl;
      cin >> b_matricula;
      cout << "Digite a primeira nota" << endl;
      cin >> b_n1;
      cout << "Digite a segunda nota" << endl;
      cin >> b_n2;

      turma.set_NovoAluno(b_matricula, b_n1, b_n2);
    }
    break;

    case 2: // 2 - Consulta Aluno
    {

      cout << "Digite o numero de matricula" << endl;
      cin >> b_matricula;

      turma.get_Consulta_aluno(b_matricula);
      break;
    }

    case 3: // 3 - Listagem Alunos
    {
      turma.get_Listagem_alunos();
    }
    break;

    case 4: // 4 - Alterar dados Aluno
    {
      cout << "Digite o numero de matricula" << endl;
      cin >> b_matricula;
      cout << "Digite a primeira nota" << endl;
      cin >> b_n1;
      cout << "Digite a segunda nota" << endl;
      cin >> b_n2;

      turma.Altera_dados_aluno(b_matricula, b_n1, b_n2);
    }
    break;

    case 5: // Excluir Aluno
    {
      cout << "Digite o numero de matricula" << endl;
      cin >> b_matricula;
      turma.Exclui_aluno(b_matricula);
      break;
    }

    case 6: // Encerra programa
    {
      continuar = false;
      break;
    }
    default:
    {
      cout << "Opcao invalida, tente novamente" << endl;
      break;
    }
    }
  }
  return 0;
}