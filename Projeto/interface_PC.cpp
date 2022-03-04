using namespace std; // Esse comando é utilizado de forma a evitar a indicação std:: antes de usar o comando cout, etc...
#include <iomanip>   // para usar setfill() e setw()
#include "List_temp_fixa.cpp"

// ============== DEFINIÇÃO DA CLASSE =========== //
class interface_PC
{
private:
public:
};
// Construtor
interface_PC::interface_PC()
{
}

// ============== MÉTODOS DA CLASSE =========== //

// ============== INTERFACE =========== //
void interface_temp()
{

  bool continuar = true;
  int b_temp, b_switch;
  float b_temp1, b_temp2;
  List_temp_fixa lista1(18250065);

  while (continuar == true)
  {
    cout << "---------------------- Interface Computador ----------------------------\n";

    // cout << "Capacidade: " << N_TEMPERATURA << " registros; Leituras disponiveis para registro: " << lista1.vagas << endl;

    cout << "1 - Cadastrar evento" << endl;
    cout << "2 - Excluir evento " << endl;
    cout << "3 - Listar todos os eventos" << endl;
    cout << "4 - Listar eventos em intervalo de data " << endl;
    // cout << "5 - Lista IDs" << endl;
    // cout << "6 - Listar todas as leituras" << endl;
    cout << "7 - Voltar " << endl;

    cout << "Digite a operacao desejada:";
    cin >> b_switch;

    switch (b_switch)
    {
      // --------------- XXX ---------------
    case 1: // 1 - Cadastro de evento
    {
      cout << "Digite a temperatura desejada (ºC): ";
      cin >> b_temp;
      lista1.insertAfterLast(b_temp, false);
      break;
    }

    case 2: // 2 - Excluir evento
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_temp;
      lista1.set_NewLeitura(b_temp);
      break;
      // o valor de leitura já é realizado na classe 'Temperatura' que fornece um rand para o método setValor da classe 'Sensor'
      // a data tbm gera automatico -> pega do sistema operacional
    }

    case 3: // 3 - Listar todos os eventos
    {
      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_temp;

      cout << "Digite os limites do intervalo de lista1 (temp1 a temp2) em graus Celsius" << endl;
      cout << "Temperatura 1: ";
      cin >> b_temp1;
      cout << "Temperatura 2: ";
      cin >> b_temp2;

      lista1.get_Consulta_temperatura(b_temp1, b_temp2);
      break;
    }

    case 4: // 4 - Listar eventos em intervalo de data
    {
      lista1.get_Lista_IDs();
      break;
    }
    case 5: // 4 - Listar todas as leituras de 1 ID
    {
      lista1.get_Listagem_temperaturas();
      break;
    }

    case 6: // Excluir
    {

      cout << "Digite o numero de identificacao (ID): ";
      cin >> b_temp;

      cout << "Digite a lista1 que deseja excluir: ";
      cin >> b_temp1;
      lista1.Exclui_temperatura(b_temp, b_temp1, false);

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