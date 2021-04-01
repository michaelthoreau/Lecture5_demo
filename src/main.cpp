#include <mbed.h>
#include <USBSerial.h>

#include <math.h>

//serial object
USBSerial serial;

// analog input on port A pin 1
AnalogIn ain(PA_1);


int main() {

  while (1) {

    // buffer of floats
    float buf[100];

    serial.printf("data:--------------------------\n\r");
    // read a block of data
    for (int i = 0; i < 100; i++){
      buf[i] = ain.read();
      wait_ms(1);
    }
    
    // write data to terminal
    for (int i = 0; i < 100; i++){
      serial.printf("%3.2f\n\r", buf[i]);
    }

    wait_ms(2000);
    

  }
}
