/* File class_Turma.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o número de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_matriculados] > aluno(nota[n_notas], media_final, matricula)
  * Numéro de matrícula deve ser único
  * Métodos: consulta_aluno, listagem_alunos(mostra todos os campos), exclusão_aluno, altera_dados_aluno(exceto matrícula)
*/
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "class_Turma.h"
#include <iomanip> // para usar setfill() e setw()

// Construtor
class_Turma::class_Turma()
{
  n_matriculados = 0;
  vagas = N_ALUNOS;
}

// ============== MÉTODOS DA CLASSE =========== //
void class_Turma::get_Consulta_aluno(int matricula)
{
  if (n_matriculados == 0)
  {
    cout << "A turma esta vazia \n \n --------" << endl;
  }
  else
  {

    for (int i = 0; i < N_ALUNOS; i++)
    {
      if (aluno[i].getMatricula() == matricula)
      {
        cout << "Matricula: " << aluno[i].getMatricula() << endl;
        cout << "Nota 1: " << aluno[i].getNota1() << endl;
        cout << "Nota 2: " << aluno[i].getNota2() << endl;
        cout << "Media Final: " << aluno[i].getMedia() << endl;
        break;
      }
      else if (i = (N_ALUNOS - 1))
      {
        cout << "Matricula nao encontrada" << endl;
      }
    }
  }
}
void class_Turma::get_Listagem_alunos()
{
  if (n_matriculados == 0)
  {
    cout << "A turma esta vazia \n \n --------" << endl;
  }
  else
  {
    cout << "Matricula | Nota 1 | Nota 2 | Media Final" << endl;

    for (int i = 0; i < N_ALUNOS; i++)
    {
      if (aluno[i].getMatricula() != 0)
      {
        cout << setw(8) << setfill('0') << aluno[i].getMatricula() << "  |  "
             << setw(3) << setfill(' ') << aluno[i].getNota1() << "   |  "
             << setw(3) << setfill(' ') << aluno[i].getNota2() << "   |  "
             << setw(3) << setfill(' ') << aluno[i].getMedia() << endl;

        // cout << setw(8) << setfill('0') << aluno[i].getMatricula() << " | "
        //      << aluno[i].getNota1() << setw(3) << setfill('0') << " | "
        //      << aluno[i].getNota2() << setw(3) << setfill('0') << " | "
        //      << aluno[i].getMedia() << setw(3) << setfill('0') << endl;}
      }
    }
  }
}
void class_Turma::set_NovoAluno(int NewMatricula, float NewNota1, float NewNota2)
{
  bool repetida = false;

  if (vagas == 0) // TURMA CHEIA
  {
    cout << "A turma esta cheia \n \n --------" << endl;
    // break;
  }
  else
  {

    for (int i = N_ALUNOS - 1; i == 0; i--) // VERIFICA REPETIÇÃO MATRICULA
    {
      if (aluno[i].getMatricula() == NewMatricula)
      {
        repetida = true;
        cout << "Matricula já existente" << endl;
        break;
      }
    }
    // else
    if (repetida == false) // só adicionaremos alguem se nao é matricula repetida
    {
      for (int i = 0; i < N_ALUNOS; i++) // ADICIONA O QUANTO ANTES NA LISTA
      {
        if (aluno[i].getMatricula() == 0)
        {
          ++n_matriculados;
          --vagas;
          aluno[i].setMatricula(NewMatricula);
          aluno[i].setNota1(NewNota1);
          aluno[i].setNota2(NewNota2);
          // cout << "Vagas: " << vagas << endl;
          break;
        }
      }
    }
  }
}
void class_Turma::Altera_dados_aluno(int matricula, float NewNota1, float NewNota2)
{
  if (n_matriculados == 0)
  {
    cout << "A turma ja esta vazia" << endl;
  }
  else
  {
    for (int i = 0; i < N_ALUNOS; i++)
    {
      if (aluno[i].getMatricula() == matricula)
      {
        aluno[i].setNota1(NewNota1);
        aluno[i].setNota2(NewNota2);
        break;
      }
      else if (i = (N_ALUNOS - 1))
      {
        cout << "Matricula não encontrada" << endl;
      }
    }
  }
} // o número de matrícula não pode ser alterado
void class_Turma::Exclui_aluno(int matricula)
{
  if (n_matriculados == 0)
  {
    cout << "A turma esta vazia  \n \n --------" << endl;
  }
  else
  {
    for (int i = 0; i < N_ALUNOS; i++)
    {
      if (matricula == aluno[i].getMatricula())
      {
        cout << "Aluno de matricula " << aluno[i].getMatricula() << " excluido" << endl;
        aluno[i].setMatricula(0);
        aluno[i].setNota1(0);
        aluno[i].setNota2(0);
        --n_matriculados;
        ++vagas;
        break;
      }
      else if (i = (N_ALUNOS - 1))
      {
        cout << "Matricula nao encontrada" << endl;
      }
    }
  }
}