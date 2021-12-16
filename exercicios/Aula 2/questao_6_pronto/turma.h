/* File alunos.h


   Descricao: Definicao dos "headers" (interface) para a classe alunos

*/

#include "alunos.h"

#define N_ALUNOS 20

class Turma
{
public:
    Aluno aluno[N_ALUNOS];

public:
    void listaTurma(void);
    void novoAluno(int matricula, int nota1, int nota2);
    void consultaAluno(int matricula);
    void alteraAluno(int matricula, int nota1, int nota2);
    void excluiAluno(int matricula);

};
