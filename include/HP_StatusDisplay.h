#ifndef HP_STATUSDISPLAY_H
#define HP_STATUSDISPLAY_H

#include <HP_Types.h>
#include <stdint.h>

void HP_StatusDisplay_Init(uint8_t ledPin);

void HP_StatusDisplay_ShowStatus(HP_ModStatus status);


#endif 