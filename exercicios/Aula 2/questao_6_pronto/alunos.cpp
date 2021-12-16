#include "alunos.h"

using namespace std;


Aluno::Aluno()
{
    matricula = 0;
    nota1 = 0;
    nota2 = 0;
}

Aluno::~Aluno()
{

}

void Aluno::setMatricula(int matricula)
{
    this->matricula = matricula;
}

void Aluno::setNota1(float nota)
{
    if ((nota >= 0) && (nota <= 100))
        nota1 = nota;
    else
        cout << "Nota inválida, insira um valor entre 0 e 100" << endl;
}

void Aluno::setNota2(float nota)
{
    if ((nota >= 0) && (nota <= 100))
        nota2 = nota;
    else
        cout << "Nota inválida, insira um valor entre 0 e 100" << endl;
}

int Aluno::getMatricula()
{
    return matricula;
}

float Aluno::getNota1(void)
{
    return nota1;
}

float Aluno::getNota2(void)
{
    return nota2;
}

float Aluno::getNotaFinal(void)
{
    return (nota1 + nota2)/2;
}


