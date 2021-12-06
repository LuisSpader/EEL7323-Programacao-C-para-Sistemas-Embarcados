/* File class_Aluno.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o número de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_alunos] > aluno(nota[n_notas], media_final, matricula)
  * Numéro de matrícula deve ser único
  * Métodos: consulta_aluno, listagem_alunos(mostra todos os campos), exclusão_aluno, altera_dados_aluno(exceto matrícula)
*/

//---------------------------- LIBRARIES ------------------------ //
#include <string.h> // Para trabalhar com strings
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
// #include <string.h>  // Para trabalhar com strings
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

//---------------------------- MY LIBRARIES ------------------------ //
#include "class_Aluno.cpp"

//---------------------------- CONSTANTS ------------------------ //
#define N_ALUNOS 20

class class_Turma
{
private:
  class_Aluno aluno[N_ALUNOS];

public:
  // classe_Turma();  // Construtor: inicia objeto
  // ~classe_Turma(); // Destrutor: destroi objeto

  void get_Consulta_aluno(int matricula);
  void get_Listagem_alunos();
  void set_NovoAluno(int NewMatricula, float NewNota1, float NewNota2);
  void Altera_dados_aluno(int matricula, float NewNota1, float NewNota2); // o número de matrícula não pode ser alterado
  void Exclui_aluno(int matricula);
};