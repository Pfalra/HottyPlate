#include <HP_Settings.h>
#include <HP_WiFi.h>
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiServer.h>
#include <HP_Types.h>


void HP_initializeWiFi(const char* ssid, const char* pwd)
{
    /* Initialize WiFi */
    WiFi.begin(ssid, pwd);
    WiFi.setAutoConnect(true);
    Serial.print("Connecting to: ");
    Serial.println(ssid);

    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(250);
        Serial.print('.');
    }

    Serial.println('\n');
    Serial.println("> Connection up and running!");
    Serial.print("IP address: \t");
    Serial.println(WiFi.localIP());
}

HP_ModStatus HP_getWiFiStatus()
{
    /* Check if the modem is in sleep mode */
    bool sleep = WiFi.getSleep();

    /* Check RSSI */
    int32_t rssi = WiFi.RSSI();

    return MOD_FUNCTIONAL;
}

bool HP_reconnectWiFi()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.reconnect();
    }
    return true;
}

void HP_reportWiFiEvent()
{

}