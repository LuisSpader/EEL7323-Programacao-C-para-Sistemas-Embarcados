#include "turma.h"

using namespace std;


void Turma::listaTurma(void)
{
    int countAlunos = 0;
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula())
        {
            cout << "Matrícula = " << aluno[i].getMatricula();
            cout << " Nota1 = " << aluno[i].getNota1();
            cout << " Nota2 = " << aluno[i].getNota2();
            cout << " Média = " << aluno[i].getNotaFinal() << endl;
            countAlunos++;
        }
    }
    if (countAlunos == 0)
    {
        cout << "Nenhum aluno cadastrado" << endl;
    }
    
}

void Turma::novoAluno(int matricula, int nota1, int nota2)
{
    if (matricula <= 0)
    {
        cout << "Matrícula inválida. Matrícula deve ser maior de 0" << endl;
        cout << "Aluno não cadastrado" << endl;
        return;
    }

    //verifica se já existe algum aluno com a mesma matrícula
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula() == matricula)
        {
            cout << "Erro ao cadastrar novo aluno. Matrícula já existe" << endl;
            return;
        }
    }

    //Se matricula ok, preenche o cadastro do primeiro aluno com matrícula vazia
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula() == 0)
        {
            aluno[i].setMatricula(matricula);
            aluno[i].setNota1(nota1);
            aluno[i].setNota2(nota2);
            cout << "Aluno cadastrado com sucesso" << endl;
            break;
        }
        else if (i == (N_ALUNOS - 1))
        {
            cout << "Não é possível cadastrar mais aluno, turma cheia" << endl;
        }
        
    }
}

void Turma::consultaAluno(int matricula)
{
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula() == matricula)
        {
            cout << "Matrícula = " << aluno[i].getMatricula();
            cout << " Nota1 = " << aluno[i].getNota1();
            cout << " Nota2 = " << aluno[i].getNota2();
            cout << " Média = " << aluno[i].getNotaFinal() << endl;
            break;
        }
        else if (i == (N_ALUNOS - 1))
        {
            cout << "Matrícula não encontrada" << endl;
        }   
    }
}

void Turma::alteraAluno(int matricula, int nota1, int nota2)
{
    //procura a matrícula do aluno para alterar suas notas
    for (uint8_t i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula() == matricula)
        {
            aluno[i].setNota1(nota1);
            aluno[i].setNota2(nota2);
        }
        else if (i == (N_ALUNOS - 1))
        {
            cout << "Matrícula não encontrada" << endl;
        }        
    }
    

}

void Turma::excluiAluno(int matricula)
{
    //procura a matrícula do aluno a ser exluido
    for (uint8_t i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].getMatricula() == matricula)
        {
            aluno[i].setMatricula(0);
            aluno[i].setNota1(0);
            aluno[i].setNota2(0);
        }
        else if (i == (N_ALUNOS - 1))
        {
            cout << "Matrícula não encontrada" << endl;
        }        
    }
}