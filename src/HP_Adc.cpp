#include <ADS1X15.h>
#include <HP_Settings.h>
#include <Arduino.h>

ADS1115 ExtADC(EXT_ADC_ADDR);


void HP_Adc_init()
{
    /* Initialize ADC */
    Serial.print("ADS1x15 LIB: ");
    Serial.println(ADS1X15_LIB_VERSION);

    ExtADC.begin();

    Serial.println(F("\nSET\tACTUAL\n=================="));
    for (uint32_t speed = 50000; speed <= 1000000; speed += 50000)
    {
        ExtADC.setWireClock(speed);
        Serial.print(speed); 
        Serial.print("\t");
        Serial.println(ExtADC.getWireClock());
    }
    ExtADC.setWireClock(1000000);
    Serial.println();
    ExtADC.setGain(0);
}