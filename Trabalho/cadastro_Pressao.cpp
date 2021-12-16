/* File cadastro_Pressao.cpp

  Luis Antonio Spader Simon <luisspaders@gmail.com>
  Curso: Engenharia Eletrônica - Graduação - CTC - UFSC
  2021

  Descricao: Definicao das funcoes membro para os "headers" declarados na classe.h
*/
using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...

#include "cadastro_Pressao.h"
#include <iomanip> // para usar setfill() e setw()

// Construtor
cadastro_Pressao::cadastro_Pressao()
{
  // n_leituras = 0;
  // temp_valida = false;
  vagas = N_PRESSAO;
}

// ============== MÉTODOS DA CLASSE =========== //

void cadastro_Pressao::set_new_ID(int NewID)
{

  if (NewID <= 0) // NewID > 0
  {
    cout << "---------------------------------------------------------------\n";
    cout << "Valor deve ser um inteiro maior que zero!" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  }
  for (int i = 0; i < N_PRESSAO + 1; i++)
  {
    if (vpressao[i].getID_pressao() == NewID) // verifica id repetido
    {
      cout << "---------------------------------------------------------------\n";
      cout << "                   Este ID ja existe!" << endl;
      cout << "---------------------------------------------------------------\n";
      return;
    }
    else
    {
      if (vpressao[i].getID_pressao() == 0) // quando pressao = 0 = vazio
      {
        vpressao[i].setID_pressao(NewID);
        cout << "---------------------------------------------------------------\n";
        cout << "             Sensor de ID: " << NewID << " registrado!" << endl;
        cout << "---------------------------------------------------------------\n";
        return;
        // break;
      }
      else if (i == N_PRESSAO)
      {
        cout << "---------------------------------------------------------------\n";

        cout << "           Nao ha espaco para novos IDs" << endl;
        cout << "---------------------------------------------------------------\n";
        return;
      }
    }
  }
}

