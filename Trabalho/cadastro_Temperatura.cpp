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

void cadastro_Temperatura::set_new_ID(int NewID)
{

  if (NewID <= 0) // NewID > 0
  {
    cout << "---------------------------------------------------------------\n";
    cout << "Valor deve ser um inteiro maior que zero!" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  }
  for (int i = 0; i < N_TEMPERATURA + 1; i++)
  {
    if (vtemperatura[i].getID_temp() == NewID) // verifica id repetido
    {
      cout << "---------------------------------------------------------------\n";
      cout << "                   Este ID ja existe!" << endl;
      cout << "---------------------------------------------------------------\n";
      return;
    }
    else
    {
      if (vtemperatura[i].getID_temp() == 0) // quando temperatura = 0 = vazio
      {
        vtemperatura[i].setID_temp(NewID);
        cout << "---------------------------------------------------------------\n";
        cout << "             Sensor de ID: " << NewID << " registrado!" << endl;
        cout << "---------------------------------------------------------------\n";
        return;
        // break;
      }
      else if (i == N_TEMPERATURA)
      {
        cout << "---------------------------------------------------------------\n";

        cout << "           Nao ha espaco para novos IDs" << endl;
        cout << "---------------------------------------------------------------\n";
        return;
      }
    }
  }
}

void cadastro_Temperatura::set_NewLeitura(int check_id)
{
  if (vagas == 0) // VETOR CHEIO
  {
    cout << "---------------------------------------------------------------\n";
    cout << "Leitura nao pode ser armazenada. Espaco de armazenamento esta cheio!" << endl;
    cout << "---------------------------------------------------------------\n";

    // break;
    return;
  }

  // CASO O ID SEJA VÁLIDO O LOOP ANTERIOR NÃO DARÁ 'EXIT' na função (id válida) E O QUE ESTÁ ABAIXO SERÁ EXECUTADO
  for (int i = 0; i < N_TEMPERATURA; i++)
  {                                               // loop de checagem id válido (já existente em alguma linha)
    if (vtemperatura[i].getID_temp() == check_id) // se achamos algum ID igual ao check_id, entao podemos cadastrar uma nova leitura
    //  porém essa nova leitura pode ser uma linha que já tem o ID mas não tem a temperatura (= -300)
    //  ou a nova leitura sera em uma linha onde nao temos NENHUM ID
    {
      // aí aqui fazemos o loop para procurar registros vazios (temperatura = -300) com o ID passado que já foi validado no 'if' anterior
      for (int i = 0; i < N_TEMPERATURA; i++)
      {
        if ((vtemperatura[i].getID_temp() == 0 || vtemperatura[i].getID_temp() == check_id) & vtemperatura[i].getValor_temp() == -300) // QUANDO ACHARMOS LUGAR VAZIO (temperatura = -300) => CADASTRO DE NOVA LEITURA
        {
          vtemperatura[i].setID_temp(check_id);
          vtemperatura[i].readSensor();
          --vagas;

          cout << "---------------------------------------------------------------\n";
          cout << "Registro efetuado: \n";
          cout << "    ID    |      Data     |     Hora     |   Valor" << endl;
          cout << setw(8) << setfill('0') << vtemperatura[i].getID_temp() << "  |  "; // ID
          vtemperatura[i].dataHora.readCalendar();                                    // Data
          cout << "   |   ";
          vtemperatura[i].dataHora.readClock(); // Hora
          cout << "   |  ";
          cout << vtemperatura[i].getValor_temp() << endl; // Valor
          cout << "---------------------------------------------------------------\n \n";

          // cout << "ID: " << vtemperatura[i].getID_temp() << "; Valor: " << vtemperatura[i].getValor_temp() << endl;
          return;
        }
      }
    }
  } // caso nao dado exit (return;) irá chegar até aqui. Isso só ocorre se a nao achou nenhuma ID compatível
  cout << "---------------------------------------------------------------\n";
  cout << "                   ID nao encontrada!"
       << endl;
  cout << "---------------------------------------------------------------\n \n";
}

void cadastro_Temperatura::get_Lista_IDs()
{
  cout << "---------------------------------------------------------------\n";
  for (int i = 0; i < N_TEMPERATURA; i++)
  {

    cout << "ID[" << i << "] - " << vtemperatura[i].getID_temp() << endl;
    cout << "---------------------------------------------------------------\n";
  }
}

