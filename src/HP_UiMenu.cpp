#include <HP_UiMenu.h>
#include <HP_Oled.h>
#include <HP_Types.h>
#include <vector>

/* PROTOTYPES */
void HP_Ui_ShowMenu(std::vector <HP_MenuItem*> itemList);



/* Settings Menu */
HP_MenuItem HP_MI_Settings_WiFiMode = {"Toggle WifiMode: AP", true, true, NULL, 1};
HP_MenuItem HP_MI_Settings_StatusLEDs = {"Toggle Status LEDs", true, true, NULL, 1};
HP_MenuItem HP_MI_Settings_AutoTuning = {"Start Autotuning", true, true, NULL, 1};


/* Main Menu */
HP_MenuItem HP_MI_Main_Settings = {"Settings", true, true, HP_Ui_ShowSettingsMenu, 1};
HP_MenuItem HP_MI_Main_SDSearch = {"Search SD", true, true, NULL, 1};
HP_MenuItem HP_MI_Main_TemperatureSet = {"Set Temperature", true, true, NULL, 1};
HP_MenuItem HP_MI_Main_Reset = {"Reset Device", true, true, NULL, 1};

std::vector <HP_MenuItem*> displayVec;


void HP_Ui_ShowSettingsMenu()
{
    vTaskDelay(200);
    Serial.println("Showing Settings Menu");
    displayVec.clear();
    displayVec.push_back(&HP_MI_Main_TemperatureSet);
    displayVec.push_back(&HP_MI_Main_SDSearch);
    displayVec.push_back(&HP_MI_Main_Settings);
    displayVec.push_back(&HP_MI_Main_Reset);
    HP_Ui_ShowMenu(displayVec);
}


void HP_Ui_ShowMainMenu()
{
    vTaskDelay(200);
    Serial.println("Showing Main Menu");
    displayVec.push_back(&HP_MI_Main_TemperatureSet);
    displayVec.push_back(&HP_MI_Main_SDSearch);
    displayVec.push_back(&HP_MI_Main_Settings);
    displayVec.push_back(&HP_MI_Main_Reset);
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