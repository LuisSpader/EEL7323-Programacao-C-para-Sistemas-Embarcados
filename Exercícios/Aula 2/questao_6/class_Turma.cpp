/* File class_Turma.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o número de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_alunos] > aluno(nota[n_notas], media_final, matricula)
  * Numéro de matrícula deve ser único
  * Métodos: consulta_aluno, listagem_alunos(mostra todos os campos), exclusão_aluno, altera_dados_aluno(exceto matrícula)
*/
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "class_Turma.h"

// ============== MÉTODOS DA CLASSE =========== //
void class_Turma::get_Consulta_aluno(int matricula)
{
  for (int i = 0; i < N_ALUNOS; i++)
  {
    if (class_Aluno[i].getMatricula() == matricula)
    {
      cout << "Matrícula: " << class_Aluno[i].getMatricula() << endl;
      cout << "Nota 1: " << class_Aluno[i].getNota1() << endl;
      cout << "Nota 2: " << class_Aluno[i].getNota2() << endl;
      cout << "Média Final: " << class_Aluno[i].getMedia() << endl;
      break;
    }
    else if (i = (N_ALUNOS - 1))
    {
      cout << "Matrícula não encontrada" << endl;
    }
  }
}
void class_Turma::get_Listagem_alunos()
{
  cout << "Matrícula || Nota 1 || Nota 2 || Média Final" << endl;

  for (int i = 0; i < N_ALUNOS; i++)
  {
    cout << class_Aluno[i].getMatricula() << " || ";
    cout << class_Aluno[i].getNota1() << " || ";
    cout << class_Aluno[i].getNota2() << " || ";
    cout << class_Aluno[i].getMedia() << endl;
  }
}
void class_Turma::set_NovoAluno(int NewMatricula, float NewNota1, float NewNota2)
{
  for (int i = 0; i < N_ALUNOS; i++)
  {
    if (class_Aluno[i].getMatricula() == matricula)
    {
      cout << "Matrícula já existente" << endl;
    }
    else if (i = (N_ALUNOS - 1))
    {
      class_Aluno[i].setMatricula(NewMatricula);
      class_Aluno[i].setNota1(NewNota1);
      class_Aluno[i].setNota2(NewNota2);
    }
  }
}

void class_Turma::Altera_dados_aluno(int matricula, float NewNota1, float NewNota2)
{
  for (int i = 0; i < N_ALUNOS; i++)
  {
    if (class_Aluno[i].getMatricula() == matricula)
    {
      class_Aluno[i].setNota1(NewNota1);
      class_Aluno[i].setNota2(NewNota2);
      break;
    }
    else if (i = (N_ALUNOS - 1))
    {
      cout << "Matrícula não encontrada" << endl;
    }
  }
} // o número de matrícula não pode ser alterado
void class_Turma::Exclui_aluno(int matricula)
{
  for (int i = 0; i < N_ALUNOS; i++)
  {
    if (matricula == class_Aluno[i].getMatricula())
    {
      class_Aluno[i].setMatricula(0);
      class_Aluno[i].setNota1(0);
      class_Aluno[i].setNota2(0);
    }
    else if (i = (N_ALUNOS - 1))
    {
      cout << "Matrícula não encontrada" << endl;
    }
  }
}

// ============== MAIN =========== //

int main()
{
  int buffer;
  cout << "=========== Programa Turma " << N_ALUNOS << " alunos ===========" << endl;
  cout << "Digite a operação desejada:" << endl;
  cout << "1 - Cadastro Novo Aluno" << endl;
  cout << "2 - Consulta Aluno" << endl;
  cout << "3 - Listagem Alunos" << endl;
  cout << "4 - Alterar dados Aluno" << endl;
  cout << "5 - Excluir Aluno" << endl;
  cin >> buffer;
}