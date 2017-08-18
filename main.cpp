#include "mbed.h"

//------------------------------------
// This code for Maxbotix MB1030 LV-MaxSonar-EZ3
// Read distance Values in Meters
// Target Board: NUCLEO-L476RG
// Auther: Mishal Hamed   Alm3shaws@hotmail.com
//------------------------------------

Serial pc(SERIAL_TX, SERIAL_RX);
AnalogIn Distance(PA_0);

int main()
{
    float measure;

    pc.printf("started! !\n");
    
    while(1) {
            measure = (((Distance.read()*(3.3/4096))/2)*10000);
            measure = (measure/0.0064)*0.0254;
            pc.printf("Distance = %.2f Meter \n", measure);
            wait(2);
    }
}