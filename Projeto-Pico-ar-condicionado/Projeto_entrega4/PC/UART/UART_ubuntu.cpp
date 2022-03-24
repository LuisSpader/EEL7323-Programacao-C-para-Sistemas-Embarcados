#include <string>
#include <iostream>
#include "headers.h"
#include "CppLinuxSerial/SerialPort.hpp" // 3rd party includes
#include "gtest/gtest.h" // System includes
#include "TestUtil.hpp" // User includes
// #include "BasicTests.cpp"
#include <locale.h>
// setlocale(LC_ALL, "pt_BR.UTF-8");

#include "List_PC.cpp"

using namespace mn::CppLinuxSerial;
const std::string device0Name_ = TestUtil::GetInstance().GetDevice0Name();
const std::string device1Name_ = TestUtil::GetInstance().GetDevice1Name();

class UART_ubuntu : public testing::Environment, protected List_PC
{
private:
    // SerialPort serialPort(string "/dev/ttyUSB0", BaudRate::B_57600, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
    SerialPort obj_S_Port0, obj_S_Port1;
    
public:
    SerialPort serialPort;
    UART_ubuntu();
    ~UART_ubuntu();
    int Open();
    bool Tests();

    void SendText(string str_send);
    string ReceiveText(string str_send);
    string RequestLog();
    string RequestLogProcess();
};

UART_ubuntu::UART_ubuntu()
{
    cout << "Inicializando UART Ubuntu ..." << endl;
    // PORTA 0
    SerialPort serialPort0(device0Name_, BaudRate::B_9600);
    obj_S_Port0 = serialPort0;
    obj_S_Port0.Open();

    // PORTA 1
    SerialPort serialPort1(device1Name_, BaudRate::B_9600);
    obj_S_Port1 = serialPort1;
    obj_S_Port1.Open();

    // Tests();

}

UART_ubuntu::~UART_ubuntu()
{
    obj_S_Port0.Close();
    obj_S_Port1.Close();
}

bool UART_ubuntu::Tests()
{
    SendText("PC: Hello");

    std::string readData;
    obj_S_Port1.Read(readData);

    // ASSERT_EQ("Pico: Hi", readData);
    if (readData == "Pico: Hi"){
        setlocale(LC_ALL, "pt_BR.UTF-8");
        cout << "Comunicação UART OK" << endl;
        return true;
    }else{
        cout << "Comunicação UART Falhou" << endl;
        return false;}
}

void UART_ubuntu::SendText(string str_send)
{
    // Write some ASCII data
    obj_S_Port0.Write(str_send);
}

string UART_ubuntu::ReceiveText(string str_send)
{
    std::string readData;
    obj_S_Port1.Read(readData);
    return readData;
}

string UART_ubuntu::RequestLog()
{

    string readData;
    string new_ID, new_data, new_hora, new_temp_ext, new_temp_int, new_automatico_ou_botao;
    
    SendText("Log");
    while (readData != "Stop"){
        obj_S_Port1.Read(readData);
        // substr(init, size)
        new_data = readData.substr (0,10); // string
        new_hora = readData.substr (10,8); // string
        new_ID   = stoi(readData.substr (18,8)); // int
        new_temp_ext = stoi(readData.substr (26,2)); // int
        new_temp_int = stoi(readData.substr (28,2)); // int

        new_automatico_ou_botao = stoi(readData.substr (30,1)); // bool 
        insertAfterLast(new_ID, new_data, new_hora, new_temp, new_automatico_ou_botao)
    }
}

string UART_ubuntu::RequestLogProcess()
{
    bool b_bool;
    b_bool = Tests();

    if (b_bool == true){
        cout << "Solicitando log ..." << endl;
        RequestLog();
        }
}
