#include <HP_Sd.h>
#include <SD_MMC.h>
#include <SD.h>
#include <Arduino.h>
#include <HP_StatusDisplay.h>
#include <HP_Types.h>

#define SD_CS 5

bool HP_SDReader_connected = false;

void HP_SD_Init(HP_Sdmode mode)
{
  bool sdInserted = false;
  if (mode == SD_OVER_SPI)
  {
    /* Configure basic pins */
    pinMode(SD_CS, OUTPUT);

    if (!SD.begin(SD_CS))
    {
      Serial.println("ERROR: Was not able to mount SD!");
      /* Show error on screen and neopixel */
      while (!SD.begin(SD_CS))
      {
        vTaskDelay(500);
      }
    }

    HP_SDReader_connected = true;

    uint8_t cardType = SD.cardType();

    Serial.print("SD Type: ");
    switch (cardType)
    {
    case CARD_SD:
      Serial.println("SD");
      sdInserted = true;
      break;
    case CARD_SDHC:
      Serial.println("SDHC");
      sdInserted = true;
      break;
    case CARD_MMC:
      Serial.println("MMC");
      sdInserted = true;
      break;
    case CARD_UNKNOWN:
      Serial.println("Unknown type");
      sdInserted = true;
      break;
    case CARD_NONE:
      Serial.println("No card inserted");
      sdInserted = false;
      break;
    }

    if (sdInserted)
    {
      uint64_t cardSize = SD.cardSize() / (1024 * 1024);
      Serial.printf("SD Card Size: %lluMB\n", cardSize);
    }
  } 
  else if(mode == SD_OVER_SDIO)
  {
    // TODO
  } 
}

HP_ModStatus HP_getSDStatus()
{
  sdcard_type_t cardType = SD.cardType();
  
  if (cardType == CARD_NONE || cardType == CARD_UNKNOWN)
  {
    return MOD_FAULT;
  }

  if (!HP_SDReader_connected)
  {
    return MOD_HW_NOT_DETECTED;
  }

  return MOD_FUNCTIONAL;
}


bool HP_reconnectSD()
{
  if (!SD.begin(SD_CS))
  {
    Serial.println("ERROR: Was not able to mount SD!");
    return false;
  }

  return true;
}


void HP_reportSDEvent()
{

}
