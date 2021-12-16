/* File class_Sensor.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  6. Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno (o número de matrícula não pode ser alterado).

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h

  main > turma[n_alunos] > aluno(nota[n_notas], media_final, id_sensor)
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
// #include "Data_nascimento.h"
#include "class_Sensor.h"
// #include <Cadastro_pessoa.cpp>

// Construtor: inicia classe -> para quê? Para quando vc quer inicializar coisas da classe com algum valor, se n pode ter qualquervalor aleatório ali dependendo do compilador
class_Sensor::class_Sensor()
{
  id_sensor = 0;
  valor = 0;
  nota2 = 0;
}

class_Sensor::~class_Sensor()
{
}

void class_Sensor::setId(int newId)
{ //* Numéro de matrícula deve ser único
  id_sensor = newId;
}

void class_Sensor::setNota1(float newNota)
{
  if ((newNota >= 0) && (newNota <= 100))
    nota1 = newNota;
  else
    cout << "Nota inválida: valor válido entre 0 e 100" << endl;
}

void class_Sensor::setNota2(float newNota)
{
  if ((newNota >= 0) && (newNota <= 100))
    nota2 = newNota;
  else
    cout << "Nota inválida: valor válido entre 0 e 100" << endl;
}

int class_Sensor::getId()
{
  return id_sensor;
}

float class_Sensor::getNota1()
{
  return nota1;
}

float class_Sensor::getNota2()
{
  return nota2;
}

float class_Sensor::getMedia()
{
  return (nota1 + nota2) / 2;
}