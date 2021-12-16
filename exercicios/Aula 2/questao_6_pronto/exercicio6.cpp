/*
Desenvolver um programa para cálculo e armazenagem das notas dos alunos em uma disciplina. 
Considerar que a disciplina possui apenas duas avaliações, e o programa permite a entrada 
das notas das duas avaliações para cada um dos 20 alunos da turma, e calcula a nota final. 
As informações sobre as notas e número de matrícula dos alunos devem ficar armazenadas em 
um vetor que representa o cadastro de alunos. Esse vetor deverá armazenar objetos Aluno, 
sendo que cada objeto aluno deverá possuir os atributos e métodos necessários para a resolução 
do problema. O programa deverá possuir facilidades para o usuário realizar operações de entrada 
de dados (o número de matrícula deve ser único), consulta a um aluno, listagem de todos os 
alunos mostrando todos os campos, exclusão de alunos, e alteração dos dados de um aluno 
(o número de matrícula não pode ser alterado).
*/

#include <iostream>
#include "turma.h"

using namespace std;

int main (int argc, const char * argv[]) {
    
    Turma turma;    //Clase para armazenar os dados dos alunos
    bool encerraPrograma = false;
    int nota1, nota2, matricula, acao;

    cout << "Programa para cadastrar alunos." << endl;
    while(!encerraPrograma)
    {
        cout << "Selecione a ação desejada:" << endl;
        cout << "1 - Listar todos os alunos cadastrados;" << endl;
        cout << "2 - Cadastrar novo aluno;" << endl;
        cout << "3 - Consultar apenas um aluno;" << endl;
        cout << "4 - Alterar notas de um aluno;" << endl;
        cout << "5 - Excluir aluno." << endl;
        cout << "6 - Sai do programa" << endl;
        cin >> acao;

        switch (acao)
        {
        case (1):
        {
            turma.listaTurma();
            break;
        }
        case (2):
        {
            cout << "Digite a matricula do aluno: ";
            cin >> matricula;
            cout << "Digite a nota da primeira prova: ";
            cin >> nota1;
            cout << "Digite a nota da segunda prova: ";
            cin >> nota2;
            turma.novoAluno(matricula, nota1, nota2);
            break;
        }
        case (3):
        {
            cout << "Digite a matricula do aluno: ";
            cin >> matricula;
            turma.consultaAluno(matricula);
            break;
        }
        case (4):
        {
            cout << "Digite a matricula do aluno: ";
            cin >> matricula;
            cout << "Digite a nova nota da primeira prova: ";
            cin >> nota1;
            cout << "Digite a nova nota da segunda prova: ";
            cin >> nota2;
            turma.alteraAluno(matricula, nota1, nota2);            
            break;
        }
        case (5):
        {
            cout << "Digite a matricula do aluno: ";
            cin >> matricula;
            turma.excluiAluno(matricula);
            break;
        }
        case (6):
        {
            encerraPrograma = true;
            break;
        }
        
        default:
            cout << "Opção inválida, tente novamente" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}