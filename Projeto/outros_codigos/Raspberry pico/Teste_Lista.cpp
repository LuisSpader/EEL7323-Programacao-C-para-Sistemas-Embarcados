#include "Fila.cpp"
#include "ClockCalendar.cpp"
#include <iostream>
#include <string>
#include <stdio.h>
//#include "pico/stdlib.h"
//#include "hardware/uart.h"
/// \tag::hello_uart[]

#define UART_ID uart0
#define BAUD_RATE 9600

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1
//UTILIZADO PARA TESTAR A IMPLEMENTAÇÃO DA FILA. PODE SER USADO PARA TESTAR A LISTA
int main(){
    // Set up our UART with the required speed.
    uart_init(UART_ID, BAUD_RATE);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    cout << "Hellow World" << endl;
    Fila fila;
    int d,m,y,h,mi,s,val_valid;
    ClockCalendar test;
    string ID = "0001";
    string fullHour, fullDate;
    test.setClockCalendar(1,1,2022,23,59,0);
    test.getClock(h,mi,s);
    test.getCalendar(d,m,y);
    //Fazer uma Classe para isso//
    string str_convh(std::to_string(h));
    string str_convmi(std::to_string(mi));
    string str_convs(std::to_string(s));
    string str_convd(std::to_string(d));
    string str_convm(std::to_string(m));
    string str_convy(std::to_string(y));
    fullHour = str_convh + ":" + str_convmi + ":" + str_convs;
    fullDate = str_convd + "/" + str_convm + "/" + str_convy;
    cout << "result: " << fullHour << endl;
    cout << "result: " << fullDate << endl;
    //
    test.advance();
    test.getClock(h,mi,s); 
    test.getCalendar(d,m,y);
    


    //int saida;
    
    cout << "testando" << endl;
    fila.insertAfterLast(ID, fullDate, fullHour);
    /*fila.insertAfterLast("0001", "22/03/2022", "11:26:00");
    fila.insertAfterLast("0001", "23/03/2022", "12:26:00");
    cout << "O valor é: " << fila.readFirstID() << endl;
    cout << "O valor é: " << fila.readFirstDate() << endl; 
    cout << "O valor é: " << fila.readFirstHour() << endl;
    fila.removeFirst();
    cout << "O valor é: " << fila.readFirstID() << endl;
    cout << "O valor é: " << fila.readFirstDate() << endl;
    cout << "O valor é: " << fila.readFirstHour() << endl;
    fila.removeFirst();
    cout << "O valor é: " << fila.readFirstID() << endl;
    cout << "O valor é: " << fila.readFirstDate() << endl;
    cout << "O valor é: " << fila.readFirstHour() << endl;*/
    while(true){
        if( /*variavel temp externa atual*/ != /*variavel temp*/|| /*variavel botão*/ != 0){
        
            fila.insertAfterLast(ID, fullDate, fullHour);
        }
        //TESTAR ISSO DEPOIS
        val_valid = fila.readFirstID();
        if(/*porta UART conectada*/){
            while(val_valid != ""){
                uart_puts(UART_ID, fila.readFirstID());
                uart_puts(UART_ID, fila.readFirstDate());
                uart_puts(UART_ID, fila.readFirstHOur());
                fila.removeFirst();
                val_valid = fila.readFirstID();
                
            }
        }
    
    

return 0;
}