void cadastro_Temperatura::get_Consulta_temperatura(int temp1, int temp2)
{
  bool temp_valida = false;

  cout << "---------------------------------------------------------------\n";
  for (int i = 0; i < N_TEMPERATURA; i++)
  {
    if ((vtemperatura[i].getValor_temp() > temp1) & (vtemperatura[i].getValor_temp() < temp2))
    {
      cout << "    ID    |      Data     |     Hora     |   Valor" << endl;
      cout << setw(8) << setfill('0') << vtemperatura[i].getID_temp() << "  |  "; // ID
      vtemperatura[i].dataHora.readCalendar();                                    // Data
      cout << "   |   ";
      vtemperatura[i].dataHora.readClock(); // Hora
      cout << "   |  ";
      cout << vtemperatura[i].getValor_temp() << endl; // Valor
      cout << "---------------------------------------------------------------\n";

      temp_valida = true;
    }
  }
  if (temp_valida = true) // quando teve pelo menos 1 vtemperatura no intervalo
  {
    cout << "---------------------------------------------------------------\n";
    // terminamos impressao
    temp_valida = false; // resetamos variavel
  }
  else // quando nao teve nenhuma vtemperatura no intervalo
  {
    cout << " Nao ha temperaturas registradas no intervalo entre " << temp1 << "ºC e " << temp2 << "ºC " << endl; // mensagem ao usuario
    cout << "---------------------------------------------------------------\n";
    // terminamos impressao
  }
}

void cadastro_Temperatura::get_Listagem_temperaturas()
{
  if (vagas == N_TEMPERATURA)
  {
    cout << "---------------------------------------------------------------\n";
    cout << "   Nao ha leituras registradas" << endl; // se a turma está vazia, para por aqui
    cout << "---------------------------------------------------------------\n";
    return;
  }
  else //
  {
    cout << "---------------------------------------------------------------\n";
    cout << "    ID    |      Data     |     Hora     |   Valor" << endl;

    for (int i = 0; i < N_TEMPERATURA; i++)
    {
      if (vtemperatura[i].getID_temp() > -300)
      {
        cout << setw(8) << setfill('0') << vtemperatura[i].getID_temp() << "  |  "; // ID
        vtemperatura[i].dataHora.readCalendar();                                    // Data
        cout << "   |   ";
        vtemperatura[i].dataHora.readClock(); // Hora
        cout << "   |  ";
        cout << vtemperatura[i].getValor_temp() << endl; // Valor
      }
    }
  }
  cout << "---------------------------------------------------------------\n";
}

void cadastro_Temperatura::Exclui_temperatura(int check_id, float check_temp, bool apaga_todos)
{
  if (vagas == N_TEMPERATURA) // SEM REGISTROS
  {
    cout << "---------------------------------------------------------------\n";
    cout << "            Nao ha leitura registrada para excluir" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  }
  // COM ALGUM REGISTRO

  // if (apaga_todos == true) // quando apagamos todos
  // {
  // for (int i = 0; i < N_TEMPERATURA; i++)
  // {
  //   if ((vtemperatura[i].getID_temp() == check_id))
  //   {
  //     cout << "-------------------------------------\n";
  //     cout << "Temperatura " << check_temp << "de check_id " << vtemperatura[i].getID_temp() << " excluida" << endl;
  //     cout << "-------------------------------------\n";
  //     vtemperatura[i].setID_temp(0);
  //     vtemperatura[i].setValor_temp(0);
  //     ++vagas;
  //   }
  // }

  // else // quando vamos apagar só 1
  // {

  for (int i = 0; i < N_TEMPERATURA; i++)
  {
    // ENCONTRA ID E TEMPERATURA
    if ((vtemperatura[0].getValor_temp() > (check_temp - 0.01)) & (vtemperatura[0].getValor_temp() < (check_temp + 0.01)) & (vtemperatura[0].getID_temp() == check_id))
    {
      cout << "---------------------------------------------------------------\n";
      cout << "                     Registro excluido:" << endl;
      cout << "ID: " << vtemperatura[0].getID_temp() << "; Temperatura: " << vtemperatura[0].getValor_temp() << endl;
      cout << "---------------------------------------------------------------\n";
      vtemperatura[0].setID_temp(0);
      vtemperatura[0].setValor_temp(0);
      ++vagas;
      return;
    }
    cout << vtemperatura[0].getValor_temp();
    cout << vtemperatura[0].getID_temp();
    // return;
    // }
    // else if (i = (N_TEMPERATURA - 1)) // se chegou aqui não achou nenhuma, logo ID não existe
    // {
    cout << "---------------------------------------------------------------\n";
    cout << "                 Registro nao encontrado! " << endl;
    cout << "ID: " << check_id << "; Temperatura: " << check_temp << endl;
    cout << "---------------------------------------------------------------\n";
    //   return;
    // }
    // }
  }
}

