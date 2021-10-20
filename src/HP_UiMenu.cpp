#include <HP_UiMenu.h>
#include <HP_Oled.h>
#include <HP_Types.h>
#include <vector>

/* PROTOTYPES */
void HP_Ui_ShowMenu(std::vector <HP_MenuItem*> itemList);


/* Main Menu */
HP_MenuItem HP_MI_Main_Settings = {"Settings", true, true, NULL, 1};
HP_MenuItem HP_MI_Main_SDSearch = {"Search SD", true, true, NULL, 1};
HP_MenuItem HP_MI_Main_TemperatureSet = {"Set Temperature", true, true, NULL, 1};

std::vector <HP_MenuItem*> displayVec;

void HP_Ui_ShowMainMenu()
{
    vTaskDelay(500);
    Serial.println("Showing Main Menu");
    displayVec.push_back(&HP_MI_Main_TemperatureSet);
    displayVec.push_back(&HP_MI_Main_SDSearch);
    displayVec.push_back(&HP_MI_Main_Settings);
    HP_Ui_ShowMenu(displayVec);
}

/* TODO: Try to pass vector by reference */
void HP_Ui_ShowMenu(std::vector <HP_MenuItem*> itemList)
{
    Adafruit_SSD1306* oledPtr = HP_Oled_getOLED();
    oledPtr->clearDisplay();
    oledPtr->setCursor(0,0);
    oledPtr->println("");

    for (int i = 0; i < displayVec.size(); i++)
    {
        oledPtr->setTextSize(displayVec.at(i)->textSize);
        Serial.println(displayVec.at(i)->itemStr);
        oledPtr->println(displayVec.at(i)->itemStr);
    }
    oledPtr->display();
}