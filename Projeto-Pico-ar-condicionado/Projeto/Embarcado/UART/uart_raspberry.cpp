// #include <string.h>
// #include <iomanip>
#include <stdlib.h> // This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <iostream> // Este arquivo específico inclui declarações básicas da biblioteca de E/S do C++
using namespace std;


#include "pico/stdlib.h"
#include <cstring>
#include "pico/bootrom.h"

#define LED_PIN 25

// int main() {
// 	stdio_init_all(); // init all standard IO
//     char buffer[1024]; // to send data to raspberry
// 	while(1){
        
//         scanf("%1024s", buffer); // scanf():reads in data | %1024s: 1024 bytes long string
//         // store into the buffer
//         printf("%s\n", buffer); // print back to PC received data from PC

//         // cout << "Welcome to the world \n" ;
//         printf("Welcome to the world \n"); // receive data from raspberry
//         sleep_ms(500);
//     }

// }


int main() {
	stdio_init_all(); // init all standard IO
	char buffer[1024]; // to send data to raspberry

	gpio_init(LED_PIN); // inicializa LED = pin 25
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while(1)
	{
		scanf("%1024s", buffer);// scanf():reads in data | %1024s: 1024 bytes long string
       // store into the buffer
		printf("%s\n", buffer); // print back to PC received data from PC

		if (strcmp(buffer, "ON") == 0) // if buffer contains "ON"
		{
			gpio_put(LED_PIN, 1); // set LED on

		} else if (strcmp(buffer, "OFF") == 0) // if buffer is "OFF"
		{
			gpio_put(LED_PIN, 0);		//set LED off
		} else if (strcmp(buffer, "REBOOT") == 0) // if buffer is "REBOOT"
		{
			reset_usb_boot(0,0);
		}
	}	

}