#include <HP_StatusDisplay.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <HP_Types.h>

#include <HP_Settings.h>

#define NOT_INIT_COLOR 10,10,10
#define CONNECTING_COLOR 0,50,100
#define ERROR_COLOR 100,0,0
#define FUNCTIONAL_COLOR 0,100,0
#define INITIALIZING_COLOR CONNECTING_COLOR
#define BLINK_INTERVAL 500

#define LED_COUNT 5

#define LED_WIFI_STAT 0
#define LED_SD_STAT 1
#define LED_ADC_STAT 2
#define LED_TEMPSENSE_STAT 3
#define LED_OLED_STAT 4         // NOTE: Initially an OLED was used. Change if LCD etc. is used.



/* Variables */
Adafruit_NeoPixel statusLeds(LED_COUNT, STATUSLED_PIN, NEO_GRBW + NEO_KHZ800);
bool modstarted = false;

/* Functions */
void HP_StatusDisplay_Init(uint8_t ledPin)
{
    modstarted = true;
    statusLeds.clear();

    /* Set everything to NOT_INIT*/
    for (int i = 0; i < LED_COUNT; i++)
    {
        statusLeds.setPixelColor(i, statusLeds.Color(INITIALIZING_COLOR));
    }
    statusLeds.show();
    vTaskDelay(30);
    
}


void HP_StatusDisplay_ShowStatus(HP_ModStatus status)
{
    if (status == MOD_FUNCTIONAL)
    {
    }   
    else if (status == MOD_INIT_RUNNING) 
    {
    }
    else if (status == MOD_HW_NOT_DETECTED) 
    {
    }
    else if (status == MOD_NOT_INITIALIZED) 
    {
    }
    else if (status == MOD_FAULT) 
    {

    }
}
