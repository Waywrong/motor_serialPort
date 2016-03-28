#include <iostream>
#include <stdlib.h> 
#include <SerialStream.h>

LibSerial::SerialStream _motor;

void writePort(std::string& str){
  _motor << str;//lpBufferToWrite;
  std::cout << "wrote the demand "<<str.c_str()<<" written " << std::endl;
  
}

int main(int argc, char **argv) {

    std::string PORT ="/dev/ttyUSB0";
    
    _motor.Open(PORT);
    _motor.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
    if ( ! _motor.good() ){
      std::cerr << "Error: Could not set the baud rate." <<std::endl;
      exit(1);
    }
    _motor.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
    if ( ! _motor.good() ){
      std::cerr << "Error: Could not set the char size." <<std::endl;
      exit(1);
    }
    _motor.SetParity( LibSerial::SerialStreamBuf::PARITY_NONE ) ;
    if ( ! _motor.good() ){
      std::cerr << "Error: Could not set the parity." <<std::endl;
      exit(1);
    }
    _motor.SetNumOfStopBits( 1 ) ;
    if ( ! _motor.good() ) {
        std::cerr << "Error: Could not set the number of stop bits."
                  << std::endl ;
        exit(1) ;
    }

    _motor.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE ) ;
    if ( ! _motor.good() ){
      std::cerr << "Error: Could not set the control." <<std::endl;
      exit(1);
    }
    _motor.SetNumOfStopBits(1) ;
    if ( ! _motor.good() ){
      std::cerr << "Error: Could not set the stopbit." <<std::endl;
      exit(1);
    }
    
    //std::string enable("1en\n2en\n");
    std::string enable("v50\n");
    writePort(enable);
    
    
    
   //read port 
//     while( _motor.rdbuf()->in_avail() == 0 ) 
//     {
//         usleep(100) ;
//     }
//     //
//     // Keep reading data from serial port and print it to the screen.
//     //
//     while( _motor.rdbuf()->in_avail() > 0  ) 
//     {
//         char next_byte;
//         _motor.get(next_byte);
//         std::cerr << std::hex << static_cast<int>(next_byte) << " ";
//         usleep(100) ;
//     } 
//     std::cerr << std::endl ;

    return 0;
}
