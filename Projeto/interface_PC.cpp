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
  int b_id, b_switch;
  float b_temp1, b_temp2;
  interface_PC temperatura;

  while (continuar == true)
  {
    cout << "---------------------- Temperatura ----------------------------\n";

    cout << "Capacidade: " << N_TEMPERATURA << " registros; Leituras disponiveis para registro: " << temperatura.vagas << endl;

    cout << "1 - Cadastrar evento" << endl;
    cout << "2 - Listar todos os eventos" << endl;
    cout << "3 - Listar eventos em intervalo de data " << endl;
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