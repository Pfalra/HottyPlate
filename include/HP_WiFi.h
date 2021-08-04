#ifndef HP_WIFI_H
#define HP_WIFI_H

#include <HP_Types.h>

void HP_initializeWiFi(const char* ssid, const char* pwd);

HP_ModStatus HP_getWiFiStatus();

bool HP_reconnectWiFi();

void HP_reportWiFiEvent();

#endif