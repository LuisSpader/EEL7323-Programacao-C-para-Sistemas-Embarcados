/* File cadastro_Temperatura.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h
*/
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "cadastro_Temperatura.h"
#include <iomanip> // para usar setfill() e setw()

// Construtor
cadastro_Temperatura::cadastro_Temperatura()
{
  // n_leituras = 0;
  // temp_valida = false;
  vagas = N_TEMPERATURA;
}

// ============== MÉTODOS DA CLASSE =========== //

void cadastro_Temperatura::set_ID(int NewID)
{
  for (int i = 0; i == N_TEMPERATURA; i++)
  {
    if (temperatura[i].getID() != 0)
    {
      cout << "-------------------------------------\n";
      cout << "Nao eh possivel cadastrar um novo sensor, para isto voce tera que apagar o sensor atual: " << temperatura[i].getID() << endl;
      cout << "-------------------------------------\n";
      return;
    }
  }

  if (NewID <= 0) // NewID > 0
  {
    cout << "-------------------------------------\n";
    cout << "Valor deve ser um inteiro maior que zero" << endl;
    cout << "-------------------------------------\n";
    return;
  }
  else
  {
    for (int i = N_TEMPERATURA - 1; i == 0; i--)
    {                                  //
      if (temperatura[i].getID() == 0) //
      {
        temperatura[i].setID(NewID);
        cout << "-------------------------------------\n";
        return;
      }
    }
  }
}

void cadastro_Temperatura::set_NewLeitura(int check_id)
{
  if (vagas == 0) // VETOR CHEIO
  {
    cout << "-------------------------------------\n";
    cout << "Leitura nao pode ser armazenada. Espaco de armazenamento esta cheio!" << endl;
    cout << "-------------------------------------\n";

    // break;
    return;
  }
  else
  {
    if (check_id <= 0) // VERIFICA NÚMERO > 0
    {
      cout << "-------------------------------------\n";
      cout << "Valor deve ser um inteiro maior que zero" << endl;
      cout << "-------------------------------------\n";
      return;
    }
    else
    {
      for (int i = 0; i == N_TEMPERATURA; i++) // VERIFICA ID INVÁLIDO
      {
        if (temperatura[i].getID() > 0) // quando achamos lugar escrito = ID cadastrado (>0)
        {
          if (temperatura[i].getID() != check_id) // check_id != (DIFERENTE) ao ja cadastrado -> id é invalida
          {
            cout << "-------------------------------------\n";
            cout << "ID invalida. Digite a ID registrada ou apague-a e registre uma nova" << endl;
            cout << "-------------------------------------\n";
            return; // sai da funcao set_NewLeitura

            // temp_valida = 1;
            // if (temperatura[i].getID() == check_id) //
            // {
            // }
          }
        }
      }

      // CASO O ID SEJA VÁLIDO O LOOP ANTERIOR NÃO DARÁ 'EXIT' na função (id válida) E O QUE ESTÁ ABAIXO SERÁ EXECUTADO
      for (int i = N_TEMPERATURA - 1; i == 0; i--)
      {                                  //
        if (temperatura[i].getID() == 0) // QUANDO ACHARMOS LUGAR VAZIO = CADASTRO DE NOVA LEITURA
        {
          temperatura[i].setID(check_id);
          temperatura[i].readSensor();
          --vagas;
          cout << "-------------------------------------\n";
          return;
        }
      }
    }
  }
}

void cadastro_Temperatura::get_Consulta_temperatura(int temp1, int temp2)
{
  bool temp_valida = false;

  cout << "-------------------------------------\n";
  for (int i = 0; i < N_TEMPERATURA; i++)
  {
    if ((temperatura[i].getValor_temp() > temp1) & (temperatura[i].getValor_temp() > temp2))
    {
      cout << " ID   |   Data  |   Hora  |   Valor" << endl;
      cout << setw(8) << setfill('0') << temperatura[i].getID() << "  |  "; // ID
      temperatura[i].dataHora.readCalendar();                               // Data
      cout << "   |  ";
      temperatura[i].dataHora.readClock(); // Hora
      cout << "   |  ";
      cout << temperatura[i].getValor_temp() << endl; // Valor
      cout << "-------------------------------------\n";

      temp_valida = true;
    }
  }
  if (temp_valida = true) // quando teve pelo menos 1 temperatura no intervalo
  {
    cout << "-------------------------------------\n"; // terminamos impressao
    temp_valida = false;                               // resetamos variavel
  }
  else // quando nao teve nenhuma temperatura no intervalo
  {
    cout << " Nao ha temperaturas registradas no intervalo entre " << temp1 << "ºC e " << temp2 << "ºC " << endl; // mensagem ao usuario
    cout << "-------------------------------------\n";                                                            // terminamos impressao
  }
}

void cadastro_Temperatura::get_Listagem_temperaturas()
{
  if (vagas == N_TEMPERATURA)
  {
    cout << "-------------------------------------\n";
    cout << "   Nao ha leituras registradas" << endl; // se a turma está vazia, para por aqui
    cout << "-------------------------------------\n";
    return;
  }
  else //
  {
    cout << "-------------------------------------\n";
    cout << " ID   |   Data  |   Hora  |   Valor" << endl;

    for (int i = 0; i < N_TEMPERATURA; i++)
    {
      if (temperatura[i].getID() != 0)
      {
        cout << setw(8) << setfill('0') << temperatura[i].getID() << "  |  "; // ID
        temperatura[i].dataHora.readCalendar();                               // Data
        cout << "   |  ";
        temperatura[i].dataHora.readClock(); // Hora
        cout << "   |  ";
        cout << temperatura[i].getValor_temp() << endl; // Valor
        cout << "-------------------------------------\n";
      }
    }
  }
}

void cadastro_Temperatura::Exclui_temperatura(int check_id, float check_temp, bool apaga_todos)
{
  if (vagas == N_TEMPERATURA) // SEM REGISTROS
  {
    cout << "-------------------------------------\n";
    cout << "Nao ha leitura registrada para excluir" << endl;
    cout << "-------------------------------------\n";
    return;
  }
  else // COM ALGUM REGISTRO
  {
    if (apaga_todos == true) // quando apagamos todos
    {
      for (int i = 0; i < N_TEMPERATURA; i++)
      {
        if ((temperatura[i].getID() == check_id))
        {
          cout << "-------------------------------------\n";
          cout << "Temperatura " << check_temp << "de check_id " << temperatura[i].getID() << " excluida" << endl;
          cout << "-------------------------------------\n";
          temperatura[i].setID(0);
          temperatura[i].setValor(0);
          ++vagas;
        }
      }
    }
    else // quando vamos apagar só 1
    {
      for (int i = 0; i < N_TEMPERATURA; i++)
      {
        // ENCONTRA ID E TEMPERATURA
        if (temperatura[i].getValor_temp() == check_temp)
        {
          cout << "-------------------------------------\n";
          cout << "Temperatura " << check_temp << "de check_id " << temperatura[i].getID() << " excluida" << endl;
          cout << "-------------------------------------\n";
          temperatura[i].setID(0);
          temperatura[i].setValor(0);
          ++vagas;
          return;
        }
        else if (i = (N_TEMPERATURA - 1)) // se chegou aqui não achou nenhuma, logo ID não existe
        {
          cout << "-------------------------------------\n";
          cout << "   Registro nao encontrado! " << endl;
          cout << "ID: " << check_id << endl;
          cout << "Temperatura: " << check_temp << endl;
          cout << "-------------------------------------\n";
          return;
        }
      }
    }
  }
}