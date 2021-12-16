/* File alunos.h

   Descricao: Definicao dos "headers" (interface) para a classe alunos

*/

#include <iostream>
#include <string.h>

class Aluno
{
private:
    int matricula;
    float nota1;
    float nota2;

public:
    void setMatricula(int matricula);
    void setNota1(float nota);
    void setNota2(float nota);

    int getMatricula();
    float getNota1(void);
    float getNota2(void);
    float getNotaFinal(void);

    Aluno();
    ~Aluno();
};
