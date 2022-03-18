using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()
#include "List_PC.cpp"
#include "UART_ubuntu.cpp"
#include <locale.h>
// setlocale(LC_ALL, "pt_BR.UTF-8");

// // ============== DEFINIÇÃO DA CLASSE =========== //
// class interface_PC
// {
// private:
// public:
// };
// // Construtor
// interface_PC::interface_PC()
// {
// }

// ============== MÉTODOS DA CLASSE =========== //

// ============== INTERFACE =========== //
void interface_PC()
{

  bool continuar = true;
  // bool b_bool;
  int b_int1, b_int2, b_switch;
  float b_float1, b_float2;
  string b_string1, b_string2, b_string3, b_string4;
  List_PC lista1(18250065);

  while (continuar == true)
  {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "---------------------- Interface Computador ----------------------------\n";
    // cout << " Bem vindo a interface Computador";

    // cout << "Capacidade: " << N_TEMPERATURA << " registros; Leituras disponiveis para registro: " << lista1.vagas << endl;
    cout << "0 - Aquisição de log" << endl;
    cout << "1 - Cadastrar evento" << endl;
    cout << "2 - Excluir eventos" << endl;
    cout << "3 - Listar todos os eventos" << endl;
    cout << "4 - Listar eventos em intervalo de data" << endl;
    cout << "5 - Encerrar Programa" << endl;
    // cout << "5 - Lista IDs" << endl;
    // cout << "6 - Listar todas as leituras" << endl;

    cout << "Digite a operacao desejada:";
    cin >> b_switch;

    switch (b_switch)
    {
      // --------------- XXX ---------------

    case 0: // 0 - Serial UART
    {
      UART_ubuntu obj_UART;
      obj_UART.RequestLogProcess();

      break;
    }

    case 1: // 1 - Cadastro de evento - OK
    {
      setlocale(LC_ALL, "pt_BR.UTF-8");
      cout << "Digite o ID (8 dígitos): ";
      cin >> b_string1;

      cout << "Digite a data (dd:mm:aaaa): ";
      cin >> b_string2;

      cout << "Digite a hora (hh:mm:ss): ";
      cin >> b_string3;

      cout << "Digite a temperatura externa (ºC): ";
      cin >> stoi(b_int1);

      cout << "Digite a temperatura do dispositivo (ºC): ";
      cin >> stoi(b_int2);

      lista1.insertAfterLast(b_string1, b_string2, b_string3, b_int1, b_int2, false);
      // string new_ID, string new_data, string new_hora, int new_temp_ext, int new_temp_int, bool new_automatico_ou_botao
      break;
    }

    case 2: // 2 - Excluir evento - OK
    {
      cout << "Digite a temperatura que deseja excluir (irá excluir todos os eventos de mesma temperatura):";
      cin >> b_int1;
      lista1.removeNode(b_int1);
      break;
      // o valor de leitura já é realizado na classe 'Temperatura' que fornece um rand para o método setValor da classe 'Sensor'
      // a data tbm gera automatico -> pega do sistema operacional
    }

    case 3: // 3 - Listar todos os eventos - OK
    {
      lista1.listAll();

      break;
    }

    case 4: // 4 - Listar eventos em intervalo de data - OK
    {

      cout << "Digite a data de início (dd/mm/aaaa):";
      cin >> b_string1;
      cout << "Digite a data final (dd/mm/aaaa):";
      cin >> b_string2;

      cout << "Digite a hora de início (hh/mm/ss):";
      cin >> b_string3;
      cout << "Digite a hora final (hh/mm/ss):";
      cin >> b_string4;

      lista1.listInterval(b_string1, b_string2, b_string3, b_string4);
      break;
    }
    case 5: // 4 - Listar todas as leituras de 1 ID
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