void cadastro_Pressao::set_NewLeitura(int check_id)
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
  for (int i = 0; i < N_PRESSAO; i++)
  {                                              // loop de checagem id válido (já existente em alguma linha)
    if (vpressao[i].getID_pressao() == check_id) // se achamos algum ID igual ao check_id, entao podemos cadastrar uma nova leitura
    //  porém essa nova leitura pode ser uma linha que já tem o ID mas não tem a pressao (= -300)
    //  ou a nova leitura sera em uma linha onde nao temos NENHUM ID
    {
      // aí aqui fazemos o loop para procurar registros vazios (pressao = -300) com o ID passado que já foi validado no 'if' anterior
      for (int i = 0; i < N_PRESSAO; i++)
      {
        if ((vpressao[i].getID_pressao() == 0 || vpressao[i].getID_pressao() == check_id) & vpressao[i].getValor_pressao() == -300) // QUANDO ACHARMOS LUGAR VAZIO (pressao = -300) => CADASTRO DE NOVA LEITURA
        {
          vpressao[i].setID_pressao(check_id);
          vpressao[i].readSensor();
          --vagas;

          cout << "---------------------------------------------------------------\n";
          cout << "Registro efetuado: \n";
          cout << "    ID    |      Data     |     Hora     |   Valor" << endl;
          cout << setw(8) << setfill('0') << vpressao[i].getID_pressao() << "  |  "; // ID
          vpressao[i].dataHora.readCalendar();                                       // Data
          cout << "   |   ";
          vpressao[i].dataHora.readClock(); // Hora
          cout << "   |  ";
          cout << vpressao[i].getValor_pressao() << endl; // Valor
          cout << "---------------------------------------------------------------\n \n";

          // cout << "ID: " << vpressao[i].getID_pressao() << "; Valor: " << vpressao[i].getValor_pressao() << endl;
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

void cadastro_Pressao::get_Lista_IDs()
{
  cout << "---------------------------------------------------------------\n";
  for (int i = 0; i < N_PRESSAO; i++)
  {

    cout << "ID[" << i << "] - " << vpressao[i].getID_pressao() << endl;
    cout << "---------------------------------------------------------------\n";
  }
}

void cadastro_Pressao::get_Consulta_pressao(int temp1, int temp2)
{
  bool temp_valida = false;

  cout << "---------------------------------------------------------------\n";
  for (int i = 0; i < N_PRESSAO; i++)
  {
    if ((vpressao[i].getValor_pressao() > temp1) & (vpressao[i].getValor_pressao() < temp2))
    {
      cout << "    ID    |      Data     |     Hora     |   Valor" << endl;
      cout << setw(8) << setfill('0') << vpressao[i].getID_pressao() << "  |  "; // ID
      vpressao[i].dataHora.readCalendar();                                       // Data
      cout << "   |   ";
      vpressao[i].dataHora.readClock(); // Hora
      cout << "   |  ";
      cout << vpressao[i].getValor_pressao() << endl; // Valor
      cout << "---------------------------------------------------------------\n";

      temp_valida = true;
    }
  }
  if (temp_valida = true) // quando teve pelo menos 1 vpressao no intervalo
  {
    cout << "---------------------------------------------------------------\n";
    // terminamos impressao
    temp_valida = false; // resetamos variavel
  }
  else // quando nao teve nenhuma vpressao no intervalo
  {
    cout << " Nao ha temperaturas registradas no intervalo entre " << temp1 << "ºC e " << temp2 << "ºC " << endl; // mensagem ao usuario
    cout << "---------------------------------------------------------------\n";
    // terminamos impressao
  }
}

void cadastro_Pressao::get_Listagem_pressao()
{
  if (vagas == N_PRESSAO)
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

    for (int i = 0; i < N_PRESSAO; i++)
    {
      if (vpressao[i].getID_pressao() > -300)
      {
        cout << setw(8) << setfill('0') << vpressao[i].getID_pressao() << "  |  "; // ID
        vpressao[i].dataHora.readCalendar();                                       // Data
        cout << "   |   ";
        vpressao[i].dataHora.readClock(); // Hora
        cout << "   |  ";
        cout << vpressao[i].getValor_pressao() << endl; // Valor
      }
    }
  }
  cout << "---------------------------------------------------------------\n";
}

void cadastro_Pressao::Exclui_pressao(int check_id, float check_pressao, bool apaga_todos)
{
  if (vagas == N_PRESSAO) // SEM REGISTROS
  {
    cout << "---------------------------------------------------------------\n";
    cout << "            Nao ha leitura registrada para excluir" << endl;
    cout << "---------------------------------------------------------------\n";
    return;
  }
  // COM ALGUM REGISTRO

  // if (apaga_todos == true) // quando apagamos todos
  // {
  // for (int i = 0; i < N_PRESSAO; i++)
  // {
  //   if ((vpressao[i].getID_pressao() == check_id))
  //   {
  //     cout << "-------------------------------------\n";
  //     cout << "Pressao " << check_pressao << "de check_id " << vpressao[i].getID_pressao() << " excluida" << endl;
  //     cout << "-------------------------------------\n";
  //     vpressao[i].setID_pressao(0);
  //     vpressao[i].setValor_pressao(0);
  //     ++vagas;
  //   }
  // }

  // else // quando vamos apagar só 1
  // {

  for (int i = 0; i < N_PRESSAO; i++)
  {
    // ENCONTRA ID E TEMPERATURA
    if ((vpressao[0].getValor_pressao() > (check_pressao - 0.01)) & (vpressao[0].getValor_pressao() < (check_pressao + 0.01)) & (vpressao[0].getID_pressao() == check_id))
    {
      cout << "---------------------------------------------------------------\n";
      cout << "                     Registro excluido:" << endl;
      cout << "ID: " << vpressao[0].getID_pressao() << "; Pressao: " << vpressao[0].getValor_pressao() << endl;
      cout << "---------------------------------------------------------------\n";
      vpressao[0].setID_pressao(0);
      vpressao[0].setValor_pressao(0);
      ++vagas;
      return;
    }
    cout << vpressao[0].getValor_pressao();
    cout << vpressao[0].getID_pressao();
    // return;
    // }
    // else if (i = (N_PRESSAO - 1)) // se chegou aqui não achou nenhuma, logo ID não existe
    // {
    cout << "---------------------------------------------------------------\n";
    cout << "                 Registro nao encontrado! " << endl;
    cout << "ID: " << check_id << "; Pressao: " << check_pressao << endl;
    cout << "---------------------------------------------------------------\n";
    //   return;
    // }
    // }
  }
}

void interface_pressao()
{

  bool continuar = true;
  int b_id, b_switch;
  float b_pressao1, b_pressao2;
  cadastro_Pressao pressao;

  while (continuar == true)
  {
    cout << "------------------------- Pressao -------------------------------\n";
    cout << "Capacidade: " << N_PRESSAO << " registros; Leituras disponiveis para registro: " << pressao.vagas << endl;

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
      // --------------- Pressao ---------------
    case 1: // 1 - Cadastro de Sensor
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;
      pressao.set_new_ID(b_id);
      break;
    }

    case 2: // 2 - Registo Leitura do Sensor
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;
      pressao.set_NewLeitura(b_id);
      break;
      // o valor de leitura já é realizado na classe 'Pressao' que fornece um rand para o método setValor da classe 'Sensor'
      // a data tbm gera automatico -> pega do sistema operacional
    }

    case 3: // 3 - Consultar
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;

      cout << "Digite os limites do intervalo de pressao (temp1 a temp2) em graus Celsius" << endl;
      cout << "Pressao 1: ";
      cin >> b_pressao1;
      cout << "Pressao 2: ";
      cin >> b_pressao2;

      pressao.get_Consulta_pressao(b_pressao1, b_pressao2);
      break;
    }

    case 4: // 4 - Listar IDs
    {
      pressao.get_Lista_IDs();
      break;
    }
    case 5: // 4 - Listar todas as leituras de 1 ID
    {
      pressao.get_Listagem_pressao();
      break;
    }

    case 6: // Excluir
    {

      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_id;

      // cout << "Qual dos registros voce deseja excluir:" << endl;
      // for (int i = 0; i < N_PRESSAO; i++)
      // {
      //   if (pressao.vpressao[i].getValor_pressao() > (-273.15))
      //   {
      //     cout << i << " - " << vpressao[i].getValor_pressao() << endl;
      //   }
      // }
      cout << "Voce deseja excluir um ou todos os registros?\n";
      cout << "1 - Apenas um registro do sensor" << endl;
      cout << "2 - Todos os registros do sensor" << endl;
      cin >> b_pressao2;

      cout << "Digite a pressao que deseja excluir: ";
      cin >> b_pressao1;
      pressao.Exclui_pressao(b_id, b_pressao1, false);

      // if (b_pressao2 == 2)
      // {
      //   pressao.Exclui_pressao(b_pressao1, 0, true);
      //   break;
      // }
      // else
      // {
      //   cout << "Digite a pressao que deseja excluir: ";
      //   cin >> b_pressao1;
      //   pressao.Exclui_pressao(b_pressao1, b_pressao1, false);
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