void interface_temp()
{

  bool continuar = true;
  int b_id, b_switch;
  float b_temp1, b_temp2;
  cadastro_Temperatura temperatura;

  while (continuar == true)
  {
    cout << "---------------------- Temperatura ----------------------------\n";

    cout << "Capacidade: " << N_TEMPERATURA << " registros; Leituras disponiveis para registro: " << temperatura.vagas << endl;

    cout << "1 - Cadastro de Sensor" << endl;
    cout << "2 - Registro Leitura do Sensor" << endl;
    cout << "3 - Consultar " << endl;
    cout << "4 - Lista IDs" << endl;
    cout << "5 - Listar todas as leituras" << endl;
    cout << "6 - Excluir " << endl;
    cout << "7 - Voltar " << endl;

    cout << "Digite a operacao desejada:";
    cin >> b_switch;

    switch (b_switch)
    {
      // --------------- Temperatura ---------------
    case 1: // 1 - Cadastro de Sensor
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;
      temperatura.set_new_ID(b_id);
      break;
    }

    case 2: // 2 - Registo Leitura do Sensor
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;
      temperatura.set_NewLeitura(b_id);
      break;
      // o valor de leitura já é realizado na classe 'Temperatura' que fornece um rand para o método setValor da classe 'Sensor'
      // a data tbm gera automatico -> pega do sistema operacional
    }

    case 3: // 3 - Consultar
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;

      cout << "Digite os limites do intervalo de temperatura (temp1 a temp2) em graus Celsius" << endl;
      cout << "Temperatura 1: ";
      cin >> b_temp1;
      cout << "Temperatura 2: ";
      cin >> b_temp2;

      temperatura.get_Consulta_temperatura(b_temp1, b_temp2);
      break;
    }

    case 4: // 4 - Listar IDs
    {
      temperatura.get_Lista_IDs();
      break;
    }
    case 5: // 4 - Listar todas as leituras de 1 ID
    {
      temperatura.get_Listagem_temperaturas();
      break;
    }

    case 6: // Excluir
    {

      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;

      cout << "Digite a temperatura que deseja excluir: ";
      cin >> b_temp1;
      temperatura.Exclui_temperatura(b_id, b_temp1, false);

      // cout << "Qual dos registros voce deseja excluir:" << endl;
      // for (int i = 0; i < N_TEMPERATURA; i++)
      // {
      //   if (temperatura.vtemperatura[i].getValor_temp() > (-273.15))
      //   {
      //     cout << i << " - " << vtemperatura[i].getValor_temp() << endl;
      //   }
      // }
      // cout << "Voce deseja excluir um ou todos os registros?\n";
      // cout << "1 - Apenas um registro do sensor" << endl;
      // cout << "2 - Todos os registros do sensor" << endl;
      // cin >> b_temp2;

      // if (b_temp2 == 2)
      // {
      //   temperatura.Exclui_temperatura(b_temp1, 0, true);
      //   break;
      // }
      // else
      // {
      //   cout << "Digite a temperatura que deseja excluir: ";
      //   cin >> b_temp1;
      //   temperatura.Exclui_temperatura(b_temp1, b_temp1, false);
      break;
      // }
    }

    case 7: // Sai Sensor
    {
      continuar = false;
    }
    default:
    {
      cout << "Opcao invalida, tente novamente" << endl;
      break;
    }
    }
  }
  // return 0;
}