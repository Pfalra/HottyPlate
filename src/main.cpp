#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>

/* HottyPlate includes */
#include <HP_Types.h>
#include <HP_WiFi.h>
#include <HP_Sd.h>
#include <HP_StatusDisplay.h>
#include <HP_Settings.h>
#include <HP_SysMon.hpp>
#include <HP_Adc.h>
#include <HP_Oled.h>
#include <HP_Graphics.h>



HP_SysMon gSystemMonitor(SYSMON_EXEC_TIME);

void CreateAppInitTasks();

void InitializeWiFi(void * param);
void InitializeOther(void * param);
void ShowSysStatus(void * param);
void InitializeSD(void * param);

/* TASK HANDLES */
TaskHandle_t initWiFiHandle; 
TaskHandle_t initOtherHandle; 
TaskHandle_t initSDHandle; 


void setup() {
    /* Start Serial communication */
    Serial.begin(250000);
    Serial.println();
    Serial.println("Hotty starting up...");
    vTaskDelay(200);

    /* Initialize Neopixel */
    HP_StatusDisplay_Init(STATUSLED_PIN);

    /* Initialize OLED */
    HP_Oled_init();
    /* Create tasks for initialization */
    CreateAppInitTasks();

    gSystemMonitor.assignMod("WiFi-Mon", HP_getWiFiStatus, HP_reconnectWiFi, HP_reportWiFiEvent);
    gSystemMonitor.startMon();
}

void loop() 
{
}

void CreateAppInitTasks()
{
    /* Create tasks for further initializations */
    xTaskCreate(
        InitializeWiFi,   // Function that should be called
        "Initialize WiFi",// Name of the task (for debugging)
        4096,             // Stack size (bytes)
        NULL,             // Parameter to pass
        3,                // Task priority
        &initWiFiHandle
    );

    xTaskCreate(
        InitializeOther,    // Function that should be called
        "Initialize Other", // Name of the task (for debugging)
        8192,            // Stack size (bytes)
        NULL,            // Parameter to pass
        2,               // Task priority
        &initOtherHandle
    );

    xTaskCreate(
        InitializeSD,     // Function that should be called
        "Initialize SD",  // Name of the task (for debugging)
        8192,             // Stack size (bytes)
        NULL,             // Parameter to pass
        2,                // Task priority
        &initSDHandle
    );
}


void InitializeWiFi(void * param)
{
    /* Start WiFi */
    Serial.println("I>Starting WiFi.");
    HP_initializeWiFi(MY_SSID, MY_PWD);
    Serial.println("I>WiFi init done");
    /* Make task only execute once */
    vTaskDelete(initWiFiHandle);
}

void InitializeOther(void * param)
{
    Serial.println("\r\nI>Initializing other hardware");
    /* Initialize ADC */
    HP_Adc_init();

    Serial.println("\r\nI>Other hardware init done");
    vTaskDelete(initOtherHandle);
}

void InitializeSD(void * param)
{
    /* Initialize SD */
    HP_SD_Init(SD_OVER_SPI);
    Serial.println("I>SD init done");
    vTaskDelete(initSDHandle);
}

