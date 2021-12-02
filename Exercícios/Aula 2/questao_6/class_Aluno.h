/* File class_Aluno.h

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o número de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_alunos] > aluno(nota[n_notas], media_final, matricula)
  * Numéro de matrícula deve ser único
  * Métodos: consulta_aluno, listagem_alunos(mostra todos os campos), exclusão_aluno, altera_dados_aluno(exceto matrícula)
*/
// dúvidas: vetores, como alterar dados do objeto, como deletar objeto

// ===================== LIBRARIES & CLASSES ===================== //
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iostream>  // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
#include <stdlib.h>  // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <string.h>  // Para trabalhar com strings

#include "Cadastro_pessoa.cpp" //Nome, idade, peso || Data_nascimento dob

// ===================== CONSTANTS ===================== //

#define n_notas = 2;

class class_Aluno : public Cadastro_pessoa
{
private: // private: só será acessado pelos métodos da própria classe
  // float nota[n_notas];
  float nota1, nota2;
  float media_final;
  int matricula;

public: // public: aqui qualquer classe acessa
  // funções SET
  void setMatricula(int newMatricula); //* Numéro de matrícula deve ser único
  void setNota1(float newNota);
  void setNota2(float newNota);

  // funções GET
  float getNota1();
  float getNota2();
  int getMatricula();
  float getMedia();

  class_Aluno();  // declara construtor
  ~class_Aluno(); // declara destrutor
};
