#ifndef HP_SD_H
#define HP_SD_H

#include <HP_Types.h>

typedef enum HP_Sdmode_e
{
    SD_OVER_SPI,
    SD_OVER_SDIO
} HP_Sdmode;

void HP_SD_Init(HP_Sdmode mode);

#endif