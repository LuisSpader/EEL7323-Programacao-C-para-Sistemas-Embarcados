/************************************************************
 * File RobotLinux.h - Header for RobotLinux class
 *
 * This class has the implementation for virtual
 * methods from Robot.h (and Robot.cpp)
 *
 * Project: Fischer Arm
 *
 * Author: Eduardo Augusto Bezerra
 * Date: 04/04/2003
 *
 * Last change: Eduardo Augusto Bezerra
 * Date: 26/04/2003
 *
 * Methods for controlling the robot in C++ under linux
 * This code has been tested on linux Red Hat 8.0
 *
 *************************************************************/

#include "Uart.cpp"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
#include <string.h>
using namespace std;

/************************************************************
 * Class RobotLinux
 * C++ header for the serial interface methods used to
 * control FischerTechnik robots under linux O.S.
 *************************************************************/
class UartLinux : public Uart
{
private:
  // char serial[11];           // serial port name (e.g. /dev/ttyS0, ...)
  int fd; // handle to serial port (fd == -1, error!)
  //
public:
  //
  UartLinux(void);  // RobotLinux.cpp
  ~UartLinux(void); // RobotLinux.cpp
  //
  char sendCommand();       // RobotLinux.cpp
  void openSerial(int ser); // RobotLinux.cpp
};

/************************************************************
 * Constructor
 *************************************************************/
UartLinux::UartLinux(void)
{
  motorWord = 0;
  fd = -1;
}
/************************************************************
 * Destructor
 *************************************************************/
UartLinux::~UartLinux(void)
{
  close(fd);
}

/************************************************************
 * void RobotLinux::open"/dev/ttyUSB0"(int ser)
 *
 * open the "/dev/ttyUSB0" connection;
 * sets the "/dev/ttyUSB0" parameters to 9600 Baud, no parity, 8, 1;
 * and turns all motors off
 *
 *************************************************************/
void UartLinux::openSerial(int ser)
{
  // serial names

  struct termios options;

  // strcpy(serial,"/dev/ttyUSB0");

  fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
  cout << "fd e: " << fd << endl;
  if (fd == -1) // ERROR!!
    cout << "Error opening "
         << "/dev/ttyUSB0" << endl;
  else
    fcntl(fd, F_SETFL, 0);
  cout << "Serial port in use: "
       << "/dev/ttyUSB0" << endl
       << endl;

  // Program serial port to 9600, 8, 1, no parity
  //

  // Get the current options for the port
  tcgetattr(fd, &options);

  // Set the baud rate to 9600
  cfsetispeed(&options, B9600);
  cfsetospeed(&options, B9600);

  // Enable the receiver and set local mode
  options.c_cflag |= (CLOCAL | CREAD);

  // Setting parity checking (no parity) 8N1
  options.c_cflag &= ~PARENB; /* no parity */
  options.c_cflag &= ~CSTOPB; /* 1 stop bit */
  options.c_cflag &= ~CSIZE;  /* Mask the character size bits */
  options.c_cflag |= CS8;     /* Select 8 data bits */

  // Setting raw input
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

  // Setting raw output
  options.c_oflag &= ~OPOST;

  // Set the new options for the port
  tcsetattr(fd, TCSANOW, &options);

  // motorsOff();                // motors off
}

/************************************************************
 * char sendCommand(char motorWord)
 *
 * gets a full word representing all inputs (1..8)
 *************************************************************/
char UartLinux::sendCommand()
{
  char read_buf[256];
  while (true)
  {
    memset(&read_buf, '\0', sizeof(read_buf));
    int num_bytes = read(fd, &read_buf, sizeof(read_buf));

    if (fd == -1)
    {
      cout << "Erro: the serial port is closed. Please, "
           << "use the openSerial() method to open it. " << endl;
    }
    // printf("Read %i bytes. Received message: %s\n", num_bytes, read_buf) ;
    printf("Value: %s\n", read_buf);
  }
  return 0;
}
// xx/xx/xxxx xx:xx